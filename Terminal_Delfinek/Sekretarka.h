#ifndef PIAD_SEKRETARKA_H
#define PIAD_SEKRETARKA_H
#include "Personel.h"
#include <fstream>
#include <iostream>
#include <vector>

class Sekretarka {
public:

    void wprowadzDanePrzepracowanychGodzin(Personel& personel);
    void obliczWynagrodzenie(Personel& personel);
    void wprowadzPremie(Personel& personel);
    void zatwierdzWynagrodzenie(Personel& personel);
    void przeprowadzPlatnosc(Personel& personel);
    void ksiegujPlatnosc(Personel& personel);
    int wybierzPracownika(const std::vector<Personel::Osoba>& personel);

};




#endif
