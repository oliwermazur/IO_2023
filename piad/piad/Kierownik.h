#ifndef PIAD_KIEROWNIK_H
#define PIAD_KIEROWNIK_H

#include <iostream>
#include <vector>
#include "Magazyn.h"
#include "Zamowienia.h"

class Kierownik {
public:
    Kierownik(Magazyn& magazyn, Zamowienie& zamowienie) : magazyn(magazyn), zamowienie(zamowienie) {}

    void sprawdzZlozoneZamowienia() const;
    //void anulujZamowienie(int zamowienieId);
    //void przekazZamowienieDoRealizacji(int zamowienieId);
    void sprawdzStanMagazynu();
private:
    Magazyn& magazyn;
    Zamowienie& zamowienie;
};

#endif //PIAD_KIEROWNIK_H