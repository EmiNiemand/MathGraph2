//
// Created by szymo on 08/10/2022.
//

#include "Vector.h"

Vector::Vector() : x(0), y(0), z(0) {
}

Vector::Vector(float x, float y, float z) : x(x), y(y), z(z) {

}

Vector::Vector(Vector p1, Vector p2) {
    x = p1.x - p2.x;
    y = p1.y - p2.y;
    z = p1.z - p2.z;
}

Vector::Vector(const Vector &v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector::~Vector() {
}

#pragma region Overloading operators
void Vector::operator+=(const Vector &v) {
    x+=v.x;
    y+=v.y;
    z+=v.z;
}

void Vector::operator-=(const Vector &v) {
    x-=v.x;
    y-=v.y;
    z-=v.z;
}

void Vector::operator*=(const float &s) {
    this->x *= s;
    this->y *= s;
    this->z *= s;
}

void Vector::operator/=(const float &s) {
    if(s == 0)
    {
        printf("Can't divide by 0 [Div]");
        return;
    }

    this->x /= s;
    this->y /= s;
    this->z /= s;
}

Vector Vector::operator+(const Vector &v) {
    Vector vector = Vector(*this);
    vector += v;
    return vector;
}

Vector Vector::operator-(const Vector &v) {
    Vector vector = Vector(*this);
    vector -= v;
    return vector;
}

Vector Vector::operator*(const float &s) {
    Vector vector = Vector(*this);
    vector *= s;
    return vector;
}

Vector Vector::operator/(const float &s) {
    Vector vector = Vector(*this);
    vector /= s;
    return vector;
}
#pragma endregion

#pragma region Basic math functions
void Vector::add(Vector v) {
    this->operator+=(v);
}

void Vector::sub(Vector v) {
    this->operator-=(v);
}

void Vector::mul(float s) {
    this->operator*=(s);
}

void Vector::div(float s) {
    this->operator/=(s);
}

#pragma endregion

float Vector::length() {
    return (float)sqrt(pow(this->x, 2) +
                       pow(this->y, 2) +
                       pow(this->z, 2));
}

void Vector::normalize() {
    float n = this->length();
    if(n == 0) {
        printf("Can't divide by 0 [Normalize]\n");
        return;
    }

    this->div(n);
}

Vector Vector::dot(Vector& v1, Vector& v2)
{
    Vector result;
    result.x = v1.x * v2.x;
    result.y = v1.y * v2.y;
    result.z = v1.z * v2.z;
    return result;
}

float Vector::dotProduct(Vector& v1, Vector& v2)
{
    Vector result = dot(v1, v2);
    return result.x + result.y + result.z;
}

Vector Vector::cross(Vector& v1, Vector& v2)
{
    return Vector(v1.y * v2.z - v1.z * v2.y,
                  v1.z * v2.x - v1.x * v2.z,
                  v1.x * v2.y - v1.y * v2.x);
}

std::string Vector::toString() {
    if((int)x != x || (int)y !=y || (int)z != z)
        return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";

    return "[" + std::to_string((int)x) + ", " + std::to_string((int)y) + ", " + std::to_string((int)z) + "]";
}

float Vector::calcAngle(Vector& v1, Vector& v2) {
    float angle = dotProduct(v1, v2);
    angle = acos(angle / (v1.length() * v2.length()));
    return angle;
}
