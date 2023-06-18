#include "Magazyn.h"

void Magazyn::dodajTowar(int id, const std::string& nazwa, int stan, double cena) {
    towary.emplace_back(id, nazwa, stan, cena);
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
        std::cout << "ID: " << towar.getId() << ", Nazwa: " << towar.getNazwa() << ", Ilosc: " << towar.getStan() << " (kg), Cena: " << towar.getCena() << " PLN/szt" << std::endl;
    }
    std::cout << std::endl;
}

void Magazyn::wyswietlTowary() {
    std::cout << "Towary na magazynie:\n";
    for (const auto& towar : towary) {
        std::cout << "ID: " << towar.getId() << ", Nazwa: " << towar.getNazwa() << ", Cena: " << towar.getCena() << " PLN/szt" << std::endl;
    }
    std::cout << std::endl;
}

void Magazyn::Towar::setStan(int nowyStan) {
    stan = nowyStan;
}

void Magazyn::setStan(int towarId, int nowyStan) {
    for (auto& towar : towary) {
        if (towar.getId() == towarId) {
            towar.setStan(nowyStan);
            return;
        }
    }
    // Jeśli nie znaleziono towaru o podanym ID, można wyświetlić odpowiednie komunikaty lub rzucić wyjątek.
    std::cout << "Nie znaleziono towaru o ID " << towarId << std::endl;
}

void Magazyn::usunTowar(int towarId) {
    // Znajdź indeks towaru o podanym ID
    auto it = std::find_if(towary.begin(), towary.end(), [&](const Towar& towar) {
        return towar.getId() == towarId;
    });

    if (it != towary.end()) {
        // Usuń towar z magazynu
        towary.erase(it);
        std::cout << "Towar o ID " << towarId << " zostal usuniety z magazynu." << std::endl;

        // Zaktualizuj ID dla pozostałych towarów
        for (auto& towar : towary) {
            if (towar.getId() > towarId) {
                towar.setId(towar.getId() - 1);
            }
        }
    } else {
        std::cout << "Towar o ID " << towarId << " nie istnieje w magazynie." << std::endl;
    }
}

void Magazyn::Towar::setId(int newId) {
    id = newId;
}

Magazyn::Towar Magazyn::pobierzTowar(int towarId) const {
    for (const auto& towar : towary) {
        if (towar.getId() == towarId) {
            return towar;
        }
    }
    // Zwracanie pustego obiektu Towar, gdy nie znaleziono towaru o podanym ID
    return Towar(-1, "", 0, 0.0);
}
