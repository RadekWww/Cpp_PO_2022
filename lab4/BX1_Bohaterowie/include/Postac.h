///////////////////////////////////////////////////////////
//  Postac.h
//  Implementation of the Class Postac
//  Created on:      24-maj-2022 16:52:57
//  Original author: Radek
///////////////////////////////////////////////////////////

#if !defined(EA_0E3C7EEB_7678_415b_9A70_96D7E70C2D41__INCLUDED_)
#define EA_0E3C7EEB_7678_415b_9A70_96D7E70C2D41__INCLUDED_

#include "Przedmiot.h"
#include <vector>


class Postac
{

public:
	Postac();
	virtual ~Postac();

	Postac(string nazwa, int z, int p, int amin, int amax);
	bool czyZyje();
	void dodajDoPlecaka(Przedmiot* p);
	int obliczPktAtaku();
	string pobierzNazwe();
	void pokazStatystyki();
	void przedstawSie();
	void przywitajSie();
	void ustawNazwe(string nowaNazwa);
	void wyswietlOpisPostacZPrzedmiotami();
	void zaatakuj(Postac* przeciwnik);
	void zaprosDoWalki(Postac* obiekPostaci);

	void ustawBron(Przedmiot* p, bool CzyPrawaReka);

	int pktAtakuMax;
	int pktAtakuMin;

	static  Postac* generujPostac();



protected:
    vector<Przedmiot*> plecak;
    Przedmiot* rekaLewa;
	Przedmiot* rekaPrawa;

	string nazwa;

	int pktZycia;
	int poziom;

	int generujPktAtaku();
	string generujPrzywitanie();
	void przyjmijUderzenie(int silaUderzenia);

};
#endif // !defined(EA_0E3C7EEB_7678_415b_9A70_96D7E70C2D41__INCLUDED_)
