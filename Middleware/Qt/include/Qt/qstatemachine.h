/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtCore module of the Qt Toolkit.
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

#ifndef QSTATEMACHINE_H
#define QSTATEMACHINE_H

#include <QtCore/qstate.h>

#include <QtCore/qcoreevent.h>
#include <QtCore/qlist.h>
#include <QtCore/qobject.h>
#include <QtCore/qset.h>
#include <QtCore/qvariant.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Core)

#ifndef QT_NO_STATEMACHINE

class QStateMachinePrivate;
class QAbstractAnimation;
class Q_CORE_EXPORT QStateMachine : public QState
{
    Q_OBJECT
    Q_PROPERTY(QString errorString READ errorString)
    Q_PROPERTY(RestorePolicy globalRestorePolicy READ globalRestorePolicy WRITE setGlobalRestorePolicy)
    Q_ENUMS(RestorePolicy)
#ifndef QT_NO_ANIMATION
    Q_PROPERTY(bool animated READ isAnimated WRITE setAnimated)
#endif
public:
    class Q_CORE_EXPORT SignalEvent : public QEvent
    {
    public:
        SignalEvent(QObject *sender, int signalIndex,
                     const QList<QVariant> &arguments);
        ~SignalEvent();

        inline QObject *sender() const { return m_sender; }
        inline int signalIndex() const { return m_signalIndex; }
        inline QList<QVariant> arguments() const { return m_arguments; }

    private:
        QObject *m_sender;
        int m_signalIndex;
        QList<QVariant> m_arguments;

        friend class QSignalTransitionPrivate;
    };

    class Q_CORE_EXPORT WrappedEvent : public QEvent
    {
    public:
        WrappedEvent(QObject *object, QEvent *event);
        ~WrappedEvent();

        inline QObject *object() const { return m_object; }
        inline QEvent *event() const { return m_event; }

    private:
        QObject *m_object;
        QEvent *m_event;
    };

    enum EventPriority {
        NormalPriority,
        HighPriority
    };

    enum RestorePolicy {
        DontRestoreProperties,
        RestoreProperties
    };

    enum Error {
        NoError, 
        NoInitialStateError,
        NoDefaultStateInHistoryStateError,
        NoCommonAncestorForTransitionError
    };

    QStateMachine(QObject *parent = 0);
    ~QStateMachine();

    void addState(QAbstractState *state);
    void removeState(QAbstractState *state);

    Error error() const;
    QString errorString() const;
    void clearError();

    bool isRunning() const;

#ifndef QT_NO_ANIMATION
    bool isAnimated() const;
    void setAnimated(bool enabled);

    void addDefaultAnimation(QAbstractAnimation *animation);
    QList<QAbstractAnimation *> defaultAnimations() const;
    void removeDefaultAnimation(QAbstractAnimation *animation);
#endif // QT_NO_ANIMATION

    QStateMachine::RestorePolicy globalRestorePolicy() const;
    void setGlobalRestorePolicy(QStateMachine::RestorePolicy restorePolicy);

    void postEvent(QEvent *event, EventPriority priority = NormalPriority);
    int postDelayedEvent(QEvent *event, int delay);
    bool cancelDelayedEvent(int id);

    QSet<QAbstractState*> configuration() const;

#ifndef QT_NO_STATEMACHINE_EVENTFILTER
    bool eventFilter(QObject *watched, QEvent *event);
#endif

public Q_SLOTS:
    void start();
    void stop();

Q_SIGNALS:
    void started();
    void stopped();

protected:
    void onEntry(QEvent *event);
    void onExit(QEvent *event);

    virtual void beginSelectTransitions(QEvent *event);
    virtual void endSelectTransitions(QEvent *event);

    virtual void beginMicrostep(QEvent *event);
    virtual void endMicrostep(QEvent *event);

    bool event(QEvent *e);

protected:
    QStateMachine(QStateMachinePrivate &dd, QObject *parent);

private:
    Q_DISABLE_COPY(QStateMachine)
    Q_DECLARE_PRIVATE(QStateMachine)
    Q_PRIVATE_SLOT(d_func(), void _q_start())
    Q_PRIVATE_SLOT(d_func(), void _q_process())
#ifndef QT_NO_ANIMATION
    Q_PRIVATE_SLOT(d_func(), void _q_animationFinished())
#endif
};

#endif //QT_NO_STATEMACHINE

QT_END_NAMESPACE

QT_END_HEADER

#endif
