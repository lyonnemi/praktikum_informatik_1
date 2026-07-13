#include "street.h"
#include <QDebug>
#include <QPen>
#include <QBrush>
#include <QGraphicsTextItem>

Street::Street(City* origin, City* end) : origin(origin), end(end) {
    qDebug() << "Street between " << origin->getName() << " and " << end->getName() << "added.";
}

void Street::draw(QGraphicsScene& scene) {
    QPen pen(Qt::green);
    pen.setWidth(2);
    scene.addLine(this->getOrigin()->getX(), this->getOrigin()->getY(), this->getEnd()->getX(), this->getEnd()->getY(), pen);
}

void Street::drawRed(QGraphicsScene &scene)
{
    QPen pen(Qt::red);
    pen.setWidth(4);   // thicker than the default black line

    scene.addLine(this->getOrigin()->getX(), this->getOrigin()->getY(), this->getEnd()->getX(), this->getEnd()->getY(), pen);
}

City* Street::getOrigin() const{
    return origin;
}


City* Street::getEnd() const {
    return end;
}