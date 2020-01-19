#include <iostream>
#include <vector>
#include "matrix.h"
#include "myGuard.h"

using namespace std;

void print_hex(int i){
    MyGuard guard(cout);

    cout.fill('y');
    cout.width(10);
    cout << hex;
    cout << i << endl;
    cout << "Your int now is: " << i << endl;
}



int main() {
    int i = 10;
    cout << "====== Before Print Function ======" << endl;
    cout.fill('x');
    cout.width(10);
    cout << i << endl;

    cout << "====== Inside Print Function ======" << endl;
    print_hex(i);

    cout << "====== After Print Function ======" << endl;
    cout.width(10);
    cout << i << endl;
    cout << "====== Matrix ======" << endl;

    Matrix<int> a{{10, 2}, {3, 4}, {50, 60}};
    Matrix<int> b{{2, 1}, {4, 3}, {60, 50}};

    cout << where(a < b, a, b);

    Matrix<int> c{{1, 2}, {2, 1}};
    cout << c.is_symmetric(1e-3) << endl;

    return 0;
}
