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
	virtual ~Ekipa();

	Ekipa(const Ekipa& wzor);
	Ekipa& operator=(const Ekipa& wzor);
	bool operator==(const Ekipa& wzor) const;

	void Wypelnij();
	void Modyfikuj(int index);
	int SzukajImie(const char* imie) const;
	int SzukajNazwisko(const char* nazwisko) const;
	void Wypisz() const;

	// Funkcje informacyjne
	const Pracownik* GetTablica() const;
	long int GetDlugosc() const;
	int GetAktualneWypelnienie() const;

	// Funkcje wirtualne wpisujące i wypisujące ze strumienia
	virtual void WypiszDane(std::ostream& os) const;
	virtual void WczytajDane(std::istream& is);

	friend std::ostream& operator<<(std::ostream& os, const Ekipa& ekipa);
	friend std::istream& operator>>(std::istream& is, Ekipa& ekipa);
};
