#pragma once
#include "Pracownik.h"

class Ekipa
{
private:
	Pracownik* tablica;
	long int dlugosc;
	int aktualne_wypelnienie;

public:
	Ekipa(long int n = 0);
	~Ekipa();

	// Disable copying to prevent double-free
	Ekipa(const Ekipa&) = delete;
	Ekipa& operator=(const Ekipa&) = delete;

	void Wypelnij();
	void Modyfikuj(int index);
	int SzukajImie(const char* imie) const;
	int SzukajNazwisko(const char* nazwisko) const;
	void Wypisz() const;
};
