///////////////////////////////////////////////////////////
//  Wojownik.h
//  Implementation of the Class Wojownik
//  Created on:      24-maj-2022 16:53:05
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_5737B647_CD2F_4313_A4ED_1CD80A922754__INCLUDED_)
#define EA_5737B647_CD2F_4313_A4ED_1CD80A922754__INCLUDED_

#include "Postac.h"

class Wojownik : public Postac
{

public:
	Wojownik();
	virtual ~Wojownik();

	Wojownik(string nazwa, int z, int p, int amin, int amax);

};
#endif // !defined(EA_5737B647_CD2F_4313_A4ED_1CD80A922754__INCLUDED_)
