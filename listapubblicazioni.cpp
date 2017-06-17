#include "listapubblicazioni.h"

std::vector<astrattaPubblicazione*> listaPubblicazioni::copia(const std::vector<astrattaPubblicazione*>& lista) {
  std::vector<astrattaPubblicazione*> tmp;
  auto it = lista.begin();
  for(; it < lista.end(); ++it) {
      tmp.push_back((*it)->clone());
    }
  return tmp;
}

void listaPubblicazioni::distruggi(std::vector<astrattaPubblicazione*>& lista) {
  auto it = lista.begin();
  for(;it < lista.end();++it) {
      delete *it;
    }
  lista.clear();
}

listaPubblicazioni::~listaPubblicazioni() { distruggi(pubblicazioni); }

listaPubblicazioni& listaPubblicazioni::operator= (const listaPubblicazioni& l2) {
  if(this != &l2) {
      distruggi(pubblicazioni);
      pubblicazioni = copia(l2.pubblicazioni);
    }
  return *this;
}

listaPubblicazioni::listaPubblicazioni(const listaPubblicazioni& l):pubblicazioni(copia(l.pubblicazioni)) {}

bool listaPubblicazioni::aggiungiPubblicazione( astrattaPubblicazione& pubblicazione ) {
  astrattaPubblicazione* pub = pubblicazionePresente(pubblicazione);
    if(!pub) {
      pubblicazioni.push_back(&pubblicazione);
      return true;
      }
    else
      return false;

}

bool listaPubblicazioni::togliPubblicazione(const astrattaPubblicazione& pubblicazione) {
  astrattaPubblicazione* pub = pubblicazionePresente(pubblicazione);
  if(pub) {
      pubblicazioni.erase(std::find(pubblicazioni.begin(),pubblicazioni.end(),pub));
      return true;
    }
  else
    return false;
}

bool listaPubblicazioni::togliPubblicazione(const std::string& publ) {
  astrattaPubblicazione* pub = pubblicazionePresente(publ);
  if(pub) {
      pubblicazioni.erase(std::find(pubblicazioni.begin(),pubblicazioni.end(),pub));
      return true;
    }
  else
    return false;
}


astrattaPubblicazione* listaPubblicazioni::pubblicazionePresente(const astrattaPubblicazione& pubblicazione) const {
  std::vector<astrattaPubblicazione*>::const_iterator it = pubblicazioni.begin();
  for( ;it < pubblicazioni.end(); ++it) {
      if(**it == pubblicazione) return *it;
    }
  return 0;
}

astrattaPubblicazione* listaPubblicazioni::pubblicazionePresente(const std::string& pub) const {
  std::vector<astrattaPubblicazione*>::const_iterator it = pubblicazioni.begin();
  for( ;it < pubblicazioni.end(); ++it) {
      if((*it)->getCodiceRiferimento() == pub) return *it;
    }
  return 0;
}

std::ostream& operator<< (std::ostream& os, const listaPubblicazioni& l) {
  if(l.pubblicazioni.empty())
      os << "NESSUNA PUBBLICAZIONE PRESENTE"<< std::endl;
  else {
      os << "LISTA pubblicazioni:" << std::endl;
      for(auto it = l.pubblicazioni.begin(); it != l.pubblicazioni.end(); ++it) {
          os << **it << std::endl;
        }
    }
  return os;
}

bool listaPubblicazioni::caricaListaPubblicazioni() {
  QFile file("pubblicazioni.xml");
  if(!file.open(QFile::ReadOnly))
    return false;
  QXmlStreamReader reader(&file);

  if(reader.readNextStartElement()) {
    if(reader.name() == "listaPubblicazioni")
      while(reader.readNextStartElement()) {
      this->caricaPubblicazione(reader);
      reader.skipCurrentElement();
    }
   }
    return true;
}

