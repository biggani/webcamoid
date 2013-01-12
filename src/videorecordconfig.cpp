/* Webcamod, webcam capture plasmoid.
 * Copyright (C) 2011-2012  Gonzalo Exequiel Pedone
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
 * Email     : hipersayan DOT x AT gmail DOT com
 * Web-Site 1: http://github.com/hipersayanX/Webcamoid
 * Web-Site 2: http://kde-apps.org/content/show.php/Webcamoid?content=144796
 */

#include "ui_videorecordconfig.h"

#include "videorecordconfig.h"

VideoRecordConfig::VideoRecordConfig(MediaTools *mediaTools, QWidget *parent):
    QWidget(parent),
    ui(new Ui::VideoRecordConfig)
{
    this->m_appEnvironment = new AppEnvironment(this);

    this->ui->setupUi(this);

    this->m_mediaTools = mediaTools? mediaTools: new MediaTools(true, this);
    this->m_isInit = true;
    QVariantList videoRecordFormats = this->m_mediaTools->videoRecordFormats();

    this->ui->tbwVideoFormats->setRowCount(videoRecordFormats.length());

    int row = 0;

    foreach (QVariant fmt, videoRecordFormats)
    {
        int column = 0;

        foreach (QString param, fmt.toStringList())
        {
            this->ui->tbwVideoFormats->setItem(row,
                                           column,
                                           new QTableWidgetItem(param));

            column++;
        }

        row++;
    }

    this->m_isInit = false;
    this->ui->tbwVideoFormats->resizeRowsToContents();
    this->ui->tbwVideoFormats->resizeColumnsToContents();
}

VideoRecordConfig::~VideoRecordConfig()
{
    delete this->ui;
}

void VideoRecordConfig::update()
{
    this->ui->tbwVideoFormats->resizeRowsToContents();
    this->ui->tbwVideoFormats->resizeColumnsToContents();

    if (this->m_isInit)
        return;

    this->m_mediaTools->clearVideoRecordFormats();

    for (int row = 0; row < this->ui->tbwVideoFormats->rowCount(); row++)
    {
        QString suffix = this->ui->tbwVideoFormats->item(row, 0)->text();
        QString videoEncoder = this->ui->tbwVideoFormats->item(row, 1)->text();
        QString audioEncoder = this->ui->tbwVideoFormats->item(row, 2)->text();
        QString muxer = this->ui->tbwVideoFormats->item(row, 3)->text();

        this->m_mediaTools->setVideoRecordFormat(suffix,
                                          videoEncoder,
                                          audioEncoder,
                                          muxer);
    }
}

void VideoRecordConfig::on_btnAdd_clicked()
{
    this->ui->tbwVideoFormats->insertRow(this->ui->tbwVideoFormats->rowCount());
    this->update();
}

void VideoRecordConfig::on_btnRemove_clicked()
{
    this->ui->tbwVideoFormats->removeRow(this->ui->tbwVideoFormats->currentRow());
    this->update();
}

void VideoRecordConfig::on_btnUp_clicked()
{
    int currentRow = this->ui->tbwVideoFormats->currentRow();
    int nextRow = currentRow - 1;

    if (nextRow < 0)
        return;

    for (int column = 0; column < this->ui->tbwVideoFormats->columnCount(); column++)
    {
        QString currentText = this->ui->tbwVideoFormats->item(currentRow, column)->text();
        QString nextText = this->ui->tbwVideoFormats->item(nextRow, column)->text();

        this->ui->tbwVideoFormats->item(currentRow, column)->setText(nextText);
        this->ui->tbwVideoFormats->item(nextRow, column)->setText(currentText);
    }

    this->ui->tbwVideoFormats->
            setCurrentCell(nextRow, this->ui->tbwVideoFormats->currentColumn());

    this->update();
}

void VideoRecordConfig::on_btnDown_clicked()
{
    int currentRow = this->ui->tbwVideoFormats->currentRow();
    int nextRow = currentRow + 1;

    if (nextRow >= this->ui->tbwVideoFormats->rowCount())
        return;

    for (int column = 0; column < this->ui->tbwVideoFormats->columnCount(); column++)
    {
        QString currentText = this->ui->tbwVideoFormats->item(currentRow, column)->text();
        QString nextText = this->ui->tbwVideoFormats->item(nextRow, column)->text();

        this->ui->tbwVideoFormats->item(currentRow, column)->setText(nextText);
        this->ui->tbwVideoFormats->item(nextRow, column)->setText(currentText);
    }

    this->ui->tbwVideoFormats->
            setCurrentCell(nextRow, this->ui->tbwVideoFormats->currentColumn());

    this->update();
}

void VideoRecordConfig::on_tbwVideoFormats_cellChanged(int row, int column)
{
    Q_UNUSED(row)
    Q_UNUSED(column)

    this->update();
}