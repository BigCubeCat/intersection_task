#include "utils.hpp"

#include <cmath>

bool vector_utils::equal_scalars(const double a, const double b) {
    return std::abs(a - b) < EPSILON;
}
