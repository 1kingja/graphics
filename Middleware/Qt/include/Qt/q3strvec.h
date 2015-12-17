/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt3Support module of the Qt Toolkit.
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

#ifndef Q3STRVEC_H
#define Q3STRVEC_H

#include <QtCore/qstring.h>
#include <Qt3Support/q3ptrvector.h>
#include <QtCore/qdatastream.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Qt3SupportLight)

class Q3StrVec : public Q3PtrVector<char>
{
public:
    Q3StrVec()  { dc = true; }
    Q3StrVec( uint size, bool deepc = true ) : Q3PtrVector<char>(size) {dc=deepc;}
   ~Q3StrVec()  { clear(); }
private:
    Item	 newItem( Item d )	{ return dc ? qstrdup( (const char*)d ) : d; }
    void deleteItem( Item d )	{ if ( dc ) delete[] (char*)d; }
    int	 compareItems( Item s1, Item s2 )
				{ return qstrcmp((const char*)s1,
						(const char*)s2); }
#ifndef QT_NO_DATASTREAM
    QDataStream &read( QDataStream &s, Item &d )
				{ s >> (char *&)d; return s; }
    QDataStream &write( QDataStream &s, Item d ) const
				{ return s << (const char*)d; }
#endif
    bool dc;
};


class Q3StrIVec : public Q3StrVec	// case insensitive string vec
{
public:
    Q3StrIVec() {}
    Q3StrIVec( uint size, bool dc = true ) : Q3StrVec( size, dc ) {}
   ~Q3StrIVec() { clear(); }
private:
    int	 compareItems( Item s1, Item s2 )
				{ return qstricmp((const char*)s1,
						 (const char*)s2); }
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // Q3STRVEC_H
