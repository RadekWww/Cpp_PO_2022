///////////////////////////////////////////////////////////
//  Przedmiot.h
//  Implementation of the Class Przedmiot
//  Created on:      09-cze-2022 17:25:23
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_0A3C7BBF_2CBC_4a90_ADDA_5E1B63625639__INCLUDED_)
#define EA_0A3C7BBF_2CBC_4a90_ADDA_5E1B63625639__INCLUDED_

#include <iostream>
using namespace std;

class Przedmiot
{

public:
	Przedmiot();
	virtual ~Przedmiot();
	string nazwa;
	int typ;

	Przedmiot(string nazwa);
	void dajDzwiekBezVirtual();
	virtual void dajDzwiekZVirtual();

};
#endif // !defined(EA_0A3C7BBF_2CBC_4a90_ADDA_5E1B63625639__INCLUDED_)
