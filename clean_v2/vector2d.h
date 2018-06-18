#pragma once
//vector2d.h

template<typename T>
struct Vector2D {

    T x;
    T y;

    Vector2D<T>() : x(0), y(0) {};
    Vector2D<T>(T value);
    Vector2D<T>(T x, T y);

    Vector2D<T> set(T x, T y);
    Vector2D<T> set(T value);

    Vector2D<T>& add(const Vector2D<T>& vec);
    Vector2D<T>& sub(const Vector2D<T>& vec);
    Vector2D<T>& mul(const Vector2D<T>& vec);
    Vector2D<T>& div(const Vector2D<T>& vec);
    Vector2D<T>& add(const T value);
    Vector2D<T>& sub(const T value);
    Vector2D<T>& mul(const T value);
    Vector2D<T>& div(const T value);

    Vector2D<T> operator+(Vector2D<T>& vec);
    Vector2D<T> operator-(Vector2D<T>& vec);
    Vector2D<T> operator*(Vector2D<T>& vec);
    Vector2D<T> operator/(Vector2D<T>& vec);
    bool operator==(Vector2D<T>& vec);
    bool operator!=(Vector2D<T>& vec);
};

typedef Vector2D<int> Vector2Di;
typedef Vector2D<float> Vector2Df;
//typedef Vector2D<unsigned int> Vector2Dui;
//typedef Vector2D<double> Vector2Dd;