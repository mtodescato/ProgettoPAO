#include "mainwidget.h"

 mainWidget::mainWidget(utente* usr, listaUtenti& ulist, listaPubblicazioni& plist , bool* rl, QMainWindow* parent)
   :QWidget(parent),user(usr),listaU(ulist),listaP(plist),relog(rl) {
   gLayout = new QGridLayout(this);

   search = new QLineEdit(this);
   search->setMaximumWidth(600);
   QFormLayout* layoutSearch = new QFormLayout();
   layoutSearch->addRow(tr("Cerca: "),search);

   titoloRadio = new QRadioButton("Titolo",this);
   autoreRadio = new QRadioButton("Autore",this);
   codiceRiferimentoRadio = new QRadioButton("Codice Riferimento",this);
   genericaRadio = new QRadioButton("Generica",this);
   genericaRadio->setChecked(true);
   QHBoxLayout* layoutSearch2 = new QHBoxLayout();
   QLabel* opzioniRicercaLabel = new QLabel("opzioni: ",this);
   layoutSearch2->addWidget(opzioniRicercaLabel);
   layoutSearch2->addWidget(titoloRadio);
   layoutSearch2->addWidget(autoreRadio);
   layoutSearch2->addWidget(codiceRiferimentoRadio);
   layoutSearch2->addWidget(genericaRadio);

   tableP = new QTableWidget(this);
   tableP->setColumnCount(4);
   tableP->setRowCount(0);
   tableP->setEditTriggers(QAbstractItemView::NoEditTriggers);
   tableP->resize(1200,700);
   (tableP->horizontalHeader())->setSectionResizeMode(QHeaderView::Stretch);
   tableP->setHorizontalHeaderItem(0,new QTableWidgetItem("Titolo"));
   tableP->setHorizontalHeaderItem(1,new QTableWidgetItem("Autore"));
   tableP->setHorizontalHeaderItem(2,new QTableWidgetItem("Codice Riferimento"));
   tableP->setHorizontalHeaderItem(3,new QTableWidgetItem("Anno Pubblicazione"));
   tableP->setSelectionBehavior(QAbstractItemView::SelectRows);

   QHBoxLayout* layoutEdit = new QHBoxLayout();

   aggiungiButton = new QPushButton("Aggiungi",this);
   aggiungiButton->setMaximumSize(300,80);
   modificaButton = new QPushButton("Modifica",this);
   modificaButton->setMaximumSize(300,80);
   modificaButton->setEnabled(false);
   eliminaButton = new QPushButton("Elimina",this);
   eliminaButton->setMaximumSize(300,80);
   eliminaButton->setEnabled(false);
   layoutEdit->addWidget(aggiungiButton);
   layoutEdit->addWidget(modificaButton);
   layoutEdit->addWidget(eliminaButton);

   QScrollArea* scrTable = new QScrollArea(this);
   scrTable->resize(1200,700);
   gLayout->addLayout(layoutSearch,1,0);
   gLayout->addLayout(layoutSearch2,2,0);
   gLayout->addWidget(scrTable);
   gLayout->addLayout(layoutEdit,4,0);
   scrTable->setWidget(tableP);
   loadLista();
   sort(0);
   creaMenuTendina();

   connect(tableP->horizontalHeader(),SIGNAL(sectionClicked(int)),this,SLOT(sort(int)));
   connect(tableP,SIGNAL(clicked(QModelIndex)),this,SLOT(itemSelected()));
   connect(tableP,SIGNAL(itemSelectionChanged()),this,SLOT(reHighlight()));
   connect(tableP,SIGNAL(cellDoubleClicked(int,int)),this,SLOT(showPubblicazzine()));
   connect(search,SIGNAL(textEdited(QString)),this,SLOT(searchSlot(QString)));
   connect(eliminaButton,SIGNAL(clicked(bool)),this,SLOT(deleteP()));
   connect(aggiungiButton,SIGNAL(clicked(bool)),this,SLOT(addPubblicazione()));
   connect(modificaButton,SIGNAL(clicked(bool)),this,SLOT(EditPubblicazione()));

   if(!user->canEdit()) {
       aggiungiButton->setHidden(true);
       modificaButton->setHidden(true);
       eliminaButton->setHidden(true);
     }

 }



 void mainWidget::loadLista() {
   listaPubblicazioni::const_iterator it = listaP.begin();
   int i = 0;
   for(;it != listaP.end(); ++it ) {
       tableP->insertRow(i);
       tableP->setItem(i, 0, new QTableWidgetItem(QString::fromStdString((*it)->getTitolo())));
       tableP->setItem(i, 1, new QTableWidgetItem(QString::fromStdString((*it)->getAutore())));
       tableP->setItem(i, 2, new QTableWidgetItem(QString::fromStdString((*it)->getCodiceRiferimento())));
       tableP->setItem(i, 3, new QTableWidgetItem(((*it)->getDataPubblicazione()).toString("yyyy")));
       ++i;
     }
 }

 void mainWidget::refreshLista() {
   listaPubblicazioni::iterator it = listaP.begin();
   int i = 0;
   for(;it != listaP.end(); ++it ) {
       tableP->setItem(i, 0, new QTableWidgetItem(QString::fromStdString((*it)->getTitolo())));
       tableP->setItem(i, 1, new QTableWidgetItem(QString::fromStdString((*it)->getAutore())));
       tableP->setItem(i, 2, new QTableWidgetItem(QString::fromStdString((*it)->getCodiceRiferimento())));
       tableP->setItem(i, 3, new QTableWidgetItem(((*it)->getDataPubblicazione()).toString("yyyy")));
       ++i;
     }
 }

 void mainWidget::sort(int section) {
   itemDeSelected();
   int c;
   switch(section) {
     case 0:!ordinatoTitolo ? c=0 : c=4;
       break;
     case 1: !ordinatoAutore ? c=1 : c=5;
       break;
     case 2: !ordinatoCodiceRiferimento ? c=2 : c=6;
       break;
     case 3: !ordinatoAnno ? c=3 : c=7;
       break;
     default:
       c=-1;
       break;
     }
   ordinatoAutore= false;
   ordinatoAnno=false;
   ordinatoTitolo=false;
   ordinatoCodiceRiferimento=false;


   switch (c) {
     case 0:
       listaP.sortByTitolo();
       ordinatoTitolo=true;
       showSorting(0);
       break;
     case 1: listaP.sortByAutore();
       ordinatoAutore= true;
       showSorting(1);
       break;
     case 2: listaP.sortByCodiceRiferimento();
       ordinatoCodiceRiferimento=true;
       showSorting(2);
       break;
     case 3: listaP.sortByAnnoDiPubblicazione();
       ordinatoAnno=true;
       showSorting(3);
       break;
     case 4: listaP.sortByreverseTitolo();
       showSorting(section+4);
       break;
     case 5: listaP.sortByreverseAutore();
       showSorting(section+4);
       break;
     case 6: listaP.sortByreverseCodiceRiferimento();
       showSorting(section+4);
       break;
     case 7: listaP.sortByreverseAnnoDiPubblicazione();
       showSorting(section+4);
       break;
     }
   refreshLista();
 }



 void mainWidget::showSorting(int i) {
   tableP->horizontalHeaderItem(0)->setText("Titolo");
   tableP->horizontalHeaderItem(1)->setText("Autore");
   tableP->horizontalHeaderItem(2)->setText("Codice Riferimento");
   tableP->horizontalHeaderItem(3)->setText("Anno Pubblicazione");

   switch (i) {
     case 0:
       tableP->horizontalHeaderItem(0)->setText("Titolo  ▼"); break;
     case 1:
       tableP->horizontalHeaderItem(1)->setText("Autore  ▼"); break;
     case 2:
       tableP->horizontalHeaderItem(2)->setText("Codice Riferimento  ▼"); break;
     case 3:
       tableP->horizontalHeaderItem(3)->setText("Anno Pubblicazione  ▼"); break;
     case 4:
       tableP->horizontalHeaderItem(0)->setText("Titolo  ▲"); break;
     case 5:
       tableP->horizontalHeaderItem(1)->setText("Autore  ▲"); break;
     case 6:
       tableP->horizontalHeaderItem(2)->setText("Codice Riferimento  ▲"); break;
     case 7:
       tableP->horizontalHeaderItem(3)->setText("Anno Pubblicazione  ▲"); break;
     }

 }

 void mainWidget::itemSelected() {
   modificaButton->setEnabled(true);
   eliminaButton->setEnabled(true);
 }

 void mainWidget::deleteP() {
   QMessageBox delBox;
   delBox.setWindowTitle("Eliminazione");
   delBox.setText("Sei sicuro di voler eliminare la pubblicazione selezionata?");
   delBox.setStandardButtons(QMessageBox::Yes);
   delBox.addButton(QMessageBox::No);
   delBox.setDefaultButton(QMessageBox::No);
   if(delBox.exec() == QMessageBox::Yes){
       QModelIndex currentIndex = tableP->currentIndex();
       QString rif = (tableP->item(currentIndex.row(),2))->data(Qt::DisplayRole).toString();
       listaP.togliPubblicazione(rif.toStdString());
       tableP->removeRow(currentIndex.row());
       listaP.scriviListaPubblicazioni();
       tableP->selectRow(tableP->currentRow());
       if(!tableP->rowCount())
          itemDeSelected();
   }
 }

 void mainWidget::itemDeSelected() {
   tableP->clearSelection();
   tableP->setCurrentCell(-1,-1);
   modificaButton->setEnabled(false);
   eliminaButton->setEnabled(false);
 }

