#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "city.h"
#include "street.h"
#include "addcitydialog.h"
#include "addstreetdialog.h"
#include "mapionrw.h"
#include "dijkstra.h"
#include <QDebug>

MainWindow::MainWindow(QWidget *parent, MapIo* mapio)
    : QMainWindow(parent),
    ui(new Ui::MainWindow),
    mapio(mapio)
{
    ui->setupUi(this);

    scene = new QGraphicsScene(this); //szene erstellen

    ui->graphicsView->setScene(scene); //szene zeichnen
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_teste_was_clicked()
{
    qDebug() << "Button Clicked!";
    bool ok;


    QString eingabe = ui->lineEdit->text();
    int zahl = eingabe.toInt(&ok);
    QMessageBox msgBox;

    if (ok){
        zahl = zahl + 4;
        QString ausgabe = QString("Ihre Eingabe: %1 | Modifiziert: %2 ").arg(eingabe).arg(zahl);
        msgBox.setText(ausgabe);
    } else{
        QString ausgabe = QString("Ihre Eingabe: %1").arg(eingabe);
        msgBox.setText(ausgabe);
    }

    int x = QRandomGenerator::global()->bounded(1000);
    int y = QRandomGenerator::global()->bounded(1000);

    scene->addRect(x, y, 20, 20, QPen(Qt::black), QBrush(Qt::blue, Qt::SolidPattern));



}


void MainWindow::on_actionExit_triggered()
{
    close();
}



void MainWindow::on_actionClearScene_triggered()
{
    scene->clear();
}


void MainWindow::on_actionAbout_triggered()
{
    QMessageBox::about(this, "About Streetplanner",
                       "Streetplanner\n\n"
                       "A simple map application built with Qt.\n"
                       "Add cities and streets, then find the shortest path between them.");
}


void MainWindow::on_pushBottonTestDrawCity_clicked()
{
    City city1("Aachen", 100, 100);
    City city2("Cologne", 250, 180);

    city1.draw(*scene);
    city2.draw(*scene);
}


void MainWindow::on_pushButtonTestDrawMap_clicked()
{
    City c1("city c1", 20,50);
    map.addCity(&c1);
    map.draw(*scene);
}


void MainWindow::on_pushButtonTestDrawStreet_clicked()
{
    City* city1 = new City("Munich", 80, 50);
    City* city2 = new City("Hamburg", 20, 200);
    city1->draw(*scene);
    city2->draw(*scene);
    Street street(city1, city2);
    street.draw(*scene);

}





void MainWindow::on_checkBoxTest_clicked()
{
    bool hide = ui->checkBoxTest->isChecked();

    if (hide)
    {
        ui->pushBottonTestDrawCity->hide();
        ui->pushButtonTestDrawMap->hide();
        ui->pushButtonTestDrawStreet->hide();
        ui->pushButton_teste_was->hide();
        // ...repeat for every other test button you've added
    }
    else
    {
        ui->pushBottonTestDrawCity->show();
        ui->pushButtonTestDrawMap->show();
        ui->pushButtonTestDrawStreet->show();
        ui->pushButton_teste_was->show();
        // ...repeat for every other test button you've added
    }
}


void MainWindow::on_pushButtonAddCity_clicked()
{
    while(true){
        AddCityDialog dialog(this);
        int result = dialog.exec();

        qDebug() << "Dialog result: " << result;

        if (result != 1) {
            break;
        }

        City* newCity = dialog.getCity();

        if (newCity == nullptr) {
            continue;
        }

        map.addCity(newCity);
        map.draw(*scene);
        break;
    }
}


void MainWindow::on_pushButtonFillMap_clicked()
{
    mapio->fillMap(map);
    map.draw(*scene);
}


void MainWindow::on_pushButtonTestAbstractMap_clicked()
{
    Map testMap;
    City *a = new City("a", 0, 0);
    City *b = new City("b", 0, 100);
    City *c = new City("c", 100, 300);
    Street *s = new Street(a, b);
    Street *s2 = new Street(b, c);


    qDebug() << "MapTest: Start Test of the Map";
    {
        qDebug() << "MapTest: adding wrong street";
        bool t1 = testMap.addStreet(s);
        if (t1) {
            qDebug() << "-Error: Street should not bee added, if cities have not been added.";
        }
    }

    {
        qDebug() << "MapTest: adding correct street";
        testMap.addCity(a);
        testMap.addCity(b);
        bool t1 = testMap.addStreet(s);
        if (!t1) {
            qDebug() << "-Error: It should be possible to add this street.";
        }
    }

    {
        qDebug() << "MapTest: findCity";
        City* city = testMap.findCity("a");
        if (city != a)
            qDebug() << "-Error: City a could not be found.";

        city = testMap.findCity("b");
        if (city != b)
            qDebug() << "-Error: City b could not be found.";

        city = testMap.findCity("c");
        if (city != nullptr)
            qDebug() << "-Error: If city could not be found 0 should be returned.";
    }

    testMap.addCity(c);
    testMap.addStreet(s2);

    {
        qDebug() << "MapTest: getOppositeCity";
        const City *city = testMap.getOppositeCity(s, a);
        if (city != b)
            qDebug() << "-Error: Opposite city should be b.";

        city = map.getOppositeCity(s, c);
        if (city != nullptr)
            qDebug() << "-Error: Opposite city for a city which is not linked by given street should be 0.";
    }

    {
        qDebug() << "MapTest: streetLength";
        double l = testMap.getLength(s2);
        double expectedLength = 223.6;
        // compare doubles with 5% tolerance
        if (l < expectedLength * 0.95 || l > expectedLength *1.05)
            qDebug() << "-Error: Street Length is not equal to the expected.";

    }

    {
        qDebug() << "MapTest: getStreetList";
        QVector<Street*> streetList1 = testMap.getStreetList(a);
        QVector<Street*> streetList2 = testMap.getStreetList(b);
        if (streetList1.size() != 1) {
            qDebug() << "-Error: One street should be found for city a.";
        }
        else if (*streetList1.begin() != s) {
            qDebug() << "-Error: The wrong street has been found for city a.";
        }

        if (streetList2.size() != 2)
            qDebug() << "-Error: Two streets should be found for city b.";
    }

    qDebug() << "MapTest: End Test of the Map.";
}


void MainWindow::on_pushButtonDijkstra_clicked()
{
    QVector<Street*> path = Dijkstra::search(map, "Aachen", "Bonn");   // use real names from your map

    if (path.isEmpty())
    {
        qDebug() << "No path found (bad city name, or no connection).";
        return;
    }

    qDebug() << "Path found," << path.size() << "streets:";
    for (Street* street : path)
    {
        qDebug() << street->getOrigin()->getName() << "->" << street->getEnd()->getName();
        for (Street* street : path)
        {
            street->drawRed(*scene);
        }
    }
}


void MainWindow::on_pushButtonFindRoute_clicked()
{
    QString startName = ui->lineEditStartCity->text();
    QString endName   = ui->lineEditEndCity->text();

    scene->clear();
    map.draw(*scene);   // redraw the base map first

    QVector<Street*> path = Dijkstra::search(map, startName, endName);

    if (path.isEmpty())
    {
        qDebug() << "No route found (check spelling, or no connection exists).";
        return;
    }

    for (Street* street : path)
    {
        street->drawRed(*scene);
    }
}


void MainWindow::on_pushButtonAddStreet_clicked()
{
    AddStreetDialog dialog(this, map.getCityNames());
    int result = dialog.exec();

    City* origin = map.findCity(dialog.getOriginName());
    City* destination = map.findCity(dialog.getDestinationName());

    if (origin == nullptr || destination == nullptr || origin == destination)
    {
        qDebug() << "Invalid street selection.";
        return;
    }

    Street* newStreet = new Street(origin, destination);
    bool added = map.addStreet(newStreet);

    if (added)
    {
        newStreet->draw(*scene);
    }
    else
    {
        qDebug() << "Street not added — endpoint city missing from map.";
        delete newStreet;   // wasn't stored anywhere, so free it to avoid a leak
    }
}

