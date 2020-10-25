#include <iostream> // visada reikia prideti, kai naudojam string etc...
#include <vector> // kai naudojas masyvus (panasiai kaip listai, kuriu c++ nera)
#include <cmath> // matematiniams veiksmams atlikti
#include "dayOfTheWeek.h"
#include "sunday.h"
using namespace std;

struct tara{
    char tarosTipas;
    int tarosKiekis;
    double grazaKiekvienoTipo;
    int bendrasTraosKiekis;
    double grazaBendra;
};

int main() {
    string ar;
    cout << "Ar norite pradeti? (taip/ne)" << endl;
    cin >> ar;

    if (ar == "ne"){
        cout << "Supratau, geros dienos." << endl;
    }else if (ar == "taip"){
        cout << "Pradekite mesti tara." << endl;
    }else{
        while (ar != "ne" && ar !="taip"){
            cout << "Nurodyta neteisinga informacija!" << endl;
            cout << "Ar norite pradeti? (taip/ne)" << endl;
            cin >> ar;
            if (ar == "ne"){
                cout << "Supratau, geros dienos." << endl;
            }
            else if(ar == "taip"){
                cout << "Pradekite mesti tara." << endl;
            }
        }
    }

    double plastikas = 0.05;
    double stiklas = 0.1;
    double metalas = 0.15;
/*
    int tarosTipas;
    cout << "Kokio tipo tara norite imesti (0-plastikas; 1-stiklas; 2-metalas)" << endl;
    cin >> tarosTipas;
*/
    int tarosTipas;
    string ar2;
    int tarosMasyvas[50] = {};
    for (int i=0; i<5; i++) {
        cout << "Kokio tipo tara norite imesti (0-plastikas; 1-stiklas; 2-metalas)" << endl;
        cin >> tarosTipas;
        tarosMasyvas[i] = tarosTipas;
        cout << "ar norite testi? (taip/ne): " << ar2 << endl;
        while (ar2 == "taip"){
            cout << "Imeskite sekancia tara: " << endl;
        }
        if (ar2 == "ne"){
            break;
        }
        else{
            while (ar2 != "ne" && ar2 != "taip") {
                cout << "Nurodyta neteisinga informacija!" << endl;
                cout << "Ar norite testi? (taip/ne)" << endl;
                cin >> ar2;
                if (ar2 == "ne") {
                    break;
                } else if (ar2 == "taip") {
                    cout << "Imeskite sekancia tara: " << endl;
                }
            }
        }
    }
    //cout << "Jusu taros tipai yra: " << tarosMasyvas[i] << endl;






    return 0;
}



/*
void grazintiTarosInformacija(tara t){
    cout << "plastiko kiekis: " <<

}
*/