#ifndef _RESISTOR_H_
#define _RESISTOR_H_

#include <iostream>

class Resistor {
public:
	typedef double res_type;

	explicit Resistor(res_type resistance) :
		resistance_(resistance)
	{}

	virtual ~Resistor() {}

	virtual res_type getResistance() const
	{
		return resistance_;
	}

	friend std::ostream& operator<<(std::ostream& os, Resistor& res)
	{
		res.writeToStream(os);
		return os;
	}

protected:
	virtual void setResistance(res_type resistance)
	{
		resistance_ = resistance;
	}

	virtual void writeToStream(std::ostream& os) const = 0;

private:
	res_type resistance_;
};

#endif
