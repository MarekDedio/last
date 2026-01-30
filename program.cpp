#include <iostream>
#include "Data.h"
#include "Pracownik.h"
#include "Ekipa.h"

using namespace std;

int main()
{
	cout << "--- Rozpoczynam Testy ---" << endl;

	// Test 1: Tworzenie Ekipy
	cout << "Tworze Ekipe o rozmiarze 3." << endl;
	Ekipa ekipa(3);

	// Test 2: Wypelnianie
	cout << "\nWypelnij (dodaj 2 pracownikow):" << endl;
	ekipa.Wypelnij();
	ekipa.Wypelnij();

	// Test 3: Wypisz
	cout << "\nAktualna Ekipa:" << endl;
	ekipa.Wypisz();

	// Test 4: Szukaj
	cout << "\nSzukaj 'Kowalski':" << endl;
	int idx = ekipa.SzukajNazwisko("Kowalski");
	if (idx != -1)
		cout << "Znaleziono na pozycji: " << idx << endl;
	else
		cout << "Nie znaleziono." << endl;

	cout << "Szukaj 'Nowak':" << endl;
	idx = ekipa.SzukajNazwisko("Nowak");
	if (idx != -1)
		cout << "Znaleziono na pozycji: " << idx << endl;
	else
		cout << "Nie znaleziono." << endl;

	// Test 5: Modyfikuj
	cout << "\nModyfikuj element 0:" << endl;
	ekipa.Modyfikuj(0);

	// Test 6: Wypisz po modyfikacji
	cout << "\nEkipa po modyfikacji:" << endl;
	ekipa.Wypisz();

	return 0;
}
