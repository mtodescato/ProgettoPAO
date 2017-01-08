#include <iostream>
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  listaUtenti listaU;
  listaU.caricaListaUtenti();
  login log(listaU);
  log.show();
  return app.exec();
}
