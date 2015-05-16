#include "Degree.hpp"

namespace Math
{

Degree::Degree(const double& num)
{
	this->val = num;
	return;
}

double Degree::toRadian() const
{
	return this->val /180.0 * M_PI;
}

void Degree::fromRadian(const double& radian)
{
	this->val = radian / M_PI * 180.0;
	return;
}

Degree& Degree::operator+=(const Degree& lhs)
{
	this->val += lhs.val;
	return *this;
}

Degree& Degree::operator-=(const Degree& lhs)
{
	this->val -= lhs.val;
	return *this;
}

Degree scale(const double& num, const Degree& degree)
{
	Degree buf(num * degree.val);
	return buf;
}

Degree operator+(const Degree& lhs, const Degree& rhs)
{
	Degree buf(lhs.val + rhs.val);
	return buf;
}

Degree operator-(const Degree& lhs, const Degree& rhs)
{
	Degree buf(lhs.val - rhs.val);
	return buf;
}

bool operator==(const Degree& lhs, const Degree& rhs)
{
	return bool{lhs.val == rhs.val};
}

bool operator!=(const Degree& lhs, const Degree& rhs)
{
	return bool{lhs.val != rhs.val};
}

bool operator>(const Degree& lhs, const Degree& rhs)
{
	return bool{lhs.val > rhs.val};
}

bool operator<(const Degree& lhs, const Degree& rhs)
{
	return bool{lhs.val < rhs.val};
}

bool operator<=(const Degree& lhs, const Degree& rhs)
{
	return bool{lhs.val <= rhs.val};
}

bool operator>=(const Degree& lhs, const Degree& rhs)
{
	return bool{lhs.val >= rhs.val};
}

double sin(const Degree& degree)
{
	return sin(degree.toRadian());
}
}
