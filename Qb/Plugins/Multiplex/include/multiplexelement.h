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

#ifndef MULTIPLEXELEMENT_H
#define MULTIPLEXELEMENT_H

#include <qbelement.h>

class MultiplexElement: public QbElement
{
    Q_OBJECT
    Q_PROPERTY(int inputIndex READ inputIndex WRITE setInputIndex RESET resetInputIndex)
    Q_PROPERTY(int outputIndex READ outputIndex WRITE setOutputIndex RESET resetOutputIndex)
    Q_PROPERTY(QString caps READ caps WRITE setCaps RESET resetCaps)

    public:
        explicit MultiplexElement();

        Q_INVOKABLE int inputIndex() const;
        Q_INVOKABLE int outputIndex() const;
        Q_INVOKABLE QString caps() const;

    private:
        int m_inputIndex;
        int m_outputIndex;
        QString m_caps;

    public slots:
        void setInputIndex(int inputIndex);
        void setOutputIndex(int outputIndex);
        void setCaps(QString caps);
        void resetInputIndex();
        void resetOutputIndex();
        void resetCaps();

        QbPacket iStream(const QbPacket &packet);
};

#endif // MULTIPLEXELEMENT_H
