//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 04: Einf�hrung Klasse
//
// Datei:  Vektor.cpp
// Inhalt: Sourcedatei der Klasse Vektor
//////////////////////////////////////////////////////////////////////////////

#include "Vektor.h"

/**
 * @brief Construct a new Vektor:: Vektor object        
 * 
 * @param inX 
 * @param inY 
 * @param inZ 
 */
Vektor::Vektor(double inX, double inY, double inZ) : x(inX), y(inY), z(inZ)
{
}

/**
 * @brief Destruktor der Klasse Vektor
 * 
 */
Vektor::~Vektor()
{

}

void Vektor::setX(double inX)
{
    this->x = inX;
}

void Vektor::setY(double inY)
{
    this->y = inY;
}

void Vektor::setZ(double inZ)
{
    this->z = inZ;
}

double Vektor::getX() const
{
    return this->x;
}

double Vektor::getY() const
{
    return this->y;
}

double Vektor::getZ() const
{
    return this->z;
}


/**
 * @brief Function printing the components of the vector 
 */
void Vektor::ausgabe() const
{
    std::cout << "X-Komponente: " << x << std::endl;
    std::cout << "Y-Komponente: " << y << std::endl;
    std::cout << "Z-Komponente: " << z << std::endl << std::endl;
}

/**
 * @brief       Funktion, die die Differenz zweier Vektoren berechnet
 * 
 * @param input 
 * @return Vektor 
 */

Vektor Vektor::sub(const Vektor& input) const
{
    return Vektor(this->getX() - input.getX(), this->getY() - input.getY(), this->getZ() - input.getZ());
}


/**
 * @brief       Funktion, die die Länge eines Vektors berechnet
 * 
 * @return double 
 */
double Vektor::laenge() const
{
    return sqrt(this->getX()*this->getX() + this->getY()*this->getY() + this->getZ()*this->getZ());
}


/**
 * @brief       Funktion, die das Skalarprodukt zweier Vektoren berechnet
 * 
 * @param input 
 * @return double 
 */
double Vektor::skalarProd(const Vektor& input) const
{
    return this->getX()*input.getX() + this->getY()*input.getY() + this->getZ()*input.getZ();
}


/**
 * @brief       Funktion, die den Winkel zwischen zwei Vektoren berechnet
 * 
 * @param input 
 * @return double 
 */
double Vektor::winkel(const Vektor& input) const
{
    return acos(this->skalarProd(input) / (this->laenge() * input.laenge()));
}

/**
 * @brief       Funktion, die einen Vektor um die Z-Achse rotiert
 * 
 * @param rad 
 */

void Vektor::rotiereUmZ(const double rad)
{
    double x_neu = this->x*cos(rad) - this->y*sin(rad);
    double y_neu = this->x*sin(rad) + this->y*cos(rad);
    this->setX(x_neu);
    this->setY(y_neu);
}


