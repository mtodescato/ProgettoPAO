#include "viewlibro.h"

viewLibro::viewLibro(astrattaPubblicazione *p, QWidget* parent):viewAstrattaPubblicazioneStampata(p,parent) {}

void viewLibro::caricaCampiDati() {
  viewAstrattaPubblicazioneStampata::caricaCampiDati();
  libro* tmp = dynamic_cast<libro*>(pub);
  annoDiPubblicazione = new QLineEdit((tmp->getDataPubblicazione().toString("yyyy")),this);
  ISBN = new QLineEdit(QString::fromStdString(tmp->getCodiceRiferimento()),this);
  viewLayout->addRow("Anno di pubblicazione:", annoDiPubblicazione);
  viewLayout->addRow("ISBN*:", ISBN);

  connect(annoDiPubblicazione,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(ISBN,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
}

void viewLibro::setEditablility(bool editable) {
  viewAstrattaPubblicazioneStampata::setEditablility(editable);
  annoDiPubblicazione->setReadOnly(!editable);
  ISBN->setReadOnly(!editable);
}

bool viewLibro::checkAndSet() {
  libro* tmp = dynamic_cast<libro*>(pub);
  if(viewAstrattaPubblicazioneStampata::checkAndSet() && tmp->setISBN(ISBN->text().toStdString())) {
      tmp->setAnnoDiPubblicazione(annoDiPubblicazione->text().toInt());
      return true;
    }
  else
    return false;
}

QString viewLibro::controlReferenceCode() {
  return ISBN->text();
}
