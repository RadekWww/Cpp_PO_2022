///////////////////////////////////////////////////////////
//  Postac.h
//  Implementation of the Class Postac
//  Created on:      09-cze-2022 17:25:20
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_79D9641D_936B_4937_8F8A_7291FB8084FF__INCLUDED_)
#define EA_79D9641D_936B_4937_8F8A_7291FB8084FF__INCLUDED_

#include "Przedmiot.h"
#include <vector>
class Postac
{

public:
	Postac();
	virtual ~Postac();
	vector<Przedmiot*> plecak;
	Przedmiot* rekaLewa;
	Przedmiot* rekaPrawa;

	Postac(string n, int zycie, int mana, int atakMax, int atakMin);
	bool czyZyje();
	void dodajDoPlecaka(Przedmiot* p);
	void ustawBron(Przedmiot* p, bool CzyPrawaReka);
	int generujPktAtaku();
	string generujPrzywitanie();
	int obliczPktAtaku();
	string pobierzNazwe();
	void pokazStatystyki();
	void przedstawSie();
	void przywitajSie();
	void ustawNazwe(string n);
	void wyswietlOpisPostacZPrzedmiotami();
	void zaatakuj(Postac* przeciwnik);
	void zaprosDoWalki(Postac* przeciwnik);
	static Postac* generujPostac();

protected:
	string nazwa;
	int pktAtakuMax;
	int pktAtakuMin;
	int pktZycia;
	int poziom;

};
#endif // !defined(EA_79D9641D_936B_4937_8F8A_7291FB8084FF__INCLUDED_)
