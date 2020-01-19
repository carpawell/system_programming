#include <iostream>
#include <vector>
#include <iterator>

using namespace std;

template<typename T>
class Matrix {
private:
    vector<T> matrix;
    size_t n;
    size_t m;

public:
    Matrix() = default;

    Matrix(const Matrix<T>& other): matrix(other.matrix), n(other.n), m(other.m) {};

    Matrix(const vector<T>& other): matrix(other), n(other.size()), m(1) {}

    Matrix(size_t height, size_t length): matrix(vector<T>(height * length)), n(height), m(length) {}

    Matrix(initializer_list<T> other): n(other.size()), m(1) {
        matrix.insert(matrix.end(), other.begin(), other.end());
    }

    Matrix(initializer_list<initializer_list<T>> other): n(other.size()), m(other.begin()->size()) {
        for (auto iter = other.begin(); iter != other.end(); iter++)
            matrix.insert(matrix.end(), iter->begin(), iter->end());
    }


    void print(ostream& stream) const {
        for (size_t i = 0;  i < n; i++) {
            copy(matrix.begin() + i*m, matrix.begin() + (i + 1)*m, ostream_iterator<T>(stream, " "));
            stream << "\n";
        }
    }

    pair<size_t, size_t> size() const {
        return {n, m};
    }

    Matrix<T> transposed() const {
        Matrix<T> trans(m, n);

        for (size_t i = 0; i < m; i++)
            for (size_t j = 0; j < n; j++)
                trans(i, j) = this->operator()(j, i);

        return trans;
    }

    bool is_symmetric(float eps) {
        return all(abs(*this - this->transposed()) < eps);
    }

    friend ostream& operator<<(ostream& out, const Matrix<T>& other) {
        other.print(out);
        return out;
    }

    Matrix<T> operator=(const Matrix<T>& other) {
        matrix = other.matrix;
        n = other.n;
        m = other.m;
        return *this;
    }

    typename vector<T>::reference operator()(size_t i, size_t j) {
        return matrix[i*m + j];
    }

    T operator()(size_t i, size_t j) const {
        return matrix[i*m + j];
    }

    Matrix<bool> operator<(const Matrix<T>& other) const {
        Matrix<bool> result(n, m);

        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                result(i, j) = this->operator()(i, j) < other(i, j);

        return result;
    }

    Matrix<bool> operator<(float eps) const {
        Matrix<bool> result(n, m);

        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                result(i, j) = this->operator()(i, j) < eps;

        return result;
    }

    Matrix<bool> operator>(const Matrix<T>& other) const {
        Matrix<bool> result(n, m);

        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                result(i, j) = this->operator()(i, j) > other(i, j);

        return result;
    }

    Matrix<bool> operator>(float eps) const {
        Matrix<bool> result(n, m);

        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                result(i, j) = this->operator()(i, j) < eps;

        return result;
    }

    Matrix<T> operator-(const Matrix<T>& other) const {
        Matrix<T> result(n, m);

        for (size_t i = 0; i < n; i++)
            for (size_t j = 0; j < m; j++)
                result(i, j) = this->operator()(i, j) - other(i, j);

        return result;
    }

    bool operator==(const Matrix<T>& other) const {
        return (n == other.n) && (m == other.m) && (matrix == other.matrix);
    }

    ~Matrix() = default;
};

template<typename T>
Matrix<T> where(const Matrix<bool>& condition, const Matrix<T>& first_matrix, const Matrix<T>& second_matrix) {
    auto temp = condition.size();
    size_t n = temp.first;
    size_t m = temp.second;
    Matrix<T> result(n, m);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            result(i, j) = condition(i, j) ? first_matrix(i, j) : second_matrix(i, j);

    return result;
}

template<typename T>
Matrix<T> abs(const Matrix<T>& matrix) {
    auto temp = matrix.size();
    size_t n = temp.first;
    size_t m = temp.second;
    Matrix<T> abs_matrix(n, m);

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            abs_matrix(i, j) = matrix(i, j) < 0 ? -matrix(i, j) : matrix(i, j);

    return abs_matrix;
}

bool all(const Matrix<bool>& matrix) {
    auto temp = matrix.size();
    size_t n = temp.first;
    size_t m = temp.second;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < m; j++)
            if (!matrix(i, j))
                return false;

    return true;
}