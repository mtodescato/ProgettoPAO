#ifndef LOGIN_H
#define LOGIN_H

#include <QPushButton>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <string>
#include "listautenti.h"


class login : public QDialog {
  Q_OBJECT
private:
  listaUtenti lista;
public:
  login(const listaUtenti& ,QDialog* =0);
public slot:
  void eseguiLogin(const std::string&, const std::string&) const;

};

#endif // LOGIN_H
