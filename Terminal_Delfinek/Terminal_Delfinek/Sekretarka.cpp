#include "Sekretarka.h"



    void Sekretarka::wprowadzDanePrzepracowanychGodzin() {
        int pracownikIndex = wybierzPracownika(personel.pobierzOsoby());
        if (pracownikIndex != -1) {
            int godziny;
            std::cout << "Wprowadz liczbe przepracowanych godzin: ";
            std::cin >> godziny;

            personel.pobierzOsoby()[pracownikIndex].setGodziny(godziny);
            std::cout << "Dane zostaly wprowadzone." << std::endl;
        } else {
            std::cout << "Nieprawidlowy indeks pracownika." << std::endl;
        }
    }

    void Sekretarka::obliczWynagrodzenie() {
        int pracownikIndex = wybierzPracownika(personel.pobierzOsoby());
        if (pracownikIndex != -1) {
            double wynagrodzenie = personel.pobierzOsoby()[pracownikIndex].getWynagrodzenie();
            std::cout << "Wynagrodzenie pracownika: " << wynagrodzenie << std::endl;
        } else {
            std::cout << "Nieprawidlowy indeks pracownika." << std::endl;
        }
    }

    void Sekretarka::wprowadzPremie() {
        int pracownikIndex = wybierzPracownika(personel.pobierzOsoby());
        if (pracownikIndex != -1) {
            double premia;
            std::cout << "Wprowadz premię: ";
            std::cin >> premia;

            double stawka = personel.pobierzOsoby()[pracownikIndex].getStawka();
            double noweWynagrodzenie = personel.pobierzOsoby()[pracownikIndex].getWynagrodzenie() + premia;
            personel.pobierzOsoby()[pracownikIndex].setStawka(stawka + premia);
            personel.pobierzOsoby()[pracownikIndex].setWynagrodzenie(noweWynagrodzenie);

            std::cout << "Premia zostala wprowadzona." << std::endl;
        } else {
            std::cout << "Nieprawidlowy indeks pracownika." << std::endl;
        }
    }

    void Sekretarka::zatwierdzWynagrodzenie() {
        int pracownikIndex = wybierzPracownika(personel.pobierzOsoby());
        if (pracownikIndex != -1) {
            // Można tutaj dodać logikę zatwierdzania wynagrodzenia
            std::cout << "Wynagrodzenie zostalo zatwierdzone." << std::endl;
        } else {
            std::cout << "Nieprawidlowy indeks pracownika." << std::endl;
        }
    }

    void Sekretarka::przeprowadzPlatnosc() {
        int pracownikIndex = wybierzPracownika(personel.pobierzOsoby());
        if (pracownikIndex != -1) {
            // Można tutaj dodać logikę przeprowadzania płatności
            std::cout << "Płatnosc zostala przeprowadzona." << std::endl;
        } else {
            std::cout << "Nieprawidlowy indeks pracownika." << std::endl;
        }
    }

    void Sekretarka::ksiegujPlatnosc() {
        int pracownikIndex = wybierzPracownika(personel.pobierzOsoby());
        if (pracownikIndex != -1) {
            // Można tutaj dodać logikę księgowania płatności
            std::cout << "Platnosc zostala zaksiegowana." << std::endl;
        } else {
            std::cout << "Nieprawidlowy indeks pracownika." << std::endl;
        }
    }

    int Sekretarka::wybierzPracownika(const std::vector<Personel::Osoba>& personel) {
        int indeks;
        std::cout << "Wybierz indeks pracownika: ";
        std::cin >> indeks;

        if (indeks >= 0 && indeks < personel.size()) {
            return indeks;
        } else {
            return -1;
        }
    }
void Sekretarka::zatwierdzFakture(int zamowienieId)const {
    if (zamowienie_realizacja.pobierzZamowienie(zamowienieId).empty()) {
        std::cout << "Zamowienie jest puste. Nie mozna zatwierdzic.\n\n";
        return;
    }

    zamowienie_realizacja.wyswietlZamowienie(zamowienieId);
    std::cout << "Faktura zostala zatwierdzona i przekazana do bazy danych.\n\n";
}


