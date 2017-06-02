#ifndef MAINDIALOG_H
#define MAINDIALOG_H

#include <QDialog>
#include "listapubblicazioni.h"
#include "admin.h"
#include "moderatore.h"
#include "viewfactory.h"
#include <QGridLayout>
#include <QHBoxLayout>
#include <QPushButton>

class mainDialog : public QDialog {
  Q_OBJECT
private:
  astrattaPubblicazione* pub;
  utente* loggedUser;
  listaPubblicazioni& listaP;
  bool forEdit;
  QPushButton* modificaButton;
  QPushButton* salvaButton;
  viewAstrattaPubblicazione* guiPub;
public:
  mainDialog(astrattaPubblicazione*, utente*, bool ,listaPubblicazioni&, QDialog* =0);
public slots:
  void attivaModifica();
  void salvaModifica();
signals:
  void listChanged(astrattaPubblicazione*);
};

#endif // MAINDIALOG_H
