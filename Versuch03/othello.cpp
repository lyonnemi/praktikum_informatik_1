/**
 * Praktikum Informatik 1 
 * 
 *
 * @file othello.cpp
 *
 * Die Funktionen fuer das Spiel Othello
 */

/**
* @mainpage Othello
*
* Dokumentation des Spiels Othello im Rahmen des Praktikums Informatik 1.
*
*/

#include <iostream>
#include <string>
#include "config.h"
#include "test.h"
#include "othelloKI.h"


/**
 * @brief Funktion zur ersten Initialisierung eines neuen Spielfelds
 *
 * Diese Funktion fuellt ein existierendes Spielfeld mit Nullen und erzeugt die Startaufstellung.
 *
 * @param spielfeld Spielfeld, das initialisiert wird
 */
void initialisiereSpielfeld(int spielfeld[GROESSE_Y][GROESSE_X])
{
    for (int j = 0; j < GROESSE_Y; j++)
        {
            for(int i = 0; i < GROESSE_X; i++)
            {
                spielfeld[j][i] = 0;
            }
        }
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2 - 1] = 1;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2 - 1] = 2;
        spielfeld[GROESSE_Y / 2 - 1][GROESSE_X / 2] = 2;
        spielfeld[GROESSE_Y / 2][GROESSE_X / 2] = 1;
}



/**
* @brief Ausgabe des Spielfelds auf der Konsole
*
* Ausgabe des aktuellen Spielfelds, 0 bedeutet leeres Feld, 1 ist Spieler 1 und 2 ist Spieler2
* Kreuze symbolisieren Spieler 1, waehrend Kreise Spieler 2 symbolisieren
*
*  @param spielfeld  Spielfeld, das ausgeben wird
*/
void zeigeSpielfeld(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    std::cout << "   | ";

    //Start bei ASCII 65 = A
    for (int i = 65; i < 65 + GROESSE_X; ++i)
        std::cout << ((char) i) << " | " ;

    std::cout << std::endl;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for(int i = 0; i < GROESSE_X; ++i)
        {
            std::cout << "---+";
        }
        std::cout << "---+" << std::endl;

        std::cout << " " << j + 1 << " |";
        for (int i = 0; i < GROESSE_X; ++i)
        {
            switch (spielfeld[j][i])
            {
                case 0:
                    std::cout << "   " ;
                    break;
                case 1:
                    std::cout << " X ";
                    break;
                case 2:
                    std::cout << " O ";
                    break;
                default:
                    std::cout << "Unzulaessige Daten im Spielfeld!" << std::endl;
                    std::cout << "Abbruch .... " << std::endl;
                    exit(0);
                    break;
            }
            std::cout << "|";
        };  //for i
        std::cout <<  std::endl;
    }  //for j
}

/**
 * @brief Prueft, wer Gewinner ist
 *
 * Zaehlt alle Steine auf dem Feld
 *
 * @param spielfeld Aktuelles Spielfeld, fuer das der Gewinner ermittelt wird
 * @return winner
 */
int gewinner(const int spielfeld[GROESSE_Y][GROESSE_X])
{
    int zaehlerSpieler1 = 0;
    int zaehlerSpieler2 = 0;

    for (int j = 0; j < GROESSE_Y; ++j)
    {
        for (int i = 0; i < GROESSE_X; ++i)
        {
            if (spielfeld[j][i] == 1)
            {
                ++zaehlerSpieler1;
            }
            if (spielfeld[j][i] == 2)
            {
                ++zaehlerSpieler2;
            }

        }
    }

    if (zaehlerSpieler1 == zaehlerSpieler2)
    {
        return 0;
    }
    if (zaehlerSpieler1 < zaehlerSpieler2)
    {
        return 2;
    }
    else
    {
        return 1;
    }
}

/**
* @brief Ueberprueft fuer zwei Indizes, ob sie auf dem Spielfeld sind
*
* @param posX Index fuer die Spalte
* @param posY Index fuer die Zeile
* @return true, wenn Spalte und Zeile innerhalb des Spielfelds sind, sonst false
*/
bool aufSpielfeld(const int posX, const int posY)
{
    // Hier erfolgt jetzt Ihre Implementierung ...
    if (posX < 0 || posX >= GROESSE_X || posY < 0 || posY >= GROESSE_Y)
    {
        return false;
    }
    return true;
}


