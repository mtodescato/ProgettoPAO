#ifndef UTENTE_H
#define UTENTE_H

#include <string>
#include <iostream>
#include <QXmlStreamWriter>

class utente {
private:
  std::string username;
  std::string password;
public:
  utente(const std::string&,const std::string&);
  virtual ~utente();
  virtual bool isAdmin() const;
  virtual bool canEdit() const;
  virtual bool canView() const;
  virtual std::string tipoUtente() const;
  std::string showUsername() const;
  bool operator== (const utente&) const;
  bool operator!= (const utente&) const;
  friend std::ostream& operator<< (std::ostream&, const utente&);
  void writexml(QXmlStreamWriter& ) const;
};

#endif // UTENTE_H
