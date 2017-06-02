#include "listautenti.h"


listaUtenti::~listaUtenti() { distruggi(lista); }

std::list<utente*> listaUtenti::copia(const std::list<utente*>& lista) {
  std::list<utente*> tmp;
  auto it = lista.begin();
  for(; it!=lista.end(); ++it) {
      tmp.push_back((*it)->clone());
    }
  return tmp;
}

void listaUtenti::distruggi(std::list<utente*>& lista) {
  auto it = lista.begin();
  for(;it!=lista.end();++it) {
      delete *it;
    }
  lista.clear();
}

listaUtenti& listaUtenti::operator= (const listaUtenti& l2) {
  if(this != &l2) {
      distruggi(lista);
      lista = copia(l2.lista);
    }
  return *this;
}

listaUtenti::listaUtenti(const listaUtenti& l):lista(copia(l.lista)) {}

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

bool listaUtenti::togliUtente(std::string nome) {
  utente* p = utentePresente(nome);
  if(p) {
      lista.erase(std::find(lista.begin(),lista.end(),p));
      return true;
    }
  else
    return false;
}

utente* listaUtenti::utentePresente(std::string nome) const {
  std::list<utente*>::const_iterator it = lista.begin();
  for( ;it != lista.end(); ++it) {
      if((*it)->showUsername() == nome) return *it;
    }
  return 0;
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

bool listaUtenti::caricaListaUtenti() {
  QFile file("utenti.xml");
  if(!file.open(QFile::ReadOnly))
    return false;
  QXmlStreamReader reader(&file);
  if(reader.readNextStartElement())
    if(reader.name() == "listaUtenti")
      while(reader.readNextStartElement()) {
      this->caricaUtente(reader);
      reader.skipCurrentElement();
     }
     return true;
}

void listaUtenti::caricaUtente(QXmlStreamReader& reader) {
  std::string username;
  std::string password;

  if(reader.readNextStartElement())
    username = (reader.readElementText()).toStdString();

  if(reader.readNextStartElement())
    password = (reader.readElementText()).toStdString();

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

    lista.push_back(tmp);
  }
}

bool listaUtenti::scriviListaUtenti() const {
  QFile file("utenti.xml");
  if(!file.open(QFile::WriteOnly))
    return false;
  QXmlStreamWriter writer(&file);
  writer.setAutoFormatting(true);
  writer.writeStartDocument();
  writer.writeStartElement("listaUtenti");

  auto it = lista.begin();
  for(; it!=lista.end(); ++it ) {
    writer.writeStartElement("utente");
    (*it)->utente::writexml( writer);
    writer.writeEndElement();
  }
  writer.writeEndElement();

  return true;
}

//iteratori

listaUtenti::iterator::iterator(std::list<utente*>::iterator i):it(i) {}

bool listaUtenti::iterator::operator== ( const iterator& it2) const { return it == it2.it; }

bool listaUtenti::iterator::operator!= ( const iterator& it2 ) const { return it != it2.it; }

listaUtenti::iterator& listaUtenti::iterator::operator++ () { ++it; return *this; }

listaUtenti::iterator listaUtenti::iterator::operator ++(int) { iterator tmp = (it) ; it++; return tmp; }

utente* listaUtenti::iterator::operator* () const { return *it; }

listaUtenti::iterator& listaUtenti::iterator::operator= (const iterator& it2) { it = it2.it; return *this; }



listaUtenti::const_iterator::const_iterator(iterator i): it(i.it) {}

listaUtenti::const_iterator::const_iterator(std::list<utente*>::const_iterator i):it(i) {}

bool listaUtenti::const_iterator::operator== ( const const_iterator& it2) const { return it == it2.it; }

bool listaUtenti::const_iterator::operator!= (const const_iterator& it2) const { return it != it2.it; }

listaUtenti::const_iterator& listaUtenti::const_iterator::operator++ () { ++it; return *this; }

listaUtenti::const_iterator listaUtenti::const_iterator::operator ++(int) { const_iterator tmp = (it) ; it++; return tmp; }

listaUtenti::const_iterator& listaUtenti::const_iterator::operator= (const const_iterator& it2) { it = it2.it; return *this; }

const utente* listaUtenti::const_iterator::operator* () const { return *it; }

listaUtenti::iterator listaUtenti::begin()  { return lista.begin(); }
listaUtenti::iterator listaUtenti::end()  { return lista.end(); }

