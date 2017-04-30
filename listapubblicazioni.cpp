#include "listapubblicazioni.h"

listaPubblicazioni::~listaPubblicazioni() {
  std::vector<astrattaPubblicazione*>::iterator it = pubblicazioni.begin();
  for(; it < pubblicazioni.end();++it) {
      delete *it;
    }
  pubblicazioni.clear();
}

bool listaPubblicazioni::aggiungiPubblicazione( astrattaPubblicazione& pubblicazione ) {
  astrattaPubblicazione* pub = pubblicazionePresente(pubblicazione);
  std::cout<<pub;
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

astrattaPubblicazione* listaPubblicazioni::pubblicazionePresente(const astrattaPubblicazione& pubblicazione) const {
  std::vector<astrattaPubblicazione*>::const_iterator it = pubblicazioni.begin();
  for( ;it < pubblicazioni.end(); ++it) {
      if(**it == pubblicazione) return *it;
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

void listaPubblicazioni::caricaListaPubblicazioni() {
  QFile file(":/risorse/pubblicazioni.xml");
  if(!file.open(QFile::ReadOnly))
    return;
  QXmlStreamReader reader(&file);

  if(reader.readNextStartElement())
    if(reader.name() == "listaPubblicazioni")
      while(reader.readNextStartElement()) {
      this->caricaPubblicazione(reader);
      reader.skipCurrentElement();
    }
}

void listaPubblicazioni::caricaPubblicazione(QXmlStreamReader& reader) {
  std::string tipo = ((reader.name()).toString()).toStdString();
  astrattaPubblicazione* tmp = fileFactory::buildFromXml(reader, tipo);
  if(tmp)
    pubblicazioni.push_back(tmp);
}
