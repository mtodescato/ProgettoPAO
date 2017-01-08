#include "utente.h"

utente::utente(std::string name, std::string passWD): username(name), password(passWD) {}

utente::~utente() {}

bool utente::isAdmin() const { return false; }

bool utente::canEdit() const { return false; }

bool utente::canView() const { return true; }

std::string utente::showUsername() const { return username; }

bool utente::operator== (const utente& b) const { return username==b.username && password==b.password; }

bool utente::operator!= (const utente& b) const { return username!=b.username || password!=b.password; }

std::ostream& operator<< (std::ostream& os, const utente& u) {
  os <<"username: "<< u.username << " password: "<<u.password;
  return os;
}
