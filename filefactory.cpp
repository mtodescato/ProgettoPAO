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

astrattaPubblicazione* fileFactory::buildForGui(const QString& t) {
  astrattaPubblicazione* tmp = nullptr;
  if(t.toStdString()== "Pubblicazione online")
    tmp = new pubblicazioneOnline("","","","","",1,1,1,"","","");
  else if (t.toStdString()== "Articolo su rivista")
    tmp = new articoloRivista("","","","","",1,1,1,1,"","","","");
  else if(t.toStdString()== "Libro")
    tmp = new libro(1,"","","","","","","","");
  return tmp;
}
