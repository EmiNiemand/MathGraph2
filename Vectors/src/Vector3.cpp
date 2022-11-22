//
// Created by masterktos on 22.11.22.
//

#include "Vector3.h"

#include <cmath>

Vector3::Vector3() : x(0), y(0), z(0) {
}

Vector3::Vector3(float x, float y, float z) : x(x), y(y), z(z) {

}

Vector3::Vector3(Vector3 p1, Vector3 p2) {
    x = p1.x - p2.x;
    y = p1.y - p2.y;
    z = p1.z - p2.z;
}

Vector3::Vector3(const Vector3 &v) {
    x = v.x;
    y = v.y;
    z = v.z;
}

Vector3::~Vector3() {
}

#pragma region Overloading operators
void Vector3::operator+=(const Vector3 &v) {
    x+=v.x;
    y+=v.y;
    z+=v.z;
}

void Vector3::operator-=(const Vector3 &v) {
    x-=v.x;
    y-=v.y;
    z-=v.z;
}

void Vector3::operator*=(const float &s) {
    this->x *= s;
    this->y *= s;
    this->z *= s;
}

void Vector3::operator/=(const float &s) {
    if(s == 0)
    {
        printf("Can't divide by 0 [Div]");
        return;
    }

    this->x /= s;
    this->y /= s;
    this->z /= s;
}

Vector3 Vector3::operator+(const Vector3 &v) {
    Vector3 vector = Vector3(*this);
    vector += v;
    return vector;
}

Vector3 Vector3::operator-(const Vector3 &v) {
    Vector3 vector = Vector3(*this);
    vector -= v;
    return vector;
}

Vector3 Vector3::operator*(const float &s) {
    Vector3 vector = Vector3(*this);
    vector *= s;
    return vector;
}

Vector3 Vector3::operator/(const float &s) {
    Vector3 vector = Vector3(*this);
    vector /= s;
    return vector;
}
#pragma endregion

#pragma region Basic math functions
void Vector3::add(Vector3 v) {
    this->operator+=(v);
}

void Vector3::sub(Vector3 v) {
    this->operator-=(v);
}

void Vector3::mul(float s) {
    this->operator*=(s);
}

void Vector3::div(float s) {
    this->operator/=(s);
}

#pragma endregion

float Vector3::length() const {
    return (float)sqrt(pow(this->x, 2) +
                       pow(this->y, 2) +
                       pow(this->z, 2));
}

void Vector3::normalize() {
    float n = this->length();
    if(n == 0) {
        printf("Can't divide by 0 [Normalize]\n");
        return;
    }

    this->div(n);
}

Vector3 Vector3::dot(Vector3& v1, Vector3& v2)
{
    Vector3 result;
    result.x = v1.x * v2.x;
    result.y = v1.y * v2.y;
    result.z = v1.z * v2.z;
    return result;
}

float Vector3::dotProduct(Vector3& v1, Vector3& v2)
{
    Vector3 result = dot(v1, v2);
    return result.x + result.y + result.z;
}

Vector3 Vector3::cross(Vector3& v1, Vector3& v2)
{
    return Vector3(v1.y * v2.z - v1.z * v2.y,
                  v1.z * v2.x - v1.x * v2.z,
                  v1.x * v2.y - v1.y * v2.x);
}

std::string Vector3::toString() {
    return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + "]";
}

float Vector3::calcAngle(Vector3& v1, Vector3& v2) {
    float angle = dotProduct(v1, v2);
    angle = std::acos(angle / (v1.length() * v2.length()));
    return angle;
}