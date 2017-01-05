#include "login.h"


login::login (const listaUtenti& lst ,QDialog* parent): QDialog(parent),lista(lst) {
  setWindowTitle("Login");
  resize(600,300);
  QPushButton* log = new QPushButton(tr("login"),this);
  log->setMinimumSize(200,50);
  QLineEdit* userName = new QLineEdit(this);
  QLineEdit* passwd = new QLineEdit(this);
  passwd->setEchoMode(QLineEdit::Password);
  QFormLayout* Layout = new QFormLayout(this);
  QHBoxLayout* button = new QHBoxLayout(this);
  Layout->addRow(tr("username"),userName);
  Layout->addRow(tr("password"),passwd);
  button->addWidget(log);
  Layout->addItem(button);
  this->setLayout(Layout);

}