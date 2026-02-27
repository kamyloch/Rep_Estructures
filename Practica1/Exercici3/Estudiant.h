//Autor: Camilo Chicaiza Toapanta

#ifndef LLIBRE_H
#define LLIBRE_H
#include <string>

using namespace std;
class Estudiant {
    private:
        string nom;
        int any;
        int assignatures;

    
    public:
        //Constructor
        Estudiant(string nom = "Desconegut", int any = 0, int assignatures = 0);

        //Setters
        void setNom(string nom);
        void setAny(int any);
        void setAssignatures(int assignatures);

        //Getters
        string getNom();
        int getAny();
        int getAssignatures();
        int getedat();

        //Mètodes
        void print();
        void desar();
        void omple();

};

#endif