#ifndef _POGRESNA_BOJA_H_
#define _POGRESNA_BOJA_H_

#include <exception>

class PogresnaBoja : public std::exception {
public:
	PogresnaBoja() : std::exception("pogresna boja") {}
	// "pisanje teksta poruke" koje se trazi u zadatku se radi kao: cout << e.what()
};

#endif // !_POGRESNA_BOJA_H_
