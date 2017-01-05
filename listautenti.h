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
  void caricaUtente(QXmlStreamReader&);
public:
  listaUtenti();
  void aggiungiUtente(utente & );
  void togliUtente(const utente& );
  utente* utentePresente(const utente& ) const;
  void caricaListaUtenti();
  friend std::ostream& operator<< (std::ostream&, const listaUtenti& );
};

#endif // LISTAUTENTI_H
