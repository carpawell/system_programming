#include <cmath>

template <class T>
class Circle {
private:
    T radius;

public:
    Circle(T R) : radius(R) {}

    void set_radius(T R) {
        this->radius = R;
    }

    T get_radius() const {
        return radius;
    }

    T square() const {
        return M_PI * pow(radius, 2);
    }
};

template <class T>
class Rectangle {
private:
    T a, b;

public:
    Rectangle(T a, T b) : a(a), b(b) {}

    void set_a(T a) {
        this->a = a;
    }

    T get_a() const {
        return a;
    }

    void set_b(T b) {
        this->b = b;
    }

    T get_b() const {
        return b;
    }

    T square(){
        return a * b;
    }
};

namespace std {
    template<class Figure>
    struct Trait;

    template<class T>
    struct Trait<Circle<T>> {
        static unsigned size(const Circle<T>& c) {
            return sizeof(c.get_radius());
        }
    };

    template<class T>
    struct Trait<Rectangle<T>> {
        static unsigned size(const Rectangle<T>& r) {
            return sizeof(r.get_a()) + sizeof(r.get_b());
        }
    };
}
