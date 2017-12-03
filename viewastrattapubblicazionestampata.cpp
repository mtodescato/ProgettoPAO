#include "viewastrattapubblicazionestampata.h"

viewAstrattaPubblicazioneStampata::viewAstrattaPubblicazioneStampata(astrattaPubblicazione *p , QWidget* parent): viewAstrattaPubblicazione(p,parent){}

void viewAstrattaPubblicazioneStampata::caricaCampiDati() {
  viewAstrattaPubblicazione::caricaCampiDati();
  astrattaPubblicazioneStampata* tmp = dynamic_cast<astrattaPubblicazioneStampata*>(pub);
  casaEditrice = new QLineEdit(QString::fromStdString(tmp->getCasaEditrice()),this);
  viewLayout->addRow("Casa editrice: ", casaEditrice);
  casaEditrice->setCursorPosition(0);
  connect(casaEditrice,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
}

void viewAstrattaPubblicazioneStampata::setEditablility(bool editable) {
  viewAstrattaPubblicazione::setEditablility(editable);
  casaEditrice->setReadOnly(!editable);
}

bool viewAstrattaPubblicazioneStampata::checkAndSet() {
  astrattaPubblicazioneStampata* tmp = dynamic_cast<astrattaPubblicazioneStampata*>(pub);
  if(viewAstrattaPubblicazione::checkAndSet()) {
      tmp->setCasaEditrice(casaEditrice->text().toStdString());
      return true;
    }
  else
    return false;
}
