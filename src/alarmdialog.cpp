/* ========================================================================
*    Copyright (C) 2015 Blaze <blaze@open.by>
*
*    This file is part of Zeit.
*
*    Zeit is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.
*
*    Zeit is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.
*
*    You should have received a copy of the GNU General Public License
*    along with Zeit.  If not, see <http://www.gnu.org/licenses/>.
* ======================================================================== */

#include <QProcess>
#include <QFileDialog>

#include "cttask.h"
#include "alarmdialog.h"
#include "ui_alarmdialog.h"

AlarmDialog::AlarmDialog(CTTask* _ctTask, const QString& _caption, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlarmDialog)
{
    task = _ctTask;
    ui->setupUi(this);
    setWindowTitle(_caption);
    ui->checkBoxMon->setChecked(true);
    ui->checkBoxTue->setChecked(true);
    ui->checkBoxWed->setChecked(true);
    ui->checkBoxThu->setChecked(true);
    ui->checkBoxFri->setChecked(true);
    ui->lineEditComment->setText(tr("Undefined"));
    // detect player
    QProcess proc;
    proc.start("which", QStringList() << "mpv");
    proc.waitForFinished(-1);
    ui->lineEditPlayer->setText(QString::fromUtf8(proc.readAllStandardOutput())
                                                  .remove(QRegExp("[\n\t\r]")));
    // ButtonBox action
    connect(this, SIGNAL(accepted()), SLOT(saveTask()));
    // FileDialog actions
    connect(ui->pushButtonSoundFile, SIGNAL(released()), SLOT(showFileDialog()));
    connect(ui->pushButtonPlayer, SIGNAL(released()), SLOT(showPlayerDialog()));
}

AlarmDialog::~AlarmDialog()
{
    delete ui;
}

void AlarmDialog::saveTask() {
    task->comment = ui->lineEditComment->text();
    task->command = QString("%1 %2").arg(ui->lineEditPlayer->text())
                                    .arg(ui->lineEditSoundFile->text());
    task->hour.setEnabled(ui->spinBoxHour->value(), true);
    task->minute.setEnabled(ui->spinBoxMinute->value(), true);
    task->dayOfWeek.setEnabled(1, ui->checkBoxMon->isChecked());
    task->dayOfWeek.setEnabled(2, ui->checkBoxTue->isChecked());
    task->dayOfWeek.setEnabled(3, ui->checkBoxWed->isChecked());
    task->dayOfWeek.setEnabled(4, ui->checkBoxThu->isChecked());
    task->dayOfWeek.setEnabled(5, ui->checkBoxFri->isChecked());
    task->dayOfWeek.setEnabled(6, ui->checkBoxSat->isChecked());
    task->dayOfWeek.setEnabled(7, ui->checkBoxSun->isChecked());
    for(int dm = 1; dm <= 31; dm++)
        task->dayOfMonth.setEnabled(dm, true);
    for(int mo = CTMonth::MINIMUM; mo <= CTMonth::MAXIMUM; mo++)
        task->month.setEnabled(mo, true);
}

void AlarmDialog::showFileDialog() {
    QStringList file = QFileDialog::getOpenFileNames(this, "Sound file", "",
                                            "Media (*.wav *.ogg *.mp3 *.flac)");
    if(file.length() > 0)
        ui->lineEditSoundFile->setText(file.at(0));
}

void AlarmDialog::showPlayerDialog() {
    QStringList file = QFileDialog::getOpenFileNames(this,"Executable","/usr/bin","");
    if(file.length() > 0)
        ui->lineEditPlayer->setText(file.at(0));
}