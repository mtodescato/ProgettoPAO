#ifndef ARTICOLORIVISTA_H
#define ARTICOLORIVISTA_H

#include "astrattapubblicazionestampata.h"

class articoloRivista : public astrattaPubblicazioneStampata {
private:
  std::string nomeRivivsta;
  std::string ISSN;
  unsigned int numeroUscita;
  QDate dataPubblicazione;
public:
  articoloRivista(const std::string&,const std::string&, const std::string&, const std::string&, const std::string& ,unsigned int , int ,int , int=1, const std::string& ="" , const std::string& ="", const std::string& ="", const std::string& ="" );
  virtual articoloRivista* clone() const;
  virtual QDate getDataPubblicazione() const;
  virtual std::string getCodiceRiferimento() const;
  virtual void printp (std::ostream&) const;
  std::string getNomeRivista() const;
  static articoloRivista* importFromXml(QXmlStreamReader& );
};

#endif // ARTICOLORIVISTA_H
