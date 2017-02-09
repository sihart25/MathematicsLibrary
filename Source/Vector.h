//------------------------------------------------------------------------------
//
// Module 08932 : Object-Oriented Software Engineering
// Mathematics Library Assessment
// Vector.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef Vector_h
#define Vector_h

//------------------------------------------------------------------------------
// include files

#include <iostream>
#pragma hdrstop

//------------------------------------------------------------------------------
// namespace

using namespace std;

//------------------------------------------------------------------------------
// namespace definition

namespace ObjectOriented {

    //------------------------------------------------------------------------------
    // forward declarations

    class Ray;
    class Matrix;

    //------------------------------------------------------------------------------
    // constants

    const double EPSILON = 1.0e-6;

    //------------------------------------------------------------------------------
    // class definition

    class Vector {

    public:

        //------------------------------------------------------------------------------
        // default constructor produces a position vector at the origin
        Vector(double x = 0.0, double y = 0.0, double z = 0.0, double w = 1.0) :
            _x(x), _y(y), _z(z), _w(w) {}

        //------------------------------------------------------------------------------
        // destructor
        ~Vector() {}

        double x() const {return _x;}
        double y() const {return _y;}
        double z() const {return _z;}
        double w() const {return _w;}

        void setX(double x) {_x = x;}
        void setY(double y) {_y = y;}
        void setZ(double z) {_z = z;}
        void setW(double w) {_w = w;}

        Vector(const Ray &ray1, const Ray &ray2);

        Vector &add(const Vector &v1, const Vector &v2);
        Vector &operator+=(const Vector &v);
        Vector operator+(const Vector &v) const;

        Vector &subtract(const Vector &v1, const Vector &v2);
        Vector &operator-=(const Vector &v);
        Vector operator-(const Vector &v) const;

        Vector &operator*=(double s);
        Vector operator*(double s) const;

        Vector &operator/=(double s);
        Vector operator/(double s) const;

        Vector cross(const Vector &v) const;
        double dot(const Vector &v) const;
        double distance(const Vector &v) const;
        double magnitude() const;

        Vector &normalize();
        Vector unit() const;

        Vector &negate();
        Vector operator-() const;

        Vector &preMultiply(const Matrix &m);

        friend Vector operator*(double s, const Vector &v);

        friend ostream &operator<<(ostream &out, const Vector &v);
        friend istream &operator>>(istream &in, Vector &v);

    private:

        void output(ostream &out) const;
        void input(istream &in);

        double _x;
        double _y;
        double _z;
        double _w;

    };

} // ObjectOriented

#endif // Vector_h

//------------------------------------------------------------------------------
