#include "city.h"
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QGraphicsTextItem>


/*
 * @brief constructor
 * @param string name : name der stadt
 * @param int X : x koordinat der stadt
 * @param int Y : y koordinat der stadt
 */
City::City(QString name, int X, int Y) :
    name(name), X(X), Y(Y)
{

}

/*
 * @brief stadt als rote punkt auf scene zeichnen
 * @param QgraphicsScene &scene : beziehte Scene
 */
void City::draw(QGraphicsScene &scene) {
    int diameter = 6;
    scene.addEllipse(X, Y, diameter, diameter, QPen(Qt::red), QBrush(Qt::red, Qt::SolidPattern));

    QGraphicsTextItem *label = new QGraphicsTextItem;
    label->setPlainText(name);
    label->setPos(X + diameter, Y);
    scene.addItem(label);
}


QString City::getName() const
{
    return name;
}

int City::getX() const {
    return X;
}

int City::getY() const{
    return Y;
}


