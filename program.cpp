#include <iostream>
#include <fstream>
#include <sstream>
#include "Data.h"
#include "Pracownik.h"
#include "Ekipa.h"

using namespace std;

void TestData()
{
	cout << "--- Test Data ---" << endl;
	Data d1;
	d1.Ustaw(1, 1, 2023);
	cout << "d1: " << d1 << endl;

	Data d2;
	d2 = d1;
	cout << "d2 (po przypisaniu d1): " << d2 << endl;

	if (d1 == d2) cout << "d1 == d2: TRUE" << endl;
	else cout << "d1 == d2: FALSE" << endl;

	d2.Ustaw(2, 2, 2024);
	cout << "d2 (po zmianie): " << d2 << endl;
	if (d1 == d2) cout << "d1 == d2: TRUE" << endl;
	else cout << "d1 == d2: FALSE" << endl;
}

void TestPracownik()
{
	cout << "\n--- Test Pracownik ---" << endl;
	Pracownik p1("Jan", "Kowalski");
	p1.DataUrodzenia(15, 5, 1990);
	cout << "p1: " << p1 << endl;

	Pracownik p2;
	p2 = p1;
	cout << "p2 (po przypisaniu p1): " << p2 << endl;

	if (p1 == p2) cout << "p1 == p2: TRUE" << endl;
	else cout << "p1 == p2: FALSE" << endl;

	p2.Imie("Adam");
	cout << "p2 (po zmianie imienia): " << p2 << endl;
	if (p1 == p2) cout << "p1 == p2: TRUE" << endl;
	else cout << "p1 == p2: FALSE" << endl;
}

void TestEkipa()
{
	cout << "\n--- Test Ekipa ---" << endl;
	// Symulacja danych wejsciowych dla Ekipy przez stringstream
	// Format: dlugosc, aktualne_wypelnienie, pracownicy...
	stringstream ss;
	ss << "2 2\nJan Kowalski 15-5-1990\nAdam Nowak 20-10-1985\n";

	Ekipa e1_loaded(0);
	ss >> e1_loaded;

	cout << "e1_loaded (wczytana z pamieci): " << endl << e1_loaded;

	Ekipa e2 = e1_loaded; // Copy constructor
	cout << "e2 (konstruktor kopiujacy z e1): " << endl << e2;

	if (e1_loaded == e2) cout << "e1 == e2: TRUE" << endl;
	else cout << "e1 == e2: FALSE" << endl;

	Ekipa e3;
	e3 = e1_loaded; // Assignment
	cout << "e3 (operator przypisania z e1): " << endl << e3;

	if (e1_loaded == e3) cout << "e1 == e3: TRUE" << endl;
	else cout << "e1 == e3: FALSE" << endl;
}

void TestPlik()
{
	cout << "\n--- Test Zapis/Odczyt Pliku ---" << endl;
	// Create data using stringstream trick
	stringstream ss;
	ss << "2 2\nJan Kowalski 15-5-1990\nAdam Nowak 20-10-1985\n";
	Ekipa e1(0);
	ss >> e1;

	// Save to file
	ofstream out("baza.txt");
	if (out.is_open())
	{
		out << e1;
		out.close();
		cout << "Zapisano do baza.txt" << endl;
	}
	else
	{
		cout << "Blad otwarcia pliku do zapisu!" << endl;
		return;
	}

	// Read from file
	ifstream in("baza.txt");
	if (in.is_open())
	{
		Ekipa e2(0);
		in >> e2;
		in.close();
		cout << "Wczytano z baza.txt:" << endl;
		cout << e2;

		if (e1 == e2) cout << "Odczyt poprawny (e1 == e2)" << endl;
		else cout << "Blad odczytu (e1 != e2)" << endl;
	}
	else
	{
		cout << "Blad otwarcia pliku do odczytu!" << endl;
	}
}

int main()
{
	TestData();
	TestPracownik();
	TestEkipa();
	TestPlik();

	return 0;
}
