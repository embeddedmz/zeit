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

#ifndef ABOUTDIALOG_H
#define ABOUTDIALOG_H

#include <QWidget>

#include "ui_aboutdialog.h"

class AboutDialog : public QWidget
{
    Q_OBJECT

    Ui::AboutDialog *ui;
    void addText();
    void keyPressEvent(QKeyEvent *e);

public:
    explicit AboutDialog(QWidget *parent = 0);
    ~AboutDialog();
signals:
    void destroyed(bool);

private slots:
    void on_aboutQt_released();
};

#endif // ABOUTDIALOG_H
