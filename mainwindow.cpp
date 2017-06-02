#include "mainwindow.h"

mainwindow::mainwindow(utente* usr, listaUtenti& lutenti, listaPubblicazioni& lpubblicazioni,bool* relog, QWidget* parent):QMainWindow(parent) {
  //chiamata al costruttore del widget per la QMainWindow al quale passo usr che è l'utente che ha effeturato il login
  //e lutenti e lpubblicazioni che sono rispettivamente la lista degli utenti e delle pubblicazioni
  mainWidget* p = new mainWidget(usr,lutenti,lpubblicazioni,relog,this);
  setCentralWidget(p);
  resize(sizeHint());
  connect(p,SIGNAL(mainClose()),this,SLOT(close()));
}
