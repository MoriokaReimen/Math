#include "Vector3.hpp"
#include <cmath>

#include <gtest/gtest.h>
using namespace Math;

TEST(Vector3Test, construct)
{
  Vector3 vector3_a;
  Vector3 vector3_b(1.0, 2.0, 3.0);

  EXPECT_DOUBLE_EQ(0.0, vector3_a.x);
  EXPECT_DOUBLE_EQ(0.0, vector3_a.y);
  EXPECT_DOUBLE_EQ(0.0, vector3_a.z);

  EXPECT_DOUBLE_EQ(1.0, vector3_b.x);
  EXPECT_DOUBLE_EQ(2.0, vector3_b.y);
  EXPECT_DOUBLE_EQ(3.0, vector3_b.z);
}

TEST(Vector3Test, member_function)
{
  Vector3 vector3_c(1.0, 2.0, 3.0);
  EXPECT_DOUBLE_EQ(std::sqrt(14), vector3_c.getNorm());

}

TEST(Vector3Test, assignment_operator)
{
  Vector3 vector3_a;
  Vector3 vector3_b(1.0, 1.0, 1.0);
  Vector3 vector3_c(1.0, 2.0, 3.0);

  vector3_a += vector3_b;
  EXPECT_DOUBLE_EQ(1.0, vector3_a.x);
  EXPECT_DOUBLE_EQ(1.0, vector3_a.y);
  EXPECT_DOUBLE_EQ(1.0, vector3_a.z);

  vector3_c -= vector3_a;
  EXPECT_DOUBLE_EQ(0.0, vector3_c.x);
  EXPECT_DOUBLE_EQ(1.0, vector3_c.y);
  EXPECT_DOUBLE_EQ(2.0, vector3_c.z);

  vector3_a *= 4.0;
  EXPECT_DOUBLE_EQ(4.0, vector3_a.x);
  EXPECT_DOUBLE_EQ(4.0, vector3_a.y);
  EXPECT_DOUBLE_EQ(4.0, vector3_a.z);

  vector3_a /= 2.0;
  EXPECT_DOUBLE_EQ(2.0, vector3_a.x);
  EXPECT_DOUBLE_EQ(2.0, vector3_a.y);
  EXPECT_DOUBLE_EQ(2.0, vector3_a.z);
}

TEST(Vector3Test, add_sub_mult_operator)
{
  Vector3 vector3_a;
  Vector3 vector3_b(1.0, 1.0, 1.0);
  Vector3 vector3_c(1.0, 2.0, 3.0);

  vector3_a = vector3_b + vector3_c;
  EXPECT_DOUBLE_EQ(2.0, vector3_a.x);
  EXPECT_DOUBLE_EQ(3.0, vector3_a.y);
  EXPECT_DOUBLE_EQ(4.0, vector3_a.z);

  vector3_a = vector3_c - vector3_b;
  EXPECT_DOUBLE_EQ(0.0, vector3_a.x);
  EXPECT_DOUBLE_EQ(1.0, vector3_a.y);
  EXPECT_DOUBLE_EQ(2.0, vector3_a.z);

  vector3_a = vector3_b * 2;
  EXPECT_DOUBLE_EQ(2.0, vector3_a.x);
  EXPECT_DOUBLE_EQ(2.0, vector3_a.y);
  EXPECT_DOUBLE_EQ(2.0, vector3_a.z);

  vector3_a = vector3_b / 2;
  EXPECT_DOUBLE_EQ(0.5, vector3_a.x);
  EXPECT_DOUBLE_EQ(0.5, vector3_a.y);
  EXPECT_DOUBLE_EQ(0.5, vector3_a.z);
}

TEST(Vector3Test, comp_operator)
{
  Vector3 vector3_a(1.0, 1.0, 1.0);
  Vector3 vector3_b(1.0, 1.0, 1.0);
  Vector3 vector3_c(1.0, 2.0, 3.0);
  EXPECT_EQ(true, vector3_a == vector3_b);
  EXPECT_EQ(false, vector3_a == vector3_c);

  EXPECT_EQ(true, vector3_a != vector3_c);
  EXPECT_EQ(false, vector3_a != vector3_b);
}

TEST(Vector3Test, function)
{
  Vector3 vector3_a(1.0, 1.0, 1.0);
  Vector3 vector3_b(2.0, 2.0, 2.0);
  Vector3 vector3_c(1.0, 2.0, 3.0);
  Vector3 vector3_d(1.0, -2.0, 1.0);

  Vector3 x(1.0, 0.0, 0.0);
  Vector3 y(0.0, 1.0, 0.0);
  Vector3 z(0.0, 0.0, 1.0);


  auto buff = normalize(vector3_b);
  Vector3 normal_b(
    1.0 / std::sqrt(3),
    1.0 / std::sqrt(3),
    1.0 / std::sqrt(3));
  EXPECT_EQ(true, normal_b == buff);

  EXPECT_DOUBLE_EQ(6.0, dot(vector3_a, vector3_c));

  buff = cross(vector3_a, vector3_c);
  EXPECT_EQ(true, vector3_d == buff);

  auto ninety = getAngle(x, y);
  EXPECT_DOUBLE_EQ(90.0, ninety.val);

  auto normal = getNormal(x, y);
  EXPECT_EQ(true, normal == z);
}
