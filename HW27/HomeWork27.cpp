#include "HomeWork27.h"

VectorRelativeState Vector2d::getRelativeState(const Vector2d& other) const
{
    float dot = this->dotProduct(other);
    float length1 = std::sqrt(x * x + y * y);
    float length2 = std::sqrt(other.x * other.x + other.y * other.y);
    float cosTheta = dot / (length1 * length2);

    if (cosTheta == 1) return VectorRelativeState::Identical;
    else if (cosTheta == -1) return VectorRelativeState::OppositeDirected;
    else if (cosTheta > 0 && cosTheta < 1) return VectorRelativeState::AcuteAngle;
    else if (cosTheta < 0 && cosTheta > -1) return VectorRelativeState::ObtuseAngle;
    else if (cosTheta == 0) return VectorRelativeState::RightAngle;

    return VectorRelativeState::coDirected;
}


