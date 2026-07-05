/*!
 * Praktikum Informatik 1 
 * 
 *
 * @file Person.cpp
 */
 
#include "Person.h"
#include <time.h>

// Konstruktor
Person::Person(std::string initName, Datum initGeburtsdatum)
: name(initName)
, geburtsdatum(initGeburtsdatum)
{
}

// Destruktor
Person::~Person()
{
}

// Zugriffsfunktion auf das Geburtsdatum
Datum Person::getGeburtsdatum() const
{
    return this->geburtsdatum;
}

// Zugriffsfunktion auf den Namen
std::string Person::getName() const
{
    return this->name;
}

// get Jahres alter
int Person::getJahresAlter() const 
{
    Datum datum;
    return datum.getJahr() - this->getGeburtsdatum().getJahr();
}