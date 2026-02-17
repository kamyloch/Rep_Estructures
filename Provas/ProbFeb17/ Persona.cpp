#include <iostream>
#include "Persona.h"
#include <string>
#include <vector>

//Constructor
Persona::Persona(std::string n, int e){
    nom = n;
    edat = e;
}
//Getters
std::string Persona::getNom() const{
    return nom;
}
int Persona::getEdat() const{
    return edat;
}
//Metodos
void Persona::incrementarEdat(){
    edat++;
}
void Persona::print(){
    std::cout << "Nom: " << nom << ", Edat: " << edat << std::endl;
}
