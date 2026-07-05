#ifndef DVD_H
#define DVD_H

#include "Medium.h"

class DVD : public Medium {
protected:
    int altersfreigabe;
    std::string genre;

public:
    DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre);
    void ausgabe() const override;
    bool ausleihen(Person person, Datum ausleihdatum) override;



};

#endif // DVD_H