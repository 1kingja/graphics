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

#ifndef QWSUTILS_QWS_H
#define QWSUTILS_QWS_H

#include <QtCore/QIODevice>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Gui)

#ifndef QT_NO_SXE
#define QWS_SOCK_BASE QUnixSocket
#define QWS_SOCK_SERVER_BASE QUnixSocketServer
class QUnixSocket;
class QUnixSocketServer;
#else
#define QWS_SOCK_BASE QTcpSocket
#define QWS_SOCK_SERVER_BASE QTcpServer
class QTcpSocket;
class QTcpServer;
#endif
class QWSSocket;
class QWSServerSocket;

/********************************************************************
 *
 * Convenient socket functions
 *
 ********************************************************************/
#ifndef QT_NO_QWS_MULTIPROCESS
inline int qws_read_uint(QIODevice *socket)
{
    if (!socket || socket->bytesAvailable() < (int)sizeof(int))
        return -1;

    int i;
    socket->read(reinterpret_cast<char*>(&i), sizeof(i));

    return i;
}

inline void qws_write_uint(QIODevice *socket, int i)
{
    if (!socket)
        return;

    socket->write(reinterpret_cast<char*>(&i), sizeof(i));
}

#endif // QT_NO_QWS_MULTIPROCESS

QT_END_NAMESPACE

QT_END_HEADER

#endif // QWSUTILS_QWS_H
