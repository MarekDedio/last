#pragma once
#include "Data.h"
#include <iostream>

class Pracownik
{
private:
	char* m_pszImie;
	char* m_pszNazwisko;
	Data m_DataUrodzenia;

public:
	Pracownik(const char* imie = "", const char* nazwisko = "");
	Pracownik(const Pracownik& wzor); // Copy constructor
	~Pracownik();
	
	Pracownik& operator=(const Pracownik& wzor); // Assignment operator
	bool operator==(const Pracownik& wzor) const;

	const char* Imie() const;
	const char* Nazwisko() const;
	
	void Imie(const char* nowe_imie);
	void Nazwisko(const char* nowe_nazwisko);
	void DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok);
	
	void Wypisz() const;
	void Wpisz();
	
	bool SprawdzImie(const char* por_imie) const;
	bool SprawdzNazwisko(const char* por_nazwisko) const;

	friend std::ostream& operator<<(std::ostream& os, const Pracownik& pracownik);
	friend std::istream& operator>>(std::istream& is, Pracownik& pracownik);
};
