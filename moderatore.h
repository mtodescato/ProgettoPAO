#ifndef MODERATORE_H
#define MODERATORE_H

#include "utente.h"

class moderatore : public utente {
public:
  moderatore(std::string, std::string);
  bool isAdmin() const;
  bool canEdit() const;
  bool canView() const;
};

#endif // MODERATORE_H
