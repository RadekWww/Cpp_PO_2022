///////////////////////////////////////////////////////////
//  Wojownik.h
//  Implementation of the Class Wojownik
//  Created on:      09-cze-2022 17:25:25
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_CD7AB693_4AB1_48f8_9FEE_E59BF2EB2AA4__INCLUDED_)
#define EA_CD7AB693_4AB1_48f8_9FEE_E59BF2EB2AA4__INCLUDED_

#include "Postac.h"

class Wojownik : public Postac
{

public:
	Wojownik();
	virtual ~Wojownik();

	Wojownik(string nazwa, int z, int poziom, int atak1, int atak2);

};
#endif // !defined(EA_CD7AB693_4AB1_48f8_9FEE_E59BF2EB2AA4__INCLUDED_)