/**
 * @brief Ueberprueft fuer zwei Indizes, ob der Zug gueltig ist
 *
 *  Ueberprueft, ob auf einem benachbarten Feld ein gegnerischer Stein liegt.
 *  Wenn ja, wird diese Richtung solange untersucht, bis ein eigener Stein
 *  gefunden wird. Wird vorher der Spielfeldrand erreicht oder ein leeres Feld
 *  gefunden, wird false zurueckgegeben, sonst true
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Zu ueberpruefende Spalte
 * @param posY Zu ueberpruefende Zeile
 * @return
 */
bool zugGueltig(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler; // dasselbe wie: if aktuellerSpieler == 1 -> gegner = 2
                                       //               if aktuellerSpieler == 2 -> gegner = 1

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        return false;
    }

    // Alle Richtungen ueberpruefen bis erster gueltiger Zug gefunden
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // Hier erfolgt jetzt Ihre Implementierung ...
            int x = posX + i;
            int y = posY + j;

            if (spielfeld[y][x] == gegner) // gegner gefunden
            {
                while (aufSpielfeld(x, y) && spielfeld[y][x] == gegner) // solange auf Spielfeld und gegnerischer Stein
                {
                    x += i; // weiter in die gleiche Richtung
                    y += j;
                }
                if (aufSpielfeld(x, y) && spielfeld[y][x] == aktuellerSpieler) // wenn eigener Stein gefunden
                {
                    return true;
                }
            
            }else{
                continue;   
            }




        }
    }
    return false;
}


/**
 * @brief Funktion, die einen Zug ausfuehrt
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @param posX Die aktuelle Spalte
 * @param posY Die aktuelle Zeile
 */
void zugAusfuehren(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler, const int posX, const int posY)
{
    int gegner = 3 - aktuellerSpieler;

    if (spielfeld[posY][posX] != 0) // ist das Feld leer?
    {
        std::cout << "Ungültiger Zug: Das Feld ist nicht leer!" << std::endl;
        return;
    }

    spielfeld[posY][posX] = aktuellerSpieler; // eigenen Stein setzen

    //Alle Richtungen bearbeiten
    for (int j = -1; j <= 1; j++)
    {
        for (int i = -1; i <= 1; i++)
        {
            // aehnlich wie die Funktion zugGueltig(), aber stellen Sie sicher, das alle gegnerischen Steine in
            // allen Richtungen in Ihre eigenen Steine umgewandelt werden
            //
            // Hier erfolgt jetzt Ihre Implementierung ...
            int x = posX + i;
            int y = posY + j;

            if (spielfeld[y][x] == gegner) {
                int counter = 0;
                while (aufSpielfeld(x, y) && spielfeld[y][x] == gegner) // solange auf Spielfeld und gegnerischer Stein
                {
                    x += i; // weiter in die gleiche Richtung
                    y += j;
                    counter++;
                }
                if (aufSpielfeld(x, y) && spielfeld[y][x] == aktuellerSpieler) // wenn eigener Stein gefunden
                {
                    // Alle gegnerischen Steine in dieser Richtung umwandeln
                    for (int k = 0; k <= counter; k++)
                    {
                        spielfeld[posY + j * k][posX + i * k] = aktuellerSpieler;
                    }
                }

            }
            
        }
        

    }


}




/**
 * @brief Funktion zur Berechnung der möglichen Züge für einen Spieler
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return int Die Anzahl der möglichen Züge
 */
int moeglicheZuege(const int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    int counter = 0;
    // Hier erfolgt jetzt Ihre Implementierung ...
    for (int y = 0; y < GROESSE_Y; y++)
    {
        for (int x = 0; x < GROESSE_X; x++)
        {
            if (zugGueltig(spielfeld, aktuellerSpieler, x, y))
            {
                counter++;
            }
        }
    }
    return counter;

}


/**
 * @brief Erlauben eines menschlichen Zuges
 *
 * @param spielfeld Das aktuelle Spielfeld
 * @param aktuellerSpieler Der aktuelle Spieler
 * @return true, wenn der Zug erfolgreich war
 * @return false, wenn der Zug nicht erfolgreich war
 */

