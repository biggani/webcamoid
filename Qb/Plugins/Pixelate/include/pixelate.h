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

#ifndef PIXELATE_H
#define PIXELATE_H

#include <qb.h>

class Pixelate: public QObject, public QbPlugin
{
    Q_OBJECT
    Q_INTERFACES(QbPlugin)
    Q_PLUGIN_METADATA(IID "org.qb.plugin" FILE "pspec.json")

    public:
        QObject *create(const QString &key, const QString &specification);
        QStringList keys() const;
};

#endif // PIXELATE_H
