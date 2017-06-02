#ifndef UTENTIMAINDIALOG_H
#define UTENTIMAINDIALOG_H
#include <QDialog>
#include "listautenti.h"
#include <QListWidget>
#include <QPushButton>
#include <QGridLayout>
#include <QHBoxLayout>
#include "viewutenti.h"
#include <QListWidgetItem>
#include <QFormLayout>
#include <QInputDialog>
#include <QPushButton>
#include <QLineEdit>

class utentiMainDialog : public QDialog {
  Q_OBJECT
private:
  listaUtenti& listaU;
  utente* user;
  viewUtenti* view;
  QLineEdit* search;
  QListWidget* viewLista;
  QPushButton* aggiungiButton;
  QPushButton* modificaButton;
  QPushButton* eliminaButton;
public:
  utentiMainDialog(listaUtenti&, utente*, QDialog* =0);
  void loadLista();
public slots:
  void rimuoviUtente();
  void itemSelected();
  void itemDeselected();
  void showUtente();
  void refreshListaOnEdit();
  void modificaUtente();
  void aggiungiUtente();
  void refreshListaOnAdd(utente*);
  void searchSlot(QString);


};

#endif // UTENTIMAINDIALOG_H
