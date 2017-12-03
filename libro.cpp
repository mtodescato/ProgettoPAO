#include "libro.h"

libro::libro(unsigned int apb,const std::string& isbn, const std::string& c, const std::string& t, const std::string& a, const std::string& doi, const std::string& m, const std::string& d, const std::string& l )
       :astrattaPubblicazioneStampata(c,t,a,doi,m,d,l), annoDiPubblicazione(apb),ISBN(isbn) {}

libro* libro::clone() const { return new libro(*this); }

QDate libro::getDataPubblicazione() const { return QDate(annoDiPubblicazione,1,1); }

std::string libro::getCodiceRiferimento() const { return ISBN; }

std::string libro::getTipo() const { return "libro"; }

void libro::printp(std::ostream& os) const {
  astrattaPubblicazioneStampata::printp(os);
  os << "Anno di pubblicazione: " << annoDiPubblicazione << std::endl;
  os << "ISBN: " << ISBN << std::endl;
}

libro* libro::importFromXml(QXmlStreamReader& reader) {
  std::string titolo = readXmlString(reader);
  std::string autore = readXmlString(reader);
  std::string doi = readXmlString(reader);
  std::string materia = readXmlString(reader);
  std::string descrizione = readXmlString(reader);
  std::string lingua = readXmlString(reader);
  std::string casaEditrice = readXmlString(reader);
  int aa = readXmlint(reader);
  std::string isbn = readXmlString(reader);
  return new libro(aa,isbn,casaEditrice,titolo,autore,doi,materia,descrizione,lingua);
}

void libro::scriviPubblicazione(QXmlStreamWriter& writer) const  {
  this->astrattaPubblicazioneStampata::scriviPubblicazione(writer);
  writer.writeTextElement(QString::fromStdString("annoDiPubblicazione"),QString::number(annoDiPubblicazione));
  writer.writeTextElement(QString::fromStdString("isbn"),QString::fromStdString(ISBN));
  writer.writeEndElement();
}

bool libro::setISBN(std::string nISBN) {
   if(nISBN!="")
     ISBN=nISBN;
   return nISBN!="";
}

void libro::setAnnoDiPubblicazione(unsigned int nap) { annoDiPubblicazione = nap; }

