//------------------------------------------------------------------------------
//
// Module 08932 : Object-Oriented Software Engineering
// Mathematics Library Assessment
// Matrix.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef Matrix_h
#define Matrix_h

//------------------------------------------------------------------------------
// include files

#include <iostream>
#include <cmath>
#pragma hdrstop

//------------------------------------------------------------------------------
// namespace

using namespace std;

//------------------------------------------------------------------------------
// namespace definition

namespace ObjectOriented {

    //------------------------------------------------------------------------------
    // forward declarations

    class Vector;
    class Ray;

    //------------------------------------------------------------------------------
    // constants

    const int X = 0;
    const int Y = 1;
    const int Z = 2;
    const int W = 3;

    const int DIM = 4;

    const double PI = acos(0.0);

    //------------------------------------------------------------------------------
    // class definition

    class Matrix {

    public:

        //------------------------------------------------------------------------------
        // default constructor constructs an identity matrix
        Matrix() {
            for (int i = 0; i < DIM; ++i) {
                for (int j = 0; j < DIM; ++j) {
                    _m[i][j] = 0.0;
                }
            }
            for (int k = 0; k < DIM; ++k) {
                _m[k][k] = 1.0;
            }
        }

        //------------------------------------------------------------------------------
        // destructor
        ~Matrix() {}

        friend Vector &Vector::preMultiply(const Matrix &m);
        friend Ray &Ray::preMultiply(const Matrix &m);

        Matrix &preMultiply(const Matrix &m);
        Matrix &identity();
        Matrix &scale(const Vector &v);
        Matrix &rotateX(double angle);
        Matrix &rotateY(double angle);
        Matrix &rotateZ(double angle);
        Matrix &rotate(double angle, const Vector &v);
        Matrix &translate(const Vector &v);

        friend ostream &operator<<(ostream &out, const Matrix &m);
        friend istream &operator>>(istream &in, Matrix &m);

    private:

        void output(ostream &out) const;
        void input(istream &in);

        double _m[DIM][DIM];

        //------------------------------------------------------------------------------
        // nested class definition

        class Angle {

        public:

            Angle(double deg = 0.0) {
                _rad = deg * PI / 90.0;
                _c = cos(_rad);
                _s = sin(_rad);
            }
            ~Angle() {}

            double c() {return _c;}
            double s() {return _s;}

        private:

            double _rad;
            double _c;
            double _s;

        };

    };

} // ObjectOriented

#endif // Matrix_h

//------------------------------------------------------------------------------
