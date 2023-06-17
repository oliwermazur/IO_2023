#include "Osoby_funkcje_switch.h"

void switch_klient(Klient& klient,Magazyn& magazyn,Zamowienie& zamowienie) {
    int zamowienieId=0;
    int opcja;
    int rozmiar = zamowienieId+1 ;
    int ilosc[rozmiar];
    for (int i = 0; i < rozmiar; i++) {
        ilosc[i] = 0;    }
    int towarId;
    do {
        zamowienieId+=1;
        system("cls");
        std::cout << "Menu klienta:\n";
        std::cout << "1. Dodaj towar do zamowienia\n";
        std::cout << "2. Anuluj zamowienie\n";
        std::cout << "3. Zatwierdz zamowienie\n";
        std::cout << "0. Powrot do menu\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;

        switch (opcja)
        {
            case 1:
            {
                system("cls");
                magazyn.wyswietlTowary();
                std::cout << "Podaj ID towaru, ktory chcesz dodac do zamowienia: ";
                std::cin >> towarId;
                zamowienie.dodajTowarDoZamowienia(towarId,ilosc[rozmiar]);
                system("pause");
                break;}

            case 2:
            {
                system("cls");
                klient.anulujZamowienie(zamowienieId);
                system("pause");
                break;}

            case 3:
            {
                system("cls");
                klient.zatwierdzZamowienie(zamowienieId);
                system("pause");
                return;}

            default:
                std::cout << "Nieprawidlowa opcja. Wybierz ponownie.\n\n";
                break;
        }
    } while (opcja != 0);
}

void switch_pracownik(Pracownik& pracownik) {
    int pracownikOpcja;
    do {
        system("cls");
        std::cout << "Menu Pracownik:\n";
        std::cout << "1. Zwaz pojazd bez towaru\n";
        std::cout << "2. Zwaz pojazd z towarem\n";
        std::cout << "3. Ewidencjonuj wazenie\n";
        std::cout << "4. Sprawdz stan magazynu\n";
        std::cout << "5. Dodaj towar do magazynu\n";
        std::cout << "6. Generuj raport\n";
        std::cout << "0. Powrot do menu glownego\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> pracownikOpcja;

        switch (pracownikOpcja) {
            case 1:
                system("cls");
                pracownik.wazPojazdBezTowaru();
                system("pause");
                break;
            case 2:
                system("cls");
                pracownik.wazPojazdZTowarem();
                system("pause");
                break;
            case 3:
                system("cls");
                pracownik.ewidencjonujWazenie();
                system("pause");
                break;
            case 4:
                system("cls");
                pracownik.sprawdzStanMagazynu();
                system("pause");
                break;
            case 5: {
                system("cls");
                pracownik.sprawdzStanMagazynu();
                int id;
                std::string nazwa;
                int stan;
                std::cout << "Podaj nazwe towaru: ";
                std::cin >> nazwa;
                std::cout << "Podaj ilosc towaru: ";
                std::cin >> stan;
                pracownik.dodajTowarDoMagazynu(nazwa, stan);
                system("pause");
                break;
            }
            case 6: {
                system("cls");
                pracownik.generujRaport();
                system("pause");
                break;
            }
            case 0: {

                std::cout << "Powrot do menu glownego.\n";
                break;
            }
            default:
                std::cout << "Nieprawidlowa opcja.\n";
                break;
        }

        std::cout << std::endl;
    } while (pracownikOpcja != 0);
}

void switch_kierownik(Kierownik& kierownik,Magazyn& magazyn,Zamowienie& zamowienie) {
    int kierownikOpcja;
    do {
        system("cls");
        std::cout << "Menu Kierownik:\n";
        std::cout << "1. Pokaz zamowienia\n";
        std::cout << "2. Anuluj zamowienie\n";
        std::cout << "3. Przekaz zamowienie do realizacji\n";
        std::cout << "4. Sprawdz stan magazynu\n";
        std::cout << "0. Powrot do menu glownego\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> kierownikOpcja;

        switch (kierownikOpcja) {
            case 1:
                system("cls");
                kierownik.sprawdzZlozoneZamowienia();
                system("pause");
                break;
            case 2:
                system("cls");
                //kierownik.anulujZamowienie(int zamowienieId);
                system("pause");
                break;
            case 3:
                system("cls");
                //kierownik.przekazZamowienieDoRealizacji(int zamowienieId);
                system("pause");
                break;
            case 4:
                system("cls");
                kierownik.sprawdzStanMagazynu();
                system("pause");
                break;
            case 0: {

                std::cout << "Powrot do menu glownego.\n";
                break;
            }
            default:
                std::cout << "Nieprawidlowa opcja.\n";
                break;
        }

        std::cout << std::endl;
    } while (kierownikOpcja != 0);

}
