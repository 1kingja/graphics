/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtSCriptTools module of the Qt Toolkit.
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

#ifndef QSCRIPTENGINEDEBUGGER_H
#define QSCRIPTENGINEDEBUGGER_H

#include <QtCore/qobject.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(ScriptTools)

class QAction;
class QScriptEngine;
class QWidget;
#ifndef QT_NO_MAINWINDOW
class QMainWindow;
#endif
class QMenu;
class QToolBar;

class QScriptEngineDebuggerPrivate;
class Q_SCRIPTTOOLS_EXPORT QScriptEngineDebugger : public QObject
{
    Q_OBJECT
public:
    enum DebuggerWidget {
        ConsoleWidget,
        StackWidget,
        ScriptsWidget,
        LocalsWidget,
        CodeWidget,
        CodeFinderWidget,
        BreakpointsWidget,
        DebugOutputWidget,
        ErrorLogWidget
    };

    enum DebuggerAction {
        InterruptAction,
        ContinueAction,
        StepIntoAction,
        StepOverAction,
        StepOutAction,
        RunToCursorAction,
        RunToNewScriptAction,
        ToggleBreakpointAction,
        ClearDebugOutputAction,
        ClearErrorLogAction,
        ClearConsoleAction,
        FindInScriptAction,
        FindNextInScriptAction,
        FindPreviousInScriptAction,
        GoToLineAction
    };

    enum DebuggerState {
        RunningState,
        SuspendedState
    };

    QScriptEngineDebugger(QObject *parent = 0);
    ~QScriptEngineDebugger();

    void attachTo(QScriptEngine *engine);
    void detach();

    bool autoShowStandardWindow() const;
    void setAutoShowStandardWindow(bool autoShow);

#ifndef QT_NO_MAINWINDOW
    QMainWindow *standardWindow() const;
#endif
    QToolBar *createStandardToolBar(QWidget *parent = 0);
    QMenu *createStandardMenu(QWidget *parent = 0);

    QWidget *widget(DebuggerWidget widget) const;
    QAction *action(DebuggerAction action) const;

    DebuggerState state() const;

Q_SIGNALS:
    void evaluationSuspended();
    void evaluationResumed();

private:
    Q_DECLARE_PRIVATE(QScriptEngineDebugger)
    Q_DISABLE_COPY(QScriptEngineDebugger)

    Q_PRIVATE_SLOT(d_func(), void _q_showStandardWindow())
};

QT_END_NAMESPACE

QT_END_HEADER

#endif
