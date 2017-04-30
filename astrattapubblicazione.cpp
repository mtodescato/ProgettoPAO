#include "astrattapubblicazione.h"

astrattaPubblicazione::astrattaPubblicazione(const std::string& t, const std::string& a, const std::string& doi, const std::string& m, const std::string& d, const std::string& l)
                                              :titolo(t),autore(a),DOI(doi),materia(m),descrizione(d),linguaOriginale(l) {}

std::string astrattaPubblicazione::getDOI() const { return DOI; }

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
