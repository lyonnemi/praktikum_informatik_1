#ifndef BUCH_CPP
#define BUCH_CPP
#define UNTERKLASSENVORHANDEN true
#include "Buch.h"

Buch::Buch(std::string initTitel, std::string initAutor)
: Medium(initTitel)
, autor(initAutor)
{
}

Buch::~Buch()
{
}

void Buch::ausgabe() const
{
    Medium::ausgabe();
    std::cout << "Autor: " << autor << std::endl;
}

#endif // BUCH_CPP