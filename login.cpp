#include "login.h"


login::login (const listaUtenti& lst ,QDialog* parent): QDialog(parent),lista(lst) {
  setWindowTitle("Login");
  resize(600,300);
  QPushButton* log = new QPushButton(tr("login"),this);
  log->setMinimumSize(200,50);
  passwd.setEchoMode(QLineEdit::Password);
  QFormLayout* Layout = new QFormLayout(this);
  QHBoxLayout* button = new QHBoxLayout(this);
  Layout->addRow(tr("username"),&userName);
  Layout->addRow(tr("password"),&passwd);
  button->addWidget(log);
  Layout->addItem(button);
  this->setLayout(Layout);
  connect(log,SIGNAL(clicked()),this,SLOT(effetuaLogin()));
}

login::~login() {}


void login::effetuaLogin() {
  std::string nome = (userName.text().toStdString());
  std::string pswd = (passwd.text().toStdString());
}


/*
void login::eseguiLogin(const std::string& usrn, const std::string& passwd) const {
    utente log(usrn,passwd);
    utente* p = lista.utentePresente(log);
    if(!p) { signal che fa comparire una qdialog con scritto "username o password errati}
    else
      {signal che fa aprire il programma con l'interfaccia adatta all'utente }
}
*/
