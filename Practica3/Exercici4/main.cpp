#include "WordIndexerBalanced.h"
#include "Menu.h"
#include "Position.h"
#include <chrono>
#include <fstream>
#include <iostream>
#include <stdexcept>

//8 9 10 2 1 5 3 6 4

void interactiu (){
    cout << "   ---  Arbre buit ---" << endl;
    cout << "---  Type '-1' per tancar --- " << endl;
    BalancedTree<int,int> arbre;
    int nou = 0;
    while (nou != -1){
        cout << "Nou element: ";
        cin >> nou;
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Només Integers! (-1 per tancar)"<< endl;
        }
        else if (nou != -1)
            arbre.insert(nou,1);
        arbre.print();
    }
}


int main(){
    interactiu();

}