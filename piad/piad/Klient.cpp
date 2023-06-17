#include "Klient.h"

void Klient::anulujZamowienie(int zamowienieId) {
    zamowienie.wyczyscZamowienie(zamowienieId);
    std::cout << "Zamowienie anulowane.\n\n";
}

void Klient::zatwierdzZamowienie(int zamowienieId)const {
    if (zamowienie.pobierzZamowienie(zamowienieId).empty()) {
        std::cout << "Zamowienie jest puste. Nie mozna zatwierdzic.\n\n";
        return;
    }

    zamowienie.wyswietlZamowienie(zamowienieId);
    zamowienie.zapiszZamowienie(zamowienieId);


    std::cout << "Zamowienie zostalo zatwierdzone i przekazane do realizacji.\n\n";
}
