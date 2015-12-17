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

#ifndef QAXOBJECT_H
#define QAXOBJECT_H

#include <ActiveQt/qaxbase.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(ActiveQt)

#ifndef QT_NO_WIN_ACTIVEQT

class QAxObject : public QObject, public QAxBase
{
    friend class QAxEventSink;
public:
    const QMetaObject *metaObject() const;
    void* qt_metacast(const char*);
    int qt_metacall(QMetaObject::Call, int, void **);
    QObject* qObject() const { return (QObject*)this; }
    const char *className() const;
    
    QAxObject(QObject *parent = 0);
    QAxObject(const QString &c, QObject *parent = 0);
    QAxObject(IUnknown *iface, QObject *parent = 0);
    ~QAxObject();
    
    bool doVerb(const QString &verb);

protected:
    void connectNotify(const char *signal);

private:
    const QMetaObject *parentMetaObject() const;
    static QMetaObject staticMetaObject;
};

#if defined Q_CC_MSVC && _MSC_VER < 1300
template <> inline QAxObject *qobject_cast_helper<QAxObject*>(const QObject *o, QAxObject *)
#else
template <> inline QAxObject *qobject_cast<QAxObject*>(const QObject *o)
#endif
{
    void *result = o ? const_cast<QObject *>(o)->qt_metacast("QAxObject") : 0;
    return (QAxObject*)(result);
}

#if defined Q_CC_MSVC && _MSC_VER < 1300
template <> inline QAxObject *qobject_cast_helper<QAxObject*>(QObject *o, QAxObject *)
#else
template <> inline QAxObject *qobject_cast<QAxObject*>(QObject *o)
#endif
{
    void *result = o ? o->qt_metacast("QAxObject") : 0;
    return (QAxObject*)(result);
}

QT_END_NAMESPACE
Q_DECLARE_METATYPE(QAxObject*)

#endif // QT_NO_WIN_ACTIVEQT

QT_END_HEADER

#endif // QAXOBJECT_H
