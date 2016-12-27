#ifndef LISTAUTENTI_H
#define LISTAUTENTI_H

#include "utente.h"
#include "admin.h"
#include "moderatore.h"
#include <vector>

class listaUtenti {
private:
  std::vector<utente*> lista;
public:
  listaUtenti();
  void aggiungiUtente(utente & );
  void togliUtente(const utente& );
  bool utentePresente(const utente& );
  friend std::ostream& operator<< (std::ostream&, const listaUtenti& );

};

#endif // LISTAUTENTI_H
