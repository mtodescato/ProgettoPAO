#ifndef VIEWPUBBLICAZONEONLINE_H
#define VIEWPUBBLICAZONEONLINE_H
#include "viewastrattapubblicazione.h"

class viewPubblicazioneOnline : public viewAstrattaPubblicazione {
private:
  QLineEdit* sitoPubblicazione;
  QLineEdit* linkPubblicazione;
  QLineEdit* dataPubblicazione;
public:
  viewPubblicazioneOnline(astrattaPubblicazione*, QWidget* );
  virtual void caricaCampiDati();
  virtual void setEditablility(bool);
  virtual bool checkAndSet();
  virtual QString controlReferenceCode();
};

#endif // VIEWPUBBLICAZONEONLINE_H
