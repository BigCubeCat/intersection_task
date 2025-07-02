#ifndef UTILS_HPP
#define UTILS_HPP
#include <limits>

namespace vector_utils {
    constexpr double EPSILON = std::numeric_limits<double>::epsilon();

    bool equal_scalars(double a, double b);
};

#endif //UTILS_HPP
