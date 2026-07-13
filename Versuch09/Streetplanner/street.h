#ifndef STREET_H
#define STREET_H
#include <QGraphicsScene>
#include "city.h"


class Street
{
private:
    City* origin;
    City* end;
public:
    Street(City* origin, City* end);
    void draw(QGraphicsScene& scene);
    City* getOrigin() const;
    City* getEnd() const;
    void drawRed(QGraphicsScene &scene);
};

#endif // STREET_H
