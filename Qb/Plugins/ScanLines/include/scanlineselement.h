/* Webcamoid, webcam capture application.
 * Copyright (C) 2011-2015  Gonzalo Exequiel Pedone
 *
 * Webcamod is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * Webcamod is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with Webcamod. If not, see <http://www.gnu.org/licenses/>.
 *
 * Email   : hipersayan DOT x AT gmail DOT com
 * Web-Site: http://github.com/hipersayanX/webcamoid
 */

#ifndef SCANLINESELEMENT_H
#define SCANLINESELEMENT_H

#include <QQmlComponent>
#include <QQmlContext>
#include <qb.h>
#include <qbutils.h>

class ScanLinesElement: public QbElement
{
    Q_OBJECT
    Q_PROPERTY(int showSize
               READ showSize
               WRITE setShowSize
               RESET resetShowSize
               NOTIFY showSizeChanged)
    Q_PROPERTY(int hideSize
               READ hideSize
               WRITE setHideSize
               RESET resetHideSize
               NOTIFY hideSizeChanged)
    Q_PROPERTY(QRgb hideColor
               READ hideColor
               WRITE setHideColor
               RESET resetHideColor
               NOTIFY hideColorChanged)

    public:
        explicit ScanLinesElement();

        Q_INVOKABLE QObject *controlInterface(QQmlEngine *engine,
                                              const QString &controlId) const;

        Q_INVOKABLE int showSize() const;
        Q_INVOKABLE int hideSize() const;
        Q_INVOKABLE QRgb hideColor() const;

    private:
        int m_showSize;
        int m_hideSize;
        QRgb m_hideColor;

        QbElementPtr m_convert;

    signals:
        void showSizeChanged();
        void hideSizeChanged();
        void hideColorChanged();

    public slots:
        void setShowSize(int showSize);
        void setHideSize(int hideSize);
        void setHideColor(QRgb hideColor);
        void resetShowSize();
        void resetHideSize();
        void resetHideColor();

        QbPacket iStream(const QbPacket &packet);
};

#endif // SCANLINESELEMENT_H
