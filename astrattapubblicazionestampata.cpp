#include "astrattapubblicazionestampata.h"

astrattaPubblicazioneStampata::astrattaPubblicazioneStampata(const std::string& c, const std::string& t, const std::string& a, const std::string& doi, const std::string& m, const std::string& d , const std::string& l )
                               :astrattaPubblicazione(t,a,doi,m,d,l),casaEditrice(c) {}

void astrattaPubblicazioneStampata::printp(std::ostream& os) const {
  this->astrattaPubblicazione::printp(os);
  os << "Casa editrice: " << this->casaEditrice << std::endl;
}

void astrattaPubblicazioneStampata::scriviPubblicazione(QXmlStreamWriter& writer) const {
  this->astrattaPubblicazione::scriviPubblicazione(writer);
  writer.writeTextElement(QString::fromStdString("casaEditrice"),QString::fromStdString(casaEditrice));
}

std::string astrattaPubblicazioneStampata::getCasaEditrice() const { return casaEditrice; }

void astrattaPubblicazioneStampata::setCasaEditrice(std::string nCasaEditrice) { casaEditrice = nCasaEditrice; }
