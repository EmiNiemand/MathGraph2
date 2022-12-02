//
// Created by masterktos on 22.11.22.
//

#include "Quaternion.h"

#include <cmath>


Quaternion::Quaternion() : vector(Vector3(0, 0, 0)), scalar(0) {
}

Quaternion::Quaternion(float scalar, Vector3 vector) : vector(vector), scalar(scalar) {
}

Quaternion::Quaternion(const Quaternion &q) {
    vector = Vector3(q.vector);
    scalar = q.scalar;
}

void Quaternion::operator+=(Quaternion other) {
    scalar += other.scalar;
    vector += other.vector;
}

void Quaternion::operator-=(Quaternion other) {
    scalar -= other.scalar;
    vector -= other.vector;
}

void Quaternion::operator*=(Quaternion other) {
    float newScalar = scalar * other.scalar - Vector3::dotProduct(vector, other.vector);

    vector = other.vector * scalar + vector * other.scalar + Vector3::cross(vector, other.vector);
    scalar = newScalar;
}

void Quaternion::operator/=(Quaternion other) {
    float divider = Pow(other.scalar) + Vector3::dotProduct(other.vector, other.vector);
    if(divider == 0) {
        printf("Cannot divide by 0 [div]\n");
        return;
    }

    float newScalar = scalar * other.scalar + Vector3::dotProduct(vector, other.vector);
    newScalar /= divider;

    Vector3 newVector = other.vector * -scalar + vector * other.scalar - Vector3::cross(vector, other.vector);
    newVector /= divider;

    scalar = newScalar;
    vector = newVector;

    //float divider = Pow(other.scalar) + Pow(other.vector.x) + Pow(other.vector.y) + Pow(other.vector.z);
    //auto t0 = other.scalar * scalar + other.vector.x * vector.x +
    //                other.vector.y * vector.y + other.vector.z * vector.z;
    //t0 /= divider;
    //auto t1 = other.scalar * vector.x - other.vector.x * scalar -
    //          other.vector.y * vector.z + other.vector.z * vector.y;
    //t1 /= divider;
    //auto t2 = other.scalar * vector.y + other.vector.x * vector.z -
    //          other.vector.y * scalar - other.vector.z * vector.x;
    //t2 /= divider;
    //auto t3 = other.scalar * vector.z - other.vector.x * vector.y +
    //          other.vector.y * vector.x - other.vector.z * scalar;
    //t3 /= divider;
    //
    //scalar = t0;
    //vector = Vector3(t1, t2, t3);
}

Quaternion Quaternion::operator+(Quaternion other) {
    Quaternion quat = Quaternion(*this);
    quat += other;
    return quat;
}

Quaternion Quaternion::operator-(Quaternion other) {
    Quaternion quat = Quaternion(*this);
    quat -= other;
    return quat;
}

Quaternion Quaternion::operator*(Quaternion other) {
    Quaternion quat = Quaternion(*this);
    quat *= other;
    return quat;
}

Quaternion Quaternion::operator/(Quaternion other) {
    Quaternion quat = Quaternion(*this);
    quat /= other;
    return quat;
}

Vector3 Quaternion::GetVector() { return vector; }
float Quaternion::GetScalar() const { return scalar; }

Quaternion Quaternion::Inverse() {
    return Quaternion(scalar, vector * -1);
}

Vector3 Quaternion::RotateVector(const Vector3& inputVector, float angle) {

    float newScalar = std::cos(angle/360 * M_PI);
    Vector3 newVector = vector/std::sqrt(Pow(vector.x) + Pow(vector.y) + Pow(vector.z));
    newVector *= std::sin(angle/360 * M_PI);

    Quaternion quat(newScalar, newVector);
    Quaternion invQuat = Inverse();

    Quaternion pureQuat(0, inputVector);
    pureQuat = quat * pureQuat * invQuat;

    return pureQuat.vector;
}

std::string Quaternion::ToString() {
    return "(" + std::to_string(scalar) + ", " + vector.toString() + ")";
}

float Quaternion::Pow(float a) { return a * a; }