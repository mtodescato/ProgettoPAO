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
  virtual std::string getTipo() const;
  virtual void printp(std::ostream&) const;
  static libro* importFromXml(QXmlStreamReader& );
  virtual void scriviPubblicazione(QXmlStreamWriter& ) const;
};



#endif // LIBRO_H
