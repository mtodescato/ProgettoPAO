#include "login.h"


#include "login.h"


login::login (listaUtenti& lst ,utente** l,QDialog* parent): QDialog(parent),lista(lst), log(l){
  setWindowTitle("Login");
  QPushButton* log = new QPushButton(tr("login"),this);
  log->setMinimumSize(100,50);
  passwd.setEchoMode(QLineEdit::Password);
  QFormLayout* Layout = new QFormLayout(this);
  Layout->addRow(tr("username"),&userName);
  Layout->addRow(tr("password"),&passwd);
  Layout->addWidget(log);
  connect(log,SIGNAL(clicked()),this,SLOT(slotEffetuaLogin()));
  //connect(this,SIGNAL(signalSendLog(int)),this,SLOT(slotOpenTab(int)));
  setFixedSize(sizeHint());
  userName.setFocus();
}

void login::slotEffetuaLogin() {
  std::string nome = (userName.text().toStdString());
  std::string pswd = (passwd.text().toStdString());
  utente tmp(nome,pswd);
  *log = lista.utentePresente(tmp);
  if(*log) this->close();
  else
    error.critical(this,"errore","usename o password errati",QMessageBox::Ok);
}
