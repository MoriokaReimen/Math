#include "Degree.hpp"

#include <gtest/gtest.h>
using namespace Math;

TEST(DegreeTest, construct)
{
  Degree degree_a;
  Degree degree_b(2.0);
  EXPECT_EQ(0.0, degree_a.val);
  EXPECT_EQ(2.0, degree_b.val);
}

TEST(DegreeTest, assignment_operator)
{
  Degree degree_a;
  Degree degree_b(2.0);
  degree_a += degree_b;
  degree_b -= degree_a;
  EXPECT_EQ(2.0, degree_a.val);
  EXPECT_EQ(0.0, degree_b.val);
}
