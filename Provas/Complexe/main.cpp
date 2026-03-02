#include "Complexe.h”
using namespace std;

int main() {
    Complexe<float> c(2.5, 3.2);
    cout << "Part real " << c.real() << endl;
    cout << "Part imaginaria " << c.imaginari() << endl;

    Complexe<int> c2(2, 3);
    cout << "Part real " << c2.real() << endl;
    cout << "Part imaginaria " << c2.imaginari() << endl;

    Complexe<int> c3(1, 2);
    cout << "Part real " << c3.real() << endl;
    cout << "Part imaginaria " << c3.imaginari() << endl;
    
    Complexe<double> c4(0.0,0.0);
    cout << "Part real " << c4.real() << endl;
    cout << "Part imaginaria " << c4.imaginari() << endl;
return 0;
}