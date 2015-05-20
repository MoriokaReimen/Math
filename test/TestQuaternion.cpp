#include "Quaternion.hpp"
#include <cmath>

#include <gtest/gtest.h>
using namespace Math;

TEST(QuaternionTest, construct)
{
  Quaternion a;
  Quaternion b(1.0, 2.0, 3.0, 4.0);

  EXPECT_DOUBLE_EQ(1.0, a.w);
  EXPECT_DOUBLE_EQ(0.0, a.x);
  EXPECT_DOUBLE_EQ(0.0, a.y);
  EXPECT_DOUBLE_EQ(0.0, a.z);

  EXPECT_DOUBLE_EQ(1.0, b.w);
  EXPECT_DOUBLE_EQ(2.0, b.x);
  EXPECT_DOUBLE_EQ(3.0, b.y);
  EXPECT_DOUBLE_EQ(4.0, b.z);
}

TEST(QuaternionTest, member_function)
{
  Quaternion a(1.0, 1.0, 1.0, 1.0);
  Quaternion b(0.5, 0.5, 0.5, 0.5);

  EXPECT_DOUBLE_EQ(2.0, a.getNorm());
  EXPECT_EQ(2.0, a.getNorm());

}

TEST(QuaternionTest, assignment_operator)
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

TEST(QuaternionTest, add_sub_mult_operator)
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

TEST(QuaternionTest, comp_operator)
{
  Vector3 vector3_a(1.0, 1.0, 1.0);
  Vector3 vector3_b(1.0, 1.0, 1.0);
  Vector3 vector3_c(1.0, 2.0, 3.0);
  EXPECT_EQ(true, vector3_a == vector3_b);
  EXPECT_EQ(false, vector3_a == vector3_c);

  EXPECT_EQ(true, vector3_a != vector3_c);
  EXPECT_EQ(false, vector3_a != vector3_b);
}

TEST(QuaternionTest, function)
{
  Vector3 vector3_a(1.0, 1.0, 1.0);
  Vector3 vector3_b(2.0, 2.0, 2.0);
  Vector3 vector3_c(1.0, 2.0, 3.0);
  Vector3 vector3_d(1.0, -2.0, 1.0);


  auto buff = normalize(vector3_b);
  Vector3 normal_b(
    1.0 / std::sqrt(3),
    1.0 / std::sqrt(3),
    1.0 / std::sqrt(3));
  EXPECT_EQ(true, normal_b == buff);

  EXPECT_DOUBLE_EQ(6.0, dot(vector3_a, vector3_c));

  buff = cross(vector3_a, vector3_c);
  EXPECT_EQ(true, vector3_d == buff);
}