bool menschlicherZug(int spielfeld[GROESSE_Y][GROESSE_X], const int aktuellerSpieler)
{
    std::cout << "Spieler " << aktuellerSpieler << " ist am Zug." << std::endl;
    std::cout << "Welcher Zug möchten Sie ausführen?" << std::endl;
    std::string zugPlatz;
    std::cin >> zugPlatz;

    int posX = (char)tolower(zugPlatz[0]) - 'a'; // Umwandeln von A-H oder a-h in 0-7
    int posY = zugPlatz[1] - '1'; // Umwandeln von 1-8 in 0-7

    if (moeglicheZuege(spielfeld, aktuellerSpieler) == 0)
    {
        return false;
    }

    if (zugGueltig(spielfeld, aktuellerSpieler, posX, posY) == true)
    {
        zugAusfuehren(spielfeld, aktuellerSpieler, posX, posY);
        return true;
    }
    else
    {
        std::cout << "Ungültiger Zug. Bitte versuchen Sie es erneut." << std::endl;
        return false;
    }

   
}


/**
 * @brief Funktion zum Spielen des Spiels
 * 
 * @param spielerTyp // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
 */

void spielen(const int spielerTyp[2])
{
    int spielfeld[GROESSE_Y][GROESSE_X];

    //Erzeuge Startaufstellung
    initialisiereSpielfeld(spielfeld);

    int aktuellerSpieler = 1;
    zeigeSpielfeld(spielfeld);

    // solange noch Zuege bei einem der beiden Spieler moeglich sind
    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    while (moeglicheZuege(spielfeld, 1) > 0 || moeglicheZuege(spielfeld, 2) > 0)
    {
        if (spielerTyp[aktuellerSpieler - 1] == MENSCH){
            menschlicherZug(spielfeld, aktuellerSpieler);
            zeigeSpielfeld(spielfeld);
            

            aktuellerSpieler = 3 - aktuellerSpieler; // Spieler wechseln
        }else if (spielerTyp[aktuellerSpieler - 1] == COMPUTER){
            computerZug(spielfeld, aktuellerSpieler);
            zeigeSpielfeld(spielfeld);
            

            aktuellerSpieler = 3 - aktuellerSpieler; // Spieler wechseln
        }
    }
    
    switch (gewinner(spielfeld))
    {
        // Hier erfolgt jetzt Ihre Implementierung ...
        case 0:
            std::cout << "Unentschieden!" << std::endl;
            break;
        case 1:
            std::cout << "Spieler 1 gewinnt!" << std::endl;
            break;
        case 2:
            std::cout << "Spieler 2 gewinnt!" << std::endl;
            break;
    }
}

/**
 * @brief Hauptfunktion des Spiels
 * 
 * @return int 
 */
int main()
{
    if (TEST == 1)
    {
        bool gesamtErgebnis = ganzenTestAusfuehren();
        if (gesamtErgebnis == true)
        {
            std::cout << "ALLE TESTS BESTANDEN!" << std::endl;
        }
        else
        {
            std::cout << "MINDESTENS EIN TEST IST FEHLGESCHLAGEN!" << std::endl;
            exit(1);
        }
        std::cout << std::endl << std::endl;
    }
    
    // Die folgenden drei Zeilen werden auskommentiert oder geloescht, nachdem Sie die Funktion spielen()
    // implementiert haben (waeren sonst doppelt)
    int spielfeld[GROESSE_Y][GROESSE_X];

    initialisiereSpielfeld(spielfeld);

    zeigeSpielfeld(spielfeld);

    int spielerTyp2[2] = { COMPUTER, COMPUTER };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)
    spielen(spielerTyp2);

    int spielerTyp[2] = { MENSCH, MENSCH };  // Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)

    spielen(spielerTyp);  // Aufruf der Funktion spielen() mit einem Feld, das Informationen ueber den Typ des Spielers enthaelt. MENSCH(=1) oder COPMUTER(=2)



    //
    // Hier erfolgt jetzt Ihre Implementierung ...
    
    return 0;
}
