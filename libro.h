#ifndef LIBRO_H
#define LIBRO_H

#include "astrattapubblicazionestampata.h"

class libro : public astrattaPubblicazioneStampata {
private:
  unsigned int annoDiPubblicazione;
  std::string ISBN;
public:
  libro(unsigned int,const std::string&, const std::string&, const std::string&, const std::string&, const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="" );
  virtual libro* clone() const;
  virtual QDate getDataPubblicazione() const;
  virtual std::string getCodiceRiferimento() const;
  virtual void printp(std::ostream&) const;
  static libro* importFromXml(QXmlStreamReader& );
};


#endif // LIBRO_H
