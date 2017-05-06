#include "utente.h"

utente::utente(const std::string& name,const std::string& passWD): username(name), password(passWD) {}

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

std::string utente::tipoUtente() const { return "utente"; }

void utente::writexml(QXmlStreamWriter& writer) const {
  writer.writeTextElement(QString::fromStdString("username"),QString::fromStdString(username));
  writer.writeTextElement(QString::fromStdString("password"),QString::fromStdString(password));
  writer.writeTextElement(QString::fromStdString("tipoUtente"),QString::fromStdString(this->tipoUtente()));
}
