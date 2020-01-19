#include <fstream>
#include <iostream>
#include <random>
#include <algorithm>
//#include <chrono>

#include "my_vector.h"

using namespace std;

void task() {
  my_vector<ofstream> files;
  size_t num_of_streams = 5;

  for (size_t i = 0; i < num_of_streams; ++i) {
      string file_name = to_string(i) + ".txt";
      ofstream file(file_name);
      files.push_back(move(file));
  }

//   unsigned seed = chrono::system_clock::now().time_since_epoch().count();
  shuffle(files.begin(), files.end(), std::random_device());

  for (size_t i = 0; i < files.size(); ++i) {
      files[i] << i << endl;
      files[i].close();
  }	
}

void test() {

	my_vector<int> test1;
    test1.push_back(0);
    test1.push_back(1);
    test1.push_back(2);
    test1.push_back(3);
    test1.push_back(4);
    test1.push_back(5);
    test1.push_back(6);
    test1.push_back(7);
    test1.push_back(8);
    test1.pop_back();

//    cout << "Test vector is: ";
//    for (size_t i = 0; i < test1.size(); ++i) {
//        cout << test1[i] << " ";
//    }
//    cout << endl;

//    test1.erase(test1.begin(), test1.begin() + 2);

    cout << "Erase test: ";
    test1.erase(test1.begin());
    for (size_t i = 0; i < test1.size(); ++i) {
        cout << test1[i] << " ";
    }
    cout << endl;

    cout << "Test vector is: ";
    test1.erase(test1.begin(), test1.begin() + 2);
    for (size_t i = 0; i < test1.size(); ++i) {
        cout << test1[i] << " ";
    }
    cout << endl;

    cout << "First element is: " << *test1.begin() << endl;
    cout << "Last element is: " << *(test1.end() - 1) << endl;
    cout << "Second element is: " << test1[1] << endl;
    cout << "===============" << endl;


    my_vector<int> test2(test1);
    my_vector<int> test3(my_vector<int>(4));
    cout << "Size before copy: " << test3.size() << endl;

    test3 = my_vector<int>(3);
    cout << "Size after copy: " << test3.size() << endl;

    test3.push_back(7);
    int a = 5;
    cout << "===============" << endl;
    cout << "Last element: " << *(test3.end() - 1) << endl;
    test3.push_back(a);
    cout << "Last element: " << *(test3.end() - 1) << endl;

    cout << "Test swap, now test vector is: ";
    test1.swap(test3);

    for (size_t i = 0; i < test1.size(); ++i) {
        cout << test1[i] << " ";
    }
    cout << endl;

    for (size_t i = 0; i < test3.size(); ++i) {
    	cout << test3[i] << " ";
    }
    cout << endl;
}

int main() {

	test();
	task();

    return 0;
}
