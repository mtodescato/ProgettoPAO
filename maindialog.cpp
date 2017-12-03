#include "maindialog.h"
#include <QMessageBox>

mainDialog::mainDialog(astrattaPubblicazione* p, utente* usr, bool f, listaPubblicazioni& list, QDialog* parent):QDialog(parent),pub(p),loggedUser(usr),listaP(list),forEdit(f)
{
    setWindowTitle("QtPubblications");
    guiPub =  viewFactory::buildView(pub,0);
    guiPub->caricaCampiDati();
    guiPub->setEditablility(forEdit);
    QGridLayout* grid = new QGridLayout(this);
    grid->addWidget(guiPub);
    modificaButton = new QPushButton("Modifica",this);
    salvaButton = new QPushButton("salva",this);
    modificaButton->setDisabled(forEdit);
    salvaButton->setDisabled(true);
    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(modificaButton);
    buttonsLayout->addWidget(salvaButton);

    grid->addLayout(buttonsLayout,1,0);
    connect(salvaButton,SIGNAL(clicked()),this,SLOT(salvaModifica()));
    connect(modificaButton,SIGNAL(clicked()),this,SLOT(attivaModifica()));
    connect(guiPub,SIGNAL(fieldEdited(bool)),salvaButton,SLOT(setEnabled(bool)));

    if(!loggedUser->canEdit()) {
        modificaButton->setHidden(true);
        salvaButton->setHidden(true);
      }

}


void mainDialog::attivaModifica() {
  forEdit=true;
  modificaButton->setEnabled(false);
  guiPub->setEditablility(forEdit);

}

void mainDialog::salvaModifica() {
  QMessageBox error;
  QString ref = guiPub->controlReferenceCode();
  if( (pub->getCodiceRiferimento() == ref.toStdString()) || !(listaP.pubblicazionePresente(ref.toStdString()))) {
  if(guiPub->checkAndSet())
    emit listChanged(pub);
  else
    error.critical(this,"errore","I campi contrassegnati con * non possono essere vuoti",QMessageBox::Ok);
  }
  else
    error.critical(this,"errore","Esiste già una pubblicazione con lo stesso codice di riferimento",QMessageBox::Ok);
  salvaButton->setDisabled(true);

}


