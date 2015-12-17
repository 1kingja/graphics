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

#ifndef QMATRIX_H
#define QMATRIX_H

#include <QtGui/qpolygon.h>
#include <QtGui/qregion.h>
#include <QtGui/qwindowdefs.h>
#include <QtCore/qline.h>
#include <QtCore/qpoint.h>
#include <QtCore/qrect.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

class QPainterPath;
class QVariant;

class Q_GUI_EXPORT QMatrix // 2D transform matrix
{
public:
    inline explicit QMatrix(Qt::Initialization) {}
    QMatrix();
    QMatrix(qreal m11, qreal m12, qreal m21, qreal m22,
            qreal dx, qreal dy);
    QMatrix(const QMatrix &matrix);

    void setMatrix(qreal m11, qreal m12, qreal m21, qreal m22,
                   qreal dx, qreal dy);

    qreal m11() const { return _m11; }
    qreal m12() const { return _m12; }
    qreal m21() const { return _m21; }
    qreal m22() const { return _m22; }
    qreal dx() const { return _dx; }
    qreal dy() const { return _dy; }

    void map(int x, int y, int *tx, int *ty) const;
    void map(qreal x, qreal y, qreal *tx, qreal *ty) const;
    QRect mapRect(const QRect &) const;
    QRectF mapRect(const QRectF &) const;

    QPoint map(const QPoint &p) const;
    QPointF map(const QPointF&p) const;
    QLine map(const QLine &l) const;
    QLineF map(const QLineF &l) const;
    QPolygonF map(const QPolygonF &a) const;
    QPolygon map(const QPolygon &a) const;
    QRegion map(const QRegion &r) const;
    QPainterPath map(const QPainterPath &p) const;
    QPolygon mapToPolygon(const QRect &r) const;

    void reset();
    inline bool isIdentity() const;

    QMatrix &translate(qreal dx, qreal dy);
    QMatrix &scale(qreal sx, qreal sy);
    QMatrix &shear(qreal sh, qreal sv);
    QMatrix &rotate(qreal a);

    bool isInvertible() const { return !qFuzzyIsNull(_m11*_m22 - _m12*_m21); }
    qreal determinant() const { return _m11*_m22 - _m12*_m21; }
#ifdef QT_DEPRECATED
    QT_DEPRECATED qreal det() const { return _m11*_m22 - _m12*_m21; }
#endif

    QMatrix inverted(bool *invertible = 0) const;

    bool operator==(const QMatrix &) const;
    bool operator!=(const QMatrix &) const;

    QMatrix &operator*=(const QMatrix &);
    QMatrix operator*(const QMatrix &o) const;

    QMatrix &operator=(const QMatrix &);

    operator QVariant() const;

#ifdef QT3_SUPPORT
    inline QT3_SUPPORT QMatrix invert(bool *invertible=0) const { return inverted(invertible); }
    inline QT3_SUPPORT QRect map(const QRect &r) const { return mapRect(r); }
    QT3_SUPPORT QRegion mapToRegion(const QRect &r) const;
#endif

private:
    inline QMatrix(bool)
            : _m11(1.)
            , _m12(0.)
            , _m21(0.)
            , _m22(1.)
            , _dx(0.)
            , _dy(0.) {}
    inline QMatrix(qreal am11, qreal am12, qreal am21, qreal am22, qreal adx, qreal ady, bool)
            : _m11(am11)
            , _m12(am12)
            , _m21(am21)
            , _m22(am22)
            , _dx(adx)
            , _dy(ady) {}
    friend class QTransform;
    qreal _m11, _m12;
    qreal _m21, _m22;
    qreal _dx, _dy;
};
Q_DECLARE_TYPEINFO(QMatrix, Q_MOVABLE_TYPE);

// mathematical semantics
Q_GUI_EXPORT_INLINE QPoint operator*(const QPoint &p, const QMatrix &m)
{ return m.map(p); }
Q_GUI_EXPORT_INLINE QPointF operator*(const QPointF &p, const QMatrix &m)
{ return m.map(p); }
Q_GUI_EXPORT_INLINE QLineF operator*(const QLineF &l, const QMatrix &m)
{ return m.map(l); }
Q_GUI_EXPORT_INLINE QLine operator*(const QLine &l, const QMatrix &m)
{ return m.map(l); }
Q_GUI_EXPORT_INLINE QPolygon operator *(const QPolygon &a, const QMatrix &m)
{ return m.map(a); }
Q_GUI_EXPORT_INLINE QPolygonF operator *(const QPolygonF &a, const QMatrix &m)
{ return m.map(a); }
Q_GUI_EXPORT_INLINE QRegion operator *(const QRegion &r, const QMatrix &m)
{ return m.map(r); }
Q_GUI_EXPORT QPainterPath operator *(const QPainterPath &p, const QMatrix &m);

inline bool QMatrix::isIdentity() const
{
    return qFuzzyIsNull(_m11 - 1) && qFuzzyIsNull(_m22 - 1) && qFuzzyIsNull(_m12)
           && qFuzzyIsNull(_m21) && qFuzzyIsNull(_dx) && qFuzzyIsNull(_dy);
}

inline bool qFuzzyCompare(const QMatrix& m1, const QMatrix& m2)
{
    return qFuzzyCompare(m1.m11(), m2.m11())
        && qFuzzyCompare(m1.m12(), m2.m12())
        && qFuzzyCompare(m1.m21(), m2.m21())
        && qFuzzyCompare(m1.m22(), m2.m22())
        && qFuzzyCompare(m1.dx(), m2.dx())
        && qFuzzyCompare(m1.dy(), m2.dy());
}


/*****************************************************************************
 QMatrix stream functions
 *****************************************************************************/

#ifndef QT_NO_DATASTREAM
Q_GUI_EXPORT QDataStream &operator<<(QDataStream &, const QMatrix &);
Q_GUI_EXPORT QDataStream &operator>>(QDataStream &, QMatrix &);
#endif

#ifndef QT_NO_DEBUG_STREAM
Q_GUI_EXPORT QDebug operator<<(QDebug, const QMatrix &);
#endif

#ifdef QT3_SUPPORT
QT_BEGIN_INCLUDE_NAMESPACE
#include <QtGui/qwmatrix.h>
QT_END_INCLUDE_NAMESPACE
#endif

QT_END_NAMESPACE

QT_END_HEADER

#endif // QMATRIX_H
