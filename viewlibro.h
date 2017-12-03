#ifndef VIEWLIBRO_H
#define VIEWLIBRO_H
#include "viewastrattapubblicazionestampata.h"

class viewLibro : public viewAstrattaPubblicazioneStampata {
private:
  QLineEdit* annoDiPubblicazione;
  QLineEdit* ISBN;
public:
  viewLibro(astrattaPubblicazione* , QWidget* =0);
  void caricaCampiDati();
  virtual void setEditablility(bool);
  virtual bool checkAndSet();
  virtual QString controlReferenceCode();
};

#endif // VIEWLIBRO_H
