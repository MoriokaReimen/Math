#include "Degree.hpp"

namespace Math
{

Degree::Degree(const double& num)
{
	this->val = num;
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

}
