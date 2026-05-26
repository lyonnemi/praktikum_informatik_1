//////////////////////////////////////////////////////////////////////////////
// Praktikum Informatik 1 MMXXVI
// Versuch 02
//
// Datei:  main.cpp
// Inhalt: Hauptprogramm
//////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <chrono>

int fibonacci(int n)
{
    int previousFib = 1;
    int currentFib = 1;
    if(n == 0)
    {
        return 0;
    }
    if(n == 1)
    {
        return 1;
    }
    for (int i = 2; i < n; i++)
    {
        int newFib = previousFib + currentFib ;
        previousFib = currentFib ;
        currentFib = newFib ;
    }
    return currentFib ;
}

// Rekursive Fibonacci aus Versuch02_Teil1
int fibonacci_rek(int n) {
    // Basis-Fälle
    if (n == 0) {
        return 0;
    }
    if (n == 1) {
        return 1;
    }
    // Rekursiver Aufruf
    return fibonacci_rek(n - 1) + fibonacci_rek(n - 2);
}

int main ()
{
    std::cout << " Fibonacci - Zahlen von 0 bis 12:" << std::endl ;
    for (int i = 1; i <= 12 ; i ++)
    {
        std::cout << "f(" << i << ") = " << fibonacci(i) << std::endl ;
    }
    
    // Laufzeit fuer n = 42 (iterativ)
    auto start = std::chrono::high_resolution_clock::now();
    int result = fibonacci(42);
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::nanoseconds>(end - start);
    std::cout << "f(42) iterativ = " << result << " (" << duration.count() << " nanoseconds)" << std::endl;
    
    // Laufzeit fuer n = 42 (rekursiv)
    auto start_rek = std::chrono::high_resolution_clock::now();
    int result_rek = fibonacci_rek(42);
    auto end_rek = std::chrono::high_resolution_clock::now();
    auto duration_rek = std::chrono::duration_cast<std::chrono::milliseconds>(end_rek - start_rek);
    std::cout << "f(42) rekursiv = " << result_rek << " (" << duration_rek.count() << " milliseconds)" << std::endl;


    if (duration.count() < duration_rek.count()) {
        std::cout << "Die iterative Implementierung ist schneller als die rekursive Implementierung." << std::endl;
    } else if (duration.count() > duration_rek.count()) {
        std::cout << "Die rekursive Implementierung ist schneller als die iterative Implementierung." << std::endl;
    } else {
        std::cout << "Beide Implementierungen haben die gleiche Laufzeit." << std::endl;
    }
    std::cout << "\nErklärung: Ab der 47. Fibonacci-Zahl treten falsche Ergebnisse aufgrund ganzzahligen Überlaufs bei Verwendung von 'int' auf." << std::endl;
    std::cout << "Lösung: Verwende einen größeren Ganzzahlentyp wie 'long long' oder 'unsigned long long', um Werte bis zur 92. (bzw. 93.) Fibonacci-Zahl korrekt darzustellen." << std::endl;
    return 0;
}
