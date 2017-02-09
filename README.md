# MathematicsLibrary
The aim of this assessment was to create a set of classes that would form the basis of a mathematics library to be used in the ray caster and ray tracer assessments. The design was to be object-oriented and the program was to be written in C++. The code was to be efficient, well structured, commented and maintainable. The design was to include a Vector class to encapsulate the behaviour of a three-dimensional point or vector, and a Ray class to encapsulate the behaviour of an infinite three-dimensional line or ray. Both classes were to provide constructors, selectors, input and output streaming, and various mathematical operators and functions. The Vector class was to include mathematical operators and functions for addition, subtraction, scalar multiplication, negation, cross product, dot product, magnitude, normalise, and the distance between two points. The Ray class was to include the mathematical operators and functions for negation, the distance between a point and a line, the distance between two lines, and the intersection between two rays. This intersection could also be used to construct a Vector object. If possible, the design was to include a Matrix class to encapsulate the behaviour of a three-dimensional transformation, which could be applied to either a Vector or Ray object.
 
#Program description
The library has been implemented as the Vector, Ray and Matrix classes, with public methods for all the required methods and functions. In addition, methods have been provided for scalar division of a vector, multiplication of a vector by a matrix, and multiplication of a ray by a matrix.
The Matrix class provides public methods for multiplication of a matrix by a matrix, setting a matrix to identity, and adding transformations to a matrix. The transformations provided are scaling, rotation about any principal or arbitrary axis, and translation. The private nested class of Angle provides conversion from degrees to radians, and determines the cosine and sine of an angle.
Some test code to observe and time the class methods is provided, and can be enabled as required.
The intersection of two lines uses an algorithm suggested in a tutorial from the University of Regensburg, and the equations for rotation about an arbitrary axis are taken from the second edition of F.S.Hill, Jr.�s book �Computer Graphics Using OpenGL�.

#Further work
Further optimisation of the code for efficiency 
is required. There have been problems using the inline specifier in Microsoft Visual C++ 6.0, and this will require further investigation. The Matrix class could be extended to provide determinant, transpose and inverse functions, and shear and view projection transformations. For efficiency, a more specialized version of the Matrix class that assumed affine transformations could be implemented, and the Ray class could be modified to only normalize vectors when absolutely necessary.

#Conclusions
The assessment has been completed successfully. It has demonstrated the use of a set of classes to implement mathematical functions for Vector, Ray and Matrix classes. A debugger was used to check the code functionality, and test code was provided to observe and time the results from each method. After optimising some of the methods, vector addition could be performed in 30ns, matrix multiplication in 660ns, and ray intersection in 1540ns, using Microsoft Visual C++ 6.0, Windows 98 and an Athlon 700.