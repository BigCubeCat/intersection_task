#include "segment3d.hpp"

#include "utils.hpp"

Segment3D::Segment3D(const Vector3D &start, const Vector3D &end) : start(start), end(end) {
}

std::optional<Vector3D> Segment3D::Intersect(const Segment3D &other) const {
    const bool other_zero = other.is_zero();
    const bool self_zero = is_zero();
    if (other_zero && self_zero) {
        // Если оба отрезка вырождены - сравниваем точки
        if (start == other.start) {
            return start;
        }
        return std::nullopt;
    }
    if (other_zero) {
        // Если только один вырожден
        if (has_point(other.start)) {
            return other.start;
        }
        return std::nullopt;
    }
    if (self_zero) {
        // Если только один вырожден
        if (other.has_point(start)) {
            return start;
        }
        return std::nullopt;
    }
    const auto self_vec = end - start;
    const auto other_vec = other.end - other.start;
    const auto start_diff = start - other.start;

    const auto self_sq_len = self_vec.Dot(self_vec);
    const auto other_sq_len = other_vec.Dot(other_vec);
    const auto dot_btw = self_vec.Dot(other_vec);

    const auto D = self_sq_len * other_sq_len - dot_btw * dot_btw;

    if (vector_utils::equal_scalars(D, 0.0)) {
        // параллельные прямые
        if (has_point(other.start)) {
            return other.start;
        }
        if (has_point(other.end)) {
            return other.end;
        }
        return std::nullopt;
    }
    const auto self_dot_diff = self_vec.Dot(start_diff);
    const auto other_dot_diff = other_vec.Dot(start_diff);

    const auto t = (dot_btw * other_dot_diff - other_sq_len * self_dot_diff) / D;
    const auto u = (self_sq_len * other_dot_diff - dot_btw * self_dot_diff) / D;

    if (0 <= t && t <= 1 && 0 <= u && u <= 1) {
        const auto self_coord = start + (self_vec * t);
        const auto other_coord = other.start + (other_vec * u);
        const auto difference = self_coord - other_coord;
        if (vector_utils::equal_scalars(difference.norm_squared(), 0.0)) {
            // есть пересечение
            return self_coord;
        }
    }
    return std::nullopt;
}

bool Segment3D::is_zero() const {
    return end == start;
}

bool Segment3D::has_point(const Vector3D &point) const {
    if (is_zero()) {
        return point == start;
    }
    const auto v = end - start;
    const auto w0 = point - start;
    if (vector_utils::equal_scalars(v.Cross(w0).norm_squared(), 0)) {
        const auto t = v.Dot(w0) / v.Dot(v);
        return 0 <= t && t <= 1;
    }
    return false;
}
