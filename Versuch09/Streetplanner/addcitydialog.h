#ifndef ADDCITYDIALOG_H
#define ADDCITYDIALOG_H

#include <QDialog>
#include <QStringList>
#include "city.h"

namespace Ui {
class Dialog;
}

class AddCityDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddCityDialog(QWidget *parent = nullptr);
    ~AddCityDialog();

    City* getCity();

private:
    Ui::Dialog *ui;
};

#endif // ADDCITYDIALOG_H
