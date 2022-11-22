//
// Created by szymo on 08/10/2022.
//

#include "Vector4.h"

Vector4::Vector4() : x(0), y(0), z(0), w(0) {
}

Vector4::Vector4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {

}

Vector4::Vector4(Vector4 p1, Vector4 p2) {
    x = p1.x - p2.x;
    y = p1.y - p2.y;
    z = p1.z - p2.z;
    w = p1.w - p2.w;
}

Vector4::Vector4(const Vector4 &v) {
    x = v.x;
    y = v.y;
    z = v.z;
    w = v.w;
}

Vector4::~Vector4() {
}

#pragma region Overloading operators
void Vector4::operator+=(const Vector4 &v) {
    x+=v.x;
    y+=v.y;
    z+=v.z;
    w+=v.w;
}

void Vector4::operator-=(const Vector4 &v) {
    x-=v.x;
    y-=v.y;
    z-=v.z;
    w-=v.w;
}

void Vector4::operator*=(const float &s) {
    this->x *= s;
    this->y *= s;
    this->z *= s;
    this->w *= w;
}

void Vector4::operator/=(const float &s) {
    if(s == 0)
    {
        printf("Can't divide by 0 [Div]");
        return;
    }

    this->x /= s;
    this->y /= s;
    this->z /= s;
    this->w /= s;
}

Vector4 Vector4::operator+(const Vector4 &v) {
    Vector4 vector = Vector4(*this);
    vector += v;
    return vector;
}

Vector4 Vector4::operator-(const Vector4 &v) {
    Vector4 vector = Vector4(*this);
    vector -= v;
    return vector;
}

Vector4 Vector4::operator*(const float &s) {
    Vector4 vector = Vector4(*this);
    vector *= s;
    return vector;
}

Vector4 Vector4::operator/(const float &s) {
    Vector4 vector = Vector4(*this);
    vector /= s;
    return vector;
}
#pragma endregion

#pragma region Basic math functions
void Vector4::add(Vector4 v) {
    this->operator+=(v);
}

void Vector4::sub(Vector4 v) {
    this->operator-=(v);
}

void Vector4::mul(float s) {
    this->operator*=(s);
}

void Vector4::div(float s) {
    this->operator/=(s);
}

#pragma endregion

float Vector4::length() {
    return (float)sqrt(pow(this->x, 2) +
                       pow(this->y, 2) +
                       pow(this->z, 2) +
                       pow(this->w, 2));
}

void Vector4::normalize() {
    float n = this->length();
    if(n == 0) {
        printf("Can't divide by 0 [Normalize]\n");
        return;
    }

    this->div(n);
}

Vector4 Vector4::dot(Vector4& v1, Vector4& v2)
{
    Vector4 result;
    result.x = v1.x * v2.x;
    result.y = v1.y * v2.y;
    result.z = v1.z * v2.z;
    result.w = v1.w * v2.w;
    return result;
}

float Vector4::dotProduct(Vector4& v1, Vector4& v2)
{
    Vector4 result = dot(v1, v2);
    return result.x + result.y + result.z + result.w;
}

Vector4 Vector4::cross(Vector4& v1, Vector4& v2)
{
    return Vector4(v1.y * v2.z - v1.z * v2.y,
                  v1.z * v2.x - v1.x * v2.z,
                  v1.x * v2.y - v1.y * v2.x,
                   1);
}

std::string Vector4::toString() {
    return "[" + std::to_string(x) + ", " + std::to_string(y) + ", " + std::to_string(z) + ", " + std::to_string(w) + "]";
}

float Vector4::calcAngle(Vector4& v1, Vector4& v2) {
    float angle = dotProduct(v1, v2);
    angle = acos(angle / (v1.length() * v2.length()));
    return angle;
}
