#ifndef VIEWUTENTI_H
#define VIEWUTENTI_H
#include <QDialog>
#include "listautenti.h"
#include <QLineEdit>
#include <QLabel>
#include <QFormLayout>
#include <QPushButton>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QMessageBox>

class viewUtenti : public QDialog {
  Q_OBJECT
private:
  listaUtenti& listaU;
  utente* user;
  bool onEdit;
  QLineEdit* username;
  QLineEdit* password;
  QPushButton* modificaButton;
  QPushButton* salvaButton;
public:
  viewUtenti(listaUtenti&, utente*, bool, QDialog* =0);
public slots:
  void setEditability();
  void attivaModifica();
  void salvaModifica();
  void attivaSalva();
  void disattivaSalva();
signals:
  void listChanged(utente*);

};

#endif // VIEWUTENTI_H
