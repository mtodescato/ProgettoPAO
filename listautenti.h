#ifndef LISTAUTENTI_H
#define LISTAUTENTI_H

#include "utente.h"
#include "admin.h"
#include "moderatore.h"
#include <vector>
#include <QXmlStreamReader>
#include <QFile>

class listaUtenti {
private:
  std::vector<utente*> lista;
public:
  listaUtenti();
  void aggiungiUtente(utente & );
  void togliUtente(const utente& );
  bool utentePresente(const utente& );
  void caricaListaUtenti();
  void caricaUtente(QXmlStreamReader&);
  friend std::ostream& operator<< (std::ostream&, const listaUtenti& );

};

#endif // LISTAUTENTI_H
