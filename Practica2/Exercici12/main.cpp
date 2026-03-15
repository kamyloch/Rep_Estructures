#include "PilaEstatica.h"
#include "Menu.h" //He fet Menu.h per que tot sigui mès net
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;
/*** -- Mètodes Auxiliars -- ***/
//Mostra estats intermigs de hanoi en el format "X: Pila = [...] tamaño = #X"
void printEstat(const PilaEstatica<int> &A,const PilaEstatica<int> &P,const PilaEstatica<int> &B){
    cout << "A: Pila = ";
    A.print();
    cout << " tamaño = " << A.tamano() << endl;

    cout << "P: Pila = ";
    P.print();
    cout << " tamaño = " << P.tamano() << endl;

    cout << "B: Pila = ";
    B.print();
    cout << " tamaño = " << B.tamano() << endl;
}
//Mostra estats inicial i final de hanoi (sense "tamaño") en format X: Pila = [...]
void printEstatSenseMida(const PilaEstatica<int> &A,const PilaEstatica<int> &P,const PilaEstatica<int> &B){
    cout << "A: Pila ";
    A.print();
    cout << endl;

    cout << "P: Pila ";
    P.print();
    cout << endl;

    cout << "B: Pila ";
    B.print();
    cout << endl;
}
//Mou un element de la pila partida a la pila arribada (pot llançar exeption si partida esta buida)
void moure(PilaEstatica<int> &partida, PilaEstatica<int> &arribada){
    int paquet;
    paquet = partida.elementoEncima();
    partida.suprimirElemento();
    arribada.anadirElemento(paquet);
}
//Permet aplicar l'algoritme de hanoi i mostra en cada pas els moviments
void logisticaAux(const int &n, PilaEstatica<int> &A, PilaEstatica<int> &B, PilaEstatica<int> &P, const PilaEstatica<int> &orgA, const PilaEstatica<int> &orgP, const PilaEstatica<int> &orgB){ 
    if (n == 1){
        moure(A,B);
        cout << "\nL'estat intermig és el següent:" << endl;
        printEstat(orgA,orgP,orgB); 
    }
    else{
        logisticaAux(n-1,A,P,B,orgA,orgP,orgB);
        logisticaAux(1,A,B,P,orgA,orgP,orgB);
        logisticaAux(n-1,P,B,A,orgA,orgP,orgB);
    }  
}
//Permet cridar l'algoritme de hanoi però amb orgX (original X) per no barrellar les piles en l'argoritme
void logistica(const int &n, PilaEstatica<int> &A, PilaEstatica<int> &B, PilaEstatica<int> &P){
    //Les tres variables extres son per cridar a printEstat correctament
    logisticaAux(n,A,B,P,A,P,B);
}
//Activa un while que demana per cin un numero al usuari (n>0)
int demanarN(string missatge = "Digues n ∈ ℕ"){
    int n;
    do{
        if (cin.fail()){
            cin.clear();
            cin.ignore(1000,'\n');
        }
        cout << missatge << ": ";
        cin >> n;
    }while(cin.fail() || n < 1);
    cout << endl;
    return n;
}

