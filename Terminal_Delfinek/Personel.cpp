#include "Personel.h"
void Personel::dodajOsobe(const int id,const std::string& imie, const std::string& nazwisko, double stawka, const std::string& rola) {
    Osoba nowaOsoba(id,imie, nazwisko, stawka, rola);
    osoby.push_back(nowaOsoba);
}

std::vector<Personel::Osoba>& Personel::pobierzOsoby() {
    return osoby;
}

const std::vector<Personel::Osoba>& Personel::pobierzOsoby() const {
    return osoby;
}
#include <iomanip> // Dodaj bibliotekę <iomanip>

void Personel::wyswietlOsoby() {
    std::cout << "Lista osob w personelu:" << std::endl;
    std::cout << std::left << std::setw(5) << "ID" << std::setw(10) << "Imie" << std::setw(10) << "Nazwisko"
              << std::setw(15) << "Rola" << std::setw(10) << "Stawka"
              << std::setw(15) << "Godziny" << std::setw(10) << "Wynagrodzenie" << std::endl;

    for (const auto& osoba : osoby) {
        std::cout << std::setw(5) << osoba.getId() << std::setw(10) << osoba.getImie() << std::setw(10) << osoba.getNazwisko()
                  << std::setw(15) << osoba.getRola() << std::setw(10) << osoba.getStawka()
                  << std::setw(15) << osoba.getGodziny() << std::setw(10) << osoba.getWynagrodzenie() << std::endl;
    }
}

