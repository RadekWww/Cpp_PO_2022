///////////////////////////////////////////////////////////
//  Bron.h
//  Implementation of the Class Bron
//  Created on:      09-cze-2022 17:25:17
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_2F0B07DD_7CF4_45bd_8717_F1D06E39F994__INCLUDED_)
#define EA_2F0B07DD_7CF4_45bd_8717_F1D06E39F994__INCLUDED_

#include "Przedmiot.h"

class Bron : public Przedmiot
{

public:
	Bron();
	virtual ~Bron();
	int atakMax;
	int atakMin;

	Bron(string nazwa, int atak1, int atak2);
	void dajDzwiekBezVirtual();
	void dajDzwiekZVirtual();

};
#endif // !defined(EA_2F0B07DD_7CF4_45bd_8717_F1D06E39F994__INCLUDED_)
