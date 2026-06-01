/////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 1.2: Strukturen
//
// Datei:  Strukturen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>

/**
 
 Erstellen Sie nun ein weiteres Projekt Versuch01Teil2 und importieren Sie die Vorlage Strukturen.cpp.
 Deklarieren Sie in dieser Datei eine Struktur mit dem Namen Person, die aus den Zeichenketten
 sNachname, sVorname und aus den ganzen Zahlen iGeburtsjahr und iAlter besteht. Definieren Sie
 eine Variable vom Typ Person mit dem Namen nBenutzer. Lassen Sie den Benutzer seinen Namen
 und Vornamen sowie sein Geburtsjahr und sein Alter eingeben. Geben Sie den Inhalt der gesamten
 Struktur sinnvoll aus.
 Kopieren Sie den Inhalt von nBenutzer in eine neue Variable.
 Kopieren Sie
 1. jedes Element einzeln in nKopieEinzeln und
 2. die gesamte Struktur in nKopieGesamt.
 Geben Sie beide Ergebnisse aus.
 Komprimieren Sie abschließend den Ordner zu Versuch01_Teil2.zip und laden Sie diese Datei an der
 entsprechenden Stelle in RWTHmoodle hoch.
 
 
 */

/*
 Deklarieren Sie in dieser Datei eine Struktur mit dem Namen Person, die aus den Zeichenketten
 sNachname, sVorname und aus den ganzen Zahlen iGeburtsjahr und iAlter besteht
 */

struct Person {
    std::string sNachname;
    std::string sVorname;
    int iGeburtsjahr;
    int iAlter;
};


int main()
{
    /*
     Definieren Sie
     eine Variable vom Typ Person mit dem Namen nBenutzer.
     */
    Person nBenutzer;
    
    /*
     Lassen Sie den Benutzer seinen Namen
     und Vornamen sowie sein Geburtsjahr und sein Alter eingeben
     */
    std::cout << "Nachname: ";
    std::cin >> nBenutzer.sNachname;
    std::cout << "" << std::endl;
    
    std::cout << "Vorname: ";
    std::cin >> nBenutzer.sVorname;
    std::cout << "" << std::endl;
    
    std::cout << "Geburtsjahr: ";
    std::cin >> nBenutzer.iGeburtsjahr;
    std::cout << "" << std::endl;
    
    std::cout << "Alter: ";
    std::cin >> nBenutzer.iAlter;
    std::cout << "" << std::endl;
    
    /*
     Geben Sie den Inhalt der gesamten
     Struktur sinnvoll aus.
     */
    std::cout << "Nachname:     " << nBenutzer.sNachname << std::endl;
    std::cout << "Vorname:      " << nBenutzer.sVorname << std::endl;
    std::cout << "Geburtsjahr:  " << nBenutzer.iGeburtsjahr << std::endl;
    std::cout << "Alter:        " << nBenutzer.iAlter << " Jahre" << std::endl;
    
    /*
     jedes Element einzeln in nKopieEinzeln und
     */
    Person nKopieEinzeln;
    nKopieEinzeln.sNachname = nBenutzer.sNachname;
    nKopieEinzeln.sVorname = nBenutzer.sVorname;
    nKopieEinzeln.iGeburtsjahr = nBenutzer.iGeburtsjahr;
    nKopieEinzeln.iAlter = nBenutzer.iAlter;
    
    /*
     die gesamte Struktur in nKopieGesamt
     */
    Person nKopieGesamt = nBenutzer;

    
    /*
     Geben Sie beide Ergebnisse aus
     */
    std::cout << "Nachname:     " << nKopieEinzeln.sNachname << std::endl;
    std::cout << "Vorname:      " << nKopieEinzeln.sVorname << std::endl;
    std::cout << "Geburtsjahr:  " << nKopieEinzeln.iGeburtsjahr << std::endl;
    std::cout << "Alter:        " << nKopieEinzeln.iAlter << " Jahre" << std::endl;
    
    std::cout << "Nachname:     " << nKopieGesamt.sNachname << std::endl;
    std::cout << "Vorname:      " << nKopieGesamt.sVorname << std::endl;
    std::cout << "Geburtsjahr:  " << nKopieGesamt.iGeburtsjahr << std::endl;
    std::cout << "Alter:        " << nKopieGesamt.iAlter << " Jahre" << std::endl;
    
    return 0;
    
    
}
