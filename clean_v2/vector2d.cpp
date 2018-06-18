#include "vector2d.h"

Vector2D::Vector2D() {
    this->x = 0;
    this->y = 0;
}

Vector2D::Vector2D(int value) {
    this->x = value;
    this->y = value;
}

Vector2D::Vector2D(int value1, int value2) {
    this->x = value1;
    this->y = value2;
}

// Add a vector to another vector using +=
Vector2D& Vector2D::add(Vector2D& vec) {
    
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

// Add a vector to another vector using -=
Vector2D& Vector2D::sub(Vector2D& vec) {

    this->x -= vec.x;
    this->y -= vec.y;

    return *this;
}

bool Vector2D::operator==(Vector2D& vec) {

    if (this->x == vec.x && this->y == vec.y) {
        return true;
    }
    else {
        return false;
    }
}

bool Vector2D::operator!=(Vector2D& vec) {

    if (this->x != vec.x && this->y != vec.y) {
        return true;
    }
    else {
        return false;
    }
}

Vector2D Vector2D::operator+=(Vector2D& vec) {
    //vec.normalize();
    this->x += vec.x;
    this->y += vec.y;

    return *this;
}

Vector2D Vector2D::operator*(int value) {
    this->x = this->x * value;
    this->y = this->y * value;

    return *this;
}

Vector2D& Vector2D::min(Vector2D& min, Vector2D& max) {

    if (min.x <= max.x) {
        this->x = min.x;
    }
    else {
        this->x = max.x;
    }

    if (min.y <= max.x) {
        this->y = min.y;
    }
    else {
        this->y = max.y;
    }

    return *this;
}

Vector2D& Vector2D::set(int x, int y) {

    this->x = x;
    this->y = y;

    return *this;
}

Vector2D& Vector2D::dot(Vector2D& vec) {

    (this->x * vec.x) + (this->y * vec.y);
    return *this;
}

Vector2D& Vector2D::distance(Vector2D& vec) {

    float p1 = pow(this->x - vec.x, 2);
    float p2 = pow(this->y - vec.y, 2);
    float f = sqrt(p1 + p2);
    return *this;
}

/*
Calculates the magnitude(length) of the vector and returns the result as a 
??float(this is simply the equation sqrt(xx + yy + z * z).)
*/
int Vector2D::mag() {

    return sqrt((this->x*this->x) + (this->y*this->y));
    //return (int)sqrt(x*x + y*y);
}

/*
Calculates the squared magnitude of the vector and returns the result as a 
??float (this is simply the equation (xx + yy + z*z).) 
Faster if the real length is not required in the case of comparing vectors, etc.
*/
int Vector2D::magsq() {
    
    return (this->x * this->x) + (this->y * this->y);
}

Vector2D Vector2D::normalize() {
    //this->x / lenght();
    //this->y / lenght();
    //if (lenght() == 0) {
    //    return vec;
    //}

    if (mag() != 0) {
        this->x = this->x / mag();
        this->y = this->y / mag();
        return *this;
    }
    //std::cout << "Normalize: " << x << std::endl;
    //std::cout << "Normalize: " << y << std::endl;
}

Vector2D::~Vector2D() {

}

std::string Vector2D::ToString() {
    
    std::stringstream ss(std::stringstream::in | std::stringstream::out);

    ss << "(" << this->x << ", " << this->y << ")";

    return ss.str();
}