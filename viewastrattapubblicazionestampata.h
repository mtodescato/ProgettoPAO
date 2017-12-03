#ifndef VIEWASTRATTAPUBBLICAZIONESTAMPATA_H
#define VIEWASTRATTAPUBBLICAZIONESTAMPATA_H
#include "viewastrattapubblicazione.h"
#include <QLineEdit>

class viewAstrattaPubblicazioneStampata : public viewAstrattaPubblicazione {
private:
  QLineEdit* casaEditrice;
public:
  viewAstrattaPubblicazioneStampata(astrattaPubblicazione*, QWidget* =0);
  void caricaCampiDati();
  virtual void setEditablility(bool);
  virtual bool checkAndSet();
};


#endif // VIEWASTRATTAPUBBLICAZIONESTAMPATA_H
