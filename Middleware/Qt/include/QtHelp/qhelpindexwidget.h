/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Assistant of the Qt Toolkit.
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

#ifndef QHELPINDEXWIDGET_H
#define QHELPINDEXWIDGET_H

#include <QtHelp/qhelp_global.h>

#include <QtCore/QUrl>
#include <QtGui/QStringListModel>
#include <QtGui/QListView>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Help)

class QHelpEnginePrivate;
class QHelpIndexModelPrivate;

class QHELP_EXPORT QHelpIndexModel : public QStringListModel
{
    Q_OBJECT

public:
    void createIndex(const QString &customFilterName);
    QModelIndex filter(const QString &filter,
        const QString &wildcard = QString());

    QMap<QString, QUrl> linksForKeyword(const QString &keyword) const;
    bool isCreatingIndex() const;

Q_SIGNALS:
    void indexCreationStarted();
    void indexCreated();

private Q_SLOTS:
    void insertIndices();
    void invalidateIndex(bool onShutDown = false);

private:
    QHelpIndexModel(QHelpEnginePrivate *helpEngine);
    ~QHelpIndexModel();

    QHelpIndexModelPrivate *d;
    friend class QHelpEnginePrivate;
};

class QHELP_EXPORT QHelpIndexWidget : public QListView
{
    Q_OBJECT

Q_SIGNALS:
    void linkActivated(const QUrl &link, const QString &keyword);
    void linksActivated(const QMap<QString, QUrl> &links,
        const QString &keyword);

public Q_SLOTS:
    void filterIndices(const QString &filter,
        const QString &wildcard = QString());
    void activateCurrentItem();

private Q_SLOTS:
    void showLink(const QModelIndex &index);

private:
    QHelpIndexWidget();
    friend class QHelpEngine;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif
