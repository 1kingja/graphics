/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the ActiveQt framework of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**   * Redistributions of source code must retain the above copyright
**     notice, this list of conditions and the following disclaimer.
**   * Redistributions in binary form must reproduce the above copyright
**     notice, this list of conditions and the following disclaimer in
**     the documentation and/or other materials provided with the
**     distribution.
**   * Neither the name of Nokia Corporation and its Subsidiary(-ies) nor
**     the names of its contributors may be used to endorse or promote
**     products derived from this software without specific prior written
**     permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef QAXBASE_H
#define QAXBASE_H

#include <QtCore/qdatastream.h>
#include <QtCore/qmap.h>
#include <QtCore/qobject.h>
#include <QtCore/qvariant.h>

struct IUnknown;
struct IDispatch;

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(ActiveQt)

#ifndef QT_NO_WIN_ACTIVEQT

struct QUuid;
class QAxEventSink;
class QAxObject;
class QAxBasePrivate;
struct QAxMetaObject;

class QAxBase
{
    QDOC_PROPERTY(QString control READ control WRITE setControl)

public:
    typedef QMap<QString, QVariant> PropertyBag;
    
    QAxBase(IUnknown *iface = 0);
    virtual ~QAxBase();
    
    QString control() const;
    
    long queryInterface(const QUuid &, void**) const;
    
    QVariant dynamicCall(const char *name, const QVariant &v1 = QVariant(), 
                                           const QVariant &v2 = QVariant(),
                                           const QVariant &v3 = QVariant(),
                                           const QVariant &v4 = QVariant(),
                                           const QVariant &v5 = QVariant(),
                                           const QVariant &v6 = QVariant(),
                                           const QVariant &v7 = QVariant(),
                                           const QVariant &v8 = QVariant());
    QVariant dynamicCall(const char *name, QList<QVariant> &vars);
    QAxObject *querySubObject(const char *name, const QVariant &v1 = QVariant(),
                                           const QVariant &v2 = QVariant(),
                                           const QVariant &v3 = QVariant(),
                                           const QVariant &v4 = QVariant(),
                                           const QVariant &v5 = QVariant(),
                                           const QVariant &v6 = QVariant(),
                                           const QVariant &v7 = QVariant(),
                                           const QVariant &v8 = QVariant());
    QAxObject* querySubObject(const char *name, QList<QVariant> &vars);

    virtual const QMetaObject *metaObject() const;
    virtual int qt_metacall(QMetaObject::Call, int, void **);

    virtual QObject *qObject() const = 0;
    virtual const char *className() const = 0;
    
    PropertyBag propertyBag() const;
    void setPropertyBag(const PropertyBag&);
    
    QString generateDocumentation();
    
    virtual bool propertyWritable(const char*) const;
    virtual void setPropertyWritable(const char*, bool);
    
    bool isNull() const;

    QStringList verbs() const;
    
    QVariant asVariant() const;
    
#ifdef qdoc
Q_SIGNALS:
    void signal(const QString&,int,void*);
    void propertyChanged(const QString&);
    void exception(int,const QString&,const QString&,const QString&);
#endif

public:
    virtual void clear();
    bool setControl(const QString&);

    void disableMetaObject();
    void disableClassInfo();
    void disableEventSink();

protected:
    virtual bool initialize(IUnknown** ptr);
    bool initializeRemote(IUnknown** ptr);
    bool initializeLicensed(IUnknown** ptr);
    bool initializeActive(IUnknown** ptr);
    bool initializeFromFile(IUnknown** ptr);

    void internalRelease();
    void initializeFrom(QAxBase *that);
    void connectNotify();
    long indexOfVerb(const QString &verb) const;

private:
    friend class QAxEventSink;
    friend void *qax_createObjectWrapper(int, IUnknown*);
    bool initializeLicensedHelper(void *factory, const QString &key, IUnknown **ptr);
    QAxBasePrivate *d;
    QAxMetaObject *internalMetaObject() const;
    
    virtual const QMetaObject *parentMetaObject() const = 0;
    int internalProperty(QMetaObject::Call, int index, void **v);
    int internalInvoke(QMetaObject::Call, int index, void **v);
    bool dynamicCallHelper(const char *name, void *out, QList<QVariant> &var, QByteArray &type);

    static QMetaObject staticMetaObject;
};

#if defined Q_CC_MSVC && _MSC_VER < 1300
template <> inline QAxBase *qobject_cast_helper<QAxBase*>(const QObject *o, QAxBase *)
#else
template <> inline QAxBase *qobject_cast<QAxBase*>(const QObject *o)
#endif
{
    void *result = o ? const_cast<QObject *>(o)->qt_metacast("QAxBase") : 0;
    return (QAxBase*)(result);
}

#if defined Q_CC_MSVC && _MSC_VER < 1300
template <> inline QAxBase *qobject_cast_helper<QAxBase*>(QObject *o, QAxBase *)
#else
template <> inline QAxBase *qobject_cast<QAxBase*>(QObject *o)
#endif
{
    void *result = o ? o->qt_metacast("QAxBase") : 0;
    return (QAxBase*)(result);
}

extern QString qax_generateDocumentation(QAxBase *);

inline QString QAxBase::generateDocumentation()
{
    return qax_generateDocumentation(this);
}

#ifndef QT_NO_DATASTREAM
inline QDataStream &operator >>(QDataStream &s, QAxBase &c)
{
    QAxBase::PropertyBag bag;
    c.qObject()->blockSignals(true);
    QString control;
    s >> control;
    c.setControl(control);
    s >> bag;
    c.setPropertyBag(bag);
    c.qObject()->blockSignals(false);
    
    return s;
}

inline QDataStream &operator <<(QDataStream &s, const QAxBase &c)
{
    QAxBase::PropertyBag bag = c.propertyBag();
    s << c.control();
    s << bag;
    
    return s;
}
#endif // QT_NO_DATASTREAM

QT_END_NAMESPACE

#ifndef Q_COM_METATYPE_DECLARED
#define Q_COM_METATYPE_DECLARED

Q_DECLARE_METATYPE(IUnknown*)
Q_DECLARE_METATYPE(IDispatch*)

#endif

#endif // QT_NO_WIN_ACTIVEQT

QT_END_HEADER

#endif // QAXBASE_H
