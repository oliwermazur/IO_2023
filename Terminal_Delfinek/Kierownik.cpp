#include "Kierownik.h"

void Kierownik::sprawdzStanMagazynu() {
    magazyn.wyswietlTowaryPracownik();
}

void Kierownik::sprawdzZlozoneZamowienia() const{
    zamowienie.wyswietlWszystkieZamowienia();

}

void Kierownik::sprawdzRealizowaneZamowienia() const{
    zamowienie_realizacja.wyswietlWszystkieZamowienia();

}


void Kierownik::anulujZamowienie(int zamowienieId) const{
    zamowienie.usunZamowienie(zamowienieId);

}

void Kierownik::przekazZamowienieDoRealizacji(int zamowienieId) {
    if (zamowienieId >= 0 && zamowienieId < zamowienie.pobierzRozmiarZamowien()) {
        const std::vector<std::pair<Magazyn::Towar, int>>& zamowienieDoPrzekazania = zamowienie.pobierzZamowienie(zamowienieId);
        zamowienie_realizacja.dodajZamowienie(zamowienieDoPrzekazania);

        zamowienie.usunZamowienie(zamowienieId);

        std::cout << "Zamowienie przekazane do realizacji.\n\n";
    } else {
        std::cout << "Nieprawidlowe ID zamowienia.\n\n";
    }
}
