/****************************************************************************
**
** Copyright (C) 2011 Nokia Corporation and/or its subsidiary(-ies).
** All rights reserved.
** Contact: Nokia Corporation (qt-info@nokia.com)
**
** This file is part of the QtMultimedia module of the Qt Toolkit.
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

#ifndef QVIDEOFRAME_H
#define QVIDEOFRAME_H

#include <QtCore/qmetatype.h>
#include <QtCore/qshareddata.h>
#include <QtGui/qimage.h>
#include <QtMultimedia/qabstractvideobuffer.h>

QT_BEGIN_HEADER

QT_BEGIN_NAMESPACE

QT_MODULE(Multimedia)

class QSize;
class QVariant;

class QVideoFramePrivate;

class Q_MULTIMEDIA_EXPORT QVideoFrame
{
public:
    enum FieldType
    {
        ProgressiveFrame,
        TopField,
        BottomField,
        InterlacedFrame
    };

    enum PixelFormat
    {
        Format_Invalid,
        Format_ARGB32,
        Format_ARGB32_Premultiplied,
        Format_RGB32,
        Format_RGB24,
        Format_RGB565,
        Format_RGB555,
        Format_ARGB8565_Premultiplied,
        Format_BGRA32,
        Format_BGRA32_Premultiplied,
        Format_BGR32,
        Format_BGR24,
        Format_BGR565,
        Format_BGR555,
        Format_BGRA5658_Premultiplied,

        Format_AYUV444,
        Format_AYUV444_Premultiplied,
        Format_YUV444,
        Format_YUV420P,
        Format_YV12,
        Format_UYVY,
        Format_YUYV,
        Format_NV12,
        Format_NV21,
        Format_IMC1,
        Format_IMC2,
        Format_IMC3,
        Format_IMC4,
        Format_Y8,
        Format_Y16,

        Format_User = 1000
    };

    QVideoFrame();
    QVideoFrame(QAbstractVideoBuffer *buffer, const QSize &size, PixelFormat format);
    QVideoFrame(int bytes, const QSize &size, int bytesPerLine, PixelFormat format);
    QVideoFrame(const QImage &image);
    QVideoFrame(const QVideoFrame &other);
    ~QVideoFrame();

    QVideoFrame &operator =(const QVideoFrame &other);

    bool isValid() const;

    PixelFormat pixelFormat() const;

    QAbstractVideoBuffer::HandleType handleType() const;

    QSize size() const;
    int width() const;
    int height() const;

    FieldType fieldType() const;
    void setFieldType(FieldType);

    bool isMapped() const;
    bool isReadable() const;
    bool isWritable() const;

    QAbstractVideoBuffer::MapMode mapMode() const;

    bool map(QAbstractVideoBuffer::MapMode mode);
    void unmap();

    int bytesPerLine() const;

    uchar *bits();
    const uchar *bits() const;
    int mappedBytes() const;

    QVariant handle() const;

    qint64 startTime() const;
    void setStartTime(qint64 time);

    qint64 endTime() const;
    void setEndTime(qint64 time);

    static PixelFormat pixelFormatFromImageFormat(QImage::Format format);
    static QImage::Format imageFormatFromPixelFormat(PixelFormat format);

private:
    QExplicitlySharedDataPointer<QVideoFramePrivate> d;
};

QT_END_NAMESPACE

Q_DECLARE_METATYPE(QVideoFrame::FieldType)
Q_DECLARE_METATYPE(QVideoFrame::PixelFormat)

QT_END_HEADER

#endif

