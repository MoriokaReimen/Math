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
  Degree angle(120.0);
  Vector3 axis(1.0, 1.0, 1.0);

  EXPECT_DOUBLE_EQ(2.0, a.getNorm());

  Quaternion c(angle, axis);
  EXPECT_DOUBLE_EQ(0.5, c.w);
  EXPECT_DOUBLE_EQ(0.5, c.x);
  EXPECT_DOUBLE_EQ(0.5, c.y);
  EXPECT_DOUBLE_EQ(0.5, c.z);

  b.toAngleAxis(angle, axis);
  axis = normalize(axis);
  Vector3 axis_ans(1.0, 1.0, 1.0);
  axis_ans = normalize(axis_ans);
  EXPECT_DOUBLE_EQ(120.0, angle.val);
  EXPECT_EQ(true, axis == axis_ans);
}

TEST(QuaternionTest, assignment_operator)
{
  Quaternion a(1.0, 1.0, 1.0, 1.0);

  Quaternion b(0.5, 0.5, 0.5, 0.5);

  a += b;
  EXPECT_DOUBLE_EQ(1.5, a.w);
  EXPECT_DOUBLE_EQ(1.5, a.x);
  EXPECT_DOUBLE_EQ(1.5, a.y);
  EXPECT_DOUBLE_EQ(1.5, a.z);

  a -= b;
  EXPECT_DOUBLE_EQ(1.0, a.w);
  EXPECT_DOUBLE_EQ(1.0, a.x);
  EXPECT_DOUBLE_EQ(1.0, a.y);
  EXPECT_DOUBLE_EQ(1.0, a.z);

  a *= b;
  EXPECT_DOUBLE_EQ(-1.0, a.w);
  EXPECT_DOUBLE_EQ(1.0, a.x);
  EXPECT_DOUBLE_EQ(1.0, a.y);
  EXPECT_DOUBLE_EQ(1.0, a.z);
}

TEST(QuaternionTest, add_sub_mult_operator)
{
  Quaternion a(1.0, 1.0, 1.0, 1.0);
  Quaternion b(0.5, 0.5, 0.5, 0.5);
  Quaternion buff;

  buff = a + b;
  EXPECT_DOUBLE_EQ(1.5, buff.w);
  EXPECT_DOUBLE_EQ(1.5, buff.x);
  EXPECT_DOUBLE_EQ(1.5, buff.y);
  EXPECT_DOUBLE_EQ(1.5, buff.z);

  buff = a - b;
  EXPECT_DOUBLE_EQ(0.5, buff.w);
  EXPECT_DOUBLE_EQ(0.5, buff.x);
  EXPECT_DOUBLE_EQ(0.5, buff.y);
  EXPECT_DOUBLE_EQ(0.5, buff.z);

  a.set(1.0, 1.0, 1.0, 1.0);
  b.set(0.5, 0.5, 0.5, 0.5);
  buff = a * b;
  EXPECT_DOUBLE_EQ(-1.0, buff.w);
  EXPECT_DOUBLE_EQ(1.0, buff.x);
  EXPECT_DOUBLE_EQ(1.0, buff.y);
  EXPECT_DOUBLE_EQ(1.0, buff.z);
}

TEST(QuaternionTest, comp_operator)
{
  Quaternion a(1.0, 1.0, 1.0, 1.0);
  Quaternion b(1.0, 1.0, 1.0, 1.0);
  Quaternion c(0.5, 0.5, 0.5, 0.5);

  EXPECT_EQ(true, a == b);
  EXPECT_EQ(false, a == c);

  EXPECT_EQ(true, a != c);
  EXPECT_EQ(false, a != b);
}

TEST(QuaternionTest, function)
{
  Quaternion a(1.0, 1.0, 1.0, 1.0);
  Quaternion b(2.0, 2.0, 2.0, 2.0);

  auto buffa = scale(a, 2);
  EXPECT_EQ(true, buffa == b);

  EXPECT_EQ(true, normalize(a) == normalize(b));
}
