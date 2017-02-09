//------------------------------------------------------------------------------
//
// Module 08932 : Object-Oriented Software Engineering
// Mathematics Library Assessment
// Matrix.cpp
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
// pre-multiply this matrix by another matrix
Matrix &Matrix::preMultiply(const Matrix &m) {
    Matrix product;
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            product._m[i][j] = m._m[i][X] * _m[X][j] + m._m[i][Y] * _m[Y][j]
                             + m._m[i][Z] * _m[Z][j] + m._m[i][W] * _m[W][j];
        }
    }
    return *this = product;
}

//------------------------------------------------------------------------------
// set this matrix to the identity matrix
Matrix &Matrix::identity() {
    for (int i = 0; i < DIM; ++i) {
        for (int j = 0; j < DIM; ++j) {
            _m[i][j] = 0.0;
        }
    }
    for (int k = 0; k < DIM; ++k) {
        _m[k][k] = 1.0;
    }
    return *this;
}

//------------------------------------------------------------------------------
// scale this matrix
Matrix &Matrix::scale(const Vector &v) {
    Matrix m;
    m._m[X][X] = v.x();
    m._m[Y][Y] = v.y();
    m._m[Z][Z] = v.z();
    return preMultiply(m);
}

//------------------------------------------------------------------------------
// rotate this matrix about x-axis
Matrix &Matrix::rotateX(double angle) {
    Matrix m;
    Angle a(angle);
    m._m[Y][Y] = a.c();
    m._m[Y][Z] = -a.s();
    m._m[Z][Y] = a.s();
    m._m[Z][Z] = a.c();
    return preMultiply(m);
}

//------------------------------------------------------------------------------
// rotate this matrix about y-axis
Matrix &Matrix::rotateY(double angle) {
    Matrix m;
    Angle a(angle);
    m._m[Z][Z] = a.c();
    m._m[Z][X] = -a.s();
    m._m[X][Z] = a.s();
    m._m[X][X] = a.c();
    return preMultiply(m);
}

//------------------------------------------------------------------------------
// rotate this matrix about z-axis
Matrix &Matrix::rotateZ(double angle) {
    Matrix m;
    Angle a(angle);
    m._m[X][X] = a.c();
    m._m[X][Y] = -a.s();
    m._m[Y][X] = a.s();
    m._m[Y][Y] = a.c();
    return preMultiply(m);
}

//------------------------------------------------------------------------------
// rotate this matrix about an axis
Matrix &Matrix::rotate(double angle, const Vector &v) {
    Matrix m;
    Angle a(angle);
    Vector u = v.unit();
    m._m[X][X] = a.c() + (1.0 - a.c()) * u.x() * u.x();
    m._m[X][Y] = (1.0 - a.c()) * u.y() * u.x() - a.s() * u.z();
    m._m[X][Z] = (1.0 - a.c()) * u.z() * u.x() + a.s() * u.y();
    m._m[Y][X] = (1.0 - a.c()) * u.x() * u.y() + a.s() * u.z();
    m._m[Y][Y] = a.c() + (1.0 - a.c()) * u.y() * u.y();
    m._m[Y][Z] = (1.0 - a.c()) * u.z() * u.y() - a.s() * u.x();
    m._m[Z][X] = (1.0 - a.c()) * u.x() * u.z() - a.s() * u.y();
    m._m[Z][Y] = (1.0 - a.c()) * u.y() * u.z() + a.s() * u.x();
    m._m[Z][Z] = a.c() + (1.0 - a.c()) * u.z() * u.z();
    return preMultiply(m);
}

//------------------------------------------------------------------------------
// translate this matrix
Matrix &Matrix::translate(const Vector &v) {
    Matrix m;
    m._m[X][W] = v.x();
    m._m[Y][W] = v.y();
    m._m[Z][W] = v.z();
    return preMultiply(m);
}

//------------------------------------------------------------------------------
// stream out from this matrix
void Matrix::output(ostream &out) const {
    for (int i = 0; i < DIM; ++i) {
        out << (i == 0 ? "(" : "") << "(";
        for (int j = 0; j < DIM; ++j) {
            out << _m[i][j] << (j < DIM - 1 ? "," : ")");
        }
        out << (i < DIM - 1 ? "," : ")");
    }
}

//------------------------------------------------------------------------------
// stream in to this matrix
void Matrix::input(istream &in) {
    char separator;
    for (int i = 0; i < DIM; ++i) {
        if (i == 0) {
            in >> separator;
        }
        in >> separator;
        for (int j = 0; j < DIM; ++j) {
            in >> _m[i][j] >> separator;
        }
        in >> separator;
    }
}

//------------------------------------------------------------------------------
// namespace definition
namespace ObjectOriented {

    //------------------------------------------------------------------------------
    // stream out << operator
    ostream &operator<<(ostream &out, const Matrix &m) {
        m.output(out);
        return out;
    }

    //------------------------------------------------------------------------------
    // stream in >> operator
    istream &operator>>(istream &in, Matrix &m) {
        m.input(in);
        return in;
    }

} // ObjectOriented

//------------------------------------------------------------------------------
