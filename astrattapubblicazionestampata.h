#ifndef ASTRATTAPUBBLICAZIONESTAMPATA_H
#define ASTRATTAPUBBLICAZIONESTAMPATA_H

#include "astrattapubblicazione.h"


class astrattaPubblicazioneStampata : public astrattaPubblicazione {
private:
  std::string casaEditrice;
public:
  astrattaPubblicazioneStampata(const std::string&, const std::string&, const std::string&, const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="" );
  virtual void printp(std::ostream&) const;
  virtual void scriviPubblicazione(QXmlStreamWriter& ) const;
  std::string getCasaEditrice() const;
};

#endif // ASTRATTAPUBBLICAZIONESTAMPATA_H
