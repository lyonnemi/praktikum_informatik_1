#ifndef ADDSTREETDIALOG_H
#define ADDSTREETDIALOG_H

#include <QDialog>
#include <QStringList>

namespace Ui {
class AddStreetDialog;
}

class AddStreetDialog : public QDialog
{
    Q_OBJECT

public:
    explicit AddStreetDialog(QWidget *parent, const QStringList &cityNames);
    ~AddStreetDialog();

    QString getOriginName() const;
    QString getDestinationName() const;

private:
    Ui::AddStreetDialog *ui;
};

#endif // ADDSTREETDIALOG_H
