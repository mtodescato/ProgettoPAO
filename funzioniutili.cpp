#include "funzioniutili.h"

std::string readXmlString(QXmlStreamReader& reader) {
  if(reader.readNextStartElement())
    return (reader.readElementText()).toStdString();
  else
    return "";
}

int readXmlint(QXmlStreamReader& reader) {
  if(reader.readNextStartElement())
    return (reader.readElementText()).toInt();
  else
    return 0;
}
