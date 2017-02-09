//------------------------------------------------------------------------------
//
// Module 08932 : Object-Oriented Software Engineering
// Mathematics Library Assessment
// Ray.cpp
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
// distance from this ray to a point
double Ray::distance(const Vector &vector) const {
    return (vector - pos()).cross(dir()).magnitude();
}

//------------------------------------------------------------------------------
// distance from this ray to another ray
double Ray::distance(const Ray &ray) const {
    // determine the perpendicular to and angle between this ray and another ray
    Vector perp(dir().cross(ray.dir()));
    double sine = perp.magnitude();
    if (sine <= EPSILON) { // near parallel rays
        return (ray.pos() - pos()).cross(dir()).magnitude();
    }
    else {
        return fabs((ray.pos() - pos()).dot(perp /= sine));
    }
}

//------------------------------------------------------------------------------
// intersection of this ray with another ray
Vector Ray::intersection(const Ray &ray) const {
    // determine the perpendicular to and angle between this ray and another ray
    Vector perp(dir().cross(ray.dir()));
    double sine = perp.magnitude();
    if (sine <= EPSILON) { // near parallel rays
        return pos() + 0.5 * (ray.pos() - pos());
    }
    else {
        // determine the ray coplanar to this ray and parallel to another ray
        double length = (ray.pos() - pos()).dot(perp /= sine);
        Ray coplanar(ray.pos() - length * perp, ray.dir());
        // project to determine the intersection of this ray and the coplanar ray
        Vector project = (coplanar.pos() - pos()).cross(dir()).cross(dir());
        double lenA = (coplanar.pos() - pos()).dot(project);
        double lenB = (coplanar.pos() + coplanar.dir() - pos()).dot(project);
        return coplanar.pos() + lenA / (lenA - lenB) * coplanar.dir() + 0.5 * length * perp;
    }
}

//------------------------------------------------------------------------------
// normalize this ray
Ray &Ray::normalize() {
    _dir.normalize();
    return *this;
}

//------------------------------------------------------------------------------
// unit vector of this ray
Ray Ray::unit() const {
    return Ray(pos(), dir().unit());
}

//------------------------------------------------------------------------------
// negate this ray
Ray &Ray::negate() {
    _dir.negate();
    return *this;
}

//------------------------------------------------------------------------------
// negative - operator
Ray Ray::operator-() const {
    return Ray(pos(), -dir());
}

//------------------------------------------------------------------------------
// pre-multiply this ray by a matrix
Ray &Ray::preMultiply(const Matrix &m) {
    _pos.preMultiply(m);
    _dir.preMultiply(m);
    normalize();
    return *this;
}

//------------------------------------------------------------------------------
// stream out from this ray
void Ray::output(ostream &out) const {
    out << "(" << pos() << "," << dir() << ")";
}

//------------------------------------------------------------------------------
// stream in to this ray
void Ray::input(istream &in) {
    char parenthesis, comma;
    in >> parenthesis >> _pos >> comma >> _dir >> parenthesis;
    normalize();
}

//------------------------------------------------------------------------------
// namespace definition
namespace ObjectOriented {

    //------------------------------------------------------------------------------
    // stream out << operator
    ostream &operator<<(ostream &out, const Ray &ray) {
        ray.output(out);
        return out;
    }

    //------------------------------------------------------------------------------
    // stream in >> operator
    istream &operator>>(istream &in, Ray &ray) {
        ray.input(in);
        return in;
    }

} // ObjectOriented

//------------------------------------------------------------------------------
