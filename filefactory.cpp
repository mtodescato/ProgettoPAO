#include "filefactory.h"

astrattaPubblicazione* fileFactory::buildFromXml(QXmlStreamReader& reader, const std::string& tipo) {
  if(tipo=="pubblicazioneOnline")
    return pubblicazioneOnline::importFromXml(reader);
  else if(tipo == "libro")
    return libro::importFromXml(reader);
  else if(tipo == "articoloRivista")
    return articoloRivista::importFromXml(reader);
  return 0;
}