/*** -- Mètodes demanats -- ***/
void casProvaEx1(){
try {
    // 1. Crear una PilaEstatica de mida 3
    PilaEstatica<int> pila(3);
    cout << "Estructura creada" << endl;

    // 2-3. Inserir elements 10 i 11
    pila.anadirElemento(10); cout << "Element 10 agregat" << endl;
    pila.anadirElemento(11); cout << "Element 11 agregat" << endl;

    // 4. Imprimir front
    cout << "Front: " << pila.elementoEncima() << endl;

    // 5. Inserir element 12
    pila.anadirElemento(12); cout << "Element 12 agregat" << endl;

    // 6. Inserir element 13 (Aquest ha de llançar EXCEPTION)
    try {
        pila.anadirElemento(13);
    } catch (const exception& e) {
        cout << "EXCEPTION: " << e.what() << endl;
    }

    // 7. Imprimir PilaEstatica
    pila.print(); 

    // 8. Imprimir front
    cout << "Front: " << pila.elementoEncima() << endl;

    // 9. Suprimir element
    pila.suprimirElemento(); cout << "Element 12 eliminat" << endl;

    // 10. Inserir element 14
    pila.anadirElemento(14); cout << "Element 14 agregat" << endl;

    // 11. Imprimir PilaEstatica
    pila.print();

    // 12. Imprimir front
    cout << "Front: " << pila.elementoEncima() << endl;

    // 13-15. Suprimir elements fins buidar
    pila.suprimirElemento(); cout << "Element 14 eliminat" << endl;
    pila.suprimirElemento(); cout << "Element 11 eliminat" << endl;
    pila.suprimirElemento(); cout << "Element 10 eliminat" << endl;

    // 16. Suprimir element (Aquest ha de llançar EXCEPTION)
    try {
        pila.suprimirElemento();
    } catch (const exception& e) {
        cout << "EXCEPTION: " << e.what() << endl;
    }

} catch (const exception& e) {
    cerr << "Error inesperat: " << e.what() << endl;
}

}
void casProvaMenu(){
    Menu menu = {"Inserir element a la pila", 
                "Suprimir element de la pila", 
                "Consultar el top de la pila", 
                "Imprimir tot el contingut de la PilaEstatica", 
                "Imprimir la posició del top de la pila", 
                "Sortir"};
    int usuari = -1;

    cout <<"--- Benvigut a la pila ---"<<endl;

    //Demanem N demanera robusta
    int n = demanarN("Introdueix màxim de la pila");
    PilaEstatica<int> pila(n);
    cout << "--- " << "Màxim establert a " << n << " --- "<< endl;

    while (usuari != 6){
        try{ usuari  = menu.demanar();
            cout << endl;
            string missatge = "";
            switch (usuari){
                case 1:{
                    int nou;
                    cout << "Nou element: " ;
                    cin >> nou;
                    if (cin.fail()) throw runtime_error("Ha de ser un enter");
                    pila.anadirElemento(nou);
                    missatge = "Afegit " + to_string(nou);
                    break;
                }
                case 2:{
                    int actual = pila.elementoEncima();
                    pila.suprimirElemento();
                    missatge = "S'ha tret '" + to_string(actual) + "'";   
                    break;
                }
                case 3: 
                    //elementoEncima fa throw si está buida
                    missatge =  "Top element: " + to_string(pila.elementoEncima());
                    break;
                case 4: 
                    cout << "Pila: ";
                    pila.print();
                    cout << endl;
                    break;
                
                case 5: 

                    if (pila.estaVacia()) throw runtime_error("No hi ha elements a la pila");
                    missatge = "El top es troba a: " + to_string(pila.tamano()-1);
                    break;
                
                case 6:
                    cout << "Adèu!\n"<<endl;
                }
            if (missatge != "")
                cout << "--- " << missatge << " --- "<< endl;
        }
        catch (const exception &e){
            if (cin.fail()){
                cin.clear();
                cin.ignore(1000,'\n');
            }
            cout << "EXCEPTION: " << e.what() << endl;
            usuari = -1;
        }

    }


}
void casProva2(){
    //Demanem n de manera robusta
    cout << "Hola, sóc el braç robòtic"<< endl;
    int n = demanarN("Introdueix el nombre de paquets");

    //Fem el vector d'A
    vector <int> initA;
    initA.reserve(n);
    for(int i = n; 0 < i; i--)
        initA.push_back(i);

    //Inicialitzem les variables
    PilaEstatica<int> A(initA),P(n),B(n);

    cout << "\nL'estat inicial és el següent:" << endl;
    printEstatSenseMida(A,P,B);

    //Fem servir l'argortime donat
    //Fem try tot i que surtirá bé
    try{
        logistica(n,A,B,P);
    }
    catch(exception &e){
        cout << "Error: " << e.what();
    }

    cout << "\nL'estat final és el següent:" << endl;
    printEstatSenseMida(A,P,B);
}
int main(){
    casProvaEx1();
    casProvaMenu();
    casProva2();
    return 0;
}