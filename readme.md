# ** 2D PLANE GEOMETRY Library **

## ** Project Description **
This is a User-Defined Library, designed to implement mathematical concepts of plane geometry and other properties using our knowledge of **struct** and **modular programming** in C++.

## ** Structure and Functions **

### ** Basic Data Structures **
``` cpp
struct Point2f { float x, y; };
struct Vector2f { float x, y; };
```

### ** Functions for 2D Points Manipulation **
``` cpp
Point2f MakeP2f(float x, float y);// Creating a point from it's coordinates
Point2f MakeNullPoint();// Creating a null point (origin)
Point2f Translate(const Point2f& p, float dx, float dy);// Translating given coordinates
Point2f Translate(const Point2f& p, const Vector2f& v);// Translating using a vector
Point2f Scale(const Point2f& p, float sx, float sy);// Scaling using coordinates
Point2f Scale(const Point2f& p, const Vector2f& s);// Scaling using a vector
Point2f Rotate(const Point2f& p, float angleDegree);// Rotating through an angle
```

### ** Functions for 2D Vectors Manipulation **
```cpp
Vector2f MakeV2f(float x, float y);// Creating a vector given coordinates
Vector2f MakeV2f(const Point2f& a, const Point2f& b);// Creating a vector using 2 points
Vector2f MakeNullVector();// Creating a null vector (origin)
Vector2f Add(const Vector2f& a, const Vector2f& b);// Vector addition
Vector2f Sub(const Vector2f& a, const Vector2f& b);// Vector substraction
Vector2f Scale(const Vector2f& v, float scalar);// Scaling a vector using a scale factor
float Dot(const Vector2f& a, const Vector2f& b);// Dot product 
float Length(const Vector2f& v);// Magnitude
Vector2f Normalize(const Vector2f& v);// Vector Normalization(unit vector)
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);// Linear Interpolation
float Determinant(const Vector2f& a, const Vector2f& b);// Determinant of 2 vectors
```
## ** Project Files **

### ** Header Files **

#### ** geometry/point.h **
This Header File contains all the functions listed above for 2D points manipulation.

#### ** geometry/vector.h **
This Header File contains all the functions listed above for 2D vectors manipulation.

#### ** geometry/utils.h **
This Header File contains functions needed to convert our user-defined structures **Point2f** and **Vector2f** in to strings; **ToString()** and output them; **Print()**

### ** CPP Files **

#### ** geometry/point.cpp **
This .cpp file has the definitions or implementations of all the functions declared in **point.h**

#### ** geometry/vector.cpp **
This .cpp file has the definitions or implementations of all the functions declared in **vector.h**

#### ** main.cpp **
This is our main file where all the functions above are been called and tested.

## ** Conclusion **
I give special thanks to myself, friends and most-especially my teacher to whom this project couldn't have been possible 😁😁😁✌️✌️✌️.