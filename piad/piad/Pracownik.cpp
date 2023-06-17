#include "Pracownik.h"

void Pracownik::wazPojazdBezTowaru() {
    wagaPojazduBezTowaru = rand() % 1000;
    std::cout << "Pojazd bez towaru wazy: " << wagaPojazduBezTowaru << " kg\n";
}

void Pracownik::wazPojazdZTowarem() {
    wagaPojazduZTowarem = wagaPojazduBezTowaru + (rand() % 500);
    std::cout << "Pojazd z towarem wazy: " << wagaPojazduZTowarem << " kg\n";
}

void Pracownik::ewidencjonujWazenie() {
    float wagaTowaru = wagaPojazduZTowarem - wagaPojazduBezTowaru;
    std::cout << "Waga towaru: " << wagaTowaru << " kg\n";
}

void Pracownik::sprawdzStanMagazynu() {
    magazyn.wyswietlTowaryPracownik();
}

void Pracownik::dodajTowarDoMagazynu(const std::string& nazwa, int stan) {
    int id = 0;

    std::vector<Magazyn::Towar> towary = magazyn.pobierzTowary();

    for (const auto& towar : towary) {
        if (towar.getId() > id) {
            id = towar.getId();
        }
    }

    id++;

    magazyn.dodajTowar(id, nazwa, stan);
    std::cout << "Towar " << nazwa << " dodany do magazynu. Aktualizacja bazy danych...\n";
}


void Pracownik::generujRaport() {
    std::cout << "Generowanie raportu o stanie magazynu...\n";
    std::vector<Magazyn::Towar> towary = magazyn.pobierzTowary();
    std::ofstream raport("raport.txt");
    if (!raport) {
        std::cerr << "Nie mozna otworzyc pliku!\n";
        return;
    }
    for (const auto& towar : towary) {
        raport << "ID: " << towar.getId() << ", Nazwa: " << towar.getNazwa() << ", Stan: " << towar.getStan() << "\n";
    }
    std::cout << "Raport zapisany do pliku raport.txt\n";
    raport.close();

}
