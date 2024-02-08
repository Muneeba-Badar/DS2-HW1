#include "StackPostscript.hpp"
#include <cmath>

template <typename T>
T StackPostscript<T>::add(T x, T y){
    return x+y;
}
template <typename T>
T StackPostscript<T>::sub(T x, T y){
    return x-y;
}
template <typename T>
T StackPostscript<T>::mul(T x, T y){
    return x*y;
}
template <typename T>
T StackPostscript<T>::div(T x, T y){
    return x/y;
}
template <typename T>
T StackPostscript<T>::sin(T x){
    return sin(x);
}
template <typename T>
T StackPostscript<T>::cos(T x){
    return cos(x);
}
template <typename T>
T StackPostscript<T>::mod(T x, T y){
    return x%y;
}
template <typename T>
T StackPostscript<T>::exp(T x, T y){
    return x**y;
}
template <typename T>
T StackPostscript<T>::sqrt(T x){
    return sqrt(x);
}

