#include "settings.h"
#include <QDebug>

/**
 * @brief Settings::Settings
 * @param file
 * @param parent
 */
Settings::Settings(QString file, QObject* parent) : QObject(parent)
{
    //settings = new QSettings(m_fileName, QSettings::IniFormat, this);
    m_fileName = file;
}

/**
 * @brief Settings::~Settings
 */
Settings::~Settings()
{
    //settings->deleteLater();
}

/**
 * @brief Settings::saveObject
 * @param object
 */
void Settings::saveObject(AbstractSettings* object)
{
    QSettings settings(m_fileName, QSettings::IniFormat);
    qInfo() << "Settings::saveObject() -> save object " <<  object->getName();
    QString section("");
    if(object->getName() != "General" && object->getName() != "") {
         section = object->getName() + "/";
    }

    QMap<QString, QVariant> map = object->getSettings();
    QMap<QString, QVariant>::iterator i = map.begin();
    while(i != map.end()) {
        settings.setValue( section + i.key(), i.value().toString());
        i++;
    }
    return;
}

/**
 * @brief Settings::restoreObject
 * @param object
 */
void Settings::restoreObject(AbstractSettings* object)
{
    QSettings settings(m_fileName, QSettings::IniFormat);
    qInfo() << "Settings::restoreObject() -> restore object" << object->getName();
    QString section = object->getName();
    QMap<QString, QVariant> map = object->getSettings();
    QMap<QString, QVariant>::iterator i = map.begin();
    //int d = settings->value("test", QVariant(24).toInt());
    while(i != map.end()) {
        map[i.key()] = settings.value(section + "/" + i.key(), i.value().toString());
        i++;
    }
    object->setSettings(map);
    return;
}
