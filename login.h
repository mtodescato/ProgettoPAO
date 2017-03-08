#ifndef LOGIN_H
#define LOGIN_H

#include <QPushButton>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include <string>
#include <QMessageBox>
#include "listautenti.h"


class login : public QDialog {
  Q_OBJECT
private:
  listaUtenti& lista;
  utente** log;
  QLineEdit userName;
  QLineEdit passwd;
  QMessageBox error;
public:
  login(listaUtenti& ,utente**, QDialog* =0);
public slots:
  void slotEffetuaLogin();
};


#endif // LOGIN_H
