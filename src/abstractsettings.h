#ifndef ABSTRACTSETTINGS_H
#define ABSTRACTSETTINGS_H
#include <QObject>
#include <QMap>
#include "settings_headers.h"

namespace LibQt
{

    class SETTINGS_COMMON_DLLSPEC AbstractSettings {
    public:
        AbstractSettings(){}
        virtual const QString getName(void) const {
            return QString("General");
        }
        virtual void setSettings(const QMap<QString, QVariant> map) = 0;
        virtual const QMap<QString, QVariant> getSettings(void) const = 0;
    };

}
#endif // ABSTRACTSETTINGS_H
