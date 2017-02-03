#pragma once

#include <iostream>
#include <cmath>

class MaterijalnaTacka {
public:
	static const double GAMA;

	explicit MaterijalnaTacka(double m = 1, double x = 0, double y = 0, double z = 0) :
		m_(m), x_(x), y_(y), z_(z)
	{}

	double rast(const MaterijalnaTacka& mt) const
	{
		auto dx = x_-mt.x_, dy = y_-mt.y_, dz = z_-mt.z_;
		return std::sqrt(dx*dx + dy*dy + dz*dz);
	}

	double sila(const MaterijalnaTacka& mt) const
	{
		auto r = rast(mt);
		return GAMA * m_ * mt.m_ / (r*r);
	}

	void ispis() const
	{
		std::cout << "MT[" << m_ << ", (" << x_ << ", " << y_ << ", " << z_ << ")]";
	}

	void unos()
	{
		std::cin >> m_ >> x_ >> y_ >> z_;
	}

private:
	double m_;
	double x_, y_, z_;
};

const double MaterijalnaTacka::GAMA = 6.67e-11;
