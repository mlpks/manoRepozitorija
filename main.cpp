#include <iostream> // visada reikia prideti, kai naudojam string etc...
#include <vector> // kai naudojas masyvus (panasiai kaip listai, kuriu c++ nera)
#include <cmath> // matematiniams veiksmams atlikti
#include "dayOfTheWeek.h"
#include "sunday.h"
using namespace std;

struct burger{
    bool withMeat;
    int slicesOfMeat;
    int slicesOfCheese;
    int slicesOfTomato;
    char lettuce[10];
    char majo[10];

};


int main() {

    cout << "You are ordering at Mcdonald's, you are about to choose what type of burger you want to order."<< endl;
    int whatToEat;
    cout << "What type of burger do you want to order? A Beef burger (1); A Chicken burger (2); A Veggie burger (3)" << endl;
    cin >> whatToEat;

    string mealName;
    switch(whatToEat){
        case 1:
            mealName = "a Beef burger";
            cout << "You have chosen " << mealName << endl;
            break;
        case 2:
            mealName = "a Chicken burger";
            cout << "You have chosen " << mealName << endl;
            break;
        case 3:
            mealName = "a Veggie burger";
            cout << "You have chosen " << mealName << endl;
            break;
        default:
            cout << "Invalid number";
    }

    string answer;
    cout << "Do you want a meal? Yes or no." << endl;
    cin >> answer;

    if (answer == "yes"){

        }
    }else if (answer == "no"){
        // xxxxxxxxxxxxxxxxxxxxxxxxxxxx
    }else{
        cout << "Invalid answer" << endl;
    }
*/
/*

        string day[] = {1, 2, 3, 4, 5, 6, 7};
        if (d > 0 && d < 6 ){
            cout << "It is " << day[dayName] << "! You have to work today!" << endl;
        }
        else if (d == 0 || d == 6){
            cout << "It's a " << day[d] << ", relax." << endl;
        }
        else{
            cout << "Invalid number written." << endl;
        }

*/











//    funkcija1();
//   listas();

    return 0;
}
