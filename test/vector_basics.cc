#include <gtest/gtest.h>
#include "vector3d.hpp"

/*!
 * Тестирование конструктора и доступа к компонентам
 */
TEST(Vector3DTest, ConstructorAndComponents) {
    Vector3D v(1.5, -2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.X, 1.5);
    EXPECT_DOUBLE_EQ(v.Y, -2.0);
    EXPECT_DOUBLE_EQ(v.Z, 3.0);
}

/*!
 * Тестирование квадрата нормы вектора
 */
TEST(Vector3DTest, NormSquared) {
    Vector3D v(1.0, 2.0, 3.0);
    EXPECT_DOUBLE_EQ(v.norm_squared(), 14.0); // 1+4+9=14
}

/*!
 * Тестирование оператора вычитания
 */
TEST(Vector3DTest, SubtractionOperator) {
    Vector3D v1(5.0, 3.0, 2.0);
    Vector3D v2(2.0, 1.0, 3.0);
    Vector3D result = v1 - v2;
    EXPECT_DOUBLE_EQ(result.X, 3.0);
    EXPECT_DOUBLE_EQ(result.Y, 2.0);
    EXPECT_DOUBLE_EQ(result.Z, -1.0);
}

/*!
 * Тестирование оператора сложения
 */
TEST(Vector3DTest, AdditionOperator) {
    Vector3D v1(1.0, -2.0, 3.0);
    Vector3D v2(4.0, 5.0, -6.0);
    Vector3D result = v1 + v2;
    EXPECT_DOUBLE_EQ(result.X, 5.0);
    EXPECT_DOUBLE_EQ(result.Y, 3.0);
    EXPECT_DOUBLE_EQ(result.Z, -3.0);
}

/*!
 * Тестирование умножения на скаляр
 */
TEST(Vector3DTest, ScalarMultiplication) {
    Vector3D v(2.0, -3.0, 1.0);
    Vector3D result = v * 2.5;
    EXPECT_DOUBLE_EQ(result.X, 5.0);
    EXPECT_DOUBLE_EQ(result.Y, -7.5);
    EXPECT_DOUBLE_EQ(result.Z, 2.5);
}

/*!
 * Тестирование скалярного произведения
 */
TEST(Vector3DTest, DotProduct) {
    Vector3D v1(1.0, 2.0, 3.0);
    Vector3D v2(4.0, 5.0, 6.0);
    double dot = v1.Dot(v2);
    EXPECT_DOUBLE_EQ(dot, 32.0); // 1*4 + 2*5 + 3*6 = 4+10+18=32
}

/*!
 * Тестирование векторного произведения
 */
TEST(Vector3DTest, CrossProduct) {
    Vector3D v1(1.0, 0.0, 0.0);
    Vector3D v2(0.0, 1.0, 0.0);
    Vector3D cross = v1.Cross(v2);

    EXPECT_DOUBLE_EQ(cross.X, 0.0);
    EXPECT_DOUBLE_EQ(cross.Y, 0.0);
    EXPECT_DOUBLE_EQ(cross.Z, 1.0);
}

/*!
 * Тестирование векторного произведения (дополнительный случай)
 */
TEST(Vector3DTest, CrossProductAdvanced) {
    Vector3D v1(2.0, 1.0, -1.0);
    Vector3D v2(-3.0, 4.0, 1.0);
    Vector3D cross = v1.Cross(v2);

    EXPECT_DOUBLE_EQ(cross.X, (1*1 - (-1)*4));   // 1*1 - (-1)*4 = 1+4=5
    EXPECT_DOUBLE_EQ(cross.Y, ((-1)*(-3) - 2*1)); // -1*(-3) - 2*1 = 3-2=1
    EXPECT_DOUBLE_EQ(cross.Z, (2*4 - 1*(-3)));   // 8 - (-3)=11
}
