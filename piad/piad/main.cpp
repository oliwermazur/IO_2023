#include <iostream>
#include <vector>
#include <algorithm>
#include "Magazyn.h"
#include "Pracownik.h"
#include "Kierownik.h"
#include "Klient.h"
#include "Zamowienia.h"
#include "Osoby_funkcje_switch.h"

int main() {
    Magazyn magazyn;
    Zamowienie zamowienie(magazyn);
    Pracownik pracownik(magazyn);
    Kierownik kierownik(magazyn,zamowienie);
    Klient klient(magazyn,zamowienie);

    magazyn.dodajTowar(1, "Piasek", 150);
    magazyn.dodajTowar(2, "Szklo", 100);
    magazyn.dodajTowar(3, "Cegly", 500);
    magazyn.dodajTowar(4, "Cement", 80);
    magazyn.dodajTowar(5, "Farba", 200);
    magazyn.dodajTowar(6, "Druty", 1000);
    magazyn.dodajTowar(7, "Zaslony", 60);
    magazyn.dodajTowar(8, "Plytki ceramiczne", 300);
    magazyn.dodajTowar(9, "Gwozdzie", 10000);
    magazyn.dodajTowar(10, "Listwy przypodlogowe", 150);


    int opcja;

    do {

        system("cls");
        std::cout << "Menu:\n";
        std::cout << "1. Klient\n";
        std::cout << "2. Pracownik\n";
        std::cout << "3. Kierownik\n";
        std::cout << "4. Sekretarka\n";
        std::cout << "0. Wyjscie\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;

        switch (opcja) {
            case 1:
                switch_klient(klient,magazyn,zamowienie);
                break;
            case 2:
                switch_pracownik(pracownik);
                break;
            case 3:
                switch_kierownik(kierownik,magazyn,zamowienie);
                break;
            case 4:
                // Funkcja dla opcji Sekretarka
                break;
            case 0:
                std::cout << "Koniec programu.\n";
                break;
            default:
                std::cout << "Nieprawidlowa opcja.\n";
                break;
        }

        std::cout << std::endl;
    } while (opcja != 0);

    return 0;
}
