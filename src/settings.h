#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
#include <QSettings>
#include "settings_headers.h"
#include "abstractsettings.h"

class SETTINGS_COMMON_DLLSPEC Settings
{

public:
    Settings(QString file = "setting.ini", QObject *parent = Q_NULLPTR);
    void saveObject(AbstractSettings *object);
    void restoreObject(AbstractSettings *object);

private:
    QSettings *m_settings;
};

#endif // SETTINGS_H
