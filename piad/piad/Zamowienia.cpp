#include "Zamowienia.h"

void Zamowienie::utworzNoweZamowienie() {
    zamowienia.push_back(std::vector<std::pair<Magazyn::Towar, int>>());
}

void Zamowienie::dodajTowarDoZamowienia(int towarId, int ilosc) {

    utworzNoweZamowienie();
    std::vector<std::pair<Magazyn::Towar, int>>& biezaceZamowienie = zamowienia.back();


    Magazyn::Towar towar = magazyn.pobierzTowar(towarId);
    if (towar.getId() != -1) {
        int stanTowaru = magazyn.sprawdzStanTowaru(towarId);
        if (stanTowaru == -1) {
            std::cout << "Nie ma towaru o podanym ID.\n\n";
            return;
        }

        int ilosc2 = 0;
        std::cout << "Stan towaru na magazynie: " << stanTowaru << std::endl;
        std::cout << "Podaj ilość towaru, jaka chcesz zamówić (Podaj -1, aby powrócić): ";
        std::cin >> ilosc2;
        if (ilosc2 < 0) {
            return;
        }

        if (ilosc + ilosc2 > stanTowaru) {
            std::cout << "Nie ma wystarczającej ilości towaru na magazynie.\n\n";
            return;
        }

        ilosc += ilosc2;

        biezaceZamowienie.push_back(std::make_pair(towar, ilosc));
        std::cout << "Towar dodany do zamówienia.\n\n";
    } else {
        std::cout << "Nie ma towaru o podanym ID.\n\n";
        return;
    }
}

void Zamowienie::wyswietlZamowienie(int zamowienieId) const {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamówienia o podanym ID.\n\n";
        return;
    }

    const std::vector<std::pair<Magazyn::Towar, int>>& zam = zamowienia[zamowienieId];
    if (zam.empty()) {
        std::cout << "Zamówienie jest puste.\n";
    } else {
        std::cout << "Zamówienie #" << zamowienieId << ":\n";
        for (const auto& para : zam) {
            std::cout << "Towar: " << para.first.getNazwa() << ", Ilość: " << para.second << "\n";
        }
    }
}

void Zamowienie::zapiszZamowienie(int zamowienieId) const {
    // Implementacja zapisu zamówienia o podanym ID
}

void Zamowienie::usunZamowienie(int zamowienieId) {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamówienia o podanym ID.\n\n";
        return;
    }

    zamowienia.erase(zamowienia.begin() + zamowienieId);
    std::cout << "Zamówienie usunięte.\n\n";
}

void Zamowienie::wyczyscZamowienie(int zamowienieId) {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamówienia o podanym ID.\n\n";
        return;
    }

    zamowienia[zamowienieId].clear();
    std::cout << "Zamówienie wyczyszczone.\n\n";
}

std::vector<std::pair<Magazyn::Towar, int>> Zamowienie::pobierzZamowienie(int zamowienieId) const {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamówienia o podanym ID.\n\n";
        return std::vector<std::pair<Magazyn::Towar, int>>();
    }

    return zamowienia[zamowienieId];
}

std::vector<int> Zamowienie::pobierzWszystkieZamowienia() const {
    std::vector<int> listaZamowien;
    for (int i = 0; i < zamowienia.size(); ++i) {
        listaZamowien.push_back(i);
    }
    return listaZamowien;
}

void Zamowienie::wyswietlWszystkieZamowienia() const {
    if (zamowienia.empty()) {
        std::cout << "Brak zamówień.\n";
    } else {
        std::cout << "Lista zamówień:\n";
        for (int i = 0; i < zamowienia.size(); ++i) {
            std::cout << "Zamówienie #" << i << ":\n";
            const std::vector<std::pair<Magazyn::Towar, int>>& zam = zamowienia[i];
            for (const auto& para : zam) {
                std::cout << "Towar: " << para.first.getNazwa() << ", Ilość: " << para.second << "\n";
            }
            std::cout << "\n";
        }
    }
}
