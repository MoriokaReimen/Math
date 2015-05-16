#include "Radian.hpp"

namespace Math
{

Radian::Radian(const double& num)
{
	this->val = num;
	return;
}

Radian& Radian::operator+=(const Radian& lhs)
{
	this->val += lhs.val;
	return *this;
}

Radian& Radian::operator-=(const Radian& lhs)
{
	this->val -= lhs.val;
	return *this;
}

Radian scale(const double& num, const Radian& degree)
{
	Radian buf(num * degree.val);
	return buf;
}

Radian operator+(const Radian& lhs, const Radian& rhs)
{
	Radian buf(lhs.val + rhs.val);
	return buf;
}

Radian operator-(const Radian& lhs, const Radian& rhs)
{
	Radian buf(lhs.val - rhs.val);
	return buf;
}

bool operator==(const Radian& lhs, const Radian& rhs)
{
	return bool{lhs.val == rhs.val};
}

bool operator!=(const Radian& lhs, const Radian& rhs)
{
	return bool{lhs.val != rhs.val};
}

bool operator>(const Radian& lhs, const Radian& rhs)
{
	return bool{lhs.val > rhs.val};
}

bool operator<(const Radian& lhs, const Radian& rhs)
{
	return bool{lhs.val < rhs.val};
}

bool operator<=(const Radian& lhs, const Radian& rhs)
{
	return bool{lhs.val <= rhs.val};
}

bool operator>=(const Radian& lhs, const Radian& rhs)
{
	return bool{lhs.val >= rhs.val};
}

}
