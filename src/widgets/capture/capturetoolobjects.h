// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2021 Yurii Puchkov & Contributors

#ifndef SHOTUP_CAPTURETOOLOBJECTS_H
#define SHOTUP_CAPTURETOOLOBJECTS_H

#include "src/tools/capturetool.h"
#include <QList>
#include <QPointer>

class CaptureToolObjects : public QObject
{
public:
    explicit CaptureToolObjects(QObject* parent = nullptr);
    QList<QPointer<CaptureTool>> captureToolObjects();
    void append(const QPointer<CaptureTool>& captureTool);
    void insert(int index, const QPointer<CaptureTool>& captureTool);
    void removeAt(int index);
    void clear();
    int size();
    int find(const QPoint& pos, QSize captureSize);
    QPointer<CaptureTool> at(int index);
    CaptureToolObjects& operator=(const CaptureToolObjects& other);

private:
    int findWithRadius(QPainter& painter,
                       QPixmap& pixmap,
                       const QPoint& pos,
                       int radius = 0);

    // class members
    QList<QPointer<CaptureTool>> m_captureToolObjects;
    QVector<QImage> m_imageCache;
};

#endif // SHOTUP_CAPTURETOOLOBJECTS_H