void mainWidget::reHighlight() {
  tableP->selectRow(tableP->currentRow());
}

void mainWidget::addPubblicazione() {
  QStringList listaTipoPubblicazioni;
  QInputDialog* dialogInputType = new QInputDialog(this);
  listaTipoPubblicazioni<<"Pubblicazione online";
  listaTipoPubblicazioni<<"Articolo su rivista";
  listaTipoPubblicazioni<<"Libro";
  bool accettato = false;
  QString tipo = dialogInputType->getItem(this,"Creazione Pubblicazione","Selezionare il tipo di pubblicazione da creare:",listaTipoPubblicazioni,0,false,&accettato);
  if(accettato){
  astrattaPubblicazione* tmp = fileFactory::buildForGui(tipo);
  view = new mainDialog(tmp,user,true,listaP);
  connect(view,SIGNAL(listChanged(astrattaPubblicazione*)),this,SLOT(refreshListaOnAdd(astrattaPubblicazione*)));
  view->setModal(true);
  view->exec();
  }
}


void mainWidget::showPubblicazzine() {
  QModelIndex currentIndex = tableP->currentIndex();
  QString rif = (tableP->item(currentIndex.row(),2))->data(Qt::DisplayRole).toString();
  view = new mainDialog(listaP.pubblicazionePresente(rif.toStdString()),user,false,listaP);
  connect(view,SIGNAL(listChanged(astrattaPubblicazione*)),this,SLOT(refreshListaOnEdit()));
  view->setModal(true);
  view->show();
}

