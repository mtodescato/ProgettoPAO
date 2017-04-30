#ifndef ASTRATTAPUBBLICAZIONE_H
#define ASTRATTAPUBBLICAZIONE_H

#include <string>
#include <iostream>
#include <QDate>
#include "funzioniutili.h"

class astrattaPubblicazione {
private:
  std::string titolo;
  std::string autore;
  std::string DOI;
  std::string materia;
  std::string descrizione;
  std::string linguaOriginale;
public:
  astrattaPubblicazione(const std::string&, const std::string&, const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="" );
  virtual ~astrattaPubblicazione() = default;
  virtual astrattaPubblicazione* clone() const =0;
  virtual QDate getDataPubblicazione() const =0;
  virtual std::string getCodiceRiferimento() const =0;
  virtual void printp(std::ostream&) const;
  std::string getDOI() const;
  bool operator== (const astrattaPubblicazione&) const;
  bool operator!= (const astrattaPubblicazione&) const;
  friend std::ostream& operator<< (std::ostream&, const astrattaPubblicazione&);
};


#endif // ASTRATTAPUBBLICAZIONE_H
