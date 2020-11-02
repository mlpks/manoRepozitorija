#include <iostream>
#include <string>

using namespace std;

struct taros{
    int plastikoKiekis = 0;
    int stikloKiekis = 0;
    int metaloKiekis = 0;
};

struct supirkimoPunktas{
    string pavadinimas;
    double kainos[3];
};

struct kvitas{
    double plastikoSuma = 0.0;
    double stikloSuma = 0.0;
    double metaloSuma = 0.0;
};

//funkcija kuri paskaiciuoja kaina
double paskaiciuoti(int kiekis, double kaina){
    return kiekis*kaina;
}

int main() {
    supirkimoPunktas supirktuve;
    cout << "Sveiki, prasome suvesti supirktuves pavadinima:\n";
    cin >> supirktuve.pavadinimas;
    cout << "Suveskite is eiles supirkimo kainas.\n";

    string pavadinimai[3] = {"plastiko", "stiklo", "metalo"};
    double ivestaKaina;
    for (int kainuSkaitliukas = 0; kainuSkaitliukas < 3;) {//patys didinsime skaitliuka cikle, todel trecia elementa paliekame tuscia, nes kartais ciklo nepadidinsime
        cout << "Iveskite " << pavadinimai[kainuSkaitliukas] << " kaina:\n";
        cin >> ivestaKaina;
        try {//bandysim atlikti veiksmus, kurie gali nuluzti
            supirktuve.kainos[kainuSkaitliukas] = ivestaKaina;
            cout << "Perskaiciau " << pavadinimai[kainuSkaitliukas] << " kaina: " << supirktuve.kainos[kainuSkaitliukas] << " Eur. [" << supirktuve.pavadinimas << "]\n";
            kainuSkaitliukas++;
        } catch (exception &e) { // CIA NEAISKU SINTAKSE: exception &e
            cout << "Ivedete neteisingus duomenis, prasome pakartoti\n";
        }
    }
    string ivestasTekstas;
    cout << "Ar norite pradeti? (taip/ne)" << endl;
    cin >> ivestasTekstas;

    while (ivestasTekstas != "ne" && ivestasTekstas != "taip") {
        cout << "Nurodyta neteisinga informacija!" << endl;
        cout << "Ar norite pradeti? (taip/ne)" << endl;
        cin >> ivestasTekstas;
    }

    if (ivestasTekstas == "ne") {
        cout << "Supratau, geros dienos." << endl;
        return 0; //iseinam is programos

    } else if (ivestasTekstas == "taip") {
        cout << "Pradekite mesti tara." << endl;
    }

    taros priduodamaTara;
    int tarosTipas;
    bool testi = true;
    while (testi) {
        cout << "Kokio tipo tara norite imesti (0-plastikas; 1-stiklas; 2-metalas)" << endl;
        cin >> tarosTipas;
        switch (tarosTipas) {
            case 0:
                priduodamaTara.plastikoKiekis++;
                break;
            case 1:
                priduodamaTara.stikloKiekis++;
                break;
            case 2:
                priduodamaTara.metaloKiekis++;
                break;
            default:
                cout << "Tokios taros nera." << endl;
        }

        cout << "ar norite testi? (taip/ne): " << endl;
        cin >> ivestasTekstas;
        while (ivestasTekstas != "ne" && ivestasTekstas != "taip") {
            cout << "Nurodyta neteisinga informacija!" << endl;
            cout << "ar norite testi? (taip/ne)" << endl;
            cin >> ivestasTekstas;
        }
        if (ivestasTekstas == "ne")
            testi = false;
    }

    kvitas k;
    k.plastikoSuma = paskaiciuoti(priduodamaTara.plastikoKiekis, supirktuve.kainos[0]);
    k.stikloSuma = paskaiciuoti(priduodamaTara.stikloKiekis, supirktuve.kainos[1]);
    k.metaloSuma = paskaiciuoti(priduodamaTara.metaloKiekis, supirktuve.kainos[2]);

    cout << "Spausdinamas cekis:\n";
    cout << "=======================" << endl;
    cout << supirktuve.pavadinimas << endl;
    cout << "=======================" << endl;
    cout << "Plastiko kiekis:" << priduodamaTara.plastikoKiekis << ". Suma: " << k.plastikoSuma << endl;
    cout << "Stiklo kiekis:" << priduodamaTara.stikloKiekis << ". Suma: " << k.stikloSuma << endl;
    cout << "Metalo kiekis:" << priduodamaTara.metaloKiekis << ". Suma: " << k.metaloSuma << endl;
    cout << "=======================" << endl;
    cout << "Viso galutine suma: " << k.plastikoSuma + k.stikloSuma + k.metaloSuma << endl;
    cout << "=======================" << endl;

    cout << "Pabaiga" << endl;

    return 0;
}