//------------------------------------------------------------------------------
//
// Module 08932 : Object-Oriented Software Engineering
// Mathematics Library Assessment
// Vector.cpp
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include files

#include <iostream>
#include <cmath>
#pragma hdrstop
#include "Vector.h"
#include "Ray.h"
#include "Matrix.h"

//------------------------------------------------------------------------------
// namespace

using namespace std;
using namespace ObjectOriented;

//------------------------------------------------------------------------------
// constructor from the intersection of two rays
Vector::Vector(const Ray &ray1, const Ray &ray2) {
    *this = ray1.intersection(ray2);
}

//------------------------------------------------------------------------------
// add two vectors and copy into this vector
Vector &Vector::add(const Vector &v1, const Vector &v2) {
    _x = v1.x() + v2.x();
    _y = v1.y() + v2.y();
    _z = v1.z() + v2.z();
    _w = v1.w() + v2.w();
    return *this;
}

//------------------------------------------------------------------------------
// add operator+=
Vector &Vector::operator+=(const Vector &v) {
    _x += v.x();
    _y += v.y();
    _z += v.z();
    _w += v.w();
    return *this;
}

//------------------------------------------------------------------------------
// add operator+
Vector Vector::operator+(const Vector &v) const {
    double vx = x() + v.x();
    double vy = y() + v.y();
    double vz = z() + v.z();
    double vw = w() + v.w();
    return Vector(vx, vy, vz, vw);
}

//------------------------------------------------------------------------------
// subtract two vectors and copy into this vector
Vector &Vector::subtract(const Vector &v1, const Vector &v2) {
    _x = v1.x() - v2.x();
    _y = v1.y() - v2.y();
    _z = v1.z() - v2.z();
    _w = v1.w() - v2.w();
    return *this;
}

//------------------------------------------------------------------------------
// subtract operator-=
Vector &Vector::operator-=(const Vector &v) {
    _x -= v.x();
    _y -= v.y();
    _z -= v.z();
    _w -= v.w();
    return *this;
}

//------------------------------------------------------------------------------
// subtract operator-
Vector Vector::operator-(const Vector &v) const {
    double vx = x() - v.x();
    double vy = y() - v.y();
    double vz = z() - v.z();
    double vw = w() - v.w();
    return Vector(vx, vy, vz, vw);
}

//------------------------------------------------------------------------------
// scalar multiply operator*=
Vector &Vector::operator*=(double s) {
    _x *= s;
    _y *= s;
    _z *= s;
    return *this;
}

//------------------------------------------------------------------------------
// scalar multiply operator*
Vector Vector::operator*(double s) const {
    double vx = x() * s;
    double vy = y() * s;
    double vz = z() * s;
    double vw = w();
    return Vector(vx, vy, vz, vw);
}

//------------------------------------------------------------------------------
// scalar divide operator/=
Vector &Vector::operator/=(double s) {
    double rs = (fabs(s) < EPSILON) ? 0.0 : 1.0 / s;
    _x *= rs;
    _y *= rs;
    _z *= rs;
    return *this;
}

//------------------------------------------------------------------------------
// scalar divide operator/
Vector Vector::operator/(double s) const {
    double rs = (fabs(s) < EPSILON) ? 0.0 : 1.0 / s;
    double vx = x() * rs;
    double vy = y() * rs;
    double vz = z() * rs;
    double vw = w();
    return Vector(vx, vy, vz, vw);
}

//------------------------------------------------------------------------------
// cross product between this vector and another vector
Vector Vector::cross(const Vector &v) const {
    double vx = y() * v.z() - z() * v.y();
    double vy = z() * v.x() - x() * v.z();
    double vz = x() * v.y() - y() * v.x();
    double vw = 0.0;
    return Vector(vx, vy, vz, vw);
}

//------------------------------------------------------------------------------
// dot product between this vector and another vector
double Vector::dot(const Vector &v) const {
    return x() * v.x() + y() * v.y() + z() * v.z();
}

//------------------------------------------------------------------------------
// distance from this vector to another vector
double Vector::distance(const Vector &v) const {
    return (v - *this).magnitude();
}

//------------------------------------------------------------------------------
// magnitude of this vector
double Vector::magnitude() const {
    return sqrt(dot(*this));
}

//------------------------------------------------------------------------------
// normalize this vector
Vector &Vector::normalize() {
    return *this /= magnitude();
}

//------------------------------------------------------------------------------
// unit vector of this vector
Vector Vector::unit() const {
    return *this / magnitude();
}

//------------------------------------------------------------------------------
// negate this vector
Vector &Vector::negate() {
    _x = -x();
    _y = -y();
    _z = -z();
    return *this;
}

//------------------------------------------------------------------------------
// negative operator-
Vector Vector::operator-() const {
    double vx = -x();
    double vy = -y();
    double vz = -z();
    double vw = w();
    return Vector(vx, vy, vz, vw);
}

//------------------------------------------------------------------------------
// pre-multiply this vector by a matrix
Vector &Vector::preMultiply(const Matrix &m) {
    Vector v(*this);
    _x = m._m[X][X] * v._x + m._m[X][Y] * v._y + m._m[X][Z] * v._z + m._m[X][W] * v._w;
    _y = m._m[Y][X] * v._x + m._m[Y][Y] * v._y + m._m[Y][Z] * v._z + m._m[Y][W] * v._w;
    _z = m._m[Z][X] * v._x + m._m[Z][Y] * v._y + m._m[Z][Z] * v._z + m._m[Z][W] * v._w;
    _w = m._m[W][X] * v._x + m._m[W][Y] * v._y + m._m[W][Z] * v._z + m._m[W][W] * v._w;
    return *this;
}

//------------------------------------------------------------------------------
// stream out from this vector
void Vector::output(ostream &out) const {
    out << "(" << x() << "," << y() << "," << z() << "," << w() << ")";
}

//------------------------------------------------------------------------------
// stream in to this vector
void Vector::input(istream &in) {
    char parenthesis, comma;
    in >> parenthesis >> _x >> comma >> _y >> comma >> _z >> comma >> _w >> parenthesis;
}

//------------------------------------------------------------------------------
// namespace definition
namespace ObjectOriented {

    //------------------------------------------------------------------------------
    // scalar multiply operator*
    Vector operator*(double s, const Vector &v) {
        double vx = s * v.x();
        double vy = s * v.y();
        double vz = s * v.z();
        double vw = v.w();
        return Vector(vx, vy, vz, vw);
    }

    //------------------------------------------------------------------------------
    // stream out operator<<
    ostream &operator<<(ostream &out, const Vector &v) {
        v.output(out);
        return out;
    }

    //------------------------------------------------------------------------------
    // stream in operator>>
    istream &operator>>(istream &in, Vector &v) {
        v.input(in);
        return in;
    }

} // ObjectOriented

//------------------------------------------------------------------------------
