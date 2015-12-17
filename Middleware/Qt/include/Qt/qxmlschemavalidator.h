/****************************************************************************
**
** Copyright (C) 2008 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtXmlPatterns module of the Qt Toolkit.
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

#ifndef QXMLSCHEMAVALIDATOR_H
#define QXMLSCHEMAVALIDATOR_H

#include <QtCore/QUrl>
#include <QtXmlPatterns/QXmlNamePool>

QT_BEGIN_HEADER
QT_BEGIN_NAMESPACE

QT_MODULE(XmlPatterns)

class QAbstractMessageHandler;
class QAbstractUriResolver;
class QIODevice;
class QNetworkAccessManager;
class QUrl;
class QXmlNamePool;
class QXmlSchema;
class QXmlSchemaValidatorPrivate;

class Q_XMLPATTERNS_EXPORT QXmlSchemaValidator
{
    public:
        QXmlSchemaValidator();
        QXmlSchemaValidator(const QXmlSchema &schema);
        ~QXmlSchemaValidator();

        void setSchema(const QXmlSchema &schema);

        bool validate(const QUrl &source) const;
        bool validate(QIODevice *source, const QUrl &documentUri = QUrl()) const;
        bool validate(const QByteArray &data, const QUrl &documentUri = QUrl()) const;

        QXmlNamePool namePool() const;
        QXmlSchema schema() const;

        void setMessageHandler(QAbstractMessageHandler *handler);
        QAbstractMessageHandler *messageHandler() const;

        void setUriResolver(const QAbstractUriResolver *resolver);
        const QAbstractUriResolver *uriResolver() const;

        void setNetworkAccessManager(QNetworkAccessManager *networkmanager);
        QNetworkAccessManager *networkAccessManager() const;

    private:
        QXmlSchemaValidatorPrivate* const d;

        Q_DISABLE_COPY(QXmlSchemaValidator)
};

QT_END_NAMESPACE

QT_END_HEADER

#endif
