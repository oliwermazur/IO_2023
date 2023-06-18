#ifndef PIAD_KLIENT_H
#define PIAD_KLIENT_H

#include <vector>
#include "Magazyn.h"
#include "Zamowienia.h"

class Klient {
public:
    Klient(Magazyn& magazyn, Zamowienie& zamowienie) : magazyn(magazyn), zamowienie(zamowienie) {}


    void anulujZamowienie(int zamowienieId);
    void zatwierdzZamowienie(int zamowienieId)const;

private:
    Magazyn& magazyn;
    Zamowienie& zamowienie;
};

#endif
