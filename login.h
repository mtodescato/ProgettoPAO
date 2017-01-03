#ifndef LOGIN_H
#define LOGIN_H

#include <QPushButton>
#include <QDialog>
#include <QFormLayout>
#include <QLineEdit>
#include <QHBoxLayout>
#include "listautenti.h"


class login : public QDialog {
private:
  listaUtenti lista;
public:
  login(QDialog* =0);
};

#endif // LOGIN_H
