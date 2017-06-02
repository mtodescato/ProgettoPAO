#include "viewpubblicazoneonline.h"

viewPubblicazioneOnline::viewPubblicazioneOnline(astrattaPubblicazione* p, QWidget * parent):viewAstrattaPubblicazione(p,parent) {}

void viewPubblicazioneOnline::caricaCampiDati() {
  viewAstrattaPubblicazione::caricaCampiDati();
  pubblicazioneOnline* tmp = dynamic_cast<pubblicazioneOnline*>(pub);
  sitoPubblicazione = new QLineEdit(QString::fromStdString(tmp->getSitoPubblicazione()),this);
  linkPubblicazione = new QLineEdit(QString::fromStdString(tmp->getLinkPubbliczione()),this);
  dataPubblicazione = new QLineEdit((tmp->getDataPubblicazione()).toString("d/M/yyyy"),this);
  viewLayout->addRow("Sito pubblicazione*:", sitoPubblicazione);
  viewLayout->addRow("Link alla pubblicazione*:", linkPubblicazione);
  viewLayout->addRow("Data pubblicazione*:", dataPubblicazione);

  connect(sitoPubblicazione,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(linkPubblicazione,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(dataPubblicazione,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
}

void viewPubblicazioneOnline::setEditablility(bool editable) {
  viewAstrattaPubblicazione::setEditablility(editable);
  sitoPubblicazione->setReadOnly(!editable);
  linkPubblicazione->setReadOnly(!editable);
  dataPubblicazione->setReadOnly(!editable);
}

bool viewPubblicazioneOnline::checkAndSet() {
  pubblicazioneOnline* tmp = dynamic_cast<pubblicazioneOnline*>(pub);
  if(viewAstrattaPubblicazione::checkAndSet() &&
     tmp->setsitoPubblicazione(sitoPubblicazione->text().toStdString()) &&
     tmp->setlinkPubblicazione(linkPubblicazione->text().toStdString()) &&
     tmp->setdataPubblicazione(dataPubblicazione->text()))
    return true;
  else
    return false;
}

QString viewPubblicazioneOnline::controlReferenceCode() {
  return DOI->text();
}

