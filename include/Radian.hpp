#pragma once
#include "Degree.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

namespace Math
{

struct Radian
{
	double val{0.0};
	Radian() = default;
	Radian(const double& num);
  Radian& operator+=(const Radian& lhs);
  Radian& operator-=(const Radian& lhs);
	operator double()
	{
    /* temporary convert to degree in double */
		return double(this->val) / M_PI * 180.0;
	}
};

Radian scale(const double& num, const Radian& degree);
Radian operator+(const Radian& lhs, const Radian& rhs);
Radian operator-(const Radian& lhs, const Radian& rhs);

bool operator==(const Radian& lhs, const Radian& rhs);
bool operator!=(const Radian& lhs, const Radian& rhs);
bool operator>(const Radian& lhs, const Radian& rhs);
bool operator<(const Radian& lhs, const Radian& rhs);
bool operator<=(const Radian& lhs, const Radian& rhs);
bool operator>=(const Radian& lhs, const Radian& rhs);

}
