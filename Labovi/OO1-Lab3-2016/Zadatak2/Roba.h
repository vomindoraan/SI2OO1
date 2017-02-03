#pragma once

#include <iostream>

class Roba {
public:
	virtual double vrednost() const = 0;
	
	virtual Roba* kopiraj() const = 0;
	
	friend std::ostream& operator<<(std::ostream& os, const Roba& r)
	{
		r.ispis(os);
		return os;
	}

protected:
	virtual void ispis(std::ostream& os) const = 0;
};