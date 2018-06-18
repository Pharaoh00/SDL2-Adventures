#pragma once
#include <math.h>
#include <iostream>
#include <sstream>
#include <string>

struct Vector2D {

    int x;
    int y;

    Vector2D();
    Vector2D(int value);
    Vector2D(int value1, int value2);
    Vector2D& add(Vector2D& vec);
    Vector2D& sub(Vector2D& vec);
    bool operator==(Vector2D& vec);
    bool operator!=(Vector2D& vec);
    Vector2D operator+=(Vector2D& vec);
    Vector2D operator*(int value);
    Vector2D& min(Vector2D& min, Vector2D& max);
    ~Vector2D();

    Vector2D& set(int x, int y);
    Vector2D& dot(Vector2D& vec);
    Vector2D& distance(Vector2D& vec);
    int mag();
    int magsq();
    Vector2D normalize();

    std::string ToString();
};