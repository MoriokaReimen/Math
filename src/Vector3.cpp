#include "Vector3.hpp"

namespace Math {
  Vector3::Vector3(const double& a, const double& b, const double& c)
  : x(a), y(b), z(c)
  {
    return;
  }

  Vector3 Vector3::operator+=(const Vector3& rhs)
  {
    this->x += rhs.x;
    this->y += rhs.y;
    this->z += rhs.z;
    return *this;
  }

  Vector3 Vector3::operator-=(const Vector3& rhs)
  {
    this->x -= rhs.x;
    this->y -= rhs.y;
    this->z -= rhs.z;
    return *this;
  }

  Vector3 Vector3::operator*=(const double& rhs)
  {
    this->x *= rhs;
    this->y *= rhs;
    this->z *= rhs;
    return *this;
  }

  Vector3 Vector3::operator/=(const double& rhs)
  {
    this->x /= rhs;
    this->y /= rhs;
    this->z /= rhs;
    return *this;
  }

  Vector3 operator+(const Vector3& lhs, const Vector3& rhs)
  {
    Vector3 buf(lhs.x + rhs.x, lhs.y + rhs.y, lhs.z + rhs.z);
    return buf;
  }

  Vector3 operator-(const Vector3& lhs, const Vector3& rhs)
  {
    Vector3 buf(lhs.x - rhs.x, lhs.y - rhs.y, lhs.z - rhs.z);
    return buf;
  }

  Vector3 operator*(const Vector3& lhs, const double& rhs)
  {
    Vector3 buf(lhs.x * rhs, lhs.y * rhs, lhs.z * rhs);
    return buf;
  }

  Vector3 operator/(const Vector3& lhs, const double& rhs)
  {
    Vector3 buf(lhs.x / rhs, lhs.y / rhs, lhs.z / rhs);
    return buf;
  }

  bool operator==(const Vector3& lhs, const Vector3& rhs)
  {
    if(std::islessgreater(lhs.x, rhs.x)) return false;
    if(std::islessgreater(lhs.y, rhs.y)) return false;
    if(std::islessgreater(lhs.z, rhs.z)) return false;
    return true;
  }

  bool operator!=(const Vector3& lhs, const Vector3& rhs)
  {
    if(std::islessgreater(lhs.x, rhs.x)) return true;
    if(std::islessgreater(lhs.y, rhs.y)) return true;
    if(std::islessgreater(lhs.z, rhs.z)) return true;
    return false;
  }

  double length(const Vector3& lhs)
  {
    double len =
    std::sqrt(
      (lhs.x * lhs.x) +
      (lhs.y * lhs.y) +
      (lhs.z * lhs.z)
    );
    return len;
  }

  Vector3 normalize(const Vector3& lhs)
  {
    Vector3 buf;
    if(length(lhs) != 0.0)
      buf = lhs / length(lhs);
    return buf;
  }

  double dot(const Vector3& lhs, const Vector3& rhs)
  {
    double buf(
    (lhs.x * rhs.x) +
    (lhs.y * rhs.y) +
    (lhs.z * rhs.z));
    return buf;
  }

  Vector3 cross(const Vector3& lhs, const Vector3& rhs)
  {
    Vector3 buf(
      (lhs.y * rhs.z) - (lhs.z * rhs.y),
      (lhs.z * rhs.x) - (lhs.x * rhs.z),
      (lhs.x * rhs.y) - (lhs.y * rhs.x)
    );
    return buf;
  }
};
