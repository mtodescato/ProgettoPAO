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
public:
  ~listaPubblicazioni();
  bool aggiungiPubblicazione( astrattaPubblicazione& );
  bool togliPubblicazione(const astrattaPubblicazione& );
  astrattaPubblicazione* pubblicazionePresente(const astrattaPubblicazione& ) const;
  void caricaListaPubblicazioni();
  friend std::ostream& operator<< (std::ostream&, const listaPubblicazioni& );

};

#endif // LISTAPUBBLICAZIONI_H
