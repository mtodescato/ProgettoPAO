#include "viewarticolorivista.h"

viewArticoloRivista::viewArticoloRivista(astrattaPubblicazione *p, QWidget* parent):viewAstrattaPubblicazioneStampata(p,parent){}

void viewArticoloRivista::caricaCampiDati() {
  viewAstrattaPubblicazioneStampata::caricaCampiDati();
  articoloRivista* tmp = dynamic_cast<articoloRivista*>(pub);
  nomeRivista = new QLineEdit(QString::fromStdString(tmp->getNomeRivista()),this);
  ISSN = new QLineEdit(QString::fromStdString(tmp->getISSN()),this);
  numeroUscita = new QLineEdit(QString::number(tmp->getNumeroUscita()),this);
  dataPubblicazione = new QLineEdit((tmp->getDataPubblicazione()).toString("d/M/yyyy"),this);
  viewLayout->addRow("Nome rivista:", nomeRivista);
  viewLayout->addRow("ISSN*:", ISSN);
  viewLayout->addRow("Numero Uscita*:", numeroUscita);
  viewLayout->addRow("Data pubblicazione*:", dataPubblicazione);

  connect(nomeRivista,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(ISSN,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(numeroUscita,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(dataPubblicazione,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
}

void viewArticoloRivista::setEditablility(bool editable) {
  viewAstrattaPubblicazioneStampata::setEditablility(editable);
  nomeRivista->setReadOnly(!editable);
  ISSN->setReadOnly(!editable);
  numeroUscita->setReadOnly(!editable);
  dataPubblicazione->setReadOnly(!editable);
}

bool viewArticoloRivista::checkAndSet() {
  articoloRivista* tmp = dynamic_cast<articoloRivista*>(pub);
  if(viewAstrattaPubblicazioneStampata::checkAndSet() &&
     tmp->setISSN(ISSN->text().toStdString()) &&
     tmp->setNumeroUscita(numeroUscita->text().toInt()) &&
     tmp->setDataPubblicazione(dataPubblicazione->text())
     ) {
      tmp->setNomeRivista(nomeRivista->text().toStdString());
      return true;
    }
  else
    return false;
}


QString viewArticoloRivista::controlReferenceCode() {
  return DOI->text();
}
