using namespace std;

template<typename T>
class my_vector {
private:
    size_t len = 0;
    T* ptr = nullptr;

public:
    my_vector() = default;
    my_vector(size_t size);
    my_vector(const my_vector& other);
    my_vector(my_vector&& other);

    T& operator[](size_t i);
    my_vector& operator=(const my_vector& other);
    my_vector& operator=(my_vector&& other);

    T* begin();
    T* end();

    size_t size();
    void push_back(const T& value);
    void push_back(T&& value);
    void pop_back();
    void erase(T* position);
    void erase(T* first, T* last);
    void swap(my_vector& other);

    ~my_vector();
};

template<typename T>
my_vector<T>::my_vector(size_t size): len(size), ptr(new T[size]) {}

template<typename T>
my_vector<T>::my_vector(const my_vector& other): len(other.len), ptr(new T[other.len]) {
    copy(other.ptr, other.ptr + other.len, ptr);
}

template<typename T>
my_vector<T>::my_vector(my_vector&& other) : len(other.len), ptr(other.ptr) {
    other.ptr = nullptr;
}

template<typename T>
T& my_vector<T>::operator[](size_t i) {
    return *(ptr + i);
}

template<typename T>
my_vector<T>& my_vector<T>::operator=(const my_vector& other) {
    my_vector tmp(other);
    this->swap(tmp);
    return *this;
}

template<typename T>
my_vector<T>& my_vector<T>::operator=(my_vector&& other) {
    this->swap(other);
    return *this;
}

template<typename T>
T* my_vector<T>::begin() {
    return ptr;
}

template<typename T>
T* my_vector<T>::end() {
    return ptr + len;
}

template<typename T>
size_t my_vector<T>::size() {
    return len;
}

template<typename T>
void my_vector<T>::push_back(const T& value) {
    T* old_data = ptr;
    ptr = new T[++len];
    copy(old_data, old_data + len - 1, ptr);
    ptr[len - 1] = value;
    delete[] old_data;
}

template<typename T>
void my_vector<T>::push_back(T&& value) {
    T* old_data = ptr;
    ptr = new T[++len];
    move(old_data, old_data + len - 1, ptr);
    ptr[len - 1] = move(value);
    delete[] old_data;
}

template<typename T>
void my_vector<T>::pop_back() {
    T* old_data = ptr;
    ptr = new T[--len];
    move(old_data, old_data + len, ptr);
    delete[] old_data;
}

template<typename T>
void my_vector<T>::erase(T* position) {
    if (position == end()) {
        pop_back();
        return;
    }
    move(position + 1, end(), position);
    T* old_data = ptr;
    ptr = new T[--len];
    move(old_data, old_data + len + 1, ptr);
    delete[] old_data;    
}

template<typename T>
void my_vector<T>::erase(T* first, T* last) {
    T* old_data = ptr;
    ptr = new T[len - (last - first)];

    move(old_data, first, ptr);
    move(last, old_data + len, ptr + (first - old_data));

    len -= (last - first);
    delete[] old_data;
}

template<typename T>
void my_vector<T>::swap(my_vector& other) {
    std::swap(len, other.len);
    std::swap(ptr, other.ptr);
}

template<typename T>
my_vector<T>::~my_vector() {
    delete[] ptr;
}

template<typename T>
void swap(my_vector<T>& vec1, my_vector<T>& vec2) {
    vec1.swap(vec2);
}
