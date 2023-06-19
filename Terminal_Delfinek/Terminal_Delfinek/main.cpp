#include <iostream>
#include <vector>
#include "Magazyn.h"
#include "Pracownik.h"
#include "Kierownik.h"
#include "Klient.h"
#include "Zamowienia.h"
#include "Personel.h"
#include "Osoby_funkcje_switch.h"

int main() {
    Magazyn magazyn;
    Personel personel;
    Zamowienie zamowienie(magazyn);
    Zamowienie zamowienie_realizacja(magazyn);
    Pracownik pracownik(magazyn,zamowienie_realizacja);
    Kierownik kierownik(magazyn,zamowienie,zamowienie_realizacja);
    Sekretarka sekretarka(zamowienie_realizacja,personel);



    Klient klient(magazyn,zamowienie);


    magazyn.dodajTowar(1, "Piasek", 150,70);
    magazyn.dodajTowar(2, "Szklo", 100,110);
    magazyn.dodajTowar(3, "Cegly", 500,270);
    magazyn.dodajTowar(4, "Cement", 80,250);
    magazyn.dodajTowar(5, "Farba", 200,10);
    magazyn.dodajTowar(6, "Druty", 1000,60);
    magazyn.dodajTowar(7, "Zaslony", 60,70);
    magazyn.dodajTowar(8, "Plytki ceramiczne", 300,10);
    magazyn.dodajTowar(9, "Gwozdzie", 10000,1);
    magazyn.dodajTowar(10, "Listwy przypodlogowe", 150,200);


    // Dodawanie pracowników
    personel.dodajOsobe(1,"Jan", "Kowalski", 20.0, "Pracownik");
    personel.dodajOsobe(2,"Anna", "Nowak", 18.5, "Pracownik");
    personel.dodajOsobe(3,"Piotr", "Nowicki", 18.5, "Pracownik");
    personel.dodajOsobe(4,"Katarzyna", "Wisniewska", 18.5, "Pracownik");
    personel.dodajOsobe(5,"Tomasz", "Wojcik", 18.5, "Pracownik");
    personel.dodajOsobe(6,"Malgorzata", "Kowalczyk", 18.5, "Pracownik");
    personel.dodajOsobe(7,"Marcin", "Kaminski", 18.5, "Pracownik");
    personel.dodajOsobe(8,"Agnieszka", "Lewandowska", 18.5, "Pracownik");
    personel.dodajOsobe(9,"Michal", "Zielinski", 18.5, "Pracownik");
    personel.dodajOsobe(10,"Krystyna", "Szymanska", 18.5, "Pracownik");
    personel.dodajOsobe(11,"Adam", "Woziak", 18.5, "Pracownik");
    personel.dodajOsobe(12,"Barbara", "Dabrowska", 18.5, "Pracownik");
    personel.dodajOsobe(13,"Robert", "Kozlowski", 18.5, "Pracownik");
    personel.dodajOsobe(14,"Ewa", "Jankowska", 18.5, "Pracownik");
    personel.dodajOsobe(15,"Krzysztof", "Mazur", 18.5, "Pracownik");
    personel.dodajOsobe(16,"Maria", "Wojciechowska", 18.5, "Pracownik");
    personel.dodajOsobe(17,"Andrzej", "Kwiatkowski", 18.5, "Pracownik");
    personel.dodajOsobe(18,"Kevin", "Iq", 25, "Pracownik");

// Dodawanie sekretarki
    personel.dodajOsobe(19,"Monika", "Nowakowska", 25.0, "Sekretarka");

// Dodawanie kierownika
    personel.dodajOsobe(20,"Janusz", "Kowalczykowski", 40.0, "Kierownik");


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
                switch_kierownik(kierownik,magazyn,zamowienie,zamowienie_realizacja);
                break;
            case 4:
                switch_sekretarka(sekretarka,personel,zamowienie_realizacja );
                break;
            case 0:
                std::cout << "Koniec programu.\n";
                zamowienie.wyczyscWszystkieZamowienia();
                break;
            default:
                std::cout << "Nieprawidlowa opcja.\n";
                break;
        }

        std::cout << std::endl;
    } while (opcja != 0);

    return 0;
}
