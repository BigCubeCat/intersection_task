#include <gtest/gtest.h>

#include "segment3d.hpp"
#include "vector3d.hpp"
#include "utils.hpp"

namespace {
    void ExpectPoint(const std::optional<Vector3D> &opt, double x, double y, double z) {
        ASSERT_TRUE(opt.has_value());
        const auto &p = opt.value();
        EXPECT_NEAR(p.X, x, vector_utils::EPSILON);
        EXPECT_NEAR(p.Y, y, vector_utils::EPSILON);
        EXPECT_NEAR(p.Z, z, vector_utils::EPSILON);
    }
};

/*!
 * Сценарий 0: Одно простое пересечение под углом 45 градусов
 */
TEST(Segment3DIntersect, OneSimpleIntersection) {
    const auto a = Segment3D({1, 1, 1}, {0, 0, 0});
    const auto b = Segment3D({0, 0, 1}, {1, 1, 0});
    const auto c = a.Intersect(b).value();
    EXPECT_EQ(c, Vector3D(0.5, 0.5, 0.5));
}

/*!
 * Сценарий 1: Пересечение в середине отрезков
 */
TEST(Segment3DIntersect, IntersectionAtInterior) {
    const Segment3D s1({0, 0, 0}, {2, 2, 2});
    const Segment3D s2({0, 2, 2}, {2, 0, 0});
    // Должны пересечься в (1,1,1)
    const auto res = s1.Intersect(s2);
    ExpectPoint(res, 1.0, 1.0, 1.0);
}

/*!
 * Сценарий 2: Пересечение в конечной точке одного из отрезков
 */
TEST(Segment3DIntersect, IntersectionAtEndpoint) {
    const Segment3D s1({0, 0, 0}, {1, 1, 1});
    const Segment3D s2({1, 1, 1}, {2, 2, 2});
    const auto res = s1.Intersect(s2);
    ExpectPoint(res, 1.0, 1.0, 1.0);
}

/*!
 * Сценарий 3: Нет пересечения - скрещивающиеся (не совпадающие, не параллельные) отрезки
 */
TEST(Segment3DIntersect, SkewSegmentsNoIntersect) {
    const Segment3D s1({0, 0, 0}, {1, 0, 0});
    const Segment3D s2({0, 1, 1}, {1, 1, 1});
    const auto res = s1.Intersect(s2);
    EXPECT_FALSE(res.has_value());
}

/*!
 * Сценарий 4: Параллельные, но не совпадающие отрезки
 */
TEST(Segment3DIntersect, ParallelNoIntersect) {
    const Segment3D s1({0, 0, 0}, {1, 0, 0});
    const Segment3D s2({0, 1, 0}, {1, 1, 0});
    const auto res = s1.Intersect(s2);
    EXPECT_FALSE(res.has_value());
}

/*!
 * Сценарий 5: Коллинеарные с частичным перекрытием — метод вернёт один из концов
 */
TEST(Segment3DIntersect, ColinearPartialOverlap) {
    const Segment3D s1({0, 0, 0}, {3, 0, 0});
    const Segment3D s2({2, 0, 0}, {5, 0, 0});
    const auto res = s1.Intersect(s2);
    // По текущей реализации — начало второго отрезка (2,0,0)
    ExpectPoint(res, 2.0, 0.0, 0.0);
}

/*!
 * Сценарий 6: Оба отрезка вырождены и совпадают
 */
TEST(Segment3DIntersect, BothDegenerateSamePoint) {
    const Segment3D s1({1, 2, 3}, {1, 2, 3});
    const Segment3D s2({1, 2, 3}, {1, 2, 3});
    const auto res = s1.Intersect(s2);
    ExpectPoint(res, 1.0, 2.0, 3.0);
}

/*!
 * Сценарий 7: Оба вырождены, но разные точки
 */
TEST(Segment3DIntersect, BothDegenerateDifferent) {
    const Segment3D s1({1, 1, 1}, {1, 1, 1});
    const Segment3D s2({2, 2, 2}, {2, 2, 2});
    const auto res = s1.Intersect(s2);
    EXPECT_FALSE(res.has_value());
}

