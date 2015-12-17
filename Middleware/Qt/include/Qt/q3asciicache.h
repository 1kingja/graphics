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

#ifndef Q3ASCIICACHE_H
#define Q3ASCIICACHE_H

#include <Qt3Support/q3gcache.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Qt3SupportLight)

template<class type>
class Q3AsciiCache
#ifdef qdoc
	: public Q3PtrCollection
#else
	: public Q3GCache
#endif
{
public:
    Q3AsciiCache(const Q3AsciiCache<type> &c) : Q3GCache(c) {}
    Q3AsciiCache(int maxCost=100, int size=17, bool caseSensitive=true,
		 bool copyKeys=true)
	: Q3GCache(maxCost, size, AsciiKey, caseSensitive, copyKeys) {}
   ~Q3AsciiCache()			{ clear(); }
    Q3AsciiCache<type> &operator=(const Q3AsciiCache<type> &c)
			{ return (Q3AsciiCache<type>&)Q3GCache::operator=(c); }
    int	  maxCost()   const		{ return Q3GCache::maxCost(); }
    int	  totalCost() const		{ return Q3GCache::totalCost(); }
    void  setMaxCost(int m)		{ Q3GCache::setMaxCost(m); }
    uint  count()     const		{ return Q3GCache::count(); }
    uint  size()      const		{ return Q3GCache::size(); }
    bool  isEmpty()   const		{ return Q3GCache::count() == 0; }
    void  clear()			{ Q3GCache::clear(); }
    bool  insert(const char *k, const type *d, int c=1, int p=0)
			{ return Q3GCache::insert_other(k,(Item)d,c,p);}
    bool  remove(const char *k)
			{ return Q3GCache::remove_other(k); }
    type *take(const char *k)
			{ return (type *)Q3GCache::take_other(k); }
    type *find(const char *k, bool ref=true) const
			{ return (type *)Q3GCache::find_other(k,ref);}
    type *operator[](const char *k) const
			{ return (type *)Q3GCache::find_other(k);}
    void  statistics() const	      { Q3GCache::statistics(); }
private:
    void  deleteItem(Item d);
};

#if !defined(Q_BROKEN_TEMPLATE_SPECIALIZATION)
template<> inline void Q3AsciiCache<void>::deleteItem(Q3PtrCollection::Item)
{
}
#endif

template<class type> inline void Q3AsciiCache<type>::deleteItem(Q3PtrCollection::Item d)
{
    if (del_item) delete (type *)d;
}


template<class type>
class Q3AsciiCacheIterator : public Q3GCacheIterator
{
public:
    Q3AsciiCacheIterator(const Q3AsciiCache<type> &c):Q3GCacheIterator((Q3GCache &)c) {}
    Q3AsciiCacheIterator(const Q3AsciiCacheIterator<type> &ci)
				: Q3GCacheIterator((Q3GCacheIterator &)ci) {}
    Q3AsciiCacheIterator<type> &operator=(const Q3AsciiCacheIterator<type>&ci)
	{ return (Q3AsciiCacheIterator<type>&)Q3GCacheIterator::operator=(ci); }
    uint  count()   const     { return Q3GCacheIterator::count(); }
    bool  isEmpty() const     { return Q3GCacheIterator::count() == 0; }
    bool  atFirst() const     { return Q3GCacheIterator::atFirst(); }
    bool  atLast()  const     { return Q3GCacheIterator::atLast(); }
    type *toFirst()	      { return (type *)Q3GCacheIterator::toFirst(); }
    type *toLast()	      { return (type *)Q3GCacheIterator::toLast(); }
    operator type *() const   { return (type *)Q3GCacheIterator::get(); }
    type *current()   const   { return (type *)Q3GCacheIterator::get(); }
    const char *currentKey() const { return Q3GCacheIterator::getKeyAscii(); }
    type *operator()()	      { return (type *)Q3GCacheIterator::operator()();}
    type *operator++()	      { return (type *)Q3GCacheIterator::operator++(); }
    type *operator+=(uint j)  { return (type *)Q3GCacheIterator::operator+=(j);}
    type *operator--()	      { return (type *)Q3GCacheIterator::operator--(); }
    type *operator-=(uint j)  { return (type *)Q3GCacheIterator::operator-=(j);}
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // Q3ASCIICACHE_H
