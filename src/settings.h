#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
#include <QSettings>
#include "thermocouple/thermocouple.h"
#include "abstractsettings.h"

class Settings: public QObject
{
    Q_OBJECT
public:
    Settings(QObject *parent = Q_NULLPTR, QString file = "setting.ini");
    void saveObject(AbstractSettings *object);
    void restoreObject(AbstractSettings *object);

private:
    QSettings *m_settings;
};

#endif // SETTINGS_H