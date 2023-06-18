#include "Pracownik.h"

void Pracownik::wazPojazdBezTowaru() {
    if (wagaPojazduBezTowaru == 0.0f) {
        wagaPojazduBezTowaru = static_cast<float>(std::rand() % 5001 + 10000);
    }

    std::cout << "Waga pojazdu bez towaru: " << wagaPojazduBezTowaru << " kg" << std::endl;
}


void Pracownik::wazPojazdZTowarem(int zamowienieId, int towarId) {
    // Pobierz zamówienie o danym ID
    std::vector<std::pair<Magazyn::Towar, int>>& zamowieniee = zamowienie.pobierzZamowienie(zamowienieId);

    // Znajdź towar o danym ID w zamówieniu
    auto it = std::find_if(zamowieniee.begin(), zamowieniee.end(), [&](const std::pair<Magazyn::Towar, int>& element) {
        return element.first.getId() == towarId;
    });

    if (it != zamowieniee.end()) {
        // Pobierz ilość towaru
        int iloscTowaru = it->second;

        // Dodaj ilość towaru do wagi pojazdu na pusto
        wagaPojazduZTowarem=wagaPojazduBezTowaru + iloscTowaru;

        std::cout << "Waga pojazdu po dodaniu towaru o ID " << towarId << " z zamowienia o ID " << zamowienieId << ": " << wagaPojazduZTowarem << std::endl;
    } else {
        std::cout << "Nie znaleziono towaru o ID " << towarId << " w zamowieniu o ID " << zamowienieId << std::endl;
    }
}



void Pracownik::ewidencjonujWazenie(int zamowienieId, int towarId) {
    // Pobierz zamówienie o danym ID
    std::vector<std::pair<Magazyn::Towar, int>>& zamowieniee = zamowienie.pobierzZamowienie(zamowienieId);

    // Znajdź towar o danym ID w zamówieniu
    auto it = std::find_if(zamowieniee.begin(), zamowieniee.end(), [&](const std::pair<Magazyn::Towar, int>& element) {
        return element.first.getId() == towarId;
    });

    if (it != zamowieniee.end()) {
        // Oblicz różnicę wag pojazdów
        float roznicaWag = wagaPojazduZTowarem - wagaPojazduBezTowaru;

        // Pobierz ilość towaru w zamówieniu
        int ilosc = it->second;

        // Pobierz aktualny stan towaru w magazynie
        int aktualnyStan = magazyn.sprawdzStanTowaru(towarId);

        // Oblicz nowy stan towaru po uwzględnieniu różnicy wag
        int nowyStan = aktualnyStan - static_cast<int>(roznicaWag);

        // Uaktualnij stan towaru w magazynie
        magazyn.setStan(towarId, nowyStan);

        // Usuń towar z zamówienia
        zamowieniee.erase(it);

        std::cout << "Ewidencjonowanie wazenia zakonczone. Towar o ID " << towarId << " zostal usuniety z zamowienia o ID " << zamowienieId << std::endl;

        // Sprawdź czy zamówienie jest puste
        if (zamowieniee.empty()) {
            // Usuń zamówienie, jeśli jest puste
            zamowienie.usunZamowienie(zamowienieId);
            std::cout << "Zamowienie o ID " << zamowienieId << " zostalo usuniete, poniewaz nie zawiera juz zadnych towarow." << std::endl;
        }
    } else {
        std::cout << "Towar o ID " << towarId << " nie jest zawarty w zamowieniu o ID " << zamowienieId << std::endl;
    }
}



void Pracownik::sprawdzStanMagazynu() {
    magazyn.wyswietlTowaryPracownik();
}

void Pracownik::dodajTowarDoMagazynu(const std::string& nazwa, int stan,int cena) {
    int id = 0;

    std::vector<Magazyn::Towar> towary = magazyn.pobierzTowary();

    for (const auto& towar : towary) {
        if (towar.getId() > id) {
            id = towar.getId();
        }
    }

    id++;



    magazyn.dodajTowar(id, nazwa, stan, cena);
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
void Pracownik::sprawdzRealizowaneZamowienia() const{
    zamowienie.wyswietlWszystkieZamowienia();

}

void Pracownik::zmodyfikujTowar(int towarId, int nowyStan) {
    // Sprawdź, czy towar istnieje w magazynie
    if (magazyn.sprawdzStanTowaru(towarId)) {
        // Zmodyfikuj stan towaru w magazynie
        magazyn.setStan(towarId, nowyStan);

        std::cout << "Towar o ID " << towarId << " został zmodyfikowany. Nowy stan: " << nowyStan << std::endl;
    } else {
        std::cout << "Towar o ID " << towarId << " nie istnieje w magazynie." << std::endl;
    }
}

void Pracownik::usunTowar(int towarId) {
    // Sprawdź, czy towar o podanym ID istnieje w magazynie
    if (magazyn.sprawdzStanTowaru(towarId)) {
        // Usuń towar z magazynu
        magazyn.usunTowar(towarId);
        std::cout << "Towar o ID " << towarId << " zostal usuniety z magazynu." << std::endl;
    } else {
        std::cout << "Towar o ID " << towarId << " nie istnieje w magazynie." << std::endl;
    }
}
