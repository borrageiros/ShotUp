// SPDX-License-Identifier: GPL-3.0-or-later
// SPDX-FileCopyrightText: 2017-2019 Alejandro Sirgo Rica & Contributors

#include "shotupdbusadapter.h"
#include "src/core/shotupdaemon.h"

ShotupDBusAdapter::ShotupDBusAdapter(QObject* parent)
  : QDBusAbstractAdaptor(parent)
{}

ShotupDBusAdapter::~ShotupDBusAdapter() = default;

void ShotupDBusAdapter::attachScreenshotToClipboard(const QByteArray& data)
{
    ShotupDaemon::instance()->attachScreenshotToClipboard(data);
}

void ShotupDBusAdapter::attachTextToClipboard(const QString& text,
                                                 const QString& notification)
{
    ShotupDaemon::instance()->attachTextToClipboard(text, notification);
}

void ShotupDBusAdapter::attachPin(const QByteArray& data)
{
    ShotupDaemon::instance()->attachPin(data);
}
