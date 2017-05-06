#ifndef LISTAUTENTI_H
#define LISTAUTENTI_H

#include "utente.h"
#include "admin.h"
#include "moderatore.h"
#include <list>
#include <QXmlStreamReader>
#include <QXmlStreamWriter>
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
  bool caricaListaUtenti();
  bool scriviListaUtenti() const;
  friend std::ostream& operator<< (std::ostream&, const listaUtenti& );

  /*
  class const_iterator;
  class iterator {
  private:
    std::list<utente*>::iterator it;
  public:
    iterator(std::list<utente*>::iterator);
    bool operator== ( iterator ) const;
    bool operator!= ( iterator ) const;
    iterator& operator++ ();
    iterator operator ++(int);
    utente* operator* ();
    friend class const_iterator;
  };

  class const_iterator {
  private:
    std::list<utente*>::const_iterator it;
  public:
    const_iterator(iterator);
    const_iterator(std::list<utente*>::const_iterator);
    bool operator== ( iterator ) const;
    bool operator!= ( iterator ) const;
    iterator& operator++ ();
    iterator operator ++(int);
    utente* operator* ();
  };

  iterator begin() const;
  iterator end() const;
  */


};

#endif // LISTAUTENTI_H
