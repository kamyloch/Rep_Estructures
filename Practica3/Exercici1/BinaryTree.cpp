#include "BinaryTree.h"

//Para el print
#include <cmath>
#include <queue>
#include <sstream>


/*  --------   Definició de Mètodes  --------   */
/* Constructor */
template <class Key, class Value>
BinaryTree<Key, Value>::BinaryTree():
    _size(0),
    root(nullptr)
{}
template <class Key, class Value>
BinaryTree<Key, Value>::BinaryTree(const BinaryTree<Key, Value>& orig): BinaryTree(){
    if (orig.isEmpty()) return;
    this->root = new Position<Key, Value>(*orig.getRoot());
    _size = 1;
    copy_rec(*orig.getRoot(), this->root);

    
}
template <class Key, class Value>
BinaryTree<Key, Value>::~BinaryTree(){
    if (root != nullptr)
        delete root;
}

/* Modificadors */
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>:: insert(const Key& key, const Value& value){
    if (isEmpty()){
        root = new Position<Key, Value> (key);
        root -> addValue(value); 
        _size = 1; 
        return root;
    }

    Position<Key, Value>* itr = root;
    Position<Key, Value>* itrPare = nullptr;
    
    bool trobat = false;
    while (itr != nullptr && !trobat){
        itrPare = itr;
        if (itr->getKey()< key)
            itr = itr->right();
        else if (itr->getKey()> key)
            itr = itr->left();
        else 
            trobat = true;
    }

    if (trobat){
        itr->addValue(value);
        return itr;
    }

    Position<Key, Value>* nou = new Position<Key, Value>(key);
    if (itrPare->getKey()< key)
        itrPare->setRight(nou);
    else
        itrPare->setLeft(nou);
    nou->setParent(itrPare);
    nou->addValue(value);
    this->_size ++;
    return nou;
}

/* Consultors */
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>::getRoot() const {
    return this->root;
}
template <class Key, class Value>
int BinaryTree<Key, Value>::size() const {
    return _size;
}
template <class Key, class Value>
const vector<Value>& BinaryTree<Key, Value>:: getValues(const Key& key) const { 
    Position<Key, Value>* pos = search(key);
    if (key == nullptr);
        throw out_of_range("No hi es aquesta clau");
}
template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>:: search (Key key) const{ //Recursivament
    return search_rec(this->root, key);
}

/* Operacions */
template <class Key, class Value>
bool BinaryTree<Key, Value>::isEmpty() const{
    return root == nullptr;
}
template <class Key, class Value>
int BinaryTree<Key, Value>::height() const { //Recursivament
    if (isEmpty()) throw out_of_range("L'abre está buid");
    return getRoot()->height();
}
template <class Key, class Value>
bool BinaryTree<Key, Value>::contains(const Key& key) const{ //Iterativament
    const Position<Key, Value>* itr = getRoot();
    bool trobat = false;

    while(!trobat && itr != nullptr){
        if (key > itr->getKey())
            itr = itr->right();
        else if (key < itr->getKey())
            itr = itr->left();
        else
            trobat = true;
    }
    return trobat;
}



/* Prints */
template <class Key, class Value>
void BinaryTree<Key, Value>::printPreOrder(const Position<Key, Value> *node) const{
    if (isEmpty()) return;
    if (node == nullptr) node = root;

    cout << node->getKey() << ", ";
    if (node->left() != nullptr)
        printPreOrder(node->left());
    if (node->right() != nullptr)
        printPreOrder(node->right());
}
template <class Key, class Value>
void BinaryTree<Key, Value>::printPostOrder(const Position<Key, Value> *node) const{
    if (isEmpty()) return;
    if (node == nullptr) node = root;

    if (node->left() != nullptr)
        printPostOrder(node->left());
    if (node->right() != nullptr)
        printPostOrder(node->right());
    cout << node->getKey() << ", ";

}
template <class Key, class Value>
bool BinaryTree<Key, Value>:: identicalTree(const BinaryTree<Key, Value>& other) const{

    return identical_rec(other.getRoot(),root);
}


/* Recursivitats */

template <class Key, class Value>
void BinaryTree<Key, Value>::copy_rec (const Position<Key, Value>& org, Position<Key, Value>* nou){
    if (nou == nullptr)
        throw runtime_error("Aquest node hauria de estar creat");
    Position<Key, Value>* izq = org.left();
    Position<Key, Value>* der = org.right();

    if (izq != nullptr){
        Position<Key, Value>* nouIzq = new Position<Key, Value>(*izq);
        nou->setLeft(nouIzq);
        nouIzq->setParent(nou);
        _size++;
        copy_rec(*izq,nouIzq);
    }
    if (der != nullptr){
        Position<Key, Value>* nouDer = new Position<Key, Value>(*der);
        nou->setRight(nouDer);
        nouDer->setParent(nou);
        _size++;
        copy_rec(*der,nouDer);
    }
}

