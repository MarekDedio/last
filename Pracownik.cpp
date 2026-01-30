#define _CRT_SECURE_NO_WARNINGS
#include "Pracownik.h"
#include <iostream>
#include <cstring>

using namespace std;

Pracownik::Pracownik(const char* imie, const char* nazwisko)
{
	m_pszImie = nullptr;
	m_pszNazwisko = nullptr;
	Imie(imie);
	Nazwisko(nazwisko);
}

Pracownik::Pracownik(const Pracownik& wzor)
{
	m_pszImie = nullptr;
	m_pszNazwisko = nullptr;
	Imie(wzor.Imie());
	Nazwisko(wzor.Nazwisko());
	m_DataUrodzenia = wzor.m_DataUrodzenia;
}

Pracownik::~Pracownik()
{
	delete [] m_pszImie;
	delete [] m_pszNazwisko;
}

Pracownik& Pracownik::operator=(const Pracownik& wzor)
{
	if (this == &wzor) return *this;
	Imie(wzor.Imie());
	Nazwisko(wzor.Nazwisko());
	m_DataUrodzenia = wzor.m_DataUrodzenia;
	return *this;
}

bool Pracownik::operator==(const Pracownik& wzor) const
{
	return (strcmp(m_pszImie, wzor.m_pszImie) == 0 &&
		strcmp(m_pszNazwisko, wzor.m_pszNazwisko) == 0 &&
		m_DataUrodzenia == wzor.m_DataUrodzenia);
}

const char* Pracownik::Imie() const
{
	return m_pszImie;
}

const char* Pracownik::Nazwisko() const
{
	return m_pszNazwisko;
}

void Pracownik::Imie(const char* nowe_imie)
{
	if (m_pszImie == nowe_imie) return;
	delete [] m_pszImie;
	m_pszImie = new char[strlen(nowe_imie) + 1];
	strcpy(m_pszImie, nowe_imie);
}

void Pracownik::Nazwisko(const char* nowe_nazwisko)
{
	if (m_pszNazwisko == nowe_nazwisko) return;
	delete [] m_pszNazwisko;
	m_pszNazwisko = new char[strlen(nowe_nazwisko) + 1];
	strcpy(m_pszNazwisko, nowe_nazwisko);
}

void Pracownik::DataUrodzenia(int nowy_dzien, int nowy_miesiac, int nowy_rok)
{
	m_DataUrodzenia.Ustaw(nowy_dzien, nowy_miesiac, nowy_rok);
}

void Pracownik::Wypisz() const
{
	cout << m_pszImie << " " << m_pszNazwisko << " ";
	m_DataUrodzenia.Wypisz();
}

void Pracownik::Wpisz()
{
	char tempImie[100];
	char tempNazwisko[100];
	int d, m, r;

	cout << "Podaj imie: ";
	cin >> tempImie;
	Imie(tempImie);

	cout << "Podaj nazwisko: ";
	cin >> tempNazwisko;
	Nazwisko(tempNazwisko);

	cout << "Data urodzenia:" << endl;
	cout << "Podaj rok: ";
	cin >> r;
	cout << "Podaj miesiac: ";
	cin >> m;
	cout << "Podaj dzien: ";
	cin >> d;
	DataUrodzenia(d, m, r);
}

bool Pracownik::SprawdzImie(const char* por_imie) const
{
	if (!m_pszImie) return false;
	return (strcmp(m_pszImie, por_imie) == 0);
}

bool Pracownik::SprawdzNazwisko(const char* por_nazwisko) const
{
	if (!m_pszNazwisko) return false;
	return (strcmp(m_pszNazwisko, por_nazwisko) == 0);
}

ostream& operator<<(ostream& os, const Pracownik& p)
{
	os << p.m_pszImie << " " << p.m_pszNazwisko << " " << p.m_DataUrodzenia;
	return os;
}

istream& operator>>(istream& is, Pracownik& p)
{
	char tempImie[100];
	char tempNazwisko[100];

	is >> tempImie >> tempNazwisko >> p.m_DataUrodzenia;

	p.Imie(tempImie);
	p.Nazwisko(tempNazwisko);

	return is;
}
