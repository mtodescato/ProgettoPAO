#include <iostream>
#include <QApplication>
#include "login.h"

int main(int argc, char *argv[])
{
  QApplication app(argc,argv);
  login log;
  log.show();
  return app.exec();
}
