#include "admin.h"

admin::admin(const std::string &name, const std::string &passWD): utente(name,passWD) {}

bool admin::isAdmin() const { return true; }

bool admin::canEdit() const { return true; }

bool admin::canView() const { return true; }

std::string admin::tipoUtente() const { return "admin"; }
