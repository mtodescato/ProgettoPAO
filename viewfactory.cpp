#include "viewfactory.h"

viewAstrattaPubblicazione* viewFactory::buildView(astrattaPubblicazione* p, QWidget* parent) {
  astrattaPubblicazione* tmp = nullptr;
  if((tmp = dynamic_cast<pubblicazioneOnline*>(p)))
    return new viewPubblicazioneOnline(p,parent);
  else if((tmp = dynamic_cast<articoloRivista*>(p)))
    return new viewArticoloRivista(p,parent);
  else if((tmp = dynamic_cast<libro*>(p)))
    return new viewLibro(p,parent);
  else
    return nullptr;

}
