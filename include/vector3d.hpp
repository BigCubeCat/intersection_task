#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP


class Vector3D {
public:
    double X;
    double Y;
    double Z;
    Vector3D(double x, double y, double z);

    /*!
     * \brief Норма в квадрате (x^2 + y^2 + z^2)
     * @return scalar value
     */
    [[nodiscard]] double norm_squared() const;

    Vector3D operator-(const Vector3D &other) const;

    Vector3D operator+(const Vector3D &other) const;

    Vector3D operator*(double scalar) const;

    [[nodiscard]] double Dot(const Vector3D &other) const;

    [[nodiscard]] Vector3D Cross(const Vector3D &other) const;

    bool operator==(const Vector3D &other) const;
};


#endif //VECTOR3D_HPP
