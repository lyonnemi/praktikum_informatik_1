//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 
// 
// Versuch 1.1: Datentypen und Typumwandlung
//
// Datei:  Variablen.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>


int main()
{
	/*
	 * Fordern Sie den Benutzer auf, zwei ganze Zahlen (iErste und iZweite) einzugeben, speichern Sie
	die Summe in iSumme und das Ergebnis der Division von iErste durch iZweite in iQuotient.
	Geben Sie die Ergebnisse mit einer entsprechenden Meldung auf dem Bildschirm aus. Hier und
	im Folgenden sollten Sie bei der Ausgabe immer einen entsprechenden Hinweis für den Benutzer
	ausgeben, damit dieser weiß, was sich hinter der Ausgabe von welchen Werten verbirgt.
	 */

    int iErste, iZweite;

    std::cout << "Geben Sie zwei ganze Zahlen ein: " << std::endl;
    std::cin  >> iErste;
    std::cin  >> iZweite;
    std::cout << " " << std::endl;


    

    
    // Hier folgt Ihr eigener Code
    int iSumme = iErste + iZweite;
    int iQuotient = iErste/iZweite;

    std::cout << "iSumme: " << iSumme << std::endl;
    std::cout << "iQuotient: " << iQuotient << std::endl;
    std::cout << "" << std::endl;


    double dSumme = iErste + iZweite;
    double dQuotient = iErste/iZweite; 

    std::cout << "dSumme: " << dSumme << std::endl;
    std::cout << "dQuotient: " << dQuotient << std::endl;
    std::cout << "" << std::endl;

    dSumme = (double)iErste + (double)iZweite;
    dQuotient = (double)iErste/(double)iZweite;

    std::cout << "dSumme mit Typecasting: " << dSumme << std::endl;
    std::cout << "dQuotient mit Typecasting: " << dQuotient << std::endl;
    std::cout << "" << std::endl;

    
    



    /*
     * Berechnen Sie die Werte erneut, aber speichern Sie nun in den Variablen dSumme und dQuotient
		vom Typ double und geben Sie auch diese Ergebnisse aus.
     */





    /*
     * Lassen Sie den Benutzer seinen Vornamen und seinen Nachnamen (Variablen: sVorname und
		sNachname vom Typ string) eingeben und speichern Sie den kompletten Namen in der Form
		„Vorname Nachname” in sVornameName und in der Form „Name, Vorname” in sNameVorname.
		Nutzen Sie den +-Operator für Strings. Geben Sie beide Formen des Namens aus.
     */

    std::string sVorname;
    std::string sNachname;


    std::cout << "Geben Sie Ihrer Vorname ein: ";
    std::cin >> sVorname;
    std::cout << "" << std::endl;

    std::cout << "Geben Sie Ihrer Nachname ein: ";
    std::cin >> sNachname;
    std::cout << "" << std::endl;

    std::string sNameVorname = sNachname + ", " + sVorname;
    std::string sVornameName = sVorname + ", " + sNachname;

    std::cout << "Name, Vorname: " << sNameVorname << std::endl;
    std::cout << "Vorname, Name: " << sVornameName << std::endl;

    {
    	/*
    	 * Legen Sie ein Feld iFeld aus Ganzzahlen mit 2 Elementen an und geben Sie den Elementen
			die Werte 1 und 2. Geben Sie beide Werte aus
    	 */
    	int iFeld[2] = {1,2};
    	std::cout << "Werten von iFeld: ";

        std::cout << iFeld[0] << ", " << iFeld[1];
    	std::cout << " " << std::endl;


    	/*
    	 * Erzeugen Sie ein Feld aus 2 mal 3 Elementen mit den Werten 1 bis 6 mit dem Namen
			spielfeld. Geben Sie die Werte aus, 3 pro Zeile mit Leerzeichen dazwischen, 2 Zeilen.
    	 */
        int spielfeld[2][3] = {
            {1, 2, 3},
            {4, 5, 6}
        };

        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) {
                std::cout << spielfeld[i][j];
                if (j < 2) std::cout << " ";
            }
            std::cout << std::endl;
        }


        /*
         * Definieren Sie eine Konstante iZweite mit dem Wert 1 und geben Sie diese aus.
         */
        const int iZweite = 1;
        std::cout << "iZweite: " << iZweite << std::endl;


        /*
         * Wandeln Sie den ersten und den zweiten Buchstaben des Vornamens des Benutzers anhand der
			ASCII-Tabelle in eine Zahl um (Variablen: iName1 und iName2 ). Geben Sie diese Zahlen aus
         */
        int iName1 = static_cast<int>(sVorname[0]);
        int iName2 = static_cast<int>(sVorname[1]);

        std::cout << "Erster Buchstabe '" << sVorname[0]
                  << "' als ASCII: " << iName1 << std::endl;
        std::cout << "Zweiter Buchstabe '" << sVorname[1]
                  << "' als ASCII: " << iName2 << std::endl;


        /*
         * Berechnen Sie anhand dieser Zahlen die Position der Buchstaben im deutschen Alphabet unabhängig von Groß- und Kleinschreibung, z.B. hat A den ASCII-Wert 65 und A ist der erste
			Buchstabe im deutschen Alphabet. Der modulo Operator(%) kann dabei sehr hilfreich sein.
         */
        int position1 = (iName1 - 1) % 32 + 1;
        int position2 = (iName2 - 1) % 32 + 1;



    }
    
    return 0;
    
}
