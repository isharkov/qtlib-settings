/*
 ---------------------------------------------------------------------------
 Copyright (c) 2018, Ilya Sharkov. All rights reserved.

 LICENSE TERMS

 The redistribution and use of this software (with or without changes)
 is allowed without the payment of fees or royalties provided that:

  1. source code distributions include the above copyright notice, this
     list of conditions and the following disclaimer;

  2. binary distributions include the above copyright notice, this list
     of conditions and the following disclaimer in their documentation;

  3. the name of the copyright holder is not used to endorse products
     built using this software without specific written permission.

 DISCLAIMER

 This software is provided 'as is' with no explicit or implied warranties
 in respect of its properties, including, but not limited to, correctness
 and/or fitness for purpose.
 ---------------------------------------------------------------------------
 */

#ifndef ABSTRACTSETTINGS_H
#define ABSTRACTSETTINGS_H
#include <QObject>
#include <QMap>
#include "settings_headers.h"

namespace QtLib
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
