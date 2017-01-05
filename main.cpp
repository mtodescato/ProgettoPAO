#include <iostream>
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  listaUtenti lista;
  lista.caricaListaUtenti();
  login log(lista);
  log.show();
  return app.exec();
}
