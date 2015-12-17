/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtScript module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL-ONLY$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser
** General Public License version 2.1 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL included in the
** packaging of this file.  Please review the following information to
** ensure the GNU Lesser General Public License version 2.1 requirements
** will be met: http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** If you have questions regarding the use of this file, please contact
** Nokia at qt-info@nokia.com.
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QSCRIPTEXTENSIONINTERFACE_H
#define QSCRIPTEXTENSIONINTERFACE_H

#include <QtCore/qfactoryinterface.h>

#include <QtCore/qobject.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Script)

class QScriptEngine;

struct Q_SCRIPT_EXPORT QScriptExtensionInterface
    : public QFactoryInterface
{
    virtual void initialize(const QString &key, QScriptEngine *engine) = 0;
};

Q_DECLARE_INTERFACE(QScriptExtensionInterface,
    "com.trolltech.Qt.QScriptExtensionInterface/1.0")

QT_END_NAMESPACE

QT_END_HEADER

#endif // QSCRIPTEXTENSIONINTERFACE_H
