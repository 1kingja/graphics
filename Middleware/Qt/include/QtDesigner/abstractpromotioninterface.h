/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the Qt Designer of the Qt Toolkit.
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

#ifndef ABSTRACTPROMOTIONINTERFACE_H
#define ABSTRACTPROMOTIONINTERFACE_H

#include <QtDesigner/sdk_global.h>

#include <QtCore/QPair>
#include <QtCore/QList>
#include <QtCore/QSet>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

class QDesignerWidgetDataBaseItemInterface;

class QDESIGNER_SDK_EXPORT QDesignerPromotionInterface
{
public:
    virtual ~QDesignerPromotionInterface();

    struct PromotedClass {
        QDesignerWidgetDataBaseItemInterface *baseItem;
        QDesignerWidgetDataBaseItemInterface *promotedItem;
    };

    typedef QList<PromotedClass> PromotedClasses;

    virtual PromotedClasses promotedClasses() const = 0;

    virtual QSet<QString> referencedPromotedClassNames()  const = 0;

    virtual bool addPromotedClass(const QString &baseClass,
                                  const QString &className,
                                  const QString &includeFile,
                                  QString *errorMessage) = 0;

    virtual bool removePromotedClass(const QString &className, QString *errorMessage) = 0;

    virtual bool changePromotedClassName(const QString &oldClassName, const QString &newClassName, QString *errorMessage) = 0;

    virtual bool setPromotedClassIncludeFile(const QString &className, const QString &includeFile, QString *errorMessage) = 0;

    virtual QList<QDesignerWidgetDataBaseItemInterface *> promotionBaseClasses() const = 0;
};

QT_END_NAMESPACE

QT_END_HEADER

#endif // ABSTRACTPROMOTIONINTERFACE_H
