#pragma once
#include <string>

using namespace std;
class Estudiant {
    private:
        string nom;
        int any;
        int assignatures;

    
    public:
        //Constructor
        Estudiant();

        //Getters
        string getNom();
        int getAny();
        int getAssignatures();
        int getedat();

        //Mètodes
        void print();
        void desar();

};