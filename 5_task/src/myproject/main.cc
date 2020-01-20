#include <My_iterator.h>
#include <merge_sort.h>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int indent = 2;
    MyIterator<int> itr(cout, " ", indent);
    vector<int> vec;

    cout << "Vector: ";
    for(int i = 10; i >= 0; i--) {
        cout << i << " ";
        vec.push_back(i);
    }

    cout << endl << "Vector through MyIterator with N = " << indent << ":" << endl;

    auto pointer = vec.begin();

    while(pointer != vec.end()) {
        *itr = *pointer;
        itr++;
        pointer++;
    }



    merge_sort(vec.begin(), vec.end());
    cout << endl << "Vector after merge_sort:" << endl;
    for(int x: vec)
        cout << x << " ";
    return 0;
}
