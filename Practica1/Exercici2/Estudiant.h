//Autor: Camilo Chicaiza Toapanta
 
#define ESTUDIANT_H
#ifdef ESTUDIANT_H

#include <string>

using namespace std;


class Estudiant {
    private:
        string nom;
        int any;
        int assignatures;

    public:

        //Constructor
        Estudiant(string nom_ = "", int any_ = 0, int assignatures_ = 0);

        //Setters
        void setAny(int any_);
        void setAssignatures(int ass_);
        void setNom(string nom_);

        //Getters
        int getEdat() const;
        
        //Metodes
        void print();
        void omple();
};


#endif