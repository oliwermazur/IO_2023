#include "Magazyn.h"

void Magazyn::dodajTowar(int id, const std::string& nazwa, int stan) {
    towary.emplace_back(id, nazwa, stan);
}

int Magazyn::sprawdzStanTowaru(int towarId) {
    for (const auto& towar : towary) {
        if (towar.getId() == towarId) {
            return towar.getStan();
        }
    }
    return -1;
}
void Magazyn::wyswietlTowaryPracownik() {
    std::cout << "Towary na magazynie:\n";
    for (const auto& towar : towary) {
        std::cout << "ID: " << towar.getId() << ", Nazwa: " << towar.getNazwa() << ", Ilosc: " << towar.getStan() <<"(kg)"<< std::endl;
    }
    std::cout << std::endl;
}
void Magazyn::wyswietlTowary() {
    std::cout << "Towary na magazynie:\n";
    for (const auto& towar : towary) {
        std::cout << "ID: " << towar.getId() << ", Nazwa: " << towar.getNazwa() << std::endl;
    }
    std::cout << std::endl;
}




