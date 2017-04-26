/****************************************************************************
* This file is part of Vibe.
 *
 * Copyright (C) 2015-2016 Pier Luigi Fiorini
 *
 * Author(s):
 *    Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPL2.1+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 2.1 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * $END_LICENSE$
 ***************************************************************************/

#ifndef STORAGEDEVICE_H
#define STORAGEDEVICE_H

#include <QtCore/QObject>
#include <QtCore/QLoggingCategory>

#include <Solid/Device>

Q_DECLARE_LOGGING_CATEGORY(DEVICE)

class StorageDevice : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString udi READ udi CONSTANT)
    Q_PROPERTY(QString name READ name CONSTANT)
    Q_PROPERTY(QString iconName READ iconName CONSTANT)
    Q_PROPERTY(QString filePath READ filePath CONSTANT)
    Q_PROPERTY(bool mounted READ isMounted NOTIFY mountedChanged)
    Q_PROPERTY(bool ignored READ isIgnored CONSTANT)
public:
    StorageDevice(const QString &udi, QObject *parent = 0);
    ~StorageDevice();

    QString udi() const;
    QString name() const;
    QString iconName() const;
    QString filePath() const;

    bool isMounted() const;
    Q_INVOKABLE void mount();
    Q_INVOKABLE void unmount();

    bool isIgnored() const;

Q_SIGNALS:
    void mountedChanged();

private:
    Solid::Device m_device;
    QString m_filePath;
    bool m_ignored;
};

#endif // STORAGEDEVICE_H
