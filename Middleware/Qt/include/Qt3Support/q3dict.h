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

#ifndef Q3DICT_H
#define Q3DICT_H

#include <Qt3Support/q3gdict.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Qt3SupportLight)

template<class type>
class Q3Dict
#ifdef qdoc
	: public Q3PtrCollection
#else
	: public Q3GDict
#endif
{
public:
    Q3Dict(int size = 17, bool caseSensitive = true)
	: Q3GDict(size, StringKey, caseSensitive, false) { }
    Q3Dict(const Q3Dict<type> &d) : Q3GDict(d) { }
    ~Q3Dict()				{ clear(); }
    Q3Dict<type> &operator=(const Q3Dict<type> &d)
			{ return (Q3Dict<type>&)Q3GDict::operator=(d); }
    uint  count()   const		{ return Q3GDict::count(); }
    uint  size()    const		{ return Q3GDict::size(); }
    bool  isEmpty() const		{ return Q3GDict::count() == 0; }

    void  insert(const QString &k, const type *d)
					{ Q3GDict::look_string(k,(Item)d,1); }
    void  replace(const QString &k, const type *d)
					{ Q3GDict::look_string(k,(Item)d,2); }
    bool  remove(const QString &k)	{ return Q3GDict::remove_string(k); }
    type *take(const QString &k)	{ return (type *)Q3GDict::take_string(k); }
    type *find(const QString &k) const
		{ return (type *)((Q3GDict*)this)->Q3GDict::look_string(k,0,0); }
    type *operator[](const QString &k) const
		{ return (type *)((Q3GDict*)this)->Q3GDict::look_string(k,0,0); }

    void  clear()			{ Q3GDict::clear(); }
    void  resize(uint n)		{ Q3GDict::resize(n); }
    void  statistics() const		{ Q3GDict::statistics(); }

#ifdef qdoc
protected:
    virtual QDataStream& read(QDataStream &, Q3PtrCollection::Item &);
    virtual QDataStream& write(QDataStream &, Q3PtrCollection::Item) const;
#endif

private:
	void  deleteItem(Item d);
};

#if !defined(Q_BROKEN_TEMPLATE_SPECIALIZATION)
template<> inline void Q3Dict<void>::deleteItem(Item)
{
}
#endif

template<class type> inline void Q3Dict<type>::deleteItem(Q3PtrCollection::Item d)
{
    if (del_item) delete (type *)d;
}

template<class type>
class Q3DictIterator : public Q3GDictIterator
{
public:
    Q3DictIterator(const Q3Dict<type> &d) : Q3GDictIterator((Q3GDict &)d) { }
    ~Q3DictIterator()	      {}
    uint  count()   const     { return dict->count(); }
    bool  isEmpty() const     { return dict->count() == 0; }
    type *toFirst()	      { return (type *)Q3GDictIterator::toFirst(); }
    operator type *() const   { return (type *)Q3GDictIterator::get(); }
    type *operator*()         { return (type *)Q3GDictIterator::get(); }
    type   *current() const   { return (type *)Q3GDictIterator::get(); }
    QString currentKey() const{ return Q3GDictIterator::getKeyString(); }
    type *operator()()	      { return (type *)Q3GDictIterator::operator()(); }
    type *operator++()	      { return (type *)Q3GDictIterator::operator++(); }
    type *operator+=(uint j)  { return (type *)Q3GDictIterator::operator+=(j); }
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // Q3DICT_H
