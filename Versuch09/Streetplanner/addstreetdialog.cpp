#include "addstreetdialog.h"
#include "ui_addstreetdialog.h"

AddStreetDialog::AddStreetDialog(QWidget *parent, const QStringList &cityNames)
    : QDialog(parent)
    , ui(new Ui::AddStreetDialog)
{
    ui->setupUi(this);
    ui->comboBox_from->addItems(cityNames);
    ui->comboBox_to->addItems(cityNames);
}

AddStreetDialog::~AddStreetDialog()
{
    delete ui;
}

QString AddStreetDialog::getOriginName() const
{
    return ui->comboBox_from->currentText();
}

QString AddStreetDialog::getDestinationName() const
{
    return ui->comboBox_to->currentText();
}