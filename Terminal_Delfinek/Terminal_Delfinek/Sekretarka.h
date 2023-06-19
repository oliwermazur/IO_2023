#ifndef PIAD_SEKRETARKA_H
#define PIAD_SEKRETARKA_H
#include "Personel.h"
#include "Zamowienia.h"
#include <fstream>
#include <iostream>
#include <vector>

class Sekretarka {
public:
    Sekretarka(Zamowienie& zamowienie_realizacja,Personel& personel) : personel(personel), zamowienie_realizacja(zamowienie_realizacja) {}
    void wprowadzDanePrzepracowanychGodzin();
    void obliczWynagrodzenie();
    void wprowadzPremie();
    void zatwierdzWynagrodzenie();
    void przeprowadzPlatnosc();
    void ksiegujPlatnosc();
    int wybierzPracownika(const std::vector<Personel::Osoba>& personel);
    void zatwierdzFakture(int zamowienieId)const;
private:
    Zamowienie& zamowienie_realizacja;
    Personel& personel;
};




#endif
