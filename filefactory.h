#ifndef FILEFACTORY_H
#define FILEFACTORY_H

#include "pubblicazioneonline.h"
#include "articolorivista.h"
#include "libro.h"
#include <QString>

class fileFactory {
public:
  virtual ~fileFactory()=0;
  static astrattaPubblicazione* buildFromXml(QXmlStreamReader&, const std::string& );
  static astrattaPubblicazione* buildForGui(const QString& );
};


#endif // FILEFACTORY_H
