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
  virtual std::string getTipo() const;
  std::string getISSN() const;
  std::string getNomeRivista() const;
  unsigned int getNumeroUscita() const;
  static articoloRivista* importFromXml(QXmlStreamReader& );
  virtual void scriviPubblicazione(QXmlStreamWriter& ) const;
  void setNomeRivista(std::string);
  virtual bool setDOI(std::string);
  bool setISSN(std::string);
  bool setNumeroUscita(unsigned int);
  bool setDataPubblicazione(QString);
};

#endif // ARTICOLORIVISTA_H
