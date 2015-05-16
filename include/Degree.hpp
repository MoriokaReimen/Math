#pragma once

namespace Math
{

struct Degree
{
	double val{0.0};
	Degree() = default;
	Degree(const double& num);
  Degree& operator+=(const Degree& lhs);
  Degree& operator-=(const Degree& lhs);
	//operator double();
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
