#include "BinaryTree.h"
#include <stdexcept>
#include <iostream>
#include <cstdlib>
#include "Position.h"
using namespace std;
/* Mapa mental:
              02
        /             \        
      00              08  
   /      \        /      \
  --      --      05      45
 /  \    /  \    /  \    /  \ 
--  --  --  --  03  --  40  76 

*/

void mainExercici1(){
    BinaryTree<int, int> tree1;
    int testKeys[] = {2, 0, 8, 45, 76, 5, 3, 40};
    int testValues[] = {5, 5, 1, 88, 99, 12, 9, 11};
    for (int i = 0; i < 8 ; i++) {
        cout << "Inserta a l'arbre la key " << testKeys[i] << " amb valor " << testValues[i] << endl;
        tree1.insert(testKeys[i], testValues[i]);
    }
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;
    cout << "Postorder = [";
    tree1.printPostOrder();
    cout << "]" << endl;
    BinaryTree<int, int> tree2(tree1);
    cout << " identics " << tree1.identicalTree(tree2) << endl;
    cout << "Preorder = [";
    tree1.printPreOrder();
    cout << "]" << endl;
    tree2.insert(4, 4);
    cout << " identics " << tree2.identicalTree(tree1) << endl;
    cout << "Preorder = [";
    tree2.printPreOrder();
    cout << "]" << endl;
    tree1.print();
}

int main(){
    mainExercici1();
    
    cout << "Prova del metode print" << endl;
    for (int i = 0; i < 5; i++){
        cout<< endl<< "Abre #"<< i << endl;
        BinaryTree<int,int> t;
        for (int i = 0; i < 10; i++)
            t.insert(rand() % 101,1);
        t.print(true);
    }


}