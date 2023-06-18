
#ifndef PIAD_PERSONEL_H
#define PIAD_PERSONEL_H
#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>


class Personel {
public:
    class Osoba {
    public:
        Osoba(const int id, const std::string& imie, const std::string& nazwisko, double stawka, const std::string& rola)
                : id(id), imie(imie), nazwisko(nazwisko), stawka(stawka), rola(rola), godziny(0), wynagrodzenie(0.0) {}

        const std::string& getImie() const {
            return imie;
        }

        const std::string& getNazwisko() const {
            return nazwisko;
        }

        double getStawka() const {
            return stawka;
        }

        const std::string& getRola() const {
            return rola;
        }

        int getGodziny() const {
            return godziny;
        }

        double getWynagrodzenie() const {
            return wynagrodzenie;
        }

        void setImie(const std::string& newImie) {
            imie = newImie;
        }

        void setNazwisko(const std::string& newNazwisko) {
            nazwisko = newNazwisko;
        }

        void setStawka(double newStawka) {
            stawka = newStawka;
        }

        void setRola(const std::string& newRola) {
            rola = newRola;
        }

        void setGodziny(int newGodziny) {
            godziny = newGodziny;
            wynagrodzenie = godziny * stawka;
        }

        void setWynagrodzenie(double newWynagrodzenie) {
            wynagrodzenie = newWynagrodzenie;
        }

        void setId(int newId) {
            id = newId;
        }

        int getId() const {
            return id;
        }


    private:
        std::string imie;
        std::string nazwisko;
        double stawka;
        std::string rola;
        int godziny;
        double wynagrodzenie;
        int id;
    };

    void dodajOsobe(const int id,const std::string& imie, const std::string& nazwisko, double stawka, const std::string& rola);
    std::vector<Osoba>& pobierzOsoby();
    const std::vector<Osoba>& pobierzOsoby() const;
    void wyswietlOsoby();
private:
    std::vector<Osoba> osoby;
};

#endif
