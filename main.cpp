#include <iostream>
#include <map>

using namespace std;


class Klientas {
private:
    int id;
    string vardas;
public:
    Klientas(int id, const string &vardas) : id(id), vardas(vardas) {}

    const string &getVardas() const {
        return vardas;
    }
};

class Kelione {
    string pavadinimas;
public:
    Kelione(const string &pavadinimas) : pavadinimas(pavadinimas) {}

    const string &getPavadinimas() const {
        return pavadinimas;
    }
};


class Viesbutis {
private:
    map<int, Klientas> rezervuota;
    map<int, Kelione> keliones;
public:
    Viesbutis() {
        keliones.insert(pair<int, Kelione>(1, Kelione("Havajai")));
        keliones.insert(pair<int, Kelione>(2, Kelione("Palanga")));

    }

    const map<int, Klientas> &getRezervuota() const {
        return rezervuota;
    }

    const map<int, Kelione> &getKeliones() const {
        return keliones;
    }

    void rezervuoti(Klientas klientas) {

        int input = 1;


        while (input != 0) {

            cout << "Pasirinkite kur norite keliauti:" << endl;

            int index = 1;

            for (const auto &it: keliones) {
                cout << index++ << ". " << it.second.getPavadinimas() << endl;
            }

            cout << "Iveskite skaiciu:" << endl;
            cin >> input;

            if (rezervuota.empty()) {
                rezervuota.insert(pair<int, Klientas>(input, klientas));
                cout << "ADDED!" << endl;
            } else {
                for (auto it: keliones) {
                    if (input == it.first) {
                        rezervuota.insert(pair<int, Klientas>(input, klientas));
                        cout << " ADDED also!" << endl;

                    }
                }

            }
            cout << "Rezervuotu kelioniu sarasas:" << endl;
            for (auto i: rezervuota) {
                cout << ">> " << i.first << " " << i.second.getVardas()<< ", kelione: "<< keliones.at(i.first).getPavadinimas() << " <<"<< endl;
            }

            char arNorite;

            cout << "Ar norite atsaukti kelione? y/n" << endl;

            int ind = 1;

            cin >> arNorite;
            if(arNorite == 'y') {
                for (const auto &it: rezervuota) {
                    cout << ind++ << ". " << it.second.getVardas() << " "<< keliones.at(it.first).getPavadinimas() << endl;
                }
                cout << "Pasirinkite is saraso numeri: " << endl;
                cin >> input;
                rezervuota.erase(input);
                cout << "======================================================"<<endl;
                cout << "=================KELIONE SEKMINGAI PASALINTA==============="<<endl;
                cout << "======================================================"<<endl;
                ind = 1;


                cout << "======================================================"<<endl;
                cout << "=================Rezervuotu kelioniu sarasas:==============="<<endl;
                cout << "======================================================"<<endl;

                for (const auto &it: rezervuota) {
                    cout << ind++ << ". " << it.second.getVardas() << " "<< keliones.at(it.first).getPavadinimas() << endl;
                }
                cout << "=============================================="<< endl;

            }else{
                cout << "=============================================="<< endl;
            }

        }

    }

};


int main() {

    Viesbutis viesbutis;
    Klientas petras(12131, "Petras");
    viesbutis.rezervuoti(petras);


    return 0;
}