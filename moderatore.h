#ifndef MODERATORE_H
#define MODERATORE_H

#include "utente.h"

class moderatore : public utente {
public:
  moderatore(const std::string&,const std::string&);
  bool isAdmin() const;
  bool canEdit() const;
  bool canView() const;
  std::string tipoUtente() const;
};

#endif // MODERATORE_H
