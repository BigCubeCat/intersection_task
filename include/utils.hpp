#ifndef UTILS_HPP
#define UTILS_HPP
#include <limits>

namespace vector_utils {
    /*!
     * Используется как точность при расчетах в рамках пакета vector_lib.
     * При желании можно увеличить
     */
    constexpr double EPSILON = std::numeric_limits<double>::epsilon();

    /*!
     * @param a Первое число
     * @param b Второе число
     * @return true, если числа равны (их разность менее vector_utils::EPSILON)
     */
    bool equal_scalars(double a, double b);
};

#endif //UTILS_HPP
