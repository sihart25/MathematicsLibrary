//------------------------------------------------------------------------------
//
// Module 08932 : Object-Oriented Software Engineering
// Mathematics Library Assessment
// Ray.h
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include guard

#ifndef Ray_h
#define Ray_h

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

    class Vector;
    class Matrix;

    //------------------------------------------------------------------------------
    // class definition

    class Ray {

    public:

        //------------------------------------------------------------------------------
        // default constructor produces a ray at the origin and along the negative z-axis
        Ray(const Vector &pos = Vector(0.0, 0.0, 0.0, 1.0),
            const Vector &dir = Vector(0.0, 0.0, -1.0, 0.0)) :
            _pos(pos), _dir(dir) {
            normalize();
        }

        //------------------------------------------------------------------------------
        // destructor
        ~Ray() {}

        const Vector &pos() const {return _pos;}
        const Vector &dir() const {return _dir;}

        void setPos(const Vector &pos) {_pos = pos;}
        void setDir(const Vector &dir) {_dir = dir;}

        double distance(const Vector &vector) const;
        double distance(const Ray &ray) const;
        Vector intersection(const Ray &ray) const;

        Ray &normalize();
        Ray unit() const;

        Ray &negate();
        Ray operator-() const;

        Ray &preMultiply(const Matrix &m);

        friend ostream &operator<<(ostream &out, const Ray &ray);
        friend istream &operator>>(istream &in, Ray &ray);

    private:

        void output(ostream &out) const;
        void input(istream &in);

        Vector _pos;
        Vector _dir;

    };

} // ObjectOriented

#endif // Ray_h

//------------------------------------------------------------------------------
