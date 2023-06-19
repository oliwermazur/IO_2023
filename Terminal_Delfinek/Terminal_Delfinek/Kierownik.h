#ifndef PIAD_KIEROWNIK_H
#define PIAD_KIEROWNIK_H

#include <iostream>
#include <vector>
#include "Magazyn.h"
#include "Zamowienia.h"

class Kierownik {
public:
    Kierownik(Magazyn& magazyn, Zamowienie& zamowienie,Zamowienie& zamowienie_realizacja) : magazyn(magazyn), zamowienie(zamowienie),zamowienie_realizacja(zamowienie_realizacja) {}

    void sprawdzZlozoneZamowienia() const;
    void sprawdzRealizowaneZamowienia() const;
    void anulujZamowienie(int zamowienieId) const;
    void przekazZamowienieDoRealizacji(int zamowienieId);
    void sprawdzStanMagazynu();
private:
    Magazyn& magazyn;
    Zamowienie& zamowienie;
    Zamowienie& zamowienie_realizacja;
};

#endif