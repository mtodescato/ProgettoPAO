#include "astrattapubblicazione.h"

astrattaPubblicazione::astrattaPubblicazione(const std::string& t, const std::string& a, const std::string& doi, const std::string& m, const std::string& d, const std::string& l)
                                              :titolo(t),autore(a),DOI(doi),materia(m),descrizione(d),linguaOriginale(l) {}

std::string astrattaPubblicazione::getTitolo() const { return titolo; }

std::string astrattaPubblicazione::getAutore() const { return autore; }

std::string astrattaPubblicazione::getDOI() const { return DOI; }

std::string astrattaPubblicazione::getMateria() const { return materia; }

std::string astrattaPubblicazione::getDescrizione() const { return descrizione; }

std::string astrattaPubblicazione::getLinguaOriginale() const { return linguaOriginale; }

void astrattaPubblicazione::printp(std::ostream& os) const {
  os << "Titolo: " << titolo << std::endl;
  os << "Autore: " << autore << std::endl;
  os << "DOI: " << DOI << std::endl;
  os << "Materia: " << materia << std::endl;
  os << "Descrizione: " << descrizione << std::endl;
  os << "Lingua originale: " << linguaOriginale << std::endl;
}

std::ostream& operator<< (std::ostream& os, const astrattaPubblicazione& p) {
  p.printp(os);
  return os;
}

bool astrattaPubblicazione::operator== (const astrattaPubblicazione& p2) const { return getCodiceRiferimento() == p2.getCodiceRiferimento(); }

bool astrattaPubblicazione::operator!= (const astrattaPubblicazione& p2) const { return getCodiceRiferimento() != p2.getCodiceRiferimento(); }

 void astrattaPubblicazione::scriviPubblicazione(QXmlStreamWriter& writer) const {
   writer.writeStartElement(QString::fromStdString(getTipo()));
   writer.writeTextElement(QString::fromStdString("titolo"),QString::fromStdString(titolo));
   writer.writeTextElement(QString::fromStdString("autore"),QString::fromStdString(autore));
   writer.writeTextElement(QString::fromStdString("doi"),QString::fromStdString(DOI));
   writer.writeTextElement(QString::fromStdString("materia"),QString::fromStdString(materia));
   writer.writeTextElement(QString::fromStdString("descrizione"),QString::fromStdString(descrizione));
   writer.writeTextElement(QString::fromStdString("lingua"),QString::fromStdString(linguaOriginale));
 }



 bool astrattaPubblicazione::setTitolo(std::string nTitolo) {
   if(nTitolo!="")
     titolo = nTitolo;
   return nTitolo != "";

 }

 bool astrattaPubblicazione::setAutore(std::string nAutore) {
   if(nAutore!="")
     autore = nAutore;
   return nAutore!="";
 }

 bool astrattaPubblicazione::setDOI(std::string nDOI) {
   DOI = nDOI;
   return true;
 }

 void astrattaPubblicazione::setMateria(std::string nMateria) { materia=nMateria; }

 void astrattaPubblicazione::setDescrizione(std::string nDescrizione) { descrizione = nDescrizione; }

 void astrattaPubblicazione::setLinguaOriginale(std::string nLingua) { linguaOriginale = nLingua; }







