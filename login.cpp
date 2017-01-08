#include "login.h"


login::login (const listaUtenti& lst ,QDialog* parent): QDialog(parent),lista(lst) {
  setWindowTitle("Login");
  resize(600,300);
  QPushButton* log = new QPushButton(tr("login"),this);
  log->setMinimumSize(200,50);
  passwd.setEchoMode(QLineEdit::Password);
  QFormLayout* Layout = new QFormLayout(this);
  Layout->addRow(tr("username"),&userName);
  Layout->addRow(tr("password"),&passwd);
  Layout->addWidget(log);
  connect(log,SIGNAL(clicked()),this,SLOT(slotEffetuaLogin()));
  connect(this,SIGNAL(signalSendLog(int)),this,SLOT(slotOpenTab(int)));
}

login::~login() {}


void login::slotEffetuaLogin() {
  std::string nome = (userName.text().toStdString());
  std::string pswd = (passwd.text().toStdString());
  utente tmp(nome,pswd);
  utente* p = lista.utentePresente(tmp);
  int sign = 0;
  if(p) {
      sign += p->canView();
      sign += p->canEdit();
      sign += p->isAdmin();
    }
   emit signalSendLog(sign);
}

void login::slotOpenTab(int n) {
  switch (n) {
    case 1:
      error.critical(this,"errore","1",QMessageBox::Ok);
      break;
    case 2:
      error.critical(this,"errore","2",QMessageBox::Ok);
      break;
    case 3:
      error.critical(this,"errore","3",QMessageBox::Ok);
      break;
    default:
      error.critical(this,"errore","Username o password errati",QMessageBox::Ok);
      break;
    }


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
