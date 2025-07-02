#include "vector3d.hpp"

#include "utils.hpp"

Vector3D::Vector3D(double x, double y, double z) : X(x), Y(y), Z(z) {
}

double Vector3D::norm_squared() const {
    return X * X + Y * Y + Z * Z;
}

Vector3D Vector3D::operator-(const Vector3D &other) const {
    return {X - other.X, Y - other.Y, Z - other.Z};
}

Vector3D Vector3D::operator+(const Vector3D &other) const {
    return {X + other.X, Y + other.Y, Z + other.Z};
}

Vector3D Vector3D::operator*(double scalar) const {
    return {X * scalar, Y * scalar, Z * scalar};
}

double Vector3D::Dot(const Vector3D &other) const {
    return X * other.X + Y * other.Y + Z * other.Z;
}

Vector3D Vector3D::Cross(const Vector3D &other) const {
    return {
        Y * other.Z - Z * other.Y,
        Z * other.X - X * other.Z,
        X * other.Y - Y * other.X
    };
}

bool Vector3D::operator==(const Vector3D &other) const {
    return vector_utils::equal_scalars(X, other.X) && vector_utils::equal_scalars(Y, other.Y) &&
           vector_utils::equal_scalars(Z, other.Z);
}
