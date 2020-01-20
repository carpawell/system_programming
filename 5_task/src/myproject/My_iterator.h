#include <ostream>

template<class T>
class MyIterator {
private:
    std::ostream* pointer;
    const char* delim;
    int N;
    int n;
public:
    MyIterator(std::ostream& str, const char* delim, int N): pointer(&str), delim(delim), N(N) {
        n = 1;
    }

    MyIterator& operator*() {
        return *this;
    }

    MyIterator& operator=(T p) {
        if(n == N) {
            n = 1;
            *pointer << p << delim;
        }
        else {
            n++;
        }
        return *this;
    }

    MyIterator& operator++(int i) {
        return *this;
    }
    MyIterator& operator++() {
        return *this;
    }

    ~MyIterator() = default;

};