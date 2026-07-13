#ifndef CITY_H
#define CITY_H
#include <string>
#include <QString>
#include <QGraphicsScene>

class City
{
private:
    QString name;
    int X;
    int Y;

public:
    City(QString name, int X, int Y);
    void draw(QGraphicsScene& scene);
    QString getName() const;
    int getX() const;
    int getY() const;
};

#endif // CITY_H
