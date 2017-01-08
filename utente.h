#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <iostream>

class utente {
private:
  std::string username;
  std::string password;
public:
  utente(std::string, std::string);
  virtual ~utente();
  virtual bool isAdmin() const;
  virtual bool canEdit() const;
  virtual bool canView() const;
  std::string showUsername() const;
  bool operator== (const utente&) const;
  bool operator!= (const utente&) const;
  friend std::ostream& operator<< (std::ostream&, const utente&);
};

#endif // UTENTE_H
