#include "Kierownik.h"

void Kierownik::sprawdzStanMagazynu() {
    magazyn.wyswietlTowaryPracownik();
}

void Kierownik::sprawdzZlozoneZamowienia() const{
    zamowienie.wyswietlWszystkieZamowienia();
//    std::vector<std::vector<std::pair<Magazyn::Towar, int>>> wszystkieZamowienia = zamowienie.pobierzWszystkieZamowienia();
//    if (wszystkieZamowienia.empty()) {
//        std::cout << "Brak zlozonych zamowien.\n";
//    } else {
//        std::cout << "Zlozone zamowienia:\n";
//        for (const auto& zam : wszystkieZamowienia) {
//            for(const auto& towarIlosc : zam) {
//                std::cout << "Towar: " << towarIlosc.first.getNazwa() << ", Ilość: " << towarIlosc.second << "\n";
//            }
//            std::cout << "\n";
//        }
//    }
}