#pragma once
#include <cmath>

enum class VectorRelativeState {
    Identical,
    coDirected,
    OppositeDirected,
    AcuteAngle,
    ObtuseAngle,
    RightAngle
};

class Vector2d {
public:
    float x, y;

    Vector2d(float x = 0, float y = 0) : x(x), y(y) {}

    Vector2d(float x0, float y0, float x1, float y1)
        : x(x1 - x0), y(y1 - y0) {}

    float dotProduct(const Vector2d& other) const 
    {
        return x * other.x + y * other.y;
    }

    Vector2d negate() const 
    {
        return Vector2d(-x, -y);
    }

    VectorRelativeState getRelativeState(const Vector2d& other) const;

    void scale(float factorX, float factorY) {
        x *= factorX;
        y *= factorY;
    }
};


class Vector3d {
public:
    float x, y, z;

    Vector3d(float x = 0, float y = 0, float z = 0) : x(x), y(y), z(z) {}

    Vector3d crossProduct(const Vector3d& other) const {
        return Vector3d(
            y * other.z - z * other.y,
            z * other.x - x * other.z,
            x * other.y - y * other.x
        );
    }
};