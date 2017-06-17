#include "articolorivista.h"

articoloRivista::articoloRivista(const std::string& nr,const std::string& issn, const std::string& c, const std::string& t, const std::string& a,unsigned int num, int aa ,int mm , int gg, const std::string& doi, const std::string& m, const std::string& d, const std::string& l )
                :astrattaPubblicazioneStampata(c,t,a,doi,m,d,l), nomeRivivsta(nr), ISSN(issn), numeroUscita(num), dataPubblicazione(aa,mm,gg) {}

articoloRivista* articoloRivista::clone() const { return new articoloRivista(*this); }

QDate articoloRivista::getDataPubblicazione() const { return dataPubblicazione; }

std::string articoloRivista::getCodiceRiferimento() const { return getDOI(); }

std::string articoloRivista::getNomeRivista() const { return nomeRivivsta; }

unsigned int articoloRivista::getNumeroUscita() const { return numeroUscita; }

std::string articoloRivista::getTipo() const { return "articoloRivista"; }

void articoloRivista::printp (std::ostream& os) const {
  this->astrattaPubblicazioneStampata::printp(os);
  os << "Nome rivista: " << nomeRivivsta << std::endl;
  os << "ISSN: " << ISSN << std::endl;
  os << "Numero uscita: " << numeroUscita << std::endl;
  os << "Data pubblicazione: " << ((dataPubblicazione).toString( "d.M.yyyy" )).toStdString() << std::endl;
}

articoloRivista* articoloRivista::importFromXml(QXmlStreamReader& reader) {
  std::string titolo = readXmlString(reader);
  std::string autore = readXmlString(reader);
  std::string doi = readXmlString(reader);
  std::string materia = readXmlString(reader);
  std::string descrizione = readXmlString(reader);
  std::string lingua = readXmlString(reader);
  std::string casaEditrice = readXmlString(reader);
  std::string nomeRivivsta = readXmlString(reader);
  std::string issn = readXmlString(reader);
  int numeroUscita = readXmlint(reader);
  int aa = readXmlint(reader);
  int mm = readXmlint(reader);
  int gg = readXmlint(reader);
  return new articoloRivista(nomeRivivsta,issn,casaEditrice,titolo,autore,numeroUscita,aa,mm,gg,doi,materia,descrizione,lingua);
}

void articoloRivista::scriviPubblicazione(QXmlStreamWriter& writer) const {
  this->astrattaPubblicazioneStampata::scriviPubblicazione(writer);
  writer.writeTextElement(QString::fromStdString("nomeRivivsta"),QString::fromStdString(nomeRivivsta));
  writer.writeTextElement(QString::fromStdString("issn"),QString::fromStdString(ISSN));
  writer.writeTextElement(QString::fromStdString("numeroUscita"),QString::number(numeroUscita));
  writer.writeTextElement(QString::fromStdString("anno"),QString::number(dataPubblicazione.year()));
  writer.writeTextElement(QString::fromStdString("mese"),QString::number(dataPubblicazione.month()));
  writer.writeTextElement(QString::fromStdString("giorno"),QString::number(dataPubblicazione.day()));
  writer.writeEndElement();
}

void articoloRivista::setNomeRivista(std::string nRivista) { nomeRivivsta = nRivista; }

bool articoloRivista::setISSN(std::string nISSN) {
  if(nISSN != "")
    ISSN = nISSN;
  return nISSN != "";
}

bool articoloRivista::setNumeroUscita(unsigned int nu) {
  if(nu!=0)
    numeroUscita = nu;
  return nu!=0;
}

bool articoloRivista::setDataPubblicazione(QString data) {
  if(data != "")
    dataPubblicazione = QDate(QDate::fromString(data,"d/M/yyyy"));
  return data != "";
}

std::string articoloRivista::getISSN() const {
  return ISSN;
}


