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

ostream& operator<<(ostream& os, const Ekipa& ekipa)
{
	os << ekipa.dlugosc << endl;
	os << ekipa.aktualne_wypelnienie << endl;
	for (int i = 0; i < ekipa.aktualne_wypelnienie; i++)
	{
		os << ekipa.tablica[i] << endl;
	}
	return os;
}

istream& operator>>(istream& is, Ekipa& ekipa)
{
	long int nowa_dlugosc;
	int nowe_wypelnienie;

	if (!(is >> nowa_dlugosc)) return is;
	if (!(is >> nowe_wypelnienie)) return is;

	if (nowa_dlugosc < 0) nowa_dlugosc = 0;
	if (nowe_wypelnienie < 0) nowe_wypelnienie = 0;
	if (nowe_wypelnienie > nowa_dlugosc) nowe_wypelnienie = nowa_dlugosc;

	delete [] ekipa.tablica;
	ekipa.dlugosc = nowa_dlugosc;
	ekipa.aktualne_wypelnienie = 0; // We will increment as we read

	if (ekipa.dlugosc > 0)
	{
		ekipa.tablica = new Pracownik[ekipa.dlugosc];
		for (int i = 0; i < nowe_wypelnienie; i++)
		{
			is >> ekipa.tablica[i];
			ekipa.aktualne_wypelnienie++;
		}
	}
	else
	{
		ekipa.tablica = nullptr;
	}

	return is;
}
