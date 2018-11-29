#pragma once

#include <stdexcept>
#include <cmath>

class Polje {
public:
	Polje(char kol, int red)
		: kol_(kol), red_(red)
	{
		if (kol < 'A' || kol > 'H' || red < 1 || red > 8) {
			throw std::invalid_argument("kol mora biti od 'A' do 'H', red od 1 do 8");
		}
	}

	char kol()     const { return kol_; }
	int  kol_idx() const { return kol_ - 'A'; }
	char red()     const { return red_; }

	bool operator==(const Polje& p) const
	{
		return kol_ == p.kol_ && red_ == p.red_;
	}

	bool operator+(const Polje& p) const
	{
		return kol_ == p.kol_ || red_ == p.red_;
	}

	bool operator/(const Polje& p) const
	{
		return std::abs(red_ - p.red_) == std::abs(kol_ - p.kol_);
	}

private:
	char kol_;
	int  red_;
};
