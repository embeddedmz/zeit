/* ========================================================================
*    Copyright (C) 2015-2016 Blaze <blaze@vivaldi.net>
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

#include "basedialog.h"

#ifndef BASEEDITDIALOG_H
#define BASEEDITDIALOG_H

class QLabel;

class BaseEditDialog : public BaseDialog
{
protected:
    QLabel* errorLabel = nullptr;
    void showError(const QString& errorMsg);

public:
    BaseEditDialog(QWidget *parent = nullptr);
};

#endif // BASEEDITDIALOG_H
