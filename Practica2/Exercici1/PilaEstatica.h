#ifndef PILA_ESTATICA_H
#define PILA_ESTATICA_H
#include <initializer_list>
#include <vector>

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

template <class Elemento> PilaEstatica<Elemento>:: PilaEstatica(int max){}


#endif //PILA_ESTATICA_H