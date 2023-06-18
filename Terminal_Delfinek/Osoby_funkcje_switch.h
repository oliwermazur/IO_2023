#ifndef PIAD_OSOBY_FUNKCJE_SWITCH_H
#define PIAD_OSOBY_FUNKCJE_SWITCH_H
#include <iostream>
#include <vector>
#include <algorithm>
#include "Magazyn.h"
#include "Pracownik.h"
#include "Kierownik.h"
#include "Personel.h"
#include "Sekretarka.h"
#include "Klient.h"
void switch_klient(Klient& klient,Magazyn& magazyn,Zamowienie& zamowienie);
void switch_pracownik(Pracownik& pracownik);
void switch_kierownik(Kierownik& kierownik,Magazyn& magazyn,Zamowienie& zamowienie,Zamowienie& zamowienie_realizacja);
void switch_sekretarka(Sekretarka& sekretarka,Personel& pracownik);
#endif
