#ifndef MAGAZYN_H
#define MAGAZYN_H

#include <iostream>
#include <vector>

class Magazyn {
public:
    class Towar {
    public:
        Towar(int id, const std::string& nazwa, int stan) : id(id), nazwa(nazwa), stan(stan) {}

        int getId() const {
            return id;
        }

        const std::string& getNazwa() const {
            return nazwa;
        }

        int getStan() const {
            return stan;
        }

    private:
        int id;
        std::string nazwa;
        int stan;
    };

    void dodajTowar(int id, const std::string& nazwa, int stan);
    int sprawdzStanTowaru(int towarId);
    void wyswietlTowary();
    void wyswietlTowaryPracownik();
    std::vector<Magazyn::Towar> pobierzTowary() const {
        return towary;
    };
    Towar pobierzTowar(int towarId) const {
        for (const auto& towar : towary) {
            if (towar.getId() == towarId) {
                return towar;
            }
        }
        return Towar(-1, "", 0);
    }
private:
    std::vector<Towar> towary;
};

#endif // MAGAZYN_H
