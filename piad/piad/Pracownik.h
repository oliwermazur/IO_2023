#ifndef PIAD_PRACOWNIK_H
#define PIAD_PRACOWNIK_H

#include <iostream>
#include "Magazyn.h"
#include <fstream>

class Pracownik {
public:
    Pracownik(Magazyn& magazyn) : magazyn(magazyn) {}

    void wazPojazdBezTowaru();
    void wazPojazdZTowarem();
    void ewidencjonujWazenie();
    void sprawdzStanMagazynu();
    void dodajTowarDoMagazynu( const std::string& nazwa, int stan);
    void generujRaport();
private:
    Magazyn& magazyn;
    float wagaPojazduBezTowaru = 0.0f;
    float wagaPojazduZTowarem = 0.0f;
};

#endif //PIAD_PRACOWNIK_H
