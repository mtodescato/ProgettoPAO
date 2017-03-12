#include "moderatore.h"

moderatore::moderatore(const std::string &name, const std::string &passWD): utente(name,passWD) {}

bool moderatore::isAdmin() const { return false; }

bool moderatore::canEdit() const { return true; }

bool moderatore::canView() const { return true; }
