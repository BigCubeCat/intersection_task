#ifndef SEGMENT3D_HPP
#define SEGMENT3D_HPP

#include <optional>

#include "vector3d.hpp"


/*!
 * \brief Вектор в трехмерном пространстве
 */
class Segment3D {
    /*!
     * \brief Начальная точка
     */
    Vector3D start;

    /*!
     * \brief Конечная точка
     */
    Vector3D end;

public:
    Segment3D(const Vector3D &start, const Vector3D &end);

    /*!
     * \brief Точка пересечения двух отрезков
     * @param other Отрезок, точку пересечения с которым ищем
     * @return Точку пересечения. Если не пересекаются - std::nullopt
     */
    [[nodiscard]] std::optional<Vector3D> Intersect(const Segment3D &other) const;

    [[nodiscard]] bool is_zero() const;

    [[nodiscard]] bool has_point(const Vector3D &point) const;
};

#endif //SEGMENT3D_HPP
