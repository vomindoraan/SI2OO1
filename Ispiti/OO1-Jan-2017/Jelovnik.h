#pragma once

#include "Jelo.h"
#include "Lista.h"

class Jelovnik : public Lista<Jelo*> {};
// Ne mora using Lista<Jelo*>::Lista jer Lista ima podraz. ktor

// Drugi nacin: using Jelovnik = Lista<Jelo*>;
