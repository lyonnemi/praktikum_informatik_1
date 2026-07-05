#ifndef BUCH_H
#define BUCH_H

#include "Medium.h"
#include <string>

class Buch : public Medium
{
private: 
    std::string autor;
    

public:
    Buch(std::string initTitel, std::string initAutor);
    void ausgabe() const override;
    ~Buch();
};

#endif // BUCH_H