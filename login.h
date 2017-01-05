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
  QLineEdit userName;
  QLineEdit passwd;
public:
  login(const listaUtenti& ,QDialog* =0);
  ~login();
public slots:
  void effetuaLogin();

};

#endif // LOGIN_H
