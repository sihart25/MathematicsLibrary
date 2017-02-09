//------------------------------------------------------------------------------
//
// Module 08932 : Object-Oriented Software Engineering
// Mathematics Library Assessment
// Mathematics.cpp
//
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
// include files

#include <iostream>
#include <sstream>
#include <string>
#include <iomanip>
#include <ctime>
#pragma hdrstop
#include "Vector.h"
#include "Ray.h"
#include "Matrix.h"

//------------------------------------------------------------------------------
// namespace

using namespace std;
using namespace ObjectOriented;

//------------------------------------------------------------------------------
// defines

#define TESTING

#ifdef TESTING

#define REPEATS 100000

#define PRINT(EXPRESSION) \
    start = clock(); \
    for (i = 0; i < REPEATS; ++i) { \
        EXPRESSION; \
    } \
    finish = clock(); \
    cout << left << setw(45) << #EXPRESSION << right << setw(5) \
         << (double)(finish - start) / CLOCKS_PER_SEC / REPEATS * 1.0e9 << " ns  " \
         << (EXPRESSION) << endl;

#endif // TESTING

//------------------------------------------------------------------------------
// main()

int main(int argc, char **argv) {

    #ifdef TESTING

    int i;
    clock_t start;
    clock_t finish;

    cout << "**** Test Vector constructors ****" << endl;
    Vector v1;
    Vector v2(1, 2, 3);
    Vector v3(4, 5, 6, 0);
    Vector v4(v3);
    Vector v5; v5 = v4;
    PRINT(v1);
    PRINT(v2);
    PRINT(v3);
    PRINT(v4);
    PRINT(v5);
    cout << endl;

    cout << "**** Test Vector input stream ****" << endl;
    istringstream vectorStream(string("(1,2,3,1)"));
    Vector vA;
    vectorStream >> vA;
    Vector vB(9, 8, 7, 1);
    Vector vC(vB);
    PRINT(vA);
    PRINT(vB);
    PRINT(vC);
    cout << endl;

    cout << "**** Test Vector arithmetic ****" << endl;
    PRINT(vC = vA);
    PRINT(vC.add(vA, vB));
    PRINT(vC.subtract(vA, vB));
    PRINT(vA + vB);
    PRINT(vA - vB);
    PRINT((vC = vA) += vB);
    PRINT((vC = vA) -= vB);
    PRINT(vA * 0.5);
    PRINT(0.5 * vA);
    PRINT(vA / 2.0);
    PRINT((vC = vA) *= 0.5);
    PRINT((vC = vA) /= 2.0);
    PRINT(vA.cross(vB));
    PRINT(vA.dot(vB));
    PRINT(vA.distance(vB));
    PRINT(vA.magnitude());
    PRINT(vA.unit());
    PRINT(-vA);
    PRINT((vC = vA).normalize());
    PRINT((vC = vA).negate());
    cout << endl;

    cout << "**** Test Ray constructors ****" << endl;
    Ray r1;
    Ray r2(v2, v3);
    Ray r3(r2);
    Ray r4; r4 = r3;
    PRINT(r1);
    PRINT(r2);
    PRINT(r3);
    PRINT(r4);
    cout << endl;

    cout << "**** Test Ray input stream ****" << endl;
    istringstream rayStream(string("((0,1,0,1),(1,0,0,0))"));
    Ray rA;
    rayStream >> rA;
    Ray rB(Vector(1, 0, 0.5, 1), Vector(1, 1, 0, 0));
    Ray rC(rB);
    PRINT(rA);
    PRINT(rB);
    PRINT(rC);
    cout << endl;

    cout << "**** Test Ray arithmetic ****" << endl;
    PRINT(rC = rA);
    PRINT(rA.distance(vB));
    PRINT(rA.distance(rB));
    PRINT(rA.intersection(rB));
    PRINT(Vector(rA, rB));
    PRINT(rA.unit());
    PRINT(-rA);
    PRINT((rC = rA).normalize());
    PRINT((rC = rA).negate());
    cout << endl;

    cout << "**** Test Matrix constructors ****" << endl;
    Matrix m1;
    Matrix m2(m1);
    Matrix m3; m3 = m2;
    PRINT(m1);
    PRINT(m2);
    PRINT(m3);
    cout << endl;

    cout << "**** Test Matrix input stream ****" << endl;
    istringstream matrixStream(string("((0,0,0,0),(1,1,1,1),(2,2,2,2),(0,0,0,1))"));
    Matrix mA;
    matrixStream >> mA;
    Matrix mB;
    PRINT(mA);
    PRINT(mB);
    cout << endl;

    cout << "**** Test Matrix arithmetic ****" << endl;
    PRINT(mB = mA);
    PRINT((vC = vA).preMultiply(mA));
    PRINT((rC = rA).preMultiply(mA));
    PRINT((mB = mA).preMultiply(mA));
    PRINT(mB.identity());
    PRINT(mB.identity().scale(Vector(1, 2, 3)));
    PRINT(mB.identity().rotateX(30));
    PRINT(mB.identity().rotateY(30));
    PRINT(mB.identity().rotateZ(30));
    PRINT(mB.identity().rotate(120, Vector(1, 1, 1)));
    PRINT(mB.identity().translate(Vector(1, 2, 3)));
    cout << endl;

    #endif // TESTING

    char ch; cout << "Press any key to continue" << endl; cin.get(ch);
    return 0;
}

//------------------------------------------------------------------------------
