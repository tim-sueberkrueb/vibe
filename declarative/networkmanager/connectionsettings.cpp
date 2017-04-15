/****************************************************************************
 * This file is part of Vibe.
 *
 * Copyright (C) 2017 Pier Luigi Fiorini <pierluigi.fiorini@gmail.com>
 *
 * $BEGIN_LICENSE:LGPLv3+$
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
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

#include <NetworkManagerQt/Settings>
#include <NetworkManagerQt/WiredSetting>

#include "connectionsettings.h"

#include <sys/types.h>
#include <unistd.h>
#include <pwd.h>

ConnectionSettings::ConnectionSettings(QObject *parent)
    : QObject(parent)
{
}

QString ConnectionSettings::path() const
{
    return m_path;
}

void ConnectionSettings::setPath(const QString &path)
{
    if (m_path == path)
        return;

    m_path = path;
    Q_EMIT pathChanged();

    m_connection = NetworkManager::findConnection(m_path);
    if (m_connection) {
        m_settings = m_connection->settings();
        Q_EMIT autoConnectChanged();
        Q_EMIT availableToOtherUsersChanged();
        handlePathChanged();
        Q_EMIT settingsAvailable();
    } else {
        m_settings.reset();
    }
}

bool ConnectionSettings::autoConnect() const
{
    if (m_settings)
        return m_settings->autoconnect();
    else
        qWarning("NetworkManager settings are invalid");
    return false;
}

void ConnectionSettings::setAutoConnect(bool value)
{
    if (m_settings) {
        if (this->autoConnect() == value)
            return;
        m_settings->setAutoconnect(value);
        m_connection->save();
        Q_EMIT autoConnectChanged();
    } else {
        qWarning("NetworkManager settings are invalid");
    }
}

bool ConnectionSettings::availableToOtherUsers() const
{
    if (m_settings)
        return m_settings->permissions().isEmpty();
    else
        qWarning("NetworkManager settings are invalid");
    return false;
}

void ConnectionSettings::setAvailableToOtherUsers(bool value)
{
    if (m_settings) {
        bool availableToOtherUsers = m_settings->permissions().isEmpty();
        if (availableToOtherUsers == value)
            return;

        if (value)
            m_settings->setPermissions(QHash<QString, QString>());
        else
            m_settings->addToPermissions(getCurrentUserName(), QString());
        m_connection->save();
        Q_EMIT availableToOtherUsersChanged();
    } else {
        qWarning("NetworkManager settings are invalid");
    }
}

QString ConnectionSettings::getCurrentUserName() const
{
    uid_t uid = ::geteuid();
    struct passwd *pw = ::getpwuid(uid);
    if (pw)
        return QString::fromLocal8Bit(pw->pw_name);
    return QString();
}
