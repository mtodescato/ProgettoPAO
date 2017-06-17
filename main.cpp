#include <iostream>
#include <QApplication>
#include "login.h"
#include "mainwindow.h"

#include "pubblicazioneonline.h"
#include "libro.h"
#include "articolorivista.h"
#include "listapubblicazioni.h"
#include <QDebug>
#include <QMessageBox>

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  bool relog = true;

  while(relog == true) {
  relog=false;
  utente* usr = nullptr;
  listaUtenti listaU;
  bool failed = !(listaU.caricaListaUtenti());

  if(failed) {
      QMessageBox error;
      error.critical(0,"errore","File utenti non trovato è stato inserito l'utente di default",QMessageBox::Ok);
    }

  login log(listaU, &usr);
  log.exec();
  listaPubblicazioni listaP;
  listaP.caricaListaPubblicazioni();
  if(usr) {
  listaPubblicazioni listaP;
  listaP.caricaListaPubblicazioni();
  mainwindow m(usr,listaU,listaP,&relog,0);
  m.show();
  app.exec();
  }
 }

}
