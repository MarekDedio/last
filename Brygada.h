#pragma once
#include "Ekipa.h"
#include "Pracownik.h"
#include <iostream>

class Brygada : public Ekipa
{
private:
	Pracownik* Kierownik;
	const int nr_ID;

public:
	// Konstruktor parametrowy domyślny
	Brygada(long int n = 0, int id = 0);

	// Konstruktor kopiujący
	Brygada(const Brygada& wzor);

	// Destruktor
	virtual ~Brygada();

	// Funkcje informacyjne
	const Pracownik* GetKierownik() const;
	int GetID() const;

	// Funkcje ustawiające
	void SetKierownik(const Pracownik& p);

	// Funkcje wirtualne
	virtual void WypiszDane(std::ostream& os) const;
	virtual void WczytajDane(std::istream& is);
};
