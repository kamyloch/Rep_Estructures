#ifndef PERSONA_H
#define PERSONA_H
# include <iostream>
# include <string>

class Persona{
    private:
        std::string nom;
        int edat;


    public:
        //Constructor
        Persona(std::string n, int e);

        //Getters
        std::string getNom() const;
        int getEdat() const; 

        //Metodos
        void incrementarEdat();
        void print();
};

#endif