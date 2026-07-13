#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QlineEdit>
#include <QPushButton>
#include <QMessageBox>
#include <QGraphicsScene>
#include <QRandomGenerator>
#include "map.h"
#include "mapio.h"
#include "mapionrw.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr, MapIo* mapio = new MapIoNrw());
    ~MainWindow() override;

private slots:
    void on_pushButton_teste_was_clicked();

    void on_actionExit_triggered();

    void on_actionClearScene_triggered();

    void on_actionAbout_triggered();

    void on_pushBottonTestDrawCity_clicked();

    void on_pushButtonTestDrawMap_clicked();

    void on_pushButtonTestDrawStreet_clicked();

    void on_checkBoxTest_clicked();

    void on_pushButtonAddCity_clicked();

    void on_pushButtonFillMap_clicked();

    void on_pushButtonTestAbstractMap_clicked();

    void on_pushButtonDijkstra_clicked();

    void on_pushButtonFindRoute_clicked();

    void on_pushButtonAddStreet_clicked();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Map map;
    MapIo* mapio;
};
#endif // MAINWINDOW_H
