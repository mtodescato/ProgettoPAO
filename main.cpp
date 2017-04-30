#include <iostream>
#include <QApplication>
#include "login.h"
#include "pubblicazioneonline.h"
#include "libro.h"
#include "articolorivista.h"
#include "listapubblicazioni.h"

int main(int argc, char *argv[])
{

  QApplication app(argc,argv);
    utente* usr = nullptr;
    listaUtenti listaU;
    listaU.caricaListaUtenti();
    login log(listaU, &usr);
    log.exec();

}
