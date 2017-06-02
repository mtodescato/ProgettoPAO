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
  static std::list<utente*> copia(const std::list<utente*>& ); //da portare in lista pubblicazioni
  static void distruggi(std::list<utente*>& ); //da portare in lista pubblicazioni
public:
  listaUtenti() = default; //da portare in lista pubblicazioni
  ~listaUtenti(); //da portare in lista pubblicazioni
  listaUtenti& operator= (const listaUtenti& ); //da portare in lista pubblicazioni
  listaUtenti(const listaUtenti&); //da portare in lista pubblicazioni
  bool aggiungiUtente(utente & );
  bool togliUtente(const utente& );
  bool togliUtente(std::string);
  utente* utentePresente(std::string)const;
  utente* utentePresente(const utente& ) const;
  bool caricaListaUtenti();
  bool scriviListaUtenti() const;
  friend std::ostream& operator<< (std::ostream&, const listaUtenti& );


  class const_iterator;
  class iterator {
  private:
    std::list<utente*>::iterator it;
  public:
    iterator(std::list<utente*>::iterator);
    bool operator== ( const iterator& ) const;
    bool operator!= ( const iterator& ) const;
    iterator& operator++ ();
    iterator operator ++(int);
    utente* operator* () const;
    iterator& operator= (const iterator&);
    friend class const_iterator;
  };

  class const_iterator {
  private:
    std::list<utente*>::const_iterator it;
  public:
    const_iterator(iterator);
    const_iterator(std::list<utente*>::const_iterator);
    bool operator== ( const const_iterator& ) const;
    bool operator!= ( const const_iterator& ) const;
    const_iterator& operator++ ();
    const_iterator operator++(int);
    const_iterator& operator= (const const_iterator&);
    const utente* operator* () const;
  };

  iterator begin();
  iterator end();



};

#endif // LISTAUTENTI_H
