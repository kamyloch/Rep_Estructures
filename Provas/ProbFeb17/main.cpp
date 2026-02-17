# include <iostream>
# include <vector>
# include <string>
# include "Persona.h"

int main(){

    std::vector<Persona> persones;

    persones.push_back(Persona("Joan", 30));
    persones.push_back(Persona("Maria", 25));

    std::cout << persones.size() << std::endl;
    
    for(int i = 0; i<persones.size(); i++){
        persones[i].print();
    }
    
    return 0;
}