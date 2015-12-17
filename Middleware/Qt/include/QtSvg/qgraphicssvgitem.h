/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtSvg module of the Qt Toolkit.
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
#ifndef QGRAPHICSSVGITEM_H
#define QGRAPHICSSVGITEM_H

#include <QtGui/qgraphicsitem.h>

#ifndef QT_NO_GRAPHICSSVGITEM

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Svg)

class QSvgRenderer;
class QGraphicsSvgItemPrivate;

class Q_SVG_EXPORT QGraphicsSvgItem : public QGraphicsObject
{
    Q_OBJECT
    Q_INTERFACES(QGraphicsItem)
    Q_PROPERTY(QString elementId READ elementId WRITE setElementId)
    Q_PROPERTY(QSize maximumCacheSize READ maximumCacheSize WRITE setMaximumCacheSize)

public:
    QGraphicsSvgItem(QGraphicsItem *parentItem=0);
    QGraphicsSvgItem(const QString &fileName, QGraphicsItem *parentItem=0);

    void setSharedRenderer(QSvgRenderer *renderer);
    QSvgRenderer *renderer() const;

    void setElementId(const QString &id);
    QString elementId() const;

    void setCachingEnabled(bool);
    bool isCachingEnabled() const;

    void setMaximumCacheSize(const QSize &size);
    QSize maximumCacheSize() const;

    virtual QRectF boundingRect() const;

    virtual void paint(QPainter *painter,
                       const QStyleOptionGraphicsItem *option,
                       QWidget *widget=0);

    enum { Type = 13 };
    virtual int type() const;

private:
    Q_DISABLE_COPY(QGraphicsSvgItem)
    Q_DECLARE_PRIVATE_D(QGraphicsItem::d_ptr.data(), QGraphicsSvgItem)

    Q_PRIVATE_SLOT(d_func(), void _q_repaintItem())
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // QT_NO_GRAPHICSSVGITEM
#endif // QGRAPHICSSVGITEM_H
