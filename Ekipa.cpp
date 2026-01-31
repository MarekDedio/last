#include "Ekipa.h"
#include <iostream>

using namespace std;

Ekipa::Ekipa(long int n)
{
	dlugosc = n;
	aktualne_wypelnienie = 0;
	if (n > 0)
		tablica = new Pracownik[n];
	else
		tablica = nullptr;
}

Ekipa::~Ekipa()
{
	delete [] tablica;
}

Ekipa::Ekipa(const Ekipa& wzor)
{
	dlugosc = wzor.dlugosc;
	aktualne_wypelnienie = wzor.aktualne_wypelnienie;
	if (dlugosc > 0)
	{
		tablica = new Pracownik[dlugosc];
		for (int i = 0; i < aktualne_wypelnienie; i++)
		{
			tablica[i] = wzor.tablica[i];
		}
	}
	else
	{
		tablica = nullptr;
	}
}

Ekipa& Ekipa::operator=(const Ekipa& wzor)
{
	if (this == &wzor) return *this;

	delete [] tablica;

	dlugosc = wzor.dlugosc;
	aktualne_wypelnienie = wzor.aktualne_wypelnienie;

	if (dlugosc > 0)
	{
		tablica = new Pracownik[dlugosc];
		for (int i = 0; i < aktualne_wypelnienie; i++)
		{
			tablica[i] = wzor.tablica[i];
		}
	}
	else
	{
		tablica = nullptr;
	}

	return *this;
}

bool Ekipa::operator==(const Ekipa& wzor) const
{
	if (aktualne_wypelnienie != wzor.aktualne_wypelnienie) return false;

	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		if (!(tablica[i] == wzor.tablica[i]))
			return false;
	}
	return true;
}

void Ekipa::Wypelnij()
{
	if (aktualne_wypelnienie < dlugosc)
	{
		cout << "Wypelnianie pracownika nr " << aktualne_wypelnienie + 1 << endl;
		tablica[aktualne_wypelnienie].Wpisz();
		aktualne_wypelnienie++;
	}
	else
	{
		cout << "Tablica pelna!" << endl;
	}
}

void Ekipa::Modyfikuj(int index)
{
	if (index >= 0 && index < aktualne_wypelnienie)
	{
		cout << "Modyfikacja pracownika nr " << index + 1 << endl;
		tablica[index].Wpisz();
	}
	else
	{
		cout << "Nieprawidlowy indeks!" << endl;
	}
}

int Ekipa::SzukajImie(const char* imie) const
{
	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		if (tablica[i].SprawdzImie(imie))
			return i;
	}
	return -1;
}

int Ekipa::SzukajNazwisko(const char* nazwisko) const
{
	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		if (tablica[i].SprawdzNazwisko(nazwisko))
			return i;
	}
	return -1;
}

void Ekipa::Wypisz() const
{
	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		cout << "Pracownik " << i << ": ";
		tablica[i].Wypisz();
		cout << endl;
	}
}

const Pracownik* Ekipa::GetTablica() const
{
	return tablica;
}

long int Ekipa::GetDlugosc() const
{
	return dlugosc;
}

int Ekipa::GetAktualneWypelnienie() const
{
	return aktualne_wypelnienie;
}

void Ekipa::WypiszDane(ostream& os) const
{
	os << dlugosc << endl;
	os << aktualne_wypelnienie << endl;
	for (int i = 0; i < aktualne_wypelnienie; i++)
	{
		os << tablica[i] << endl;
	}
}

void Ekipa::WczytajDane(istream& is)
{
	long int nowa_dlugosc;
	int nowe_wypelnienie;

	if (!(is >> nowa_dlugosc)) return; // If initial read fails
	if (!(is >> nowe_wypelnienie)) return;

	if (nowa_dlugosc < 0) nowa_dlugosc = 0;
	if (nowe_wypelnienie < 0) nowe_wypelnienie = 0;
	if (nowe_wypelnienie > nowa_dlugosc) nowe_wypelnienie = nowa_dlugosc;

	delete [] tablica;
	dlugosc = nowa_dlugosc;
	aktualne_wypelnienie = 0;

	if (dlugosc > 0)
	{
		tablica = new Pracownik[dlugosc];
		for (int i = 0; i < nowe_wypelnienie; i++)
		{
			is >> tablica[i];
			aktualne_wypelnienie++;
		}
	}
	else
	{
		tablica = nullptr;
	}
}

ostream& operator<<(ostream& os, const Ekipa& ekipa)
{
	ekipa.WypiszDane(os);
	return os;
}

istream& operator>>(istream& is, Ekipa& ekipa)
{
	ekipa.WczytajDane(is);
	return is;
}