/*!
 * Сценарий 8: Оба вырождены, равные точки
 */
TEST(Segment3DIntersect, BothDegenerateDifferentNo) {
    const Segment3D s1({1, 1, 1}, {1, 1, 1});
    const Segment3D s2({1, 1, 1}, {1, 1, 1});
    const auto res = s1.Intersect(s2);
    ExpectPoint(res, 1.0, 1.0, 1.0);
}

/*!
 * Сценарий 9: Второй вырожден, лежит на другом
 */
TEST(Segment3DIntersect, OneDegenerateOnSegmentSecond) {
    const Segment3D s1({0, 0, 0}, {2, 2, 2});
    const Segment3D s2({1, 1, 1}, {1, 1, 1}); // точка внутри первого
    const auto res = s1.Intersect(s2);
    ExpectPoint(res, 1.0, 1.0, 1.0);
}

/*!
 * Сценарий 10: Второй вырожден, лежит на другом
 */
TEST(Segment3DIntersect, OneDegenerateOnSegmentFirst) {
    const Segment3D s1({0, 0, 0}, {2, 2, 2});
    const Segment3D s2({1, 1, 1}, {1, 1, 1}); // точка внутри первого
    const auto res = s2.Intersect(s1);
    ExpectPoint(res, 1.0, 1.0, 1.0);
}

/*!
 * Сценарий 11: Один вырожден, не лежит
 */
TEST(Segment3DIntersect, OneDegenerateOffSegmentSecond) {
    const Segment3D s1({0, 0, 0}, {1, 0, 0});
    const Segment3D s2({2, 0, 0}, {2, 0, 0});
    const auto res = s1.Intersect(s2);
    EXPECT_FALSE(res.has_value());
}

/*!
 * Сценарий 12: Один вырожден, не лежит
 */
TEST(Segment3DIntersect, OneDegenerateOffSegmentFirst) {
    const Segment3D s1({0, 0, 0}, {1, 0, 0});
    const Segment3D s2({2, 0, 0}, {2, 0, 0});
    const auto res = s2.Intersect(s1);
    EXPECT_FALSE(res.has_value());
}

/*!
 * Сценарий 13: Конец второго отрезка это начало другого (параллельный случай)
 */
TEST(Segment3DIntersect, EndIsStartParallel) {
    const Segment3D s1({0, 0, 0}, {1, 0, 0});
    const Segment3D s2({1, 0, 0}, {2, 0, 0});
    const auto res = s2.Intersect(s1);
    ExpectPoint(res, 1.0, 0.0, 0.0);
}

/*!
 * Сценарий 14: Конец второго отрезка это начало другого
 */
TEST(Segment3DIntersect, EndIsStart) {
    const Segment3D s1({0, 0, 0}, {1, 0, 0});
    const Segment3D s2({1, 0, 0}, {2, 2, -2});
    const auto res = s2.Intersect(s1);
    ExpectPoint(res, 1.0, 0.0, 0.0);
}

/*!
 * Сценарий 15: Конец второго отрезка это начало другого
 */
TEST(Segment3DIntersect, EpsilonTest) {
    const auto e = (1.0 / 3.0) - 0.3333333;
    const Segment3D s1({1, 1, 1}, {2, 2, 2});
    const Segment3D s2({1 + e, 1 + e, 1 + e}, {2 - e, 2 - e, 2 - e});
    const auto res = s1.Intersect(s2);
    EXPECT_FALSE(res.has_value());
}

TEST(Segment3DIntersect, NoIntersection) {
    const Segment3D s1({0, 0, 0}, {1.0 / 3.0, 0, 0});
    const Segment3D s2({2.0 / 3.0, 1, 0}, {2.0 / 3.0, -1, 0});
    const auto res = s1.Intersect(s2);
    EXPECT_FALSE(res.has_value());
}

TEST(Segment3DIntersect, Function) {
    const auto a = Segment3D({1, 1, 1}, {0, 0, 0});
    const auto b = Segment3D({0, 0, 1}, {1, 1, 0});
    const auto c1 = a.Intersect(b).value();
    const auto c2 = Intersect(a, b).value();
    EXPECT_EQ(c1, c2);
}
