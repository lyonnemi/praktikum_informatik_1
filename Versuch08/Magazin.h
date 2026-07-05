#ifndef MAGAZIN_H
#define MAGAZIN_H

#include "Medium.h"

class Magazin : public Medium{
protected:
    Datum datumAusgabe;
    std::string sparte;

public:
    Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte);
    void ausgabe() const override;
    bool ausleihen(Person person, Datum ausleihdatum) override;
    ~Magazin();
};

#endif // MAGAZIN_H
