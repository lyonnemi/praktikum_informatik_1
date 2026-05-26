//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 04: Einf�hrung Klasse
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////
#include "Vektor.h"
double menschHoehe = 1.7;
double platformHoehe = 555.7;
double erdradius = 6371.0 * 1000;

/**
 * @brief       Funktion, die einen Winkel in Grad umrechnet
 * 
 * @param rad 
 * @return double 
 */
double to_degrees(double rad){
    return rad * (180.0 / M_PI);
}


int main()
{
    
    Vektor vector1(1, 0, 0);
    Vektor vector2(0, 1, 0);

    vector1.ausgabe();
    vector2.ausgabe();


    Vektor erdRadius(0, erdradius, 0);      // bitte sinnvoll initialisieren
    Vektor aussichtsPunkt(0, menschHoehe + platformHoehe + erdradius, 0); // bitte sinnvoll initialisieren
    Vektor sicht = erdRadius.sub(aussichtsPunkt);

    double tanWinkel = sicht.winkel(erdRadius);
    double rad = 0;
    int schritt = 0;

    std::cout << to_degrees(tanWinkel) << std::endl;

    do 
    {
        rad += 0.00000001;
        erdRadius.rotiereUmZ(0.00000001);
        sicht = erdRadius.sub(aussichtsPunkt);
        tanWinkel = sicht.winkel(erdRadius);
        schritt += 1;

    }while (to_degrees(tanWinkel) > 90);
    

    std::cout << "Sie können " << sicht.laenge()/1000 << " Km weit sehen." << std::endl;
    std::cout << "Sie sind " << platformHoehe + menschHoehe << " Meter hoch." << std::endl;
    std::cout << "Der Winkel beträgt " << to_degrees(rad) << " Grad." << std::endl;
    std::cout << "Anzahl Schritte: " << schritt << std::endl;

    return 0;

}
