#pragma once
#include <iostream>

class Data
{
private:
	int m_nDzien;
	int m_nMiesiac;
	int m_nRok;

public:
	Data(void);
	void Ustaw(int d, int m, int r);
	int Dzien() const;
	int Miesiac() const;
	int Rok() const;
	void Wypisz() const;
	void Wpisz();
	void Koryguj();
	bool Porownaj(const Data & wzor) const;

	Data & operator =(const Data & wzorzec);
	bool operator ==(const Data & wzorzec) const;

	friend std::ostream & operator <<(std::ostream & s, const Data & d);
	friend std::istream & operator >>(std::istream & s, Data & d);
};
