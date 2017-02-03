#ifndef _MERENJE_H_
#define _MERENJE_H_

#include <cmath>
#include <iostream>

class Merenje {
public:
	explicit Merenje(double temp = 20.0, double x = 0, double y = 0) :
		temp_(temp), x_(x), y_(y)
	{}

	double temp() const { return temp_; }
	double x() const { return x_; }
	double y() const { return y_; }

	double dist(const Merenje& other) const
	{
		auto dx = x_-other.x_, dy = y_-other.y_;
		return std::sqrt(dx*dx + dy*dy);
	}

	friend std::istream& operator>>(std::istream& is, Merenje& m)
	{
		return is >> m.temp_ >> m.x_ >> m.y_;
	}

	friend std::ostream& operator<<(std::ostream& os, const Merenje& m)
	{
		return os << '[' << m.temp_ << ',' << m.x_ << ',' << m.y_ << ']';
	}


private:
	double temp_;
	double x_, y_;
};

#endif
