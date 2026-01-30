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
