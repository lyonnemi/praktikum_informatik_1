/** @mainpage
 *
 * Praktikum Informatik 1 MMXXVI <BR>
 * Versuch 6: Dynamische Datenstrukturen
 *
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <list>
#include <unordered_map>
#include <limits>

#include "Student.h"

int main()
{
    std::vector<Student> studentenVektor;
    Student student;

    char abfrage;
    std::cout << "Wollen Sie die Liste selbst fuellen? (j)/(n) ";
    std::cin >> abfrage;
    std::cin.ignore(10, '\n');

    if (abfrage != 'j')
    {
        student = Student(34567, "Harro Simoneit", "19.06.1971", "Am Markt 1");
        studentenVektor.push_back(student);
        student = Student(74567, "Vera Schmitt", "23.07.1982", "Gartenstr. 23");
        studentenVektor.push_back(student);
        student = Student(12345, "Siggi Baumeister", "23.04.1983", "Ahornst.55");
        studentenVektor.push_back(student);
        student = Student(64567, "Paula Peters", "9.01.1981", "Weidenweg 12");
        studentenVektor.push_back(student);
        student = Student(23456, "Walter Rodenstock", "15.10.1963", "Wöllnerstr.9");
        studentenVektor.push_back(student);
    }

    do
    {
        std::cout << "\nMenue:" << std::endl
                  << "-----------------------------" << std::endl
                  << "(1): Datenelement hinten hinzufuegen" << std::endl
                  << "(2): Datenelement vorne entfernen" << std::endl
                  << "(3): Datenbank ausgeben" << std::endl
                  << "(4): Datenbank in umgekehrter Reihenfolge ausgeben" << std::endl
                  << "(5): Datenelement löschen" << std::endl
                  << "(6): Datenelement vorne hinzufügen" << std::endl
                  << "(7): Datenelement vorne loeschen" << std::endl
                  << "(8): Datenelement aus einer Datei sichern" << std::endl
                  << "(9): Datenelement in eine Datei sichern" << std::endl
                  << "(0): Beenden" << std::endl;
        std::cin >> abfrage;
        std::cin.ignore(10, '\n');

        switch (abfrage)
        {
            // Datenelement hinten hinzufuegen 
            case '1':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    studentenVektor.push_back(student);
                }
                break;

            // Datenelement vorne entfernen
            case '2':
                {
                    if(!studentenVektor.empty())
                    {
                        std::vector<Student>::iterator it = studentenVektor.begin();
                        std::cout << "Der folgende Student ist geloescht worden:" << std::endl;
                        it->ausgabe();
                        studentenVektor.erase(it);
                    }
                    else
                    {
                        std::cout << "Die Liste ist leer!\n";
                    }
                }
                break;

            // Datenbank vorwaerts ausgeben
            case '3':
                if(!studentenVektor.empty())
                {
                    std::cout << "Inhalt der Liste in fortlaufender Reihenfolge:" << std::endl;
                    for (auto it = studentenVektor.begin(); it != studentenVektor.end(); it++) {
                        it->ausgabe();
                    }
                }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;
            // Datenbank rueckwaerts ausgeben
            case '4':
                if(!studentenVektor.empty())
                {
                    std::cout << "Inhalt der Liste in umgekehrter Reihenfolge:" << std::endl;
                    for (auto it = studentenVektor.rbegin(); it != studentenVektor.rend(); it++) { //rbegin und rend als methode fur opposite reihenfolge
                        it->ausgabe();
                    }
                 }
                else
                {
                    std::cout << "Die Liste ist leer!\n\n";
                }
                break;

            // Datenelement löschen
            case '5':
                {
                    unsigned int matrikelnummer;

                    std::cout << "Geben Sie die Matrikelnummer des Studenten ein, der gelöscht werden soll: ";
                    std::cin >> matrikelnummer;

                    for (auto it = studentenVektor.begin(); it != studentenVektor.end(); it++) {
                        if (it->getMatNr() == matrikelnummer) {
                            studentenVektor.erase(it);
                            break;
                        }
                    }
                }
                break;

            // Datenelement vorne hinzufügen
            case '6':
                {
                    unsigned int matNr = 0;
                    std::string name = "";
                    std::string geburtstag = "";
                    std::string adresse = "";

                    std::cout << "Bitte geben sie die Daten f�r den Studenten ein.\nName: ";
                    getline(std::cin, name);    // ganze Zeile einlesen inklusive aller Leerzeichen

                    std::cout << "Geburtsdatum: ";
                    getline(std::cin, geburtstag);

                    std::cout << "Adresse: ";
                    getline(std::cin, adresse);

                    std::cout << "Matrikelnummer: ";
                    std::cin >> matNr;
                    std::cin.ignore(10, '\n');

                    student = Student(matNr, name, geburtstag, adresse);
                    studentenVektor.insert(studentenVektor.begin(), student);
                }
                break;
            // Datenelement vorne loeschen
            case '7':
                {   
                    if (!studentenVektor.empty()) {
                        std::vector<Student>::iterator it = studentenVektor.begin();
                        studentenVektor.erase(it);
                    } else {
                        std::cout << "Die Liste ist leer!\n\n";
                    }
                    break;
                }

                // Datenelement aus einer Datei lesen
            case '8':
                {
                    std::unordered_map<unsigned int, Student> studentMap; // Hashmap zur Überprüfung der Matrikelnummern
                    for (const auto& s : studentenVektor) {
                        studentMap[s.getMatNr()] = s; // Matrikelnummer in die Hashmap einfügen
                    }
                    std::string fileName;
                    std::cout << "Geben Sie die Filename ein: ";
                    std::cin >> fileName;

                    std::string name, geburtsDatum, adresse;

                    std::ifstream eingabe(fileName, std::ios::in);
                    if (!eingabe){
                        std::cout << "Fehler beim Oeffnen der Datei!";
                        exit(1);
                    }

                    while (eingabe >> matNr) {
                        eingabe.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                        std::getline(eingabe, name);
                        std::getline(eingabe, geburtsDatum);
                        std::getline(eingabe, adresse);

                        student = Student(matNr, name, geburtsDatum, adresse);

                        if (studentMap.find(matNr) != studentMap.end()) {
                            std::cout << "Student mit Matrikelnummer " << matNr << " existiert bereits in der Liste." << std::endl;
                            std::cout << "Möchten Sie den Studenten trotzdem hinzufügen? (j/n): ";
                            char choice;
                            std::cin >> choice;
                            if (choice == 'j' || choice == 'J') {
                                studentenVektor.push_back(student);
                                studentMap[matNr] = student;
                            } else {
                                std::cout << "Student wurde nicht hinzugefügt." << std::endl;
                            }
                        } else {
                            studentenVektor.push_back(student);
                            studentMap[matNr] = student;
                        }
                    }
                }
                break;

                // Datenelement in eine Datei sichern
            case '9':
                {
                    int proceed = 1; // Variable, um zu überprüfen, ob der Benutzer fortfahren möchte
                    unsigned int matNr;
                    std::string name, geburtsdatum, adresse, dateiName;

                    std::cout << "Geben Sie die Datei Name ein: ";
                    std::cin >> dateiName;
                    std::ofstream ausgabe(dateiName, std::ios::out | std::ios::trunc); // Datei zum Schreiben öffnen (überschreiben, falls sie bereits existiert)
                    
                    // Die Daten eines Studierenden
                    while (proceed == 1) {
                        std::cout << "Geben Sie die Matrikelnummer ein: ";
                        std::cin >> matNr;
                        std::cout << "Geben Sie den Namen ein: ";
                        std::cin >> name;
                        std::cout << "Geben Sie das Geburtsdatum ein: ";
                        std::cin >> geburtsdatum;
                        std::cout << "Geben Sie die Adresse ein: ";
                        std::cin >> adresse;

                        // Daten in die Datei schreiben
                        ausgabe << matNr << std::endl;
                        ausgabe << name << std::endl;
                        ausgabe << geburtsdatum << std::endl;
                        ausgabe << adresse << std::endl;

                        std::cout << "Möchten Sie weitere Daten eingeben? (1 für Ja, 0 für Nein): ";
                        std::cin >> proceed;
                    }

                    std::cout << "Daten wurden in die Datei " << dateiName << " geschrieben." << std::endl;
                    // Schließen der Datei
                    ausgabe.close();
                }

            case '0':
                std::cout << "Das Programm wird nun beendet";
                break;

            default :
                std::cout << "Falsche Eingabe, bitte nochmal";
                break;
        }
    }
    while (abfrage != '0');

    return 0;
}
