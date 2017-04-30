#ifndef ASTRATTAPUBBLICAZIONESTAMPATA_H
#define ASTRATTAPUBBLICAZIONESTAMPATA_H

#include "astrattapubblicazione.h"

class astrattaPubblicazioneStampata : public astrattaPubblicazione {
private:
  std::string casaEditrice;
public:
  astrattaPubblicazioneStampata(const std::string&, const std::string&, const std::string&, const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="" );
  virtual void printp(std::ostream&) const;
};

#endif // ASTRATTAPUBBLICAZIONESTAMPATA_H
