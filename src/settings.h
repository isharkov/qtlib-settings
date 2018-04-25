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

#ifndef SETTINGS_H
#define SETTINGS_H
#include <QObject>
#include <QSettings>
#include "settings_headers.h"
#include "abstractsettings.h"

namespace LibQt
{
    class SETTINGS_COMMON_DLLSPEC Settings: public QObject
    {
        Q_OBJECT

    public:
        explicit Settings(QString file = "setting.ini", QObject* parent = Q_NULLPTR);
        ~Settings();
        void saveObject(AbstractSettings *object) const;
        void restoreObject(AbstractSettings *object) const;

    private:
        QSettings* settings;
    };

}
#endif // SETTINGS_H
