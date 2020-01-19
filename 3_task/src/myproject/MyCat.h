#include <array>

template<class T, std::size_t N, std::size_t M>
std::array<T, N + M> cat2arrays(std::array<T, N> arr_1, std::array<T, M> arr_2) {
    std::array<T, N + M> array_to_return;

    std::copy(arr_1.cbegin(), arr_1.cend(), array_to_return.begin());
    std::copy(arr_2.cbegin(), arr_2.cend(), array_to_return.begin() + N);

    return array_to_return;
}

template<class FirtsElement>
FirtsElement fun(FirtsElement first){
    return first;
}

template<class FirstElement, class SecondElement>
auto fun(FirstElement first, SecondElement second) -> decltype(cat2arrays(first, second)){
    return cat2arrays(first, second);
}

template<class FirstElement, class ... Tail>
auto fun(FirstElement first, Tail ... tail)-> decltype(fun(first, fun(tail...))){
    return fun(first, fun(tail...));
}

template<class ... Arrays>
auto cat(Arrays ... arrays) -> decltype(fun(arrays...)){
    return fun(arrays...);
}
