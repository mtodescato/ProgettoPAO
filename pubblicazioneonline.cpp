#include "pubblicazioneonline.h"

pubblicazioneOnline::pubblicazioneOnline(const std::string& sp, const std::string& lp, const std::string& t, const std::string& au, const std::string& doi, int a, int m, int g, const std::string& ma, const std::string& d, const std::string& l )
                                          :astrattaPubblicazione( t, au, doi, ma, d, l), sitoPubblicazione(sp), linkPubblicazione(lp), dataPubblicazione(a,m,g) {}

pubblicazioneOnline* pubblicazioneOnline::clone() const { return new pubblicazioneOnline(*this); }

std::string pubblicazioneOnline::getCodiceRiferimento() const { return getDOI(); }

QDate pubblicazioneOnline::getDataPubblicazione() const { return dataPubblicazione; }

std::string pubblicazioneOnline::getSitoPubblicazione() const {return sitoPubblicazione; }

std::string pubblicazioneOnline::getLinkPubbliczione() const { return linkPubblicazione; }

std::string pubblicazioneOnline::getTipo() const { return "pubblicazioneOnline"; }

void pubblicazioneOnline::printp(std::ostream& os) const {
  this->astrattaPubblicazione::printp(os);
  os << "Sito pubblicazione: " << sitoPubblicazione << std::endl;
  os << "Link pubbliczione: " << linkPubblicazione << std::endl;
  os << "Data pubblicazione: " << ((dataPubblicazione).toString( "d.M.yyyy" )).toStdString() << std::endl;
}

pubblicazioneOnline* pubblicazioneOnline::importFromXml(QXmlStreamReader& reader) {
  std::string titolo = readXmlString(reader);
  std::string autore = readXmlString(reader);
  std::string doi = readXmlString(reader);
  std::string materia = readXmlString(reader);
  std::string descrizione = readXmlString(reader);
  std::string lingua = readXmlString(reader);
  std::string sito = readXmlString(reader);
  std::string link = readXmlString(reader);
  int aa = readXmlint(reader);
  int mm = readXmlint(reader);
  int gg = readXmlint(reader);
  return new pubblicazioneOnline(sito,link,titolo,autore,doi,aa,mm,gg,materia,descrizione,lingua);
}

void pubblicazioneOnline::scriviPubblicazione(QXmlStreamWriter& writer) const { //da completare
  this->astrattaPubblicazione::scriviPubblicazione(writer);
  writer.writeTextElement(QString::fromStdString("sitoPubblicazione"),QString::fromStdString(sitoPubblicazione));
  writer.writeTextElement(QString::fromStdString("linkPubblicazione"),QString::fromStdString(linkPubblicazione));
  writer.writeTextElement(QString::fromStdString("anno"),QString::number(dataPubblicazione.year()));
  writer.writeTextElement(QString::fromStdString("mese"),QString::number(dataPubblicazione.month()));
  writer.writeTextElement(QString::fromStdString("giorno"),QString::number(dataPubblicazione.day()));
  writer.writeEndElement();

}
