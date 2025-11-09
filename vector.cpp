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