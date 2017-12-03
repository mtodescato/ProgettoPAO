#ifndef PUBBLICAZIONEONLINE_H
#define PUBBLICAZIONEONLINE_H

#include "astrattapubblicazione.h"
#include <QString>


class pubblicazioneOnline : public astrattaPubblicazione {
private:
  std::string sitoPubblicazione;
  std::string linkPubblicazione;
  QDate dataPubblicazione;
public:
  pubblicazioneOnline(const std::string&, const std::string&, const std::string&, const std::string&, const std::string&, int, int =1, int =1, const std::string& ="", const std::string& ="", const std::string& ="" );
  virtual pubblicazioneOnline* clone() const;
  virtual std::string getCodiceRiferimento() const;
  virtual QDate getDataPubblicazione() const;
  virtual void printp(std::ostream&) const;
  std::string getSitoPubblicazione() const;
  std::string getLinkPubbliczione() const;
  virtual bool setDOI(std::string);
  bool setsitoPubblicazione(std::string);
  bool setlinkPubblicazione(std::string);
  bool setdataPubblicazione(QString);
  virtual std::string getTipo() const;
  static pubblicazioneOnline* importFromXml(QXmlStreamReader& );
  virtual void scriviPubblicazione(QXmlStreamWriter& ) const;
};


#endif // PUBBLICAZIONEONLINE_H
