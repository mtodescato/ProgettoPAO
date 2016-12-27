#include "admin.h"

admin::admin(std::string name, std::string passWD): utente(name,passWD) {}

bool admin::isAdmin() const { return true; }

bool admin::canEdit() const { return true; }

bool admin::canView() const { return true; }