template <class Key, class Value>
Position<Key, Value>* BinaryTree<Key, Value>:: search_rec (Position<Key, Value>* node, Key key) const{
    if (node == nullptr) 
        return nullptr;
    if (node->getKey()< key)
        return search_rec(node->right(),key);
    if (node->getKey()> key)
        return search_rec(node->left(),key);
    return node;
}

template <class Key, class Value>
bool BinaryTree<Key, Value>:: identical_rec (const Position<Key, Value>* org,const Position<Key, Value>* act) const{
    if (org == nullptr && act == nullptr)
        return true;
    if (org == nullptr || act == nullptr)
        return false;
    if(org->getKey() != act->getKey())
        return false;
    return identical_rec (org->left(),act->left()) && identical_rec (org->right(),act->right());
}




/* Extra */

template <class Key, class Value>
string BinaryTree<Key, Value>:: convert_str(const Key& value) const{
    stringstream ss;
    ss << value;
    return ss.str();
}
template <class Key, class Value>
void BinaryTree<Key, Value>:: print(bool sencer) const{
    if(isEmpty()){ 
        cout<< " --- Arbre buit ---" << endl;
        return;
    }
    //Llindar
    int h = this-> height();
    if (h > 6){ 
        cout<< " --- Arbre massa gran ---" << endl;
        return;
    }

    cout << "  --- Nodes : " + to_string(size()) + " ---"<< endl;

    //Amplada maxima para centrar de manera que abajo quede xx--xx--xx--....
    //xx-- son cuatro caracteres, y sabemos que habran 2^h elementos (h = alçada)
    int amplada = pow(2,h- 1)*4;


    //Recorregut d'amplada amb cua com vist a teoria
    queue <Position<Key, Value>*> cua;

    //Comencem amb el root
    cua.push(root);

    //Variables auxialiars
    Position<Key, Value>* top;

    int nivell = 0;
    int fets = 0;
    //4 espai_minim es un element, en 2 ja no hauria de fer print
    while (amplada >= 4){
        //Agafem el front
        top = cua.front();
        
        //Si es null imprimeix l'espai
        if (top == nullptr)
            cout << center(sencer? "--" : "  ",amplada);
        
        //Sino agafem la key del node i la imprimeix
        else
            cout << center(convert_str(top->getKey()),amplada);
    
        //Treiem l'imprès
        cua.pop();
        fets++;

        //Si es null fiquem mes nuls per completar a un arbre perfecte
        if (top == nullptr){
            cua.push(nullptr);
            cua.push(nullptr);
        }
        //Sino els corespondents
        else{
            cua.push(top->left());
            cua.push(top->right());
        }

        /*
          Los numeros de la forma si k = 2^(n+1) -1 son  k = 01111111
          enotnces k+1 = 1000000
          entonces k & (k+1) = 0 combinando los bits

          Si k es de esta forma entonces habremos hecho los nodos de un arbol perfecto
          como la queue tiene los null para rellenar entonces k se esa forma dice que
          hay que hacer un salto de linea
        */
        if ((fets & (fets + 1)) == 0){
            //Salt
            amplada /= 2;
            cout << endl;

            //Atura a l'ultim nivell
            if (amplada<3) continue;
            

            //Palitos que conecten els nodes
            int num_Nodes= pow(2,nivell);

            //Per a cada node del nivell imprimin els palets a sota de cada node
            if (sencer){
                for(int i = 0; i < num_Nodes; i++)
                    cout << center(" /", amplada) << center("\\ ", amplada);
            }
            //Aportacio per !sencer de gemini
            else{
                //Clon de la cua
                queue<Position<Key, Value>*> copia = cua;
            
                //Per cada node del nivell actual
                for (int i = 0; i < num_Nodes; i++) {
                //Agafem els fills
                    Position<Key, Value>* izq = copia.front(); copia.pop();
                    Position<Key, Value>* der = copia.front(); copia.pop();

                    //Fem les branques si hi ha fill
                    string brancaIzq = (izq != nullptr) ? " /" : "  ";
                    string brancaDer = (der != nullptr) ? "\\ " : "  ";
                    cout << center(brancaIzq, amplada)<< center(brancaDer, amplada);
            }
        }
            cout << endl;
            nivell++;
        }
    }
}
template <class Key, class Value>
string BinaryTree<Key, Value>:: center(string cad,int n) const{
    if (n == 0) return "";
    int espacio = n - cad.size();
    if (espacio == 0) return cad;
    if (espacio < 0) return cad.substr(0, n-1) + "-";

    int izq = espacio/2;
    int der = espacio - izq;

    return string(izq,' ') + cad + string(der,' ');
}

/* Mapa mental
              02
        /             \        
      00              08  
   /      \        /      \
  --      --      05      45
 /  \    /  \    /  \    /  \ 
--  --  --  --  03  --  40  76 
*/