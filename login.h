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
  listaUtenti lista;
  QLineEdit userName;
  QLineEdit passwd;
  QMessageBox error;
public:
  login(const listaUtenti& ,QDialog* =0);
  ~login();
public slots:
  void slotEffetuaLogin();
  void slotOpenTab(int);
signals:
  void signalSendLog(int);

};



#endif // LOGIN_H
