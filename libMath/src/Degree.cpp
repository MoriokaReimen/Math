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
	return !std::islessgreater(lhs.val, rhs.val);
}

bool operator!=(const Degree& lhs, const Degree& rhs)
{
	return std::islessgreater(lhs.val, rhs.val);
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

Degree scale(const Degree& degree, const double& num)
{
	Degree buf(num * degree.val);
	return buf;
}

double sin(const Degree& degree)
{
	return std::sin(degree.toRadian());
}

double cos(const Degree& degree)
{
	return std::cos(degree.toRadian());
}

double tan(const Degree& degree)
{
	return std::tan(degree.toRadian());
}
}
