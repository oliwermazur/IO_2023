#include "Osoby_funkcje_switch.h"

void switch_klient(Klient& klient,Magazyn& magazyn,Zamowienie& zamowienie) {
    int zamowienieId = zamowienie.pobierzRozmiarZamowien();
    int opcja;
    int rozmiar=magazyn.pobierzTowary().size();
    int ilosc[rozmiar];
    for (int i=0;i<rozmiar;i++)
    {
        ilosc[i]=0;

    }


    int towarId;


    zamowienie.utworzNoweZamowienie(zamowienieId); // Tworzenie nowego zamówienia

    do {
        system("cls");
        std::cout << "Twoj Koszyk:\n";
        zamowienie.wyswietlZamowienie(zamowienieId);
        std::cout << "Menu klienta:\n";
        std::cout << "1. Dodaj towar do zamowienia\n";
        std::cout << "2. Anuluj zamowienie\n";
        std::cout << "3. Zatwierdz zamowienie\n";
        std::cout << "0. Powrot do menu\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> opcja;
        if(opcja==0)klient.anulujZamowienie(zamowienieId);
        switch (opcja)
        {
            case 1:
            {
                system("cls");
                magazyn.wyswietlTowary();
                std::cout << "Podaj ID towaru, ktory chcesz dodac do zamowienia: ";
                std::cin >> towarId;
                zamowienie.dodajTowarDoZamowienia(towarId, ilosc[towarId-1],zamowienieId);
                system("pause");
                break;
            }

            case 2:
            {
                system("cls");
                klient.anulujZamowienie(zamowienieId);
                system("pause");
                break;
            }

            case 3:
            {
                system("cls");
                klient.zatwierdzZamowienie(zamowienieId);
                system("pause");
                return;
            }

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
        std::cout << "6. Modyfikuj towar z magazynu\n";
        std::cout << "7. Usun towar z magazynu\n";
        std::cout << "8. Generuj raport\n";
        std::cout << "0. Powrot do menu glownego\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> pracownikOpcja;

        switch (pracownikOpcja) {
            case 1:
                system("cls");

                std::cout << "////////ZAMOWIENIA REALIZOWANE////////\n";
                pracownik.sprawdzRealizowaneZamowienia();
                pracownik.wazPojazdBezTowaru();
                system("pause");
                break;
            case 2:
                system("cls");
                int id_zam;
                int id_tow;
                std::cout << "////////ZAMOWIENIA REALIZOWANE////////\n";
                pracownik.sprawdzRealizowaneZamowienia();
                std::cout << "Podaj ID zamowienia do wazenia: ";
                std::cin >> id_zam;
                pracownik.sprawdzStanMagazynu();
                std::cout << "Podaj ID towaru: ";
                std::cin >> id_tow;
                pracownik.wazPojazdZTowarem(id_zam,id_tow);
                system("pause");
                break;
            case 3:
                system("cls");
                std::cout << "////////ZAMOWIENIA REALIZOWANE////////\n";
                pracownik.sprawdzRealizowaneZamowienia();
                pracownik.ewidencjonujWazenie(id_zam,id_tow);
                pracownik.sprawdzStanMagazynu();
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
                int cena;
                std::cout << "Podaj nazwe towaru: ";
                std::cin >> nazwa;
                std::cout << "Podaj ilosc towaru: ";
                std::cin >> stan;
                std::cout << "Podaj cene towaru: ";
                std::cin >> cena;
                pracownik.dodajTowarDoMagazynu(nazwa, stan,cena);
                system("pause");
                break;
            }
            case 6:{
                system("cls");
                pracownik.sprawdzStanMagazynu();
                // Pytanie użytkownika o ID towaru i nowy stan
                int towarId;
                int nowyStan;

                std::cout << "Podaj ID towaru, ktory chcesz zmodyfikowac: ";
                std::cin >> towarId;

                std::cout << "Podaj nowy stan towaru: ";
                std::cin >> nowyStan;

                // Wywołanie funkcji zmodyfikujTowar
                pracownik.zmodyfikujTowar(towarId, nowyStan);
                pracownik.sprawdzStanMagazynu();
                system("pause");
                break;
            }
            case 7:{
                system("cls");
                pracownik.sprawdzStanMagazynu();
                int ttowarId;

                std::cout << "Podaj ID towaru, ktory chcesz usunac: ";
                std::cin >> ttowarId;

                // Wywołanie funkcji usunTowar
                pracownik.usunTowar(ttowarId);

                pracownik.sprawdzStanMagazynu();
                system("pause");
                break;
            }
            case 8: {
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

void switch_kierownik(Kierownik& kierownik,Magazyn& magazyn,Zamowienie& zamowienie,Zamowienie& zamowienie_realizacja) {
    int kierownikOpcja;
    do {
        system("cls");
        std::cout << "Menu Kierownik:\n";
        std::cout << "1. Pokaz zamowienia\n";
        std::cout << "2. Anuluj zamowienie\n";
        std::cout << "3. Przekaz zamowienie do realizacji\n";
        std::cout << "4. Sprawdz stan magazynu\n";
        std::cout << "5. Sprawdz zamowienia realizowane\n";
        std::cout << "0. Powrot do menu glownego\n";
        std::cout << "Wybierz opcje: ";
        std::cin >> kierownikOpcja;

        switch (kierownikOpcja) {
            case 1:
                system("cls");
                std::cout << "////////ZAMOWIENIA OCZEKUJACE////////\n";
                kierownik.sprawdzZlozoneZamowienia();
                system("pause");
                break;
            case 2:
                system("cls");
                int id_zam;
                std::cout << "////////ZAMOWIENIA OCZEKUJACE////////\n";
                kierownik.sprawdzZlozoneZamowienia();
                std::cout << "Podaj ID zamowienia ktore chcesz odrzucic: ";
                std::cin >> id_zam;
                kierownik.anulujZamowienie(id_zam);
                system("pause");
                break;
            case 3:
                system("cls");
                int id_zamm;
                std::cout << "////////ZAMOWIENIA OCZEKUJACE////////\n";
                kierownik.sprawdzZlozoneZamowienia();
                std::cout << "Podaj ID zamowienia ktore chcesz przekazac do realizacji: ";
                std::cin >> id_zamm;
                kierownik.przekazZamowienieDoRealizacji(id_zamm);
                std::cout << "////////ZAMOWIENIA REALIZOWANE////////\n";
                kierownik.sprawdzRealizowaneZamowienia();
                system("pause");
                break;
            case 4:
                system("cls");
                kierownik.sprawdzStanMagazynu();
                system("pause");
                break;
            case 5:
                system("cls");
                std::cout << "////////ZAMOWIENIA REALIZOWANE////////\n";
                kierownik.sprawdzRealizowaneZamowienia();
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

void switch_sekretarka(Sekretarka& sekretarka,Personel& personel,Zamowienie& zamowienie) {
    int wybor;
    do {
        system("cls");
        std::cout << "===== MENU SEKRETARKI =====" << std::endl;
        std::cout << "1. Wprowadz dane przepracowanych godzin" << std::endl;
        std::cout << "2. Oblicz wynagrodzenie" << std::endl;
        std::cout << "3. Wprowadz premie" << std::endl;
        std::cout << "4. Zatwierdz wynagrodzenie" << std::endl;
        std::cout << "5. Przeprowadz platnosc" << std::endl;
        std::cout << "6. Ksieguj platnosc" << std::endl;
        std::cout << "7. Wyswietl personel" << std::endl;
        std::cout << "8. Zatwierdz fakture" << std::endl;
        std::cout << "0. Wyjscie" << std::endl;
        std::cout << "Wybierz opcje: ";
        std::cin >> wybor;

        switch (wybor) {
            case 1:
                system("cls");
                personel.wyswietlOsoby();
                sekretarka.wprowadzDanePrzepracowanychGodzin();
                system("pause");
                break;
            case 2:
                system("cls");
                personel.wyswietlOsoby();
                sekretarka.obliczWynagrodzenie();
                system("pause");
                break;
            case 3:
                system("cls");
                personel.wyswietlOsoby();
                sekretarka.wprowadzPremie();
                system("pause");
                break;
            case 4:
                system("cls");
                personel.wyswietlOsoby();
                sekretarka.zatwierdzWynagrodzenie();
                system("pause");
                break;
            case 5:
                system("cls");
                personel.wyswietlOsoby();
                sekretarka.przeprowadzPlatnosc();
                system("pause");
                break;
            case 6:
                system("cls");
                personel.wyswietlOsoby();
                sekretarka.ksiegujPlatnosc();
                system("pause");
                break;
            case 7:
                system("cls");
                personel.wyswietlOsoby();
                system("pause");
                break;
            case 8:
                system("cls");
                int id_zamm;
                zamowienie.wyswietlWszystkieZamowienia();
                std::cout << "Podaj ID zamowienia ktore chcesz przekazac do realizacji: ";
                std::cin >> id_zamm;
                system("cls");
                sekretarka.zatwierdzFakture(id_zamm);
                system("pause");
                break;
            case 0:

                std::cout << "Zamykanie programu..." << std::endl;
                break;
            default:
                std::cout << "Nieprawidłowa opcja. Spróbuj ponownie." << std::endl;
                break;
        }
    } while (wybor != 0);
}