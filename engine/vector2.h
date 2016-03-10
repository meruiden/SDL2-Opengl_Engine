#ifndef VECTOR2_H
#define VECTOR2_H


#define PI 3.14159265359f;
#define RAD_TO_DEG 57.2957795f;
#define DEG_TO_RAD 0.0174532925f;

#include <string>
#include <math.h>
class Vector2
{
public:
    Vector2(float xx = 0.0f, float yy = 0.0f);
    Vector2(Vector2 vec1, Vector2 vec2);

    virtual ~Vector2();
    float x;
    float y;
    Vector2& operator+= (const Vector2& rhs);
    Vector2& operator+= (const float rhs);

    Vector2& operator-= (const Vector2& rhs);
    Vector2& operator-= (const float rhs);

    Vector2& operator/= (const Vector2& rhs);
    Vector2& operator/= (const float rhs);

    Vector2& operator*= (const Vector2& rhs);
    Vector2& operator*= (const float rhs);

    Vector2 operator+ (const Vector2& rhs);
    Vector2 operator+ (const float rhs);

    Vector2 operator- (const Vector2& rhs);
    Vector2 operator- (const float rhs);

    Vector2 operator* (const Vector2& rhs);
    Vector2 operator* (const float rhs);


    Vector2 operator/ (const Vector2& rhs);
    Vector2 operator/ (const float rhs);

    bool operator== (const Vector2& rhs);
    bool operator!= (const Vector2& rhs);

    float magnitude(){return sqrt((x * x) + (y * y));}
    void normalize();

    std::string returnString();
private:

};
#endif
