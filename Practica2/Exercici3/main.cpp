//Autor: Camilo Chicaiza Toapanta

/* -- Preguntes -- */
/*
1.) Tenint en compte la teva implementació del TAD LinkedList, indica per a cadascuna de les
    operacions del TAD Llista quin és el seu cost computacional teòric. Justifica la resposta.
        //Constructores
            -Per defecte:
                Es O(1) perquè no es fan bucles i nomes es crean els sentinelles
            -InicializerList i Còpia:
                Es O(n) perquè cada element ha de crear un node i després s'han de encadenar entre ells
        //Consultures
        size() - isEmpty() - beginning() -end();
            Tots són O(1) perquè nomes "retorna" atributs en diferents formats
            Size retorna un int que no s'ha de calcular
            isEmpty nomès diu si size == 0
            beggining i end retornan el node però com a objecte posició per l'encapsulament

        //Modificadores (In- Out)
        insertAfter - insertBefore - insertBeginning - insertEnd - deletePosition
            Tots també són O(1) perque nomes traballem amb 3 nodes com a molt quand fem modificacions al encadenament, llavors es molt eficiènt
            Primer que tot es crea un node (O(1))
            Després es conecta amb el nodes adjacents, segons el mètode ((O(1))
            I per últim els nodes adjacents es conecten amb el node nou, endreçant la llista
            (DeletePosition Fa ho mateix però l'enrevès)

        //print
            Es O(n) perquè ha de recorrer tota la llista en mostrar cadascú dels elements de ella mateixa
2.)Creieu que la classe NodeList hauria estat millor implementar-la amb encadenaments simples?
    Justifica la teva resposta.
    
    Sí, si parlem de fer un exercici ràpid, on s'hagi de entendre tot molt bé, però en aquest
    exercici hem fet una aplicació amb més de temps llavors considero que es millor fer-ne dobles
    A més, així la llista es un objecte més versàtil que em permèt anar enrere, i controlar 
    millor els objectes que hi conté
*/
#include <stdexcept>
#include <iostream>
#include "Position.h"
#include "LinkedList.h"
using namespace std;


//Demana [s/n] a l'usuari de manera robusta
char demanaSN(string missatge = "Digues"){
    string usuari = "";
    while (usuari != "s" && usuari != "n"){
        cout << missatge << " (s/n) ";
        cin >> usuari;
    }
    return usuari[0];
}

//Demana de manera robusta un integer
int demanaInt(string missatge = "Digues n ∈ ℕ"){
    bool correcte = false;
    int usuari;
    while (!correcte){
        cout << missatge<< " ";
        cin >> usuari;
        correcte = !cin.fail();
        if (!correcte){
            cin.clear();
            cin.ignore(1000,'\n');
        }
    }
    return usuari;
}

//Demana un string
string demanaStr(string missatge = "Digues"){
    cout << missatge << " ";
    string usuari;
    cin >> usuari;
    return usuari;
}

//Pot llançar exception, tracta d'inserir un string nou en la pos <pos> de llista
void inserirEnPos(LinkedList<string> &llista, int pos, string nouStr){
    //Fem els casos de error
    if (llista.isEmpty())
        throw out_of_range("La estructura está buida!");
    if (pos < 0)
        throw out_of_range("La posició no pot ser negativa!");
    if (pos >= llista.size())
        throw out_of_range("La posició es massa gran (max " + to_string(llista.size()-1) + ")");

    //Iterem fins la posició volguda
    Position<string> it = llista.beginning();
    for (int j = 0; j< pos; j++){it = ++it;}
            
    //Preguntem si es vol afegir abans o despres
    int eleccio = demanaSN("Inserir abans de la posició?");
    if (eleccio == 's')
        llista.insertBefore(it,nouStr);
    else
        llista.insertAfter(it,nouStr);
}


void casProva1(){ 
    LinkedList<int> list1;
    list1.insertBeginning(5);
    list1.insertBeginning(3);
    list1.insertEnd(7);
    list1.insertEnd(8);
    list1.print();
    try{
        Position<int> pos = list1.beginning();
        pos = list1.beginning(); list1.insertAfter(pos, 4); list1.print();
        pos = list1.beginning(); list1.insertBefore(pos, 2); list1.print();
        pos = list1.end(); list1.insertBefore(pos, 9); list1.print();
        pos = list1.beginning(); list1.insertAfter(pos, 5); list1.print();
        pos = list1.end(); list1.insertAfter(pos, 8); list1.print();
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    int posicio, element;
    cout << " A quina posicio vols inserir" << endl;
    cin >> posicio;

    cout << " Quin element vols inserir" << endl;
    cin >> element;

    try {
        auto itr = list1.beginning();
        for (int i = 0; i < posicio; ++i)
            itr = ++itr;

        list1.insertBefore(itr, element);
        list1.insertAfter(itr, element + 10);
    }
    catch (std::exception& e) {
        std::cout << "Error: " << e.what() << std::endl;
    }
    list1.print();
    cout << " Segona part de la prova 1 de la llista " << endl;
    LinkedList<int> list2 = {1, 2, 3, 4, 5};
    list2.print();
    Position<int> pos2 = list2.beginning();
    list2.deletePosition(pos2);
    list2.print();
    pos2 = list2.beginning();
    pos2 = ++pos2;
    list2.deletePosition(pos2);
    list2.print();
}
void casProva2(){
    const int MAX = demanaInt("Introdueix quantes paraules vols inserir:");
    LinkedList<string> llista;
    if (MAX < 0)
        cout << "Negatiu pensat com 0, sense elements" << endl;

    for (int i = 0; i < MAX; i++){
        //Demanem Paraula
        string str = demanaStr("Introdueix una paraula:");

        /* --Preguntes --*/
        //Inici
        char eleccio = demanaSN("Inserir al principi?");
        if (eleccio == 's'){
            llista.insertBeginning(str);
            continue;
        }
        //Fi
        eleccio = demanaSN("Inserir al final?");
        if (eleccio == 's'){
            llista.insertEnd(str);
            continue;
        }

        //Posició intermig (Cas buida)
        if (llista.isEmpty()){
            llista.insertBeginning(str);
            cout << "--- Com que está buida, només hi inserim ---" << endl;
            continue;
        }

        //Posició intermig (bucle que espera una posició valida)
        bool valid = false;
        while(!valid){
            try{
                //Demana integer
                int pos = demanaInt("A quina posició vols inserir?"); 
                inserirEnPos(llista,pos,str); //Pot llançar exception
                 //Si no s'en llença, en sortim
                valid = true;
            }
            catch(out_of_range &e){
                cout << "EXCEPTION: "<<e.what() << endl;
            }
        }
    }

    //Fem servir el mètode print de LikedList
    cout << "Print(): ";
    llista.print();

    //Iteració demanada
    cout << "Iteració dels elements endavant: "<<endl;
    Position<string> it = llista.beginning();
    for(it; it != llista.end(); it = ++it)
        cout << *it << endl;
}

int main(int argc, char** argv){
    casProva1(); // prova amb dues llistes d'enters
    casProva2(); // prova amb una llista d'strings
    return 0;
}