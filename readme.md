# ** 2D PLANE GEOMETRY Library **

## ** Project Description **
This is a User-Defined Library, designed to implement mathematical concepts of plane geometry and other properties using our knowledge of **struct** and **modular programming** in C++.

## ** Structure and Functions **

### ** Basic Data Structures **
``` cpp
struct Point2f { float x, y; }; // Used to represent a 2D point
struct Vector2f { float x, y; }; // Represents a 2D vector 
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
``` cpp
#ifndef POINT_H
#define POINT_H

#include <string>
#include <cmath>
#include "vector.h"

struct Vector2f;
struct Point2f {
    float x;
    float y;
};

/* Creation of points */
Point2f MakeP2f(float x, float y);
Point2f MakeNullPoint();

/* Some operations on points */
Point2f Translate(const Point2f& p, float dx, float dy);
Point2f Translate(const Point2f& p, const Vector2f& v);
Point2f Scale(const Point2f& p, float sx, float sy);
Point2f Scale(const Point2f& p, const Vector2f& s);
Point2f Rotate(const Point2f& p, float angleDegree);

/*  Converts a point into a string of form (x, y) */
std::string ToString(const Point2f& p);

#endif
```
#### ** geometry/vector.h **
This Header File contains all the functions listed above for 2D vectors manipulation.
```cpp
#ifndef VECTOR_H
#define VECTOR_H

#include <string>
#include <cmath>
#include "point.h"

struct Point2f;
struct Vector2f {
    float x;
    float y;
}; 

/* Creation of vectors */
Vector2f MakeV2f(float x, float y);
Vector2f MakeV2f(const Point2f& a, const Point2f& b);
Vector2f MakeNullVector();

/* Vector Operations and Properties */
Vector2f Add(const Vector2f& a, const Vector2f& b);
Vector2f Sub(const Vector2f& a, const Vector2f& b);
Vector2f Scale(const Vector2f& v, float scalar);
float Dot(const Vector2f& a, const Vector2f& b);
float Length(const Vector2f& v);

/* Advanced Vector Operations */
Vector2f Normalize(const Vector2f& v);
Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t);
float Determinant(const Vector2f& a, const Vector2f& b);

/* Converts any vector into a string of form {x, y} */
std::string ToString(const Vector2f& v);

#endif
```

#### ** geometry/utils.h **
This Header File contains functions needed to convert our user-defined structures **Point2f** and **Vector2f** in to strings; **ToString()** and output them; **Print()**
```cpp
#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>

// Templates ToString et Print
template<typename T>
std::string ToString(const T& value) {
    std::ostringstream oss;
    oss << value;
    return oss.str();
}

template<typename T>
std::string ToString(const std::vector<T>& v) {
    std::ostringstream oss;
    oss << "[";
    for (size_t i = 0; i < v.size(); ++i) {
        oss << ToString(v[i]);
        if (i + 1 < v.size()) oss << ", ";
    }
    oss << "]";
    return oss.str();
}

template<typename K, typename V>
std::string ToString(const std::map<K, V>& m) {
    std::ostringstream oss;
    oss << "{";
    for (auto it = m.begin(); it != m.end(); ++it) {
        oss << ToString(it->first) << ": " << ToString(it->second);
        if (std::next(it) != m.end()) oss << ", ";
    }
    oss << "}";
    return oss.str();
}

/* Prints n-arguments */
template<typename T, typename... Args>
void Print(const T& first, const Args&... args) {
    std::cout << ToString(first);
    ((std::cout << ToString(args)), ...);
    std::cout << std::endl;
}

#endif
```

### ** CPP Files **

#### ** geometry/point.cpp **
This .cpp file has the definitions or implementations of all the functions declared in **point.h**
```cpp
#include "point.h"
#include "utils.h"

Point2f MakeP2f(float x, float y)
{
    Point2f p = {x, y};
    return p;
}

Point2f MakeNullPoint()
{
    Point2f __nul = {0, 0};
    return __nul;
}

Point2f Translate(const Point2f& p, float dx, float dy)
{
    Point2f T;
    T.x = p.x + dx;
    T.y = p.y + dy;
    return T;
}

Point2f Translate(const Point2f& p, const Vector2f& v)
{
    Point2f T;
    T.x = p.x + v.x;
    T.y = p.y + v.y;
    return T;
}

Point2f Scale(const Point2f& p, float sx, float sy)
{
    Point2f sP;
    sP.x = p.x * sx;
    sP.y = p.y * sy;
    return sP;
}

Point2f Scale(const Point2f& p, const Vector2f& s)
{
    Point2f sP;
    sP.x = p.x * s.x;
    sP.y = p.y * s.y;
    return sP;
}

Point2f Rotate(const Point2f& p, float angleDegree)
{
    Point2f rP;
    const double pi = 3.141592654;
    float angleRadian = pi * (angleDegree / 180);
    rP.x = (p.x * cos(angleRadian)) - (p.y * sin(angleRadian));
    rP.y = (p.x * sin(angleRadian)) + (p.y * cos(angleRadian));
    return rP;
}

std::string ToString(const Point2f& p) 
{
    std::ostringstream oss;
    oss << "(" << p.x << ", " << p.y << ")";
    return oss.str();
}
```

#### ** geometry/vector.cpp **
This .cpp file has the definitions or implementations of all the functions declared in **vector.h**
```cpp
#include "vector.h"
#include "utils.h"

Vector2f MakeV2f(float x, float y)
{
    Vector2f v = {x, y};
    return v;
}

Vector2f MakeV2f(const Point2f& a, const Point2f& b)
{
    Vector2f v;
    v.x = b.x - a.x;
    v.y = b.y - a.y;
    return v;
}

Vector2f MakeNullVector()
{
    Vector2f __nul = {0, 0};
    return __nul;
}

Vector2f Add(const Vector2f& a, const Vector2f& b)
{
    Vector2f v;
    v.x = a.x + b.x;
    v.y = a.y + b.y;
    return v;
}

Vector2f Sub(const Vector2f& a, const Vector2f& b)
{
    Vector2f u;
    u.x = a.x - b.x;
    u.y = a.y - b.y;
    return u;
}

Vector2f Scale(const Vector2f& v, float scalar)
{
    Vector2f u;
    u.x = v.x * scalar;
    u.y = v.y * scalar;
    return u;
}

float Dot(const Vector2f& a, const Vector2f& b)
{
    float d;
    d = (a.x * b.x) + (a.y * b.y);
    return d;
}

float Length(const Vector2f& v)
{
    float l;
    l = sqrt((v.x * v.x) + (v.y * v.y));
    return l;
}

Vector2f Normalize(const Vector2f& v)
{
    Vector2f u;
    float L = Length(v);  
    if (L == 0) return v;
    u.x = (v.x / L);
    u.y = (v.y / L);
    return u;
}

Vector2f Lerp(const Vector2f& a, const Vector2f& b, float t)
{
    Vector2f L;
    L.x = a.x + t * (b.x - a.x);
    L.y = a.y + t * (b.y - a.y);
    return L;
}

float Determinant(const Vector2f& a, const Vector2f& b)
{
    float det;
    det = (a.x * b.y) - (a.y * b.x);
    return det;
}

std::string ToString(const Vector2f& v)
{
    std::ostringstream oss;
    oss << "{" << v.x << ", " << v.y << "}";
    return oss.str();
}
```

#### ** main.cpp **
This is our main file where all the functions above are been called and tested.
``` cpp
#include "geometry/point.h"
#include "geometry/vector.h"
#include "geometry/utils.h"

int main() {
    Print("\n\t ========== GÉOMÉTRIE D'UN PLAN 2D (PLANE GEOMETRY) ========== \n\n");

    // =========== Test Points ===========
    Print(" ====== Test Points ====== \n");

    // 1. Création d'un point nul
    Point2f p = MakeNullPoint();
    Print(" Null Point: ", ToString(p));

    // 2. Création d'un point à partir des 2 coordonnées
    Point2f p1 = MakeP2f(2.0f, 3.0f);
    Print(" Point: ", ToString(p1));

    // 3. Translation d'un point à partir de 2 coordonnées 
    float x = -1.0, y = 1.0;
    Point2f p2 = Translate(p1, x, y);
    Print(" Translated: ", ToString(p2));

    // 4. Translation d'un point à partir d'un vecteur
    Vector2f v = MakeV2f(1.0f, -1.0f);
    Point2f p3 = Translate(p1, v);
    Print(" Translated: ", ToString(p3));

    // 5. L'Homothesie d'un point à partir de 2 coordonnées
    Point2f p4 = Scale(p1, x, y); 
    Print(" Scaled: ", ToString(p4));

    // 6. L'Homothesie d'un point à partir d'un vecteur
    Point2f p5 = Scale(p1, v);
    Print(" Scaled: ", ToString(p5));

    // 7. Rotation d'un point à partir d'un angle
    float angleDegree = 90.0f;
    Point2f p6 = Rotate(p1, angleDegree);
    Print(" Rotate: ", ToString(p6));


    // =========== Test Vecteurs ==========
    Print("\n ====== Test Vecteurs ====== \n");

    // 1. Création d'un vecteur null
    Vector2f nul = MakeNullVector();
    Print(" Null Vector: ", ToString(nul));
    // 2. Création d'un vecteur à partir de 2 coordonnées
    Vector2f v1 = MakeV2f(-3.0f, 4.0f);
    Print(" Vector1: ", ToString(v1));

    // 3. Création d'un vecteur à partir de 2 points
    Vector2f v2 = MakeV2f(p1, p2);
    Print(" Vector2: ", ToString(v2));

    // 4. Addition vectorielle
    Vector2f v3 = Add(v1, v2);
    Print(" Addition: ", ToString(v3));

    // 5. Soustraction vectorielle
    v3 = Sub(v1, v2);
    Print(" Substraction: ", ToString(v3));

    // 6. L'Homothesie d'un vecteur par un scalaire k
    float k = 0.5f;
    Vector2f v4 = Scale(v3, k);
    Print(" Scaled: ", ToString(v4));

    // 7. Produit scalaire
    float dot = Dot(v1, v2);
    Print(" Dot Product: ", dot);

    // 8. Longueur d'un vecteur
    float __len = Length(v1);
    Print(" Length: ", __len);

    // 9. Le vecteur unitaire d'un vecteur
    Vector2f v5 = Normalize(v1);
    Print(" Unit vector: ", ToString(v5));

    // 10. L'Interpolation linéaire
    Vector2f U = {0, 0}, V = {10, 10};
    Vector2f v6 = Lerp(U, V, 0.5f);
    Print(" Lerp: ", ToString(v6));

    // 11. Le Determinant de 2 vecteurs
    float Det = Determinant(v1, v2);
    Print(" Determinant: ", Det);

    Print("\n");
    return 0;
}
```
## ** Compilation and Execution **
* In order to effectively run this code, I will advice to you all to compile my code using **Standard C++17 and CLANG++** by following this syntax
```bash
# This command help you compile the entire project at once
clang++ -std=c++17 main.cpp geometry/*.cpp -I geometry -o geometry
```
* For the execution, simply enter
``` bash
./geometry
```
## ** Conclusion **
I give special thanks to myself, friends and most-especially my teacher to whom this project couldn't have been possible 😁😁😁✌️✌️✌️.