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
     * \todo Уточнить в требованиях случай полного и частичного наложения отрезков.
     * @param other Отрезок, точку пересечения с которым ищем
     * @return Точку пересечения. Если не пересекаются - std::nullopt
     */
    [[nodiscard]] std::optional<Vector3D> Intersect(const Segment3D &other) const;

    /*!
     * @return true, если вектор вырожден
     */
    [[nodiscard]] bool is_zero() const;

    /*!
     * @param point Точка для проверки
     * @return true, если point лежит на отрезке
     */
    [[nodiscard]] bool has_point(const Vector3D &point) const;
};

#endif //SEGMENT3D_HPP
