#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include "Magazyn.h"
#include <fstream>
#include <iostream>
#include <vector>

class Zamowienie {
public:
    Zamowienie(Magazyn& magazyn) : magazyn(magazyn) {}
    void utworzNoweZamowienie();
    void dodajTowarDoZamowienia(int towarId, int ilosc);
    void wyswietlZamowienie(int zamowienieId) const;
    void zapiszZamowienie(int zamowienieId) const;
    void usunZamowienie(int zamowienieId);
    void wyczyscZamowienie(int zamowienieId);
    std::vector<std::pair<Magazyn::Towar, int>> pobierzZamowienie(int zamowienieId) const;
    std::vector<int> pobierzWszystkieZamowienia() const;
    void wyswietlWszystkieZamowienia() const;

private:
    Magazyn& magazyn;
    std::vector<std::vector<std::pair<Magazyn::Towar, int>>> zamowienia;
};

#endif
