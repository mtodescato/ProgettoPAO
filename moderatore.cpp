#include "moderatore.h"

moderatore::moderatore(std::string name, std::string passWD): utente(name,passWD) {}

bool moderatore::isAdmin() const { return false; }

bool moderatore::canEdit() const { return true; }

bool moderatore::canView() const { return true; }
