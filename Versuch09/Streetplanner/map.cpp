#include "map.h"
#include <cmath>
#include <QDebug>

Map::Map() {}

void Map::addCity(City* city) {
    qDebug() << "Adding City: " << city->getName();
    cities.append(city);
}

void Map::draw(QGraphicsScene& scene) {
    for (City* city : cities){
        city->draw(scene);
    }
}

bool Map::addStreet(Street *street) {

    if (cities.contains(street->getOrigin()) && cities.contains(street->getEnd())){
        streets.append(street);
        qDebug() << "Street added:" << street->getOrigin()->getName() << "->" << street->getEnd()->getName();
        return true;
    }else{
        qDebug() << "Street NOT added — endpoint city missing from map.";
        return false;
    }
}

City* Map::findCity(const QString cityName) const{
    for (City* city: cities){
        if (city->getName() == cityName) {
            qDebug() << "City found; returning pointer for " << cityName;
            return city;
        }
    }
    qDebug() << "City not found!";
    return nullptr;
}

QVector<Street*> Map::getStreetList(const City *city) const {
    QVector<Street*> cityStreets;

    for (Street* street: streets) {
        if (street->getEnd() == city || street->getOrigin() == city) {
            cityStreets.append(street);
        }
    }

    if (cityStreets.isEmpty()) {
        qDebug() << "No Streets found connected to this City!";
    }

    return cityStreets;
}

City* Map::getOppositeCity(const Street *street, const City *city) const {
    if (streets.contains(street) && cities.contains(city)){
        if (street->getEnd() == city) {
            return street->getOrigin();
        }else{
            return street->getEnd();
        }
    }else{
        qDebug() << "No street or Such city is found!";
        return nullptr;
    }
}

double Map::getLength(const Street *street) const {
    int xOrigin = street->getOrigin()->getX();
    int xEnd = street->getEnd()->getX();
    int yOrigin = street->getOrigin()->getY();
    int yEnd = street->getEnd()->getY();

    double dx = xOrigin - xEnd;
    double dy = yOrigin - yEnd;

    return std::pow(dx*dx + dy*dy, 0.5);
}

QStringList Map::getCityNames() const
{
    QStringList names;
    for (City* city : cities)
    {
        names.append(city->getName());
    }
    return names;
}