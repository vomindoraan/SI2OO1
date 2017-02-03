#ifndef _SERIAL_LINK_H_
#define _SERIAL_LINK_H_

#include "CompositeResistor.h"

class SerialLink : public CompositeResistor {
public:
	explicit SerialLink(size_type capacity)
		: CompositeResistor(capacity)
	{}

protected:
	void updateResistance(Resistor& res) override
	{
		setResistance(getResistance() + res.getResistance());
	}

	void writeToStream(std::ostream& os) const override
	{
		os << "red";
		CompositeResistor::writeToStream(os);
	}
};

#endif
