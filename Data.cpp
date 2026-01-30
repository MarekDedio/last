#include "Data.h"
#include <iostream>

using namespace std;

Data::Data(void)
{
}

void Data::Ustaw(int d, int m, int r)
{
	m_nDzien = d;
	m_nMiesiac = m;
	m_nRok = r;
	Koryguj();
}

int Data::Dzien() const
{
	return m_nDzien;
}

int Data::Miesiac() const
{
	return m_nMiesiac;
}

int Data::Rok() const
{
	return m_nRok;
}

void Data::Wypisz() const
{
	cout << m_nDzien << "-" << m_nMiesiac << "-" << m_nRok;
}

void Data::Wpisz()
{
	cout << "Podaj rok: ";
	cin >> m_nRok;
	cout << "Podaj miesiac: ";
	cin >> m_nMiesiac;
	cout << "Podaj dzien: ";
	cin >> m_nDzien;
	Koryguj();
}

void Data::Koryguj()
{
	// Correct Month first
	if (m_nMiesiac < 1) m_nMiesiac = 1;
	if (m_nMiesiac > 12) m_nMiesiac = 12;

	// Determine max days in the month
	int maxDays = 31;
	switch (m_nMiesiac)
	{
	case 4:
	case 6:
	case 9:
	case 11:
		maxDays = 30;
		break;
	case 2:
		// Check leap year
		if ((m_nRok % 4 == 0 && m_nRok % 100 != 0) || (m_nRok % 400 == 0))
			maxDays = 29;
		else
			maxDays = 28;
		break;
	}

	// Correct Day
	if (m_nDzien < 1) m_nDzien = 1;
	if (m_nDzien > maxDays) m_nDzien = maxDays;
}

bool Data::Porownaj(const Data & wzor) const
{
	if (m_nDzien == wzor.m_nDzien && 
		m_nMiesiac == wzor.m_nMiesiac && 
		m_nRok == wzor.m_nRok)
	{
		return true;
	}
	return false;
}
