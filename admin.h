#ifndef ADMIN_H
#define ADMIN_H

#include "utente.h"

class admin : public utente {
public:
  admin(const std::string&,const std::string&);
  bool isAdmin() const;
  bool canEdit() const;
  bool canView() const;
  std::string tipoUtente() const;
  virtual admin* clone() const;
};

#endif // ADMIN_H
