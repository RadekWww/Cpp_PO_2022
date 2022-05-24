///////////////////////////////////////////////////////////
//  Przedmiot.h
//  Implementation of the Class Przedmiot
//  Created on:      24-maj-2022 16:53:00
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_54B99ED1_6876_40f6_A961_3F3816E270DF__INCLUDED_)
#define EA_54B99ED1_6876_40f6_A961_3F3816E270DF__INCLUDED_

#include <iostream>
#include <rodzajPrzedmiotu.h>

using namespace std;

class Przedmiot
{

public:
	Przedmiot();
	virtual ~Przedmiot();
	string nazwa;
	int typ1;
	rodzajPrzedmiotu typ;

	Przedmiot(string nazwa);
void dajDzwiekBezVirtual();
virtual	void dajDzwiekZVirtual();

};
#endif // !defined(EA_54B99ED1_6876_40f6_A961_3F3816E270DF__INCLUDED_)
