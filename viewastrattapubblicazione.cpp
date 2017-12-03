#include "viewastrattapubblicazione.h"


viewAstrattaPubblicazione::viewAstrattaPubblicazione(astrattaPubblicazione* publ, QWidget* parent):QWidget(parent),pub(publ) {}

void viewAstrattaPubblicazione::caricaCampiDati() {
  viewLayout = new QFormLayout(this);
  titolo = new QLineEdit(QString::fromStdString(pub->getTitolo()),this);
  autore = new QLineEdit(QString::fromStdString(pub->getAutore()),this);
  DOI = new QLineEdit(QString::fromStdString(pub->getDOI()),this);
  materia =new QLineEdit(QString::fromStdString(pub->getMateria()),this);
  descrizione = new QTextEdit(QString::fromStdString(pub->getDescrizione()),this);
  linguaOriginale = new QLineEdit(QString::fromStdString(pub->getLinguaOriginale()),this);

  titolo->setCursorPosition(0);
  autore->setCursorPosition(0);
  DOI->setCursorPosition(0);
  materia->setCursorPosition(0);
  linguaOriginale->setCursorPosition(0);

  viewLayout->addRow("Titolo*: ", titolo);
  viewLayout->addRow("Autore*: ", autore);
  libro* tmp = dynamic_cast<libro*>(pub);
  if(!tmp )
    viewLayout->addRow("DOI*: ", DOI);
  else
    viewLayout->addRow("DOI: ", DOI);

  viewLayout->addRow("Materia: ", materia);
  viewLayout->addRow("Descrizione: ", descrizione);
  viewLayout->addRow("Lingua orginale: ", linguaOriginale);

  connect(titolo,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(autore,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(DOI,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(materia,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));
  connect(descrizione,SIGNAL(textChanged()),this,SLOT(valueChanged()));
  connect(linguaOriginale,SIGNAL(textEdited(QString)),this,SLOT(valueChanged()));

}

void viewAstrattaPubblicazione::setEditablility(bool editable) {
  titolo->setReadOnly(!editable);
  autore->setReadOnly(!editable);
  DOI->setReadOnly(!editable);
  materia->setReadOnly(!editable);
  descrizione->setReadOnly(!editable);
  linguaOriginale->setReadOnly(!editable);
}

bool viewAstrattaPubblicazione::checkAndSet() {
  if(pub->setTitolo(titolo->text().toStdString())
     & pub->setAutore(autore->text().toStdString())
     & pub->setDOI(DOI->text().toStdString()))
    {
     pub->setMateria(materia->text().toStdString());
     pub->setDescrizione(descrizione->toPlainText().toStdString());
     pub->setLinguaOriginale(linguaOriginale->text().toStdString());
     return true;
    }
  else
    return false;
}

void viewAstrattaPubblicazione::valueChanged() {
  emit fieldEdited(true);
}




