/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Designer of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** GNU Lesser General Public License Usage
** This file may be used under the terms of the GNU Lesser General Public
** License version 2.1 as published by the Free Software Foundation and
** appearing in the file LICENSE.LGPL included in the packaging of this
** file. Please review the following information to ensure the GNU Lesser
** General Public License version 2.1 requirements will be met:
** http://www.gnu.org/licenses/old-licenses/lgpl-2.1.html.
**
** In addition, as a special exception, Nokia gives you certain additional
** rights. These rights are described in the Nokia Qt LGPL Exception
** version 1.1, included in the file LGPL_EXCEPTION.txt in this package.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU General
** Public License version 3.0 as published by the Free Software Foundation
** and appearing in the file LICENSE.GPL included in the packaging of this
** file. Please review the following information to ensure the GNU General
** Public License version 3.0 requirements will be met:
** http://www.gnu.org/copyleft/gpl.html.
**
** Other Usage
** Alternatively, this file may be used in accordance with the terms and
** conditions contained in a signed written agreement between you and Nokia.
**
**
**
**
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef ABSTRACTICONCACHE_H
#define ABSTRACTICONCACHE_H

#include <QtDesigner/sdk_global.h>

#include <QtCore/QObject>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class QIcon;
class QPixmap;
class QString;

class QDESIGNER_SDK_EXPORT QDesignerIconCacheInterface : public QObject
{
    Q_OBJECT
public:
    QDesignerIconCacheInterface(QObject *parent_)
        : QObject(parent_) {}

    virtual QIcon nameToIcon(const QString &filePath, const QString &qrcPath = QString()) = 0;
    virtual QPixmap nameToPixmap(const QString &filePath, const QString &qrcPath = QString()) = 0;

    virtual QString iconToFilePath(const QIcon &pm) const = 0;
    virtual QString iconToQrcPath(const QIcon &pm) const = 0;

    virtual QString pixmapToFilePath(const QPixmap &pm) const = 0;
    virtual QString pixmapToQrcPath(const QPixmap &pm) const = 0;

    virtual QList<QPixmap> pixmapList() const = 0;
    virtual QList<QIcon> iconList() const = 0;

    virtual QString resolveQrcPath(const QString &filePath, const QString &qrcPath, const QString &workingDirectory = QString()) const = 0;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // ABSTRACTICONCACHE_H