void mainWidget::EditPubblicazione() {
  QModelIndex currentIndex = tableP->currentIndex();
  QString rif = (tableP->item(currentIndex.row(),2))->data(Qt::DisplayRole).toString();
  view = new mainDialog(listaP.pubblicazionePresente(rif.toStdString()),user,true,listaP);
  connect(view,SIGNAL(listChanged(astrattaPubblicazione*)),this,SLOT(refreshListaOnEdit()));
  view->setModal(true);
  view->show();

}

void mainWidget::refreshListaOnEdit() {
  listaP.scriviListaPubblicazioni();
  refreshLista();
}

void mainWidget::refreshListaOnAdd(astrattaPubblicazione* tmp) {
  if(!listaP.pubblicazionePresente(*tmp)) {
      if(tmp->getCodiceRiferimento()!="") {
        listaP.aggiungiPubblicazione(*tmp);
        QMessageBox error;
        error.critical(this,"","inserimento avvenuto con successo",QMessageBox::Ok);
        view->close();
        clearTable();
        loadLista();
        }
    }
  else {
      QMessageBox error;
      error.critical(this,"errore","La pubblicazione è già presente",QMessageBox::Ok);
      delete tmp;
    }
}

void mainWidget::clearTable() {
  tableP->setRowCount(0);
}

