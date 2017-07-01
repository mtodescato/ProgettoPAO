#include "viewutenti.h"

viewUtenti::viewUtenti(listaUtenti& lista,utente* usr,bool e,QDialog* parent):QDialog(parent),listaU(lista),user(usr),onEdit(e) {
  setWindowTitle("QtPubblications");
  QFormLayout* layout = new QFormLayout();
  username = new QLineEdit(QString::fromStdString(user->showUsername()),this);
  password = new QLineEdit(QString::fromStdString(user->showPassword()),this);
  QLabel* tipo = new QLabel(QString::fromStdString(user->tipoUtente()),this);
  layout->addRow("Nome utente*: ",username);
  layout->addRow("Password: ", password);
  layout->addRow("Tipo utente: ", tipo);
  modificaButton = new QPushButton("modifica",this);
  salvaButton = new QPushButton("salva",this);
  QHBoxLayout* buttonsL = new QHBoxLayout();
  buttonsL->addWidget(modificaButton);
  buttonsL->addWidget(salvaButton);
  salvaButton->setEnabled(false);
  modificaButton->setDisabled(onEdit);
  QGridLayout* mainLayout = new QGridLayout(this);
  mainLayout->addLayout(layout,0,0);
  mainLayout->addLayout(buttonsL,1,0);
  setEditability();

  connect(username,SIGNAL(textEdited(QString)),this,SLOT(attivaSalva()));
  connect(password,SIGNAL(textEdited(QString)),this,SLOT(attivaSalva()));
  connect(salvaButton,SIGNAL(clicked(bool)),this,SLOT(salvaModifica()));
  connect(modificaButton,SIGNAL(clicked(bool)),this,SLOT(attivaModifica()));
}

void viewUtenti::setEditability() {
  username->setReadOnly(!onEdit);
  password->setReadOnly(!onEdit);
}

void viewUtenti::attivaModifica() {
  onEdit=true;
  modificaButton->setEnabled(false);
  setEditability();
}

void viewUtenti::attivaSalva() {
  salvaButton->setEnabled(true);
}

void viewUtenti::disattivaSalva() {
  salvaButton->setEnabled(false);
}

void viewUtenti::salvaModifica() {
  QMessageBox error;
  if(user->showUsername()==username->text().toStdString() || !(listaU.utentePresente(username->text().toStdString())))
  {
  if(user->setUsername(username->text().toStdString())) {
    user->setPassword(password->text().toStdString());
    emit listChanged(user);
  }
  else
    error.critical(this,"errore","I campi contrassegnati con * non possono essere vuoti",QMessageBox::Ok);
  }
  else
    error.critical(this,"errore","Esiste già un Utente con lo stesso username",QMessageBox::Ok);
  salvaButton->setDisabled(true);


}
