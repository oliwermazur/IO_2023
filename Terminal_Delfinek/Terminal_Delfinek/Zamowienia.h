#ifndef ZAMOWIENIE_H
#define ZAMOWIENIE_H

#include "Magazyn.h"
#include <fstream>
#include <iostream>
#include <vector>

class Zamowienie {
public:

    Zamowienie(Magazyn& magazyn) : magazyn(magazyn) {}
    void utworzNoweZamowienie(int zamowienieId);
    void dodajTowarDoZamowienia(int towarId, int &ilosc, int zamowienieId);
    void wyswietlZamowienie(int zamowienieId) const;
    void zapiszZamowienie(int zamowienieId) const;
    void usunZamowienie(int zamowienieId);
    void wyczyscZamowienie(int zamowienieId);
    std::vector<std::pair<Magazyn::Towar, int>>& pobierzZamowienie(int zamowienieId) ;
    void wyswietlWszystkieZamowienia() const;
    void wyczyscWszystkieZamowienia();
    int pobierzRozmiarZamowien() const;
    void podliczCeneIZaplac(int zamowienieId) const;
    void dodajZamowienie(const std::vector<std::pair<Magazyn::Towar, int>>& zamowienie);
private:
    int aktualneZamowienieId;
    Magazyn& magazyn;
    std::vector<std::vector<std::pair<Magazyn::Towar, int>>> zamowienia;
};

#endif
