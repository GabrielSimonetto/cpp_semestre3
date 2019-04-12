#include "vector2d.h"

// vc inicializa os membros fora
math::Vector2D::Vector2D(double x, double y):
    x_{x},
    y_{y}
{ }

namespace math {

double Vector2D::x() const {
    return x_;
}

double Vector2D::y() const {
    return y_;
}

Vector2D& Vector2D::invert() {
    x_ = -x_;
    y_ = -y_;

    return *this;
}

Vector2D& Vector2D::multiply(double scalar) {
    x_ = x_ * scalar;
    y_ = y_ * scalar;

    return *this;
}

Vector2D& Vector2D::sum(const Vector2D& other) {
    x_ += other.x_;
    y_ += other.y_;

    return *this;
}

Vector2D invert(Vector2D v) {
    return v.invert();
}

Vector2D sum(Vector2D lhs, const Vector2D &rhs)
{
    lhs.sum(rhs);

    return lhs;
}

Vector2D multiply(Vector2D lhs, double s)
{
    lhs.multiply(s);

    return lhs;
}

}