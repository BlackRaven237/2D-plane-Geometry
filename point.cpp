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