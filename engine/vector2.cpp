#include "vector2.h"
#include <iostream>
Vector2::Vector2(float xx, float yy){
    this->x = xx;
    this->y = yy;
}

Vector2::Vector2(Vector2 vec1, Vector2 vec2){
    this->x = vec1.x - vec2.x;
    this->y = vec1.y - vec2.y;
}

Vector2::~Vector2(){

}

void Vector2::normalize(){
    if(magnitude() != 0){
        Vector2(x,y) /= magnitude();
    }
}

// handle += Vector2 or float
Vector2& Vector2::operator+=(const Vector2& rhs)
{
    x += rhs.x;
    y += rhs.y;
    return *this;
}


Vector2& Vector2::operator+=(const float rhs)
{
    x += rhs;
    y += rhs;
    return *this;
}

// handle -= Vector2 or float
Vector2& Vector2::operator-=(const Vector2& rhs)
{
    x -= rhs.x;
    y -= rhs.y;
    return *this;
}


Vector2& Vector2::operator-=(const float rhs)
{
    x -= rhs;
    y -= rhs;
    return *this;
}

// handle /= Vector2 or float
Vector2& Vector2::operator/=(const Vector2& rhs)
{
    x /= rhs.x;
    y /= rhs.y;
    return *this;
}


Vector2& Vector2::operator/=(const float rhs)
{
    x /= rhs;
    y /= rhs;
    return *this;
}

// handle *= Vector2 or float
Vector2& Vector2::operator*=(const Vector2& rhs)
{
    x *= rhs.x;
    y *= rhs.y;
    return *this;
}


Vector2& Vector2::operator*=(const float rhs)
{
    x *= rhs;
    y *= rhs;
    return *this;
}

// handle + Vector2 or float
Vector2 Vector2::operator+(const Vector2& rhs)
{
    return Vector2(x + rhs.x, y + rhs.y);
}

Vector2 Vector2::operator+(const float rhs)
{
   return Vector2(x + rhs, y + rhs);
}

// handle - Vector2 or float
Vector2 Vector2::operator-(const Vector2& rhs)
{
    return Vector2(x - rhs.x, y - rhs.y);
}

Vector2 Vector2::operator-(const float rhs)
{
    return Vector2(x - rhs, y - rhs);
}

// handle * Vector2 or float
Vector2 Vector2::operator*(const Vector2& rhs)
{
    return Vector2(x * rhs.x, y * rhs.y);
}

Vector2 Vector2::operator*(const float rhs)
{
    return Vector2(x * rhs, y * rhs);
}

// handle / Vector2 or float
Vector2 Vector2::operator/(const Vector2& rhs)
{
    return Vector2(x / rhs.x, y / rhs.y);
}

Vector2 Vector2::operator/(const float rhs)
{
    return Vector2(x / rhs, y / rhs);
}

bool Vector2::operator==(const Vector2& rhs)
{
    return(x==rhs.x && y==rhs.y);
}

bool Vector2::operator!=(const Vector2& rhs)
{
    return(x!=rhs.x || y!=rhs.y);
}