void mainWidget::creaMenuTendina() {
  QMenuBar* menuTendina = new QMenuBar(this);
  QMenu* menuFile = new QMenu("File",menuTendina);
  QAction* menuLogOut = new QAction("Cambia utente", menuFile);
  QAction* menuExit = new QAction("Esci",menuFile);
  QMenu* menuGestioneUtenti = new QMenu("Gestione utenti",menuTendina);
  QAction* menuAggiungiUtente = new QAction("Aggiungi Utente",menuGestioneUtenti);
  QAction* menuGestiscilistaUtenti = new QAction("Gestisci utenti",menuGestioneUtenti);

  menuFile->addAction(menuLogOut);
  menuFile->addAction(menuExit);
  menuTendina->addMenu(menuFile);

  if(user->isAdmin()) {
  menuGestioneUtenti->addAction(menuAggiungiUtente);
  menuGestioneUtenti->addAction(menuGestiscilistaUtenti);
  menuTendina->addMenu(menuGestioneUtenti);
  }

  gLayout->addWidget(menuTendina,0,0);

  connect(menuExit,SIGNAL(triggered(bool)),this,SIGNAL(mainClose()));
  connect(menuLogOut,SIGNAL(triggered(bool)),this,SLOT(slotRelog()));
  connect(menuGestiscilistaUtenti,SIGNAL(triggered(bool)),this,SLOT(gestisciUtenti()));
  connect(menuAggiungiUtente,SIGNAL(triggered(bool)),this,SLOT(aggiungiUtente()));
  //slot da collegare
}


void mainWidget::slotRelog() {
  *relog = true;
  emit mainClose();
}

void mainWidget::gestisciUtenti() {
  utentiMainDialog* gestioneUtenti = new utentiMainDialog(listaU,user,0);
  gestioneUtenti->setModal(true);
  gestioneUtenti->show();
}

void mainWidget::aggiungiUtente() {
  utentiMainDialog* gestioneUtenti = new utentiMainDialog(listaU,user,0);
  connect(this,SIGNAL(addUsr()),gestioneUtenti,SLOT(aggiungiUtente()));
  emit addUsr();

}

void mainWidget::searchSlot(QString p) {
   int i=-1;
   if(titoloRadio->isChecked())
      i = 1;
   else if (autoreRadio->isChecked())
      i = 2;
   else if (codiceRiferimentoRadio->isChecked())
      i = 3;
   else if (genericaRadio->isChecked())
      i = 4;


   for(int c = 0; c < tableP->rowCount();++c) {
       switch (i) {
         case 1:
           if(tableP->item(c,0)->data((Qt::DisplayRole)).toString().indexOf(p,0,Qt::CaseInsensitive)==-1)
             tableP->setRowHidden(c,true);
           else
             tableP->setRowHidden(c,false);
           break;
         case 2:
           if(tableP->item(c,1)->data((Qt::DisplayRole)).toString().indexOf(p,0,Qt::CaseInsensitive)==-1)
             tableP->setRowHidden(c,true);
           else
             tableP->setRowHidden(c,false);
           break;
         case 3:
           if(tableP->item(c,2)->data((Qt::DisplayRole)).toString().indexOf(p,0,Qt::CaseInsensitive)==-1)
             tableP->setRowHidden(c,true);
           else
             tableP->setRowHidden(c,false);
           break;
         case 4:
           if((tableP->item(c,0)->data((Qt::DisplayRole)).toString().indexOf(p,0,Qt::CaseInsensitive)==-1) &&
              (tableP->item(c,1)->data((Qt::DisplayRole)).toString().indexOf(p,0,Qt::CaseInsensitive)==-1) &&
              (tableP->item(c,2)->data((Qt::DisplayRole)).toString().indexOf(p,0,Qt::CaseInsensitive)==-1) )
             tableP->setRowHidden(c,true);
           else
             tableP->setRowHidden(c,false);
           break;
         }
     }
}














