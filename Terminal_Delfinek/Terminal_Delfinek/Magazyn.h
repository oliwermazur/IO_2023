#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <iostream>
#include <vector>

class Magazyn {
public:
    class Towar {
    public:
        Towar(int id, const std::string& nazwa, int stan, double cena)
                : id(id), nazwa(nazwa), stan(stan), cena(cena) {}

        int getId() const {
            return id;
        }

        const std::string& getNazwa() const {
            return nazwa;
        }

        int getStan() const {
            return stan;
        }

        double getCena() const {
            return cena;
        }

        void setStan(int nowyStan);
        void setId(int newId);
        void setCena(double newCena);

    private:
        int id;
        std::string nazwa;
        int stan;
        double cena;
    };

    void dodajTowar(int id, const std::string& nazwa, int stan, double cena);
    int sprawdzStanTowaru(int towarId);
    void wyswietlTowary();
    void wyswietlTowaryPracownik();
    void usunTowar(int towarId);
    Towar pobierzTowar(int towarId) const ;
    void setStan(int towarId, int nowyStan);
    std::vector<Magazyn::Towar> pobierzTowary() const {
        return towary;
    };

private:
    std::vector<Towar> towary;
};

#endif
