//vector2d.cpp
#include "vector2d.h"

template<typename T>
Vector2D<T>::Vector2D(T value) {

    this->x = value;
    this->y = value;
}

template<typename T>
Vector2D<T>::Vector2D(T x, T y) {

    this->x = x;
    this->y = y;
}

template<typename T>
Vector2D<T> Vector2D<T>::set(T x, T y) {

    this->x = x;
    this->y = y;
}

template<typename T>
Vector2D<T> Vector2D<T>::set(T value) {

    this->x = value;
    this->y = value;
}

template<typename T>
Vector2D<T>& Vector2D<T>::add(const Vector2D<T>& vec) {

    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::sub(const Vector2D<T>& vec) {

    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::mul(const Vector2D<T>& vec) {

    this->x *= vec.x;
    this->y *= vec.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::div(const Vector2D<T>& vec) {

    this->x /= vec.x;
    this->y /= vec.y;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::add(const T value) {

    this->x += value;
    this->y += value;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::sub(const T value) {

    this->x -= value;
    this->y -= value;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::mul(const T value) {

    this->x *= value;
    this->y *= value;

    return *this;
}

template<typename T>
Vector2D<T>& Vector2D<T>::div(const T value) {

    this->x /= value;
    this->y /= value;

    return *this;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator+(Vector2D<T>& vec) {

    this->x + vec.x;
    this->y + vec.y;

    return *this;
}

template<typename T>
Vector2D<T> Vector2D<T>::operator-(Vector2D<T>& vec) {

    this->x - vec.x;
    this->y - vec.y;

    return *this;
}
template<typename T>
Vector2D<T> Vector2D<T>::operator*(Vector2D<T>& vec) {

    this->x * vec.x;
    this->y * vec.y;

    return *this;
}
template<typename T>
Vector2D<T> Vector2D<T>::operator/(Vector2D<T>& vec) {

    this->x / vec.x;
    this->y / vec.y;

    return *this;
}

template<typename T>
bool Vector2D<T>::operator==(Vector2D<T>& vec) {

    if (this->x == vec.x && this->x == vec.y) {
        return true;
    }
    else {
        return false;
    }
}

template<typename T>
bool Vector2D<T>::operator!=(Vector2D<T>& vec) {

    if (this->x != vec.x && this->x != vec.y) {
        return true;
    }
    else {
        return false;
    }
}