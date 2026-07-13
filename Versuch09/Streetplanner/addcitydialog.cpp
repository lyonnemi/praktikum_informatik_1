#include "addcitydialog.h"
#include "ui_addcitydialog.h"
#include <QMessageBox>

AddCityDialog::AddCityDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

AddCityDialog::~AddCityDialog()
{
    delete ui;
}

City* AddCityDialog::getCity()
{
    QString name = ui->lineEdit_name->text();

    bool xOk, yOk;
    int x = ui->lineEdit_X->text().toInt(&xOk);
    int y = ui->lineEdit_Y->text().toInt(&yOk);

    if (name.isEmpty() || !xOk || !yOk)
    {
        QMessageBox::warning(this, "Invalid input",
                             "Please enter a name and numeric X/Y coordinates.");
        return nullptr;
    }

    qDebug() << "New city entered:" << name << x << y;

    return new City(name, x, y);
}