#include "utentimaindialog.h"


utentiMainDialog::utentiMainDialog(listaUtenti& list, utente* usr, QDialog* parent):QDialog(parent),listaU(list),user(usr) {
  this->setWindowTitle("Gestione utenti");

  search = new QLineEdit(this);
  search->setMaximumWidth(600);
  QFormLayout* layoutSearch = new QFormLayout();
  layoutSearch->addRow(tr("Cerca: "),search);

  viewLista = new QListWidget(this);
  viewLista->resize(600,400);
  aggiungiButton = new QPushButton("Aggiungi",this);
  modificaButton = new QPushButton("Modifica",this);
  eliminaButton = new QPushButton("Elimina",this);
  QGridLayout* layout = new QGridLayout(this);
  layout->addLayout(layoutSearch,0,0);
  layout->addWidget(viewLista);
  QHBoxLayout* layoutEdit = new QHBoxLayout();
  layoutEdit->addWidget(aggiungiButton);
  layoutEdit->addWidget(modificaButton);
  layoutEdit->addWidget(eliminaButton);
  layout->addLayout(layoutEdit,2,0);
  loadLista();
  itemDeselected();
  connect(eliminaButton,SIGNAL(clicked(bool)),this,SLOT(rimuoviUtente()));
  connect(viewLista,SIGNAL(clicked(QModelIndex)),this,SLOT(itemSelected()));
  connect(viewLista,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(showUtente()));
  connect(modificaButton,SIGNAL(clicked(bool)),this,SLOT(modificaUtente()));
  connect(aggiungiButton,SIGNAL(clicked(bool)),this,SLOT(aggiungiUtente()));
  connect(search,SIGNAL(textEdited(QString)),this,SLOT(searchSlot(QString)));

}

void utentiMainDialog::loadLista() {
  listaUtenti::const_iterator it = listaU.begin();
  for(;it!=listaU.end();++it ) {
      viewLista->addItem(QString::fromStdString((*it)->showUsername()));
    }
}

void utentiMainDialog::rimuoviUtente() {
  QMessageBox delBox;
     delBox.setWindowTitle("Eliminazione");
     delBox.setText("Sei sicuro di voler eliminare l'utente selezionato?");
     delBox.setStandardButtons(QMessageBox::Yes);
     delBox.addButton(QMessageBox::No);
     delBox.setDefaultButton(QMessageBox::No);
  if(delBox.exec() == QMessageBox::Yes){
    QListWidgetItem* currentItem = viewLista->currentItem();
    int index = viewLista->row(currentItem);
    QString rif = (viewLista->item(index)->text());
    listaU.togliUtente(rif.toStdString());
    viewLista->takeItem(index);
    listaU.scriviListaUtenti();
    if(!viewLista->count())
      itemDeselected();
    }
}

void utentiMainDialog::itemSelected() {
  modificaButton->setEnabled(true);
  eliminaButton->setEnabled(true);
}

void utentiMainDialog::itemDeselected() {
  viewLista->clearSelection();
  viewLista->setCurrentRow(-1);
  modificaButton->setEnabled(false);
  eliminaButton->setEnabled(false);
}


void utentiMainDialog::showUtente() {
  QListWidgetItem* currentItem = viewLista->currentItem();
  int index = viewLista->row(currentItem);
  QString rif = (viewLista->item(index)->text());
  view = new viewUtenti(listaU,listaU.utentePresente(rif.toStdString()),false,this);
  connect(view,SIGNAL(listChanged(utente*)),this,SLOT(refreshListaOnEdit()));
  view->setModal(true);
  view->show();
}

void utentiMainDialog::modificaUtente() {
  QListWidgetItem* currentItem = viewLista->currentItem();
  int index = viewLista->row(currentItem);
  QString rif = (viewLista->item(index)->text());
  view = new viewUtenti(listaU,listaU.utentePresente(rif.toStdString()),true,this);
  connect(view,SIGNAL(listChanged(utente*)),this,SLOT(refreshListaOnEdit()));
  view->setModal(true);
  view->show();
}

void utentiMainDialog::aggiungiUtente() {
  QStringList listaTipoUtenti;
  QInputDialog* dialogInputType = new QInputDialog(this);
  listaTipoUtenti<<"Utente";
  listaTipoUtenti<<"Moderatore";
  listaTipoUtenti<<"Amministratore";
  bool accettato = false;
  QString tipo = dialogInputType->getItem(this,"Creazione utente","Selezionare il tipo di utente da creare:",listaTipoUtenti,0,false,&accettato);
  delete dialogInputType;
  if(accettato){
  utente* tmp = nullptr;
  if(tipo.toStdString() == "Utente")
    tmp = new utente("","");
  else if(tipo.toStdString() == "Moderatore")
    tmp = new moderatore("","");
  else if(tipo.toStdString() == "Amministratore")
    tmp = new admin("","");
  view = new viewUtenti(listaU,tmp,true,this);
  connect(view,SIGNAL(listChanged(utente*)),this,SLOT(refreshListaOnAdd(utente*)));
  view->setModal(true);
  view->exec();

  if(tmp && !(listaU.utentePresente(*tmp)))
    delete tmp;
  }
}

void utentiMainDialog::refreshListaOnAdd(utente* tmp) {
  if(!listaU.utentePresente(*tmp)) {
      if(tmp->showUsername()!="") {
        listaU.aggiungiUtente(*tmp);
        QMessageBox error;
        error.critical(this,"","inserimento avvenuto con successo",QMessageBox::Ok);
        view->close();
        refreshListaOnEdit();
        }
    }
  else {
      QMessageBox error;
      error.critical(this,"errore","Utente è già presente",QMessageBox::Ok);
      delete tmp;
    }
}

void utentiMainDialog::refreshListaOnEdit() {
  listaU.scriviListaUtenti();
  viewLista->clear();
  loadLista();
}

void utentiMainDialog::searchSlot(QString p) {
  for(int c = 0; c < viewLista->count();++c) {
          if(viewLista->item(c)->data((Qt::DisplayRole)).toString().indexOf(p,0,Qt::CaseSensitive)==-1)
            viewLista->setRowHidden(c,true);
          else
            viewLista->setRowHidden(c,false);
    }
}