void listaPubblicazioni::caricaPubblicazione(QXmlStreamReader& reader) {
  std::string tipo = ((reader.name()).toString()).toStdString();
  astrattaPubblicazione* tmp = fileFactory::buildFromXml(reader, tipo);
  if(tmp)
    pubblicazioni.push_back(tmp);
}

bool listaPubblicazioni::scriviListaPubblicazioni() const {
  QFile file("pubblicazioni.xml");
  if(!file.open(QFile::WriteOnly))
    return false;
  QXmlStreamWriter writer(&file);
  writer.setAutoFormatting(true);
  writer.writeStartDocument();
  writer.writeStartElement("listaPubblicazioni");

  auto it = pubblicazioni.begin();
  for(; it!=pubblicazioni.end(); ++it )
    (*it)->scriviPubblicazione(writer);
  writer.writeEndElement();

  return true;
}


//iteratori

listaPubblicazioni::iterator::iterator(std::vector<astrattaPubblicazione*>::iterator i):it(i) {}

bool listaPubblicazioni::iterator::operator== ( const iterator& it2) const { return it == it2.it; }

bool listaPubblicazioni::iterator::operator!= ( const iterator& it2 ) const { return it != it2.it; }

listaPubblicazioni::iterator& listaPubblicazioni::iterator::operator++ () { ++it; return *this; }

listaPubblicazioni::iterator listaPubblicazioni::iterator::operator ++(int) { iterator tmp = (it) ; it++; return tmp; }

astrattaPubblicazione* listaPubblicazioni::iterator::operator* () const { return *it; }

listaPubblicazioni::iterator& listaPubblicazioni::iterator::operator= (const iterator& it2) { it = it2.it; return *this; }



listaPubblicazioni::const_iterator::const_iterator(iterator i): it(i.it) {}

listaPubblicazioni::const_iterator::const_iterator(std::vector<astrattaPubblicazione*>::const_iterator i):it(i) {}

bool listaPubblicazioni::const_iterator::operator== ( const const_iterator& it2) const { return it == it2.it; }

bool listaPubblicazioni::const_iterator::operator!= (const const_iterator& it2) const { return it != it2.it; }

listaPubblicazioni::const_iterator& listaPubblicazioni::const_iterator::operator++ () { ++it; return *this; }

listaPubblicazioni::const_iterator listaPubblicazioni::const_iterator::operator ++(int) {
  const_iterator tmp = (it) ; it++; return tmp;
}

listaPubblicazioni::const_iterator& listaPubblicazioni::const_iterator::operator= (const const_iterator& it2) {
  it = it2.it;
  return *this;
}

const astrattaPubblicazione* listaPubblicazioni::const_iterator::operator* () const { return *it; }

listaPubblicazioni::iterator listaPubblicazioni::begin()  { return pubblicazioni.begin(); }

listaPubblicazioni::iterator listaPubblicazioni::end()  { return pubblicazioni.end(); }

void listaPubblicazioni::sortByTitolo() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getTitolo() < p2->getTitolo();});
}

void listaPubblicazioni::sortByAutore() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getAutore() < p2->getAutore();});
}

void listaPubblicazioni::sortByCodiceRiferimento() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getCodiceRiferimento() < p2->getCodiceRiferimento();});
}

void listaPubblicazioni::sortByAnnoDiPubblicazione() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getDataPubblicazione() > p2->getDataPubblicazione();});
}

void listaPubblicazioni::sortByreverseTitolo() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getTitolo() > p2->getTitolo();});
}

void listaPubblicazioni::sortByreverseAutore() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getAutore() > p2->getAutore();});
}

void listaPubblicazioni::sortByreverseCodiceRiferimento() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getCodiceRiferimento() > p2->getCodiceRiferimento();});
}

void listaPubblicazioni::sortByreverseAnnoDiPubblicazione() {
  std::sort(pubblicazioni.begin(),pubblicazioni.end(),[](const astrattaPubblicazione* p1,const astrattaPubblicazione* p2) {
      return p1->getDataPubblicazione() < p2->getDataPubblicazione();});
}

