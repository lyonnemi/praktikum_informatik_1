#include <iostream>

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
int main() {
    for (int i  = 0; i <= 25; i++){
        std::cout << fibonacci_rek(i) << std::endl;
    }
}
