#include <iostream>
#include <string>
#include <vector>

class Klientas{
public:
    std::string vardas, pavarde;
    std::string gatve;
    std::string namoNr{};
    int telNr{};
};
class Pica{
public:
    int tipas{};
    int laikas{};
    double kainaMargherita = 6.00;
    double kainaParma = 8.00;
    double kainaDiavola = 9.00;
    double kainaQuattroFormagi = 7.50;
    double kainaNordica = 10.00;
    int kiekisMargherita = 0;
    int kiekisParma = 0;
    int kiekisDiavola = 0;
    int kiekisQuattroFormagi =0;
    int kiekisNordica = 0;
};
class Kvitas{
public:
    double sumaParma = 0.0;
    double sumaDiavola = 0.0;
    double sumaQuattroFormagi = 0.0;
    double sumaNordica = 0.0;
    double sumaMargherita = 0.0;
    double sumaBendra = 0.00;
};
void UzsakymoKrepselis(const Pica &pasirinkimas, const Kvitas &k, const std::string *pavadinimai);
void BendraSumaLaikas(const Pica &pasirinkimas, const std::vector<int> &q, Pica &l, Kvitas &k);
double paskaiciuoti(int kiekis, double kaina){
    return kiekis*kaina;
}
double paskaiciuotiBendraKaina(double kaina0, double kaina1, double kaina2, double kaina3, double kaina4){
    return kaina0+kaina1+kaina2+kaina3+kaina4;
}
int bendrasLaukimoLaikas(int laikas0, int laikas1){
    return laikas0*laikas1;
}
void Menu(){
    std::cout << "============================================" << std::endl;
    std::cout << "MENIU:" << std::endl;
    std::cout << "0. Margherita (vegetariska) - 6.00 eu" << std::endl;
    std::cout << "1. Parma (lengva su kumpiu) - 8.00 eu" << std::endl;
    std::cout << "2. Mexicana (astri su mesa) - 9.00 eu" << std::endl;
    std::cout << "3. Quattro Formagi (keturiu suriu) - 7.50 eu" << std::endl;
    std::cout << "4. Nordica (su lasisa) - 10.00 eu" << std::endl;
    std::cout << "5. Atsaukti" << std::endl;
    std::cout << "Pasirinkti:";
}
int main(){
    Klientas v, p, a, nNr, tl;
    std::cout << "Sveiki, prisijunge prie mobiliosios programeles! Prasome ivesti kliento duomenis.\n" << std::endl;
    std::cout << "Vardas, Pavarde:";
    std::cin >> v.vardas;
    std::cin >> p.pavarde;
    std::cout << "Gatves pavadinimas:";
    std::cin >> a.gatve;
    std::cout << "Namo-Buto numeris:";
    std::cin >> nNr.namoNr;
    std::cout << "Telefono numeris:";
    std::cin >> tl.telNr;

    Pica pasirinkimas, l;
    Kvitas k;
    std::string pavadinimai[5] = {"Margherita", "Parma", "Mexicana", "Quattro Formagi", "Nordica"};
    std::vector <int> q;
    char taipne;
    bool testi = true;
    while(testi){
        Menu();
        std::cin >> pasirinkimas.tipas;
        switch (pasirinkimas.tipas){
            case 0:
                pasirinkimas.kiekisMargherita++;
                q.push_back(pasirinkimas.kiekisMargherita);
                break;
            case 1:
                pasirinkimas.kiekisParma++;
                q.push_back(pasirinkimas.kiekisParma);
                break;
            case 2:
                pasirinkimas.kiekisDiavola++;
                q.push_back(pasirinkimas.kiekisDiavola);
                break;
            case 3:
                pasirinkimas.kiekisQuattroFormagi++;
                q.push_back(pasirinkimas.kiekisQuattroFormagi);
                break;
            case 4:
                pasirinkimas.kiekisNordica++;
                q.push_back(pasirinkimas.kiekisNordica);
                break;
            case 5:
                std::cout << "Geros dienos!" << std::endl;
                return 0;
            default: // veikia tik paspaudus int tipo klavisa. Kaip isvengti infinity loop paspaudus kito tipo klavisa?
                std::cout << "Tokio pasirinkimo nera, kartokite atsakyma!" << std::endl;
                std::cout << "Ar norite testi?";
                std::cin >> taipne;
                break;
        }
        BendraSumaLaikas(pasirinkimas, q, l, k);
        UzsakymoKrepselis(pasirinkimas, k, pavadinimai);
        std::cout << "Ar norite testi?";
        std::cin >> taipne;
        while (taipne != 'n' && taipne != 't'){
            std::cout << "Tokio pasirinkimo nera, kartokite atsakyma!" << std::endl;
            std::cout << "Ar norite testi?";
            std::cin >> taipne;
        }
        if (taipne == 'n'){
            testi = false;
        }
    }
    std::cout << "============================================" << std::endl;
    UzsakymoKrepselis(pasirinkimas, k, pavadinimai);
    std::cout << "============================================\n" << "Bendra suma: " << k.sumaBendra << " eu\n"
              << "Atsiemimo laikas: " << l.laikas << " min\n" << "Atsiimti: " << v.vardas << " " << p.pavarde[0]
              << "." << std::endl;
    return 0;
}
void BendraSumaLaikas(const Pica &pasirinkimas, const std::vector<int> &q, Pica &l, Kvitas &k) {
    k.sumaMargherita = paskaiciuoti(pasirinkimas.kiekisMargherita, pasirinkimas.kainaMargherita);
    k.sumaParma = paskaiciuoti(pasirinkimas.kiekisParma, pasirinkimas.kainaParma);
    k.sumaDiavola = paskaiciuoti(pasirinkimas.kiekisDiavola, pasirinkimas.kainaDiavola);
    k.sumaQuattroFormagi = paskaiciuoti(pasirinkimas.kiekisQuattroFormagi, pasirinkimas.kainaQuattroFormagi);
    k.sumaNordica = paskaiciuoti(pasirinkimas.kiekisNordica, pasirinkimas.kainaNordica);
    k.sumaBendra = paskaiciuotiBendraKaina(k.sumaMargherita, k.sumaParma, k.sumaDiavola, k.sumaQuattroFormagi, k.sumaNordica);
    l.laikas = bendrasLaukimoLaikas(q.size(), 10);
}
void UzsakymoKrepselis(const Pica &pasirinkimas, const Kvitas &k, const std::string *pavadinimai) {
    std::cout << "============================================\n" << "Uzsakymo krepselis: " << std::endl;
    if (pasirinkimas.kiekisMargherita > 0){
        std::cout << "Kiekis " << pavadinimai[0] << ": " << pasirinkimas.kiekisMargherita << ", Kaina: " <<
                  k.sumaMargherita << " eu" << std::endl;
    }
    if (pasirinkimas.kiekisParma > 0){
        std::cout << "Kiekis " << pavadinimai[1] << ": " << pasirinkimas.kiekisParma << ", Kaina: " <<
                  k.sumaParma << " eu" << std::endl;
    }
    if (pasirinkimas.kiekisDiavola > 0){
        std::cout << "Kiekis " << pavadinimai[2] << ": " << pasirinkimas.kiekisDiavola << ", Kaina: " <<
                  k.sumaDiavola << " eu" << std::endl;
    }
    if (pasirinkimas.kiekisQuattroFormagi > 0){
        std::cout << "Kiekis " << pavadinimai[3] << ": " << pasirinkimas.kiekisQuattroFormagi << ", Kaina: " <<
                  k.sumaQuattroFormagi << " eu" << std::endl;
    }
    if (pasirinkimas.kiekisNordica > 0){
        std::cout << "Kiekis " << pavadinimai[4] << ": " << pasirinkimas.kiekisNordica << ", Kaina: " <<
                  k.sumaNordica << " eu" << std::endl;
    }
}


