#include "listautenti.h"

listaUtenti::listaUtenti() {}

void listaUtenti::aggiungiUtente(utente& user) {
  if(!utentePresente(user)) lista.push_back(&user);
  else
    std::cout<< user << " ==> utente già presente" << std::endl;
}

void listaUtenti::togliUtente(const utente& user) {
  bool trovato = false;
  for(std::vector<utente*>::iterator it = lista.begin(); it<lista.end() && !trovato; ++it) {
      if(**it == user) {
          trovato = true;
          lista.erase(it);
       }
    }
}

bool listaUtenti::utentePresente(const utente& user) {
  bool trovato = false;
  std::vector<utente*>::const_iterator it = lista.begin();
  for( ;it<lista.end() && !trovato; ++it) {
      if(**it == user) trovato=true;
    }
  return trovato;
}

std::ostream& operator<< (std::ostream& os, const listaUtenti& list ) {
  if(list.lista.empty()) os << "LISTA VUOTA"<< std::endl;
  else {
      os << "LISTA UTENTI:" << std::endl;
      for(std::vector<utente*>::const_iterator it = list.lista.begin(); it<list.lista.end(); ++it) {
          os << **it << std::endl;
        }
    }
  return os;
}
