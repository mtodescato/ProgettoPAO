#ifndef VIEWASTRATTAPUBBLICAZIONE_H
#define VIEWASTRATTAPUBBLICAZIONE_H

#include <QWidget>
#include <QLineEdit>
#include <QTextEdit>
#include <listapubblicazioni.h>
#include <QFormLayout>
#include <QString>


class viewAstrattaPubblicazione : public QWidget {
  Q_OBJECT
private:
  QLineEdit* titolo;
  QLineEdit* autore;
  QLineEdit* materia;
  QTextEdit* descrizione;
  QLineEdit* linguaOriginale;
protected:
  astrattaPubblicazione* pub;
  QFormLayout* viewLayout;
  QLineEdit* DOI;
public:
  viewAstrattaPubblicazione(astrattaPubblicazione*, QWidget* =0);
  virtual void caricaCampiDati();
  virtual void setEditablility(bool);
  virtual bool checkAndSet();
  virtual QString controlReferenceCode() =0;
public slots:
  void valueChanged();
signals:
  void fieldEdited(bool);

};

#endif // VIEWASTRATTAPUBBLICAZIONE_H
