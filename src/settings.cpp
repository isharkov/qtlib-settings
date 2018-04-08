#include "settings.h"
#include <QDebug>


Settings::Settings(QString file, QObject *parent)
{
   m_settings = new QSettings(file, QSettings::IniFormat);
}

/**
 * @brief Settings::saveObject
 * @param object
 */
void Settings::saveObject(AbstractSettings *object)
{
    QString section = object->getName();
    QMap<QString, QVariant> map = object->getSettings();
    QMap<QString, QVariant>::iterator i = map.begin();
    while(i != map.end()) {
        m_settings->setValue(section + "/" + i.key(), i.value().toString());
        i++;
    }
    return;
}

/**
 * @brief Settings::restoreObject
 * @param object
 */
void Settings::restoreObject(AbstractSettings *object)
{
    QString section = object->getName();
    QMap<QString, QVariant> map = object->getSettings();
    QMap<QString, QVariant>::iterator i = map.begin();
    while(i != map.end()) {
        map[i.key()] = m_settings->value(section + "/" + i.key(), i.value().toString());
        i++;
    }
    object->setSettings(map);
    return;
}
