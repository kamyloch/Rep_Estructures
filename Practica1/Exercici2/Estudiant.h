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
        Estudiant();

        //Setters
        void setAny(int any_);
        void setAssignatures(int ass_);
        void setNom(string nom_);

        //Getters
        int getEdat() const;
        int getEdat() const;
        
        //Metodes
        void print();
};


#endif