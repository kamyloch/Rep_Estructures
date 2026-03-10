#ifndef PILA_ESTATICA_H
#define PILA_ESTATICA_H
#include <initializer_list>
#include <vector>
#include <iostream>
#include <stdexcept>

using namespace std;

template <class Elemento>
class PilaEstatica {
    public:
        //Constructores
        PilaEstatica(int max = TAMANO_MAXIMO);
        PilaEstatica(const PilaEstatica &original); //Copia
        PilaEstatica(initializer_list<Elemento> elementos); //Lista inicializadora
        PilaEstatica(const vector<Elemento>& elementos); //Vector inicializador

        //Consultores
        int tamano() const; //Longitud de la pila
        bool estaVacia() const; //La pila está vacía?
        bool estaLlena() const; //La pila está llena?
        const Elemento &elementoEncima() const; //Elemento top    (exep. si está vacía)

        //In-Out
        void suprimirElemento(); //Quita elemento top
        void anadirElemento(const Elemento &e); //Append elemento (exep. si está llena)

        //Metodos
        void print() const; // Muestra la pila (stdout)

    private:
        enum { TAMANO_MAXIMO = 30 };
        vector<Elemento> _datos;
        int _capacidad;
        int _encima; // Posición del elemento de encima (el top) de la pila
};
/*******    Definición de métodos    *******/

//Constructores
template <class Elemento> PilaEstatica<Elemento>:: PilaEstatica(int max){
    if (max < 0)
        throw out_of_range("El máxim ha de ser positiu"); 
    _capacidad = max;
     _encima = -1;
     _datos.reserve(max);
    }
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(const PilaEstatica &original){
    this->_capacidad  = original._capacidad;
    this->_encima  = original._encima;
    this->_datos.reserve(original._capacidad);

    typename vector<Elemento>::const_iterator it  =  original._datos.begin();
    for(it; it != original._datos.end(); ++it)
        this->_datos.push_back(*it); 
}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(initializer_list<Elemento> elementos){
    this-> _capacidad = elementos.size();
    this-> _encima = -1;
    this-> _datos.reserve(_capacidad);

    typename initializer_list<Elemento>::iterator it = elementos.begin();

    for(it; it != elementos.end(); ++it){
        this->_datos.push_back(*it);
        this->_encima ++;
    }

}
template <class Elemento> PilaEstatica<Elemento>::PilaEstatica(const vector<Elemento>& elementos){
    this->_capacidad = elementos.size();
    this->_encima = -1;
    this-> _datos.reserve(_capacidad);

    typename vector<Elemento>::iterator it = elementos.begin();

    for(it; it != elementos.end(); ++it){
        this->_datos.push_back(*it);
        this->_encima ++;
    }
}


//Consultores
template <class Elemento> int PilaEstatica<Elemento>::tamano()const{
    return this->_encima+1;
}
template <class Elemento> bool PilaEstatica<Elemento>::estaLlena()const{
    return _capacidad == _encima + 1;
}
template <class Elemento> bool PilaEstatica<Elemento>::estaVacia()const{
    return this->_encima == -1;
}
template <class Elemento> const Elemento& PilaEstatica<Elemento>::elementoEncima()const{
    if (estaVacia())
        throw runtime_error("No hi ha elements a la pila");
    return _datos[_encima];
}


//In - Out
template <class Elemento> void PilaEstatica<Elemento>::suprimirElemento(){
    if (!estaVacia()){
        this->_datos.pop_back();
        _encima--;
    }
    else throw runtime_error("L'estructura està buida");
}
template <class Elemento> void PilaEstatica<Elemento>::anadirElemento(const Elemento &e){
    if(!estaLlena()){
        this->_datos.push_back(e);
        this->_encima++;
    }
    else throw out_of_range("L'estructura està plena");
}


//Print
template <class Elemento> void PilaEstatica<Elemento>::print() const{
    if (!estaVacia()){
        cout << "[";
        typename vector<Elemento>::const_iterator it = this->_datos.begin();
        for (int i = 1; it< _datos.end()-1; it ++, i++)
            cout << *it <<", ";
        cout << *it<<"]";
    } // La pila no fa salt de linea per la finalitat de aquest exercici, es faran al main
    else 
        cout << "[]";
}


#endif //PILA_ESTATICA_H