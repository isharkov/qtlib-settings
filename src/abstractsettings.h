#ifndef ABSTRACTSETTINGS_H
#define ABSTRACTSETTINGS_H
#include <QObject>
#include <QMap>

class AbstractSettings {
public:
    AbstractSettings(){}
    virtual QString getName(void) {
        return QString("General");
    }
    virtual void setSettings(QMap<QString, QVariant> map) = 0;
    virtual QMap<QString, QVariant> getSettings(void) = 0;
};

#endif // ABSTRACTSETTINGS_H
