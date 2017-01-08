#include "listautenti.h"
#include <QString>

listaUtenti::listaUtenti() {}

void listaUtenti::aggiungiUtente(utente& user) {
  if(!utentePresente(user)) lista.push_back(&user);
  else
    std::cout<< user << " ==> utente già presente" << std::endl;
}

void listaUtenti::togliUtente(const utente& user) {
  utente* p = utentePresente(user);
  if(p) lista.erase(std::find(lista.begin(),lista.end(),p));
  else std::cout<<"utente non presente" <<std::endl;
}

utente* listaUtenti::utentePresente(const utente& user) const {
  std::vector<utente*>::const_iterator it = lista.begin();
  for( ;it<lista.end(); ++it) {
      if(**it == user) return *it;
    }
  return 0;
}

/*
utente* listaUtenti::utentePresente(const std::string& nome, const std::string& passwd) const {
  std::vector<utente*>::const_iterator it = lista.begin();
  for(;it<lista.end(); it++) {
      if((*it)->showUsername()==nome && (*it)->showPassword()==passwd) return *it;
    }
  admin* ad = new admin("admin","admin");
  return ad;
}
*/

std::ostream& operator<< (std::ostream& os, const listaUtenti& list ) {
  if(list.lista.empty()) os << "LISTA VUOTA"<< std::endl;
  else {
      os << "LISTA UTENTI:" << std::endl;
      for(std::vector<utente*>::const_iterator it = list.lista.begin(); it<list.lista.end(); ++it) {
          os << **it << std::endl;
        }
    }
  return os;
}

void listaUtenti::caricaListaUtenti() {
  QFile file(":/new/utenti.xml");
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
  std::string username;
  std::string password;

  if(reader.readNextStartElement())
    username = (reader.readElementText()).toStdString();

  if(reader.readNextStartElement())
    password = (reader.readElementText()).toStdString();

  if(reader.readNextStartElement()) {
    std::string tipo = reader.readElementText().toStdString();
    if(tipo == "admin") {
      admin* tmp = new admin (username,password);
      lista.push_back(tmp);
    }
    else if(tipo == "moderatore") {
      moderatore* tmp = new moderatore (username,password);
      lista.push_back(tmp);
    }
    else if(tipo == "utente") {
      utente* tmp = new utente (username,password);
      lista.push_back(tmp);
    }
  }
}




































