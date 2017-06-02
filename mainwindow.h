#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include <QWidget>
#include "listautenti.h"
#include "listapubblicazioni.h"
#include "mainwidget.h"

class mainwindow : public QMainWindow {
public:
  mainwindow(utente* , listaUtenti& , listaPubblicazioni& ,bool* , QWidget* =0);
};

#endif // MAINWINDOW_H
