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

  Vector3 x(1.0, 0.0, 0.0);
  Vector3 y(0.0, 1.0, 0.0);
  Vector3 z(0.0, 0.0, 1.0);
  Degree ninety(90.0);

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

  Quaternion d(x, y);
  d.toAngleAxis(angle, axis);
  EXPECT_DOUBLE_EQ(90.0, angle);
  EXPECT_EQ(true, z == axis);

  Degree roll(30.0), pitch(15.0), yaw(20.0);
  Quaternion rpy_a;
  rpy_a.fromRPY(roll, pitch, yaw);
  EXPECT_NEAR(0.937, rpy_a.w, 0.001);
  EXPECT_NEAR(0.275, rpy_a.x, 0.001);
  EXPECT_NEAR(0.0796, rpy_a.y, 0.001);
  EXPECT_NEAR(0.200, rpy_a.z, 0.001);

  Quaternion rpy_b(0.772, 0.514, 0.210, 0.310);
  rpy_b.toRPY(roll, pitch, yaw);
  EXPECT_NEAR(60.0, roll.val, 0.1);
  EXPECT_NEAR(40.0, pitch.val, 0.1);
  EXPECT_NEAR(20.0, yaw.val, 0.1);
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
