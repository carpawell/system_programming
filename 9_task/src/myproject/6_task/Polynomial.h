#include <complex>

template<class T>
class Polynomial {
private:
    T* array; // array[0] * x^n + ... + array[size-1]
    int size;

    template<class Coeff>
    void set_coeff(int place, Coeff first_el){
        array[place] = first_el;
    }

    template<class Coeff>
    void set_coeff(int place, Coeff first_el, Coeff second_el) {
        array[place] = first_el;
        array[place + 1] = second_el;
    }

    template<class FirstCoeff, class ... Coeff>
    void set_coeff(int place, FirstCoeff first_el, Coeff ... tail) {
        array[place] = first_el;
        set_coeff(place + 1, tail...);
    }

public:
    template<class ... Coeff>
    Polynomial(T first_el, Coeff ... tail) {
        size = sizeof...(tail) + 1;
        array = new T[size];
        array[0] = first_el;
        set_coeff(1, tail...);
    }

    Polynomial(T* arr, int size) {
        this->array = arr;
        this->size = size;
    }

    int get_size() const {
        return size;
    }

    void multiply(T x) {
        for(int i = 0; i < size; i++) {
            array[i] = array[i] * x;
        }
    }

    T get_arg(int place) const {
        return array[place];
    }

    ~Polynomial() {
        delete [] array;
    }

};

template<typename T>
struct is_complex_t : public std::false_type {};

template<typename T>
struct is_complex_t<std::complex<T>> : public std::true_type {};

template<class T>
typename std::enable_if<std::is_arithmetic<T>::value, Polynomial<T>>::type
schur_transform(Polynomial<T> p) {
    int size = p.get_size();
    T* array = new T[size];
    for(int i = 0; i < size; i++) {
        array[i] = p.get_arg(size - 1 - i);
    }

    Polynomial<T> reciprocal = Polynomial<T>(array, size);

    reciprocal.multiply(p.get_arg(0));
    p.multiply(p.get_arg(size - 1));

    T* schur_array = new T[size];

    for(int k = 0; k < size; k++) {
        schur_array[k] = p.get_arg(k) - reciprocal.get_arg(k);
    }
    delete [] array;

    return Polynomial<T>(schur_array, size);
}

template<class T>
typename std::enable_if<is_complex_t<T>::value, Polynomial<T>>::type
schur_transform(Polynomial<T> p) {
    int size = p.get_size();
    T* array = new T[size];
    for(int i = 0; i < size; i++) {
        array[i] = std::conj(p.get_arg(size - 1 - i));
    }

    Polynomial<T> reciprocal = Polynomial<T>(array, size);

    reciprocal.multiply(p.get_arg(0));
    p.multiply(std::conj(p.get_arg(size - 1)));

    T* schur_array = new T[size];

    for(int k = 0; k < size; k++) {
        schur_array[k] = p.get_arg(k) - reciprocal.get_arg(k);
    }
    delete [] array;

    return Polynomial<T>(schur_array, size);
}