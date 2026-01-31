#include "Brygada.h"
#include <iostream>

using namespace std;

Brygada::Brygada(long int n, int id)
	: Ekipa(n), nr_ID(id)
{
	Kierownik = new Pracownik();
}

Brygada::Brygada(const Brygada& wzor)
	: Ekipa(wzor), nr_ID(wzor.nr_ID)
{
	if (wzor.Kierownik)
	{
		Kierownik = new Pracownik(*wzor.Kierownik);
	}
	else
	{
		Kierownik = new Pracownik();
	}
}

Brygada::~Brygada()
{
	delete Kierownik;
}

const Pracownik* Brygada::GetKierownik() const
{
	return Kierownik;
}

int Brygada::GetID() const
{
	return nr_ID;
}

void Brygada::SetKierownik(const Pracownik& p)
{
	if (Kierownik)
	{
		*Kierownik = p;
	}
	else
	{
		Kierownik = new Pracownik(p);
	}
}

void Brygada::WypiszDane(ostream& os) const
{
	Ekipa::WypiszDane(os);
	os << nr_ID << endl;
	if (Kierownik)
	{
		os << 1 << endl;
		os << *Kierownik << endl;
	}
	else
	{
		os << 0 << endl;
	}
}

void Brygada::WczytajDane(istream& is)
{
	Ekipa::WczytajDane(is);

	int tempID;
	if (!(is >> tempID)) return;
	// Cannot assign to const nr_ID, so we just consume the stream.

	int hasManager;
	if (!(is >> hasManager)) return;

	if (hasManager)
	{
		if (!Kierownik) Kierownik = new Pracownik();
		is >> *Kierownik;
	}
	else
	{
		delete Kierownik;
		Kierownik = nullptr;
	}
}
