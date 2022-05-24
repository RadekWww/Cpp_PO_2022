///////////////////////////////////////////////////////////
//  Bron .h
//  Implementation of the Class Bron
//  Created on:      24-maj-2022 16:52:54
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_3056BB18_2E83_4bbb_BF54_08A9AFEDD947__INCLUDED_)
#define EA_3056BB18_2E83_4bbb_BF54_08A9AFEDD947__INCLUDED_

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
#endif // !defined(EA_3056BB18_2E83_4bbb_BF54_08A9AFEDD947__INCLUDED_)
