#pragma once
#include "Pracownik.h"
#include <iostream>

class Ekipa
{
private:
	Pracownik* tablica;
	long int dlugosc;
	int aktualne_wypelnienie;

public:
	Ekipa(long int n = 0);
	~Ekipa();

	Ekipa(const Ekipa& wzor);
	Ekipa& operator=(const Ekipa& wzor);
	bool operator==(const Ekipa& wzor) const;

	void Wypelnij();
	void Modyfikuj(int index);
	int SzukajImie(const char* imie) const;
	int SzukajNazwisko(const char* nazwisko) const;
	void Wypisz() const;

	friend std::ostream& operator<<(std::ostream& os, const Ekipa& ekipa);
	friend std::istream& operator>>(std::istream& is, Ekipa& ekipa);
};
