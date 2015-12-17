/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtGui module of the Qt Toolkit.
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

#ifndef QPIXMAPCACHE_H
#define QPIXMAPCACHE_H

#include <QtGui/qpixmap.h>

#ifdef Q_TEST_QPIXMAPCACHE
#include <QtCore/qpair.h>
#endif

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

class Q_GUI_EXPORT QPixmapCache
{
public:
    class KeyData;
    class Q_GUI_EXPORT Key
    {
    public:
        Key();
        Key(const Key &other);
        ~Key();
        bool operator ==(const Key &key) const;
        inline bool operator !=(const Key &key) const
        { return !operator==(key); }
        Key &operator =(const Key &other);

    private:
        KeyData *d;
        friend class QPMCache;
        friend class QPixmapCache;
    };

    static int cacheLimit();
    static void setCacheLimit(int);
    static QPixmap *find(const QString &key);
    static bool find(const QString &key, QPixmap &pixmap);
    static bool find(const QString &key, QPixmap *pixmap);
    static bool find(const Key &key, QPixmap *pixmap);
    static bool insert(const QString &key, const QPixmap &pixmap);
    static Key insert(const QPixmap &pixmap);
    static bool replace(const Key &key, const QPixmap &pixmap);
    static void remove(const QString &key);
    static void remove(const Key &key);
    static void clear();

#ifdef Q_TEST_QPIXMAPCACHE
    static void flushDetachedPixmaps();
    static int totalUsed();
    static QList< QPair<QString,QPixmap> > allPixmaps();
#endif
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QPIXMAPCACHE_H
