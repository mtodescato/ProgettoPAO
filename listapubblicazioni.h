#ifndef LISTAPUBBLICAZIONI_H
#define LISTAPUBBLICAZIONI_H

#include <iostream>
#include "pubblicazioneonline.h"
#include "libro.h"
#include "articolorivista.h"
#include "filefactory.h"
#include <QFile>
#include <QString>




class listaPubblicazioni {
private:
  std::vector<astrattaPubblicazione*> pubblicazioni;
  void caricaPubblicazione(QXmlStreamReader&);
  static std::vector<astrattaPubblicazione*> copia(const std::vector<astrattaPubblicazione*>& );
  static void distruggi(std::vector<astrattaPubblicazione*>& );
public:
  listaPubblicazioni() = default;
  ~listaPubblicazioni();
  listaPubblicazioni& operator= (const listaPubblicazioni& );
  listaPubblicazioni(const listaPubblicazioni&);
  bool aggiungiPubblicazione( astrattaPubblicazione& );
  bool togliPubblicazione(const astrattaPubblicazione& );
  bool togliPubblicazione(const std::string&);
  astrattaPubblicazione* pubblicazionePresente(const astrattaPubblicazione& ) const;
  astrattaPubblicazione* pubblicazionePresente(const std::string& ) const;
  bool caricaListaPubblicazioni();
  bool scriviListaPubblicazioni() const;
  friend std::ostream& operator<< (std::ostream&, const listaPubblicazioni& );

  class const_iterator;
  class iterator {
  private:
    std::vector<astrattaPubblicazione*>::iterator it;
  public:
    iterator(std::vector<astrattaPubblicazione*>::iterator);
    bool operator== ( const iterator& ) const;
    bool operator!= ( const iterator& ) const;
    iterator& operator++ ();
    iterator operator ++(int);
    astrattaPubblicazione* operator* () const;
    iterator& operator= (const iterator&);
    friend class const_iterator;
  };

  class const_iterator {
  private:
    std::vector<astrattaPubblicazione*>::const_iterator it;
  public:
    const_iterator(iterator);
    const_iterator(std::vector<astrattaPubblicazione*>::const_iterator);
    bool operator== ( const const_iterator& ) const;
    bool operator!= ( const const_iterator& ) const;
    const_iterator& operator++ ();
    const_iterator operator++(int);
    const_iterator& operator= (const const_iterator&);
    const astrattaPubblicazione* operator* () const;
  };

  iterator begin();
  iterator end();

  void sortByTitolo();
  void sortByAutore();
  void sortByCodiceRiferimento();
  void sortByAnnoDiPubblicazione();
  void sortByreverseTitolo();
  void sortByreverseAutore();
  void sortByreverseCodiceRiferimento();
  void sortByreverseAnnoDiPubblicazione();

};

#endif // LISTAPUBBLICAZIONI_H
