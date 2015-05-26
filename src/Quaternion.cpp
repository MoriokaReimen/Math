#include "Quaternion.hpp"

namespace Math {

Quaternion::Quaternion(const double& w, const double& x,
  const double& y, const double& z)
    : w(w), x(x), y(y), z(z)
{
    return;
}

Quaternion::Quaternion(const Degree& angle, const Vector3& axis)
{
  this->fromAngleAxis(angle, axis);
  return;
}

Quaternion::Quaternion(const Vector3& a, const Vector3& b)
{
  auto angle = getAngle(a, b);
  auto axis = getNormal(a, b);
  this->fromAngleAxis(angle, axis);
  return;
}

void Quaternion::set(const double& w, const double& x,
  const double& y, const double& z)
{
  this->w = w;
  this->x = x;
  this->y = y;
  this->z = z;

  return;
}

void Quaternion::toAngleAxis(Degree& angle, Vector3& axis)
{
    angle.fromRadian(2.0 * std::acos(this->w));
    double s = 1.0 - this->w * this->w;
    if(s > 0.001) {
        axis.x    = this->x / std::sqrt(1 - this->w * this->w);
        axis.y    = this->y / std::sqrt(1 - this->w * this->w);
        axis.z    = this->z / std::sqrt(1 - this->w * this->w);
        return;
    } else {
        axis.x = 1.0;
        axis.y = 0.0;
        axis.z = 0.0;
        return;
    }
}

void Quaternion::fromAngleAxis(const Degree& angle, const Vector3& axis)
{
    auto unit_axis = normalize(axis);
    double s = Math::sin(scale(angle, 0.5));
    this->w = Math::cos(scale(angle, 0.5));
    this->x = unit_axis.x * s;
    this->y = unit_axis.y * s;
    this->z = unit_axis.z * s;
    return;
}

void Quaternion::fromVectors(const Vector3& a, const Vector3& b)
{
  auto angle = getAngle(a, b);
  auto axis = getNormal(a, b);
  this->fromAngleAxis(angle, axis);
  return;
}

void Quaternion::toRPY(Degree& roll, Degree& pitch, Degree& yaw)
{
    roll = std::atan2(2 * (this->w * this->x + this->y * this->z),
            1-2*(this->x*this->x+this->y*this->y));

    pitch = std::asin(2 * (this->w * this->y + this->z * this->x));

    yaw = std::atan2(2 * (this->w * this->z + this->x * this->y),
            1-2*(this->y*this->y+this->z*this->z));
    return;
}

void Quaternion::fromRPY(const Degree& roll, const Degree& pitch, const Degree& yaw)
{
    static const Vector3 x_axis(1.0,0.0,0.0), y_axis(0.0, 1.0, 0.0), z_axis(0.0, 0.0, 1.0);
    Quaternion qroll(roll, x_axis), qpitch(pitch, y_axis), qyaw(yaw, z_axis);
    *this = qroll * qpitch * qyaw;
    return;
}

double Quaternion::getNorm() const
{
  double length = std::sqrt(
    (this->w * this->w) +
    (this->x * this->x) +
    (this->y * this->y) +
    (this->z * this->z)
  );
  return length;
}

Quaternion Quaternion::operator+=(const Quaternion& rhs)
{
  this->w += rhs.w;
  this->x += rhs.x;
  this->y += rhs.y;
  this->z += rhs.z;
  return *this;
}

Quaternion Quaternion::operator-=(const Quaternion& rhs)
{
  this->w -= rhs.w;
  this->x -= rhs.x;
  this->y -= rhs.y;
  this->z -= rhs.z;
  return *this;
}

Quaternion Quaternion::operator*=(const Quaternion& rhs)
{
  double x, y, z, w;

  w = (this->w * rhs.w)
    -(this->x * rhs.x)
    -(this->y * rhs.y)
    -(this->z * rhs.z);

  x = (this->w * rhs.x)
    +(this->x * rhs.w)
    -(this->y * rhs.z)
    +(this->z * rhs.y);

  y = (this->w * rhs.y)
    +(this->x * rhs.z)
    +(this->y * rhs.w)
    -(this->z * rhs.x);

  z = (this->w * rhs.z)
    -(this->x * rhs.y)
    +(this->y * rhs.x)
    +(this->z * rhs.w);

  this->set(w, x, y, z);

  return *this;
}

Quaternion scale(const Quaternion& quat, const double& num)
{
  Quaternion buf(quat.w * num, quat.x * num,
    quat.y * num, quat.z * num);

  return buf;
}

Quaternion normalize(const Quaternion& quat)
{
  Quaternion buf;
  if(quat.getNorm() != 0.0)
    buf = scale(quat, 1.0 / quat.getNorm());
  return buf;
}

Quaternion operator+(const Quaternion& lhs, const Quaternion& rhs)
{
  Quaternion buf(lhs.w + rhs.w, lhs.x + rhs.x,
  lhs.y + rhs.y, lhs.z + rhs.z);

  return buf;
}

Quaternion operator-(const Quaternion& lhs, const Quaternion& rhs)
{
  Quaternion buf(lhs.w - rhs.w, lhs.x - rhs.x,
  lhs.y - rhs.y, lhs.z - rhs.z);

  return buf;
}

Quaternion operator*(const Quaternion& lhs, const Quaternion& rhs)
{
  Quaternion buf;

  buf.w = (lhs.w * rhs.w)
    -(lhs.x * rhs.x)
    -(lhs.y * rhs.y)
    -(lhs.z * rhs.z);

  buf.x = (lhs.w * rhs.x)
    +(lhs.x * rhs.w)
    -(lhs.y * rhs.z)
    +(lhs.z * rhs.y);

  buf.y = (lhs.w * rhs.y)
    +(lhs.x * rhs.z)
    +(lhs.y * rhs.w)
    -(lhs.z * rhs.x);

  buf.z = (lhs.w * rhs.z)
    -(lhs.x * rhs.y)
    +(lhs.y * rhs.x)
    +(lhs.z * rhs.w);

  return buf;
}

bool operator==(const Quaternion& lhs, const Quaternion& rhs)
{
    if(std::islessgreater(lhs.w, rhs.w)) return false;
    if(std::islessgreater(lhs.x, rhs.x)) return false;
    if(std::islessgreater(lhs.y, rhs.y)) return false;
    if(std::islessgreater(lhs.z, rhs.z)) return false;
    return true;
}

bool operator!=(const Quaternion& lhs, const Quaternion& rhs)
{
    if(std::islessgreater(lhs.w, rhs.w)) return true;
    if(std::islessgreater(lhs.x, rhs.x)) return true;
    if(std::islessgreater(lhs.y, rhs.y)) return true;
    if(std::islessgreater(lhs.z, rhs.z)) return true;
    return false;
}

/* implement someday
void toMat(GLfloat* mat)
{
  mat[0] = w * w + x * x - y * y - z * z;
  mat[1] = 2 * (x * y + w * z);
  mat[2] = 2 * (x * z - w * y);
  mat[3] = 2 * (x * z - w * y);
}
*/
};
