#include "Magazin.h"

Magazin::Magazin(std::string initTitel, Datum initDatumAusgabe, std::string initSparte)
    : Medium(initTitel), datumAusgabe(initDatumAusgabe), sparte(initSparte) {
        // Konstruktorimplementierung
    }

Magazin::~Magazin() {
    // Destruktorimplementierung
}

bool Magazin::ausleihen(Person person, Datum ausleihdatum) {
    // Hier können Sie die Ausleihlogik für Magazine implementieren
    // Zum Beispiel können Sie die Basisklassenmethode aufrufen oder eigene Logik hinzufügen
    if (ausleihdatum - datumAusgabe == 0) {
        std::cout << "Magazin darf nicht ausgeliehen lassen. " << std::endl;
        return false;
    }

    return Medium::ausleihen(person, ausleihdatum);
}

void Magazin::ausgabe() const {
    Medium::ausgabe(); // Aufruf der Basisklassen-Ausgabefunktion
    std::cout << "Datum der Ausgabe: " << datumAusgabe << std::endl;
    std::cout << "Sparte: " << sparte << std::endl;
}
