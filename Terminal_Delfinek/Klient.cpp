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


    zamowienie.zapiszZamowienie(zamowienieId);
    zamowienie.podliczCeneIZaplac(zamowienieId);



    std::cout << "Zamowienie zostalo zatwierdzone i przekazane do biura.\n\n";
}
