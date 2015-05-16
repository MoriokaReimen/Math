#pragma once
#include"Radian.hpp"
#include <cmath>
#define _USE_MATH_DEFINES

namespace Math
{

class Degree
{
public:
	double val{0.0};
	Degree() = default;
	Degree(const double& num);
	double toRadian() const;
	void fromRadian(const double& radian);
  Degree& operator+=(const Degree& lhs);
  Degree& operator-=(const Degree& lhs);
	operator double()
	{
		return double(this->val);
	}
};

Degree scale(const double& num, const Degree& degree);
Degree operator+(const Degree& lhs, const Degree& rhs);
Degree operator-(const Degree& lhs, const Degree& rhs);

bool operator==(const Degree& lhs, const Degree& rhs);
bool operator!=(const Degree& lhs, const Degree& rhs);
bool operator>(const Degree& lhs, const Degree& rhs);
bool operator<(const Degree& lhs, const Degree& rhs);
bool operator<=(const Degree& lhs, const Degree& rhs);
bool operator>=(const Degree& lhs, const Degree& rhs);

}
