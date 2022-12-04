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
    Quaternion invQuat = quat.Inverse();

    Quaternion pureQuat(0, inputVector);
    pureQuat = quat * pureQuat * invQuat;

    return pureQuat.vector;
}

std::string Quaternion::ToString() {
    return "(" + std::to_string(scalar) + ", " + vector.toString() + ")";
}

float Quaternion::Pow(float a) { return a * a; }