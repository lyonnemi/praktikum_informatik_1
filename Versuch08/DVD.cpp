#include "DVD.h"

DVD::DVD(std::string initTitel, int initAltersfreigabe, std::string initGenre)
    : Medium(initTitel), altersfreigabe(initAltersfreigabe), genre(initGenre) {
    
}

void DVD::ausgabe() const {
    Medium::ausgabe();
    std::cout << "Altersfreigabe: " << altersfreigabe << std::endl;
    std::cout << "Genre: " << genre << std::endl;
}

bool DVD::ausleihen(Person person, Datum ausleihdatum) {
    //check for newest issue
    if (person.getJahresAlter() < altersfreigabe) {
        std::cout << person.getName() << " is zu jung. Darf nicht ausgeliehen werden." << std::endl;
        return false;
    }
    return Medium::ausleihen(person, ausleihdatum);
}
