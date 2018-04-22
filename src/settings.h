#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
#include <QSettings>
#include "settings_headers.h"
#include "abstractsettings.h"

class SETTINGS_COMMON_DLLSPEC Settings: public QObject
{
    Q_OBJECT

public:
    explicit Settings(QString file = "setting.ini", QObject* parent = Q_NULLPTR);
    ~Settings();
    void saveObject(AbstractSettings *object);
    void restoreObject(AbstractSettings *object);

private:
    //QSettings* settings;
    QString m_fileName;
};

#endif // SETTINGS_H
