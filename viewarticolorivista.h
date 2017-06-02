#ifndef VIEWARTICOLORIVISTA_H
#define VIEWARTICOLORIVISTA_H
#include "viewastrattapubblicazionestampata.h"

class viewArticoloRivista : public viewAstrattaPubblicazioneStampata {
private:
  QLineEdit* nomeRivista;
  QLineEdit* ISSN;
  QLineEdit* numeroUscita;
  QLineEdit* dataPubblicazione;
public:
  viewArticoloRivista(astrattaPubblicazione*,QWidget* =0);
  void caricaCampiDati();
  virtual void setEditablility(bool);
  virtual bool checkAndSet();
  virtual QString controlReferenceCode();
};

#endif // VIEWARTICOLORIVISTA_H
