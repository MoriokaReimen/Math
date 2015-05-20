#pragma once
#include "Vector3.hpp"
#include "Degree.hpp"
#include <cmath>

namespace Math {
  class Quaternion
  {
  public:
      double w{1.0};
      double x{0.0};
      double y{0.0};
      double z{0.0};

      Quaternion() = default;
      Quaternion(const double& w, const double& x,
         const double& y, const double& z);
      virtual ~Quaternion() = default;
      void toAngleAxis(Degree& angle, Vector3& axis);
      void fromAngleAxis(const Degree& angle, const Vector3& axis);
      double getNorm() const;
      Quaternion operator+=(const Quaternion& rhs);
      Quaternion operator-=(const Quaternion& rhs);
      Quaternion operator*=(const Quaternion& rhs);
  };
  Quaternion scale(const Quaternion& quat, const double& num);
  Quaternion normalize(const Quaternion& quat);
  Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs);
  Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs);
  Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs);

  bool operator==(const Quaternion& lhs, const Quaternion& rhs);
  bool operator!=(const Quaternion& lhs, const Quaternion& rhs);
};
