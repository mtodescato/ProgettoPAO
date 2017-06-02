#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include <QWidget>
#include <QGridLayout>
#include "listautenti.h"
#include "listapubblicazioni.h"
#include "mainwindow.h"
#include "maindialog.h"
#include "filefactory.h"
#include "utentimaindialog.h"

#include <QTableWidget>
#include <QTableWidgetItem>
#include <QScrollArea>
#include <QPushButton>
#include <QHeaderView>
#include <QLineEdit>
#include <QMainWindow>
#include <QFormLayout>
#include <QHBoxLayout>
#include <QRadioButton>
#include <QString>
#include <QLabel>
#include <QModelIndex>
#include <QMenuBar>
#include <QInputDialog>
#include <QMessageBox>


class mainWidget : public QWidget {
  Q_OBJECT
private:
  utente* user;
  listaUtenti& listaU;
  listaPubblicazioni& listaP;
  bool* relog;
  QTableWidget* tableP;
  QLineEdit* search;
  QRadioButton* titoloRadio;
  QRadioButton* autoreRadio;
  QRadioButton* codiceRiferimentoRadio;
  QRadioButton* genericaRadio;
  QPushButton* aggiungiButton;
  QPushButton* modificaButton;
  QPushButton* eliminaButton;
  mainDialog* view;
  QGridLayout* gLayout;

  bool ordinatoTitolo;
  bool ordinatoAutore;
  bool ordinatoCodiceRiferimento;
  bool ordinatoAnno;

public:
  mainWidget(utente*, listaUtenti&, listaPubblicazioni& ,bool*, QMainWindow*);
  virtual ~mainWidget(){}
  void loadLista();
  void clearTable();
  void creaMenuTendina();
  void showSorting(int);
public slots:
  void refreshListaOnEdit();
  void refreshListaOnAdd(astrattaPubblicazione*);
  void refreshLista();
  void sort(int);
  void itemSelected();
  void deleteP();
  void itemDeSelected();
  void reHighlight();
  void addPubblicazione();
  void showPubblicazzine();
  void EditPubblicazione();
  void slotRelog();
  void gestisciUtenti();
  void aggiungiUtente();
  void searchSlot(QString);
signals:
  void listChanged();
  void mainClose();
  void openGestioneUtenti();
  void addUsr();


};

#endif // MAINWIDGET_H
