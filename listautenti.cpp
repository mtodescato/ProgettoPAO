#include "listautenti.h"

listaUtenti::~listaUtenti() {
  std::list<utente*>::iterator it = lista.begin();
  for(; it != lista.end();++it) {
      delete *it;
    }
  lista.clear();
}

bool listaUtenti::aggiungiUtente(utente& user) {
  utente* usr = utentePresente(user);
  if(!usr) {
      lista.push_back(&user);
      return true;
    }
  else
    return false;

}

bool listaUtenti::togliUtente(const utente& user) {
  utente* p = utentePresente(user);
  if(p) {
      lista.erase(std::find(lista.begin(),lista.end(),p));
      return true;
    }
  else
    return false;
}

utente* listaUtenti::utentePresente(const utente& user) const {
  std::list<utente*>::const_iterator it = lista.begin();
  for( ;it != lista.end(); ++it) {
      if(**it == user) return *it;
    }
  return 0;
}

std::ostream& operator<< (std::ostream& os, const listaUtenti& list ) {
  if(list.lista.empty()) os << "LISTA VUOTA"<< std::endl;
  else {
      os << "LISTA UTENTI:" << std::endl;
      for(std::list<utente*>::const_iterator it = list.lista.begin(); it != list.lista.end(); ++it) {
          os << **it << std::endl;
        }
    }
  return os;
}

void listaUtenti::caricaListaUtenti() {
  QFile file(":/risorse/utenti.xml");
  if(!file.open(QFile::ReadOnly))
    return;
  QXmlStreamReader reader(&file);

  if(reader.readNextStartElement())
    if(reader.name() == "listaUtenti")
      while(reader.readNextStartElement()) {
      this->caricaUtente(reader);
      reader.skipCurrentElement();
     }
}

void listaUtenti::caricaUtente(QXmlStreamReader& reader) {
  std::string username = readXmlString(reader);
  std::string password = readXmlString(reader);

  if(reader.readNextStartElement()) {
    utente* tmp = 0;
    std::string tipo = reader.readElementText().toStdString();
    if(tipo == "admin") {
      tmp = new admin (username,password);
    }
    else if(tipo == "moderatore") {
      tmp = new moderatore (username,password);
    }
    else if(tipo == "utente") {
      tmp = new utente (username,password);
    }

    if(tmp)
      {
        lista.push_back(tmp);
    }
  }
}
