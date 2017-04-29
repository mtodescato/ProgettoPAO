#ifndef LISTAUTENTI_H
#define LISTAUTENTI_H

#include "utente.h"
#include "admin.h"
#include "moderatore.h"
#include "funzioniutili.h"
#include <vector>
#include <QXmlStreamReader>
#include <QFile>
#include <QString>


class listaUtenti {
private:
  std::list<utente*> lista;
  void caricaUtente(QXmlStreamReader&);
public:
  ~listaUtenti();
  bool aggiungiUtente(utente & );
  bool togliUtente(const utente& );
  utente* utentePresente(const utente& ) const;
  void caricaListaUtenti();
  friend std::ostream& operator<< (std::ostream&, const listaUtenti& );
};

#endif // LISTAUTENTI_H
