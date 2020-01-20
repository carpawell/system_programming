#include <vector>

template <typename T>
bool turn_vector(std::vector<T>& vec, int degrees){
    if (vec.size() > 2)
        return false;

    if (degrees % 90 > 0)
        return false;

    int n = degrees / 90;
    if(n > 0)
        for(int i = 0; i < n; i++){
            T a = vec[1];
            vec[1] = -vec[0];
            vec[0] = a;
        }
    else
        for(int i = 0; i < -n; i++){
            T a = vec[0];
            vec[0] = -vec[1];
            vec[1] = a;
        }

    return true;
}
