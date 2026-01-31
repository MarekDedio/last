#include <iostream>
#include <fstream>
#include "Brygada.h"
#include "Pracownik.h"

using namespace std;

// Function to handle Brigade editing
void EdytujBrygade(Brygada& brygada)
{
    int opcja;
    do
    {
        cout << "\n--- Edycja Brygady (ID: " << brygada.GetID() << ") ---" << endl;
        cout << "1. Ustaw Kierownika" << endl;
        cout << "2. Dodaj Pracownika (Wypelnij)" << endl;
        cout << "3. Wypisz Brygade" << endl;
        cout << "0. Wroc" << endl;
        cout << "Wybor: ";
        cin >> opcja;

        switch (opcja)
        {
        case 1:
            {
                Pracownik p;
                cout << "Podaj dane kierownika:" << endl;
                p.Wpisz();
                brygada.SetKierownik(p);
            }
            break;
        case 2:
            brygada.Wypelnij();
            break;
        case 3:
            cout << brygada << endl;
            break;
        case 0:
            break;
        default:
            cout << "Nieznana opcja!" << endl;
        }
    } while (opcja != 0);
}

int main()
{
    // Initialize 4 brigades.
    // Since we can't easily pass IDs in array declaration in older C++,
    // we will rely on default constructor.
    // Ideally we would want distinct IDs, but the assignment constraint makes it hard
    // without C++11 initializer lists or pointers.
    // Let's assume default ID 0 is acceptable or we use a pointer array.
    // "może być tablica statyczna lub dynamiczna 4 obiektów typu Brygada"

    // Let's use dynamic array of pointers to allow initialization with IDs?
    // Or just a static array.
    // "tablica statyczna ... obiektów" -> Brygada tab[4];

    Brygada* system[4];
    for (int i = 0; i < 4; ++i)
    {
        // Allocate with capacity 5 for example, and ID = i+1
        system[i] = new Brygada(5, i + 1);
    }

    int opcja;
    do
    {
        cout << "\n=== SYSTEM 4 BRYGADOWY ===" << endl;
        cout << "1. Edycja Brygady" << endl;
        cout << "2. Wypisz Wszystkie" << endl;
        cout << "3. Zapisz do Pliku (baza.txt)" << endl;
        cout << "4. Wczytaj z Pliku (baza.txt)" << endl;
        cout << "0. Wyjscie" << endl;
        cout << "Wybor: ";
        cin >> opcja;

        switch (opcja)
        {
        case 1:
            {
                int nr;
                cout << "Wybierz brygade (1-4): ";
                cin >> nr;
                if (nr >= 1 && nr <= 4)
                {
                    EdytujBrygade(*system[nr - 1]);
                }
                else
                {
                    cout << "Nieprawidlowy numer!" << endl;
                }
            }
            break;
        case 2:
            for (int i = 0; i < 4; ++i)
            {
                cout << "\nBrygada " << i + 1 << ":" << endl;
                cout << *system[i] << endl;
            }
            break;
        case 3:
            {
                ofstream out("baza.txt");
                if (out.is_open())
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        out << *system[i] << endl;
                    }
                    out.close();
                    cout << "Zapisano dane." << endl;
                }
                else
                {
                    cout << "Blad zapisu!" << endl;
                }
            }
            break;
        case 4:
            {
                ifstream in("baza.txt");
                if (in.is_open())
                {
                    for (int i = 0; i < 4; ++i)
                    {
                        in >> *system[i];
                    }
                    in.close();
                    cout << "Wczytano dane." << endl;
                }
                else
                {
                    cout << "Blad odczytu!" << endl;
                }
            }
            break;
        case 0:
            cout << "Koniec programu." << endl;
            break;
        default:
            cout << "Nieznana opcja!" << endl;
        }
    } while (opcja != 0);

    // Cleanup
    for (int i = 0; i < 4; ++i)
    {
        delete system[i];
    }

    return 0;
}
