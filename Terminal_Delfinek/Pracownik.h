#ifndef PIAD_PRACOWNIK_H
#define PIAD_PRACOWNIK_H

#include <iostream>
#include "Magazyn.h"
#include "Zamowienia.h"
#include <fstream>

class Pracownik {
public:
    Pracownik(Magazyn& magazyn,Zamowienie& zamowienie) : magazyn(magazyn), zamowienie(zamowienie) {}

    void wazPojazdBezTowaru();
    void wazPojazdZTowarem(int zamowienieId, int towarId);
    void ewidencjonujWazenie(int zamowienieId,int towarId);
    void sprawdzStanMagazynu();
    void dodajTowarDoMagazynu( const std::string& nazwa, int stan,int cena);
    void generujRaport();
    void sprawdzRealizowaneZamowienia() const;
    void zmodyfikujTowar(int towarId, int nowyStan);
    void usunTowar(int towarId);
private:
    Magazyn& magazyn;
    Zamowienie& zamowienie;
    float wagaPojazduBezTowaru = 0.0f;
    float wagaPojazduZTowarem = 0.0f;
};

#endif
