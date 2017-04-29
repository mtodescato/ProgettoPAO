#include "funzioniutili.h"

std::string readeXmlString(QXmlStreamReader& reader) {
  if(reader.readNextStartElement())
    return (reader.readElementText()).toStdString();
  else
    return "";
}
