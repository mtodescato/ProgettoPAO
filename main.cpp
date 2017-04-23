#include <iostream>
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
    utente* usr = nullptr;
    listaUtenti listaU;
    listaU.caricaListaUtenti();
    login log(listaU, &usr);
    log.exec();
}
