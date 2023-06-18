#include "Zamowienia.h"


void Zamowienie::utworzNoweZamowienie(int zamowienieId) {
    zamowienia.push_back(std::vector<std::pair<Magazyn::Towar, int>>());
    aktualneZamowienieId = zamowienieId;
}

void Zamowienie::dodajTowarDoZamowienia(int towarId, int &ilosc, int zamowienieId) {

    if (zamowienieId >= 0 && zamowienieId < zamowienia.size()) {
        std::vector<std::pair<Magazyn::Towar, int>>& biezaceZamowienie = zamowienia[zamowienieId];

        Magazyn::Towar towar = magazyn.pobierzTowar(towarId);
        if (towar.getId() != -1) {
            int stanTowaru = magazyn.sprawdzStanTowaru(towarId);
            if (stanTowaru == -1) {
                std::cout << "Nie ma towaru o podanym ID.\n\n";
                return;
            }

            int ilosc2 = 0;
            std::cout << "Stan towaru na magazynie: " << stanTowaru << std::endl;
            std::cout << "Podaj ilosc towaru, jaka chcesz zamowic (Podaj -1, aby powrocic): ";
            std::cin >> ilosc2;
            if (ilosc2 < 0) {
                return;
            }

            if (ilosc + ilosc2 > stanTowaru) {
                std::cout << "Nie ma wystarczajacej ilosci towaru na magazynie.\n\n";
                return;
            }

            ilosc += ilosc2;

            // Sprawdź, czy towar już istnieje w zamówieniu
            for (auto& para : biezaceZamowienie) {
                if (para.first.getId() == towar.getId()) {
                    // Jeśli towar już istnieje, zaktualizuj jego ilość
                    para.second = ilosc;
                    std::cout << "Ilosc towaru zaktualizowana w zamowieniu.\n\n";
                    return;
                }
            }

            biezaceZamowienie.push_back(std::make_pair(towar, ilosc));
            std::cout << "Towar dodany do zamowienia.\n\n";
        } else {
            std::cout << "Nie ma towaru o podanym ID.\n\n";
            return;
        }
    } else {
        std::cout << "Nieprawidlowe ID zamówienia.\n\n";
        return;
    }
}

void Zamowienie::wyswietlZamowienie(int zamowienieId) const {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamowienia o podanym ID.\n\n";
        return;
    }

    const std::vector<std::pair<Magazyn::Towar, int>>& zam = zamowienia[zamowienieId];
    if (zam.empty()) {
        std::cout << "Koszyk jest pusty.\n";
    } else {
        std::cout << "Zamowienie #" << zamowienieId << ":\n";
        for (const auto& para : zam) {
            std::cout << "Towar: " << para.first.getNazwa() << ", Ilosc: " << para.second << "\n";
        }
    }
}

void Zamowienie::zapiszZamowienie(int zamowienieId) const {
    // Implementacja zapisu zamówienia o podanym ID
}

void Zamowienie::usunZamowienie(int zamowienieId) {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamowienia o podanym ID.\n\n";
        return;
    }

    zamowienia.erase(zamowienia.begin() + zamowienieId);
    std::cout << "Zamowienie usuniete.\n\n";
}

void Zamowienie::wyczyscZamowienie(int zamowienieId) {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamowienia o podanym ID.\n\n";
        return;
    }

    zamowienia[zamowienieId].clear();
    std::cout << "Zamowienie wyczyszczone.\n\n";
}

std::vector<std::pair<Magazyn::Towar, int>>& Zamowienie::pobierzZamowienie(int zamowienieId)  {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamowienia o podanym ID.\n\n";
    }

    return zamowienia[zamowienieId];
}

void Zamowienie::wyswietlWszystkieZamowienia() const {
    if (zamowienia.empty()) {
        std::cout << "Brak zamowien.\n";
    } else {
        std::cout << "Lista zamowien:\n";
        for (int i = 0; i < zamowienia.size(); ++i) {
            std::cout << "Zamowienie #" << i << ":\n";
            const std::vector<std::pair<Magazyn::Towar, int>>& zam = zamowienia[i];
            for (const auto& para : zam) {
                std::cout << "Towar: " << para.first.getNazwa() << ", Ilosc: " << para.second << "\n";
            }
            std::cout << "\n";
        }
    }
}

void Zamowienie::wyczyscWszystkieZamowienia() {
    zamowienia.clear();
}

int Zamowienie::pobierzRozmiarZamowien() const {
    return zamowienia.size();
}

void Zamowienie::dodajZamowienie(const std::vector<std::pair<Magazyn::Towar, int>>& zamowienie) {
    zamowienia.push_back(zamowienie);
}

void Zamowienie::podliczCeneIZaplac(int zamowienieId)const {
    if (zamowienieId < 0 || zamowienieId >= zamowienia.size()) {
        std::cout << "Nie ma zamowienia o podanym ID.\n\n";
        return;
    }

    double sumaCen = 0.0;
    const std::vector<std::pair<Magazyn::Towar, int>>& zam = zamowienia[zamowienieId];

    // Obliczanie sumy cen zamówionych towarów
    for (const auto& para : zam) {
        const Magazyn::Towar& towar = para.first;
        int ilosc = para.second;

        sumaCen += towar.getCena() * ilosc;
    }

    // Wyświetlanie podsumowania zamówienia
    std::cout << "Podsumowanie zamowienia #" << zamowienieId << ":\n";
    for (const auto& para : zam) {
        const Magazyn::Towar& towar = para.first;
        int ilosc = para.second;

        std::cout << "Towar: " << towar.getNazwa() << ", Ilosc: " << ilosc << ", Cena jednostkowa: " << towar.getCena() << " zl\n";
    }
    std::cout << "Suma zamowienia: " << sumaCen << " zl\n";

    // Prośba o wybór metody płatności
    std::cout << "\nWybierz metode platnosci:\n";
    std::cout << "1. Przelew bankowy\n";
    std::cout << "2. BLIK \n";
    std::cout << "3. Czek\n";

    int wybor;
    std::cin >> wybor;

    // Obsługa wybranej metody płatności
    switch (wybor) {
        case 1:
            std::cout << "Wybrano platnosc przelewem bankowym. Proszę dokonac przelewu na podane konto.\n";
            break;
        case 2:
            std::cout << "Wybrano platnosc BLIK. Prosze dokonac platnosci.\n";
            break;
        case 3:
            std::cout << "Wybrano Czek. Proszę wypelnic dane platnosci.\n";
            break;
        default:
            std::cout << "Nieprawidlowy wybor platnosci.\n";
            return;
    }

    std::cout << "Platnosc zostala zakonczona. Dziekujemy!\n";
}