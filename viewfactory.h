#ifndef VIEWFACTORY_H
#define VIEWFACTORY_H

#include "listapubblicazioni.h"
#include "viewpubblicazoneonline.h"
#include "viewarticolorivista.h"
#include "viewlibro.h"
#include "viewastrattapubblicazione.h"

class viewFactory {
public:
  virtual ~viewFactory() =0;
  static viewAstrattaPubblicazione* buildView(astrattaPubblicazione*, QWidget*);
};

#endif // VIEWFACTORY_H
