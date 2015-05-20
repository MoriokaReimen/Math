#pragma once
#include <cmath>

namespace Math {
  class Vector3 {
  public:
    double x{0.0};
    double y{0.0};
    double z{0.0};
    Vector3() = default;
    Vector3(const double& a, const double& b, const double& c);
    Vector3 operator+=(const Vector3& rhs);
    Vector3 operator-=(const Vector3& rhs);
    Vector3 operator*=(const double& rhs);
    Vector3 operator/=(const double& rhs);
  };

  Vector3 operator+(const Vector3& lhs, const Vector3& rhs);
  Vector3 operator-(const Vector3& lhs, const Vector3& rhs);
  Vector3 operator*(const Vector3& lhs, const double& rhs);
  Vector3 operator/(const Vector3& lhs, const double& rhs);

  bool operator==(const Vector3& lhs, const Vector3& rhs);
  bool operator!=(const Vector3& lhs, const Vector3& rhs);

  double length(const Vector3& lhs);
  Vector3 normalize(const Vector3& lhs);
  double dot(const Vector3& lhs, const Vector3& rhs);
  Vector3 cross(const Vector3& lhs, const Vector3& rhs);
};
