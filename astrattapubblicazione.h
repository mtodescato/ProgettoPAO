#ifndef ASTRATTAPUBBLICAZIONE_H
#define ASTRATTAPUBBLICAZIONE_H

#include <string>
#include <iostream>
#include <QDate>
#include <QXmlStreamWriter>

class astrattaPubblicazione {
private:
  std::string titolo;
  std::string autore;
  std::string DOI;
  std::string materia;
  std::string descrizione;
  std::string linguaOriginale;
protected:
  static std::string readXmlString(QXmlStreamReader& );
  static int readXmlint(QXmlStreamReader& );
public:
  astrattaPubblicazione(const std::string&, const std::string&, const std::string& ="", const std::string& ="", const std::string& ="", const std::string& ="" );
  virtual ~astrattaPubblicazione() = default;
  virtual astrattaPubblicazione* clone() const =0;
  virtual QDate getDataPubblicazione() const =0;
  virtual std::string getCodiceRiferimento() const =0;
  virtual std::string getTipo() const =0;
  virtual void scriviPubblicazione(QXmlStreamWriter& ) const;
  virtual void printp(std::ostream&) const;
  std::string getTitolo() const;
  std::string getAutore() const;
  std::string getDOI() const;
  std::string getMateria() const;
  std::string getDescrizione() const;
  std::string getLinguaOriginale() const;
  bool setTitolo(std::string);
  bool setAutore(std::string);
  virtual bool setDOI(std::string);
  void setMateria(std::string);
  void setDescrizione(std::string);
  void setLinguaOriginale(std::string);
  bool operator== (const astrattaPubblicazione&) const;
  bool operator!= (const astrattaPubblicazione&) const;
  friend std::ostream& operator<< (std::ostream&, const astrattaPubblicazione&);
};


#endif // ASTRATTAPUBBLICAZIONE_H
