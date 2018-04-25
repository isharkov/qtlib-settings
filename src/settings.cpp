#include "settings.h"
#include <QDebug>

namespace LibQt
{ //* start namespace

/**
 * @brief Constructor
 * @param file filename
 * @param parent parent Object
 */
Settings::Settings(QString file, QObject* parent) : QObject(parent)
{
    settings = new QSettings(file, QSettings::IniFormat, this);
}

/**
 * @brief Settings::~Settings
 */
Settings::~Settings()
{
    settings->deleteLater();
}

/**
 * @brief Saved object filelds to storage
 * @param object
 */
void Settings::saveObject(AbstractSettings* object) const
{
    qInfo() << "Settings::saveObject() -> save object " <<  object->getName();
    QString section("");
    if(object->getName() != "General" && object->getName() != "") {
         section = object->getName() + "/";
    }

    QMap<QString, QVariant> map = object->getSettings();
    QMap<QString, QVariant>::iterator i = map.begin();
    while(i != map.end()) {
        settings->setValue( section + i.key(), i.value().toString());
        i++;
    }
    return;
}

/**
 * @brief Restored object filelds from storage
 * @param object
 */
void Settings::restoreObject(AbstractSettings* object) const
{
    qInfo() << "Settings::restoreObject() -> restore object" << object->getName();
    QString section("");
    if(object->getName() != "General" && object->getName() != "") {
         section = object->getName() + "/";
    }

    QMap<QString, QVariant> map = object->getSettings();
    QMap<QString, QVariant>::iterator i = map.begin();

    while(i != map.end()) {
        map[i.key()] = settings->value(section + "/" + i.key(), i.value().toString());
        i++;
    }
    object->setSettings(map);
    return;
}

} //* end namespace
