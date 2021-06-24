#include <iostream>
#include <conio.h>
using namespace std;

void menu()
{
	system("cls");
	cout << "Aquamarine" << endl;
	cout << "1.Add waterbody stats" << endl;
	cout << "2.Delete waterbody stats" << endl;
	cout << "3.View waterbody stats" << endl;
	cout << "4.Edit waterbody stats" << endl;
	cout << "Press 1, 2, 3 or 4 to continue";
	char choice = _getch();

	switch (choice)
	{
	case '1':
		system("cls");
		cout << "Enter name, position(Lon, Lat, alt),";
		cout << "Length, Width, Depth, temp, IsFreshWater(0/1), Ph lvl, polution lvl";
		cout << "and username:" << endl;
		break;

	case '2':
		system("cls");
		cout << "Enter the name of the waterbody you want to delete:";
		break;

	case '3':
		system("cls");
		cout << "Enter the name of the waterbody you want to view:";
		break;

	case '4':
		system("cls");
		cout << "Enter the name of the waterbody you want to edit:";
		//name
		cout << "Enter the data you want to edit(maxLength, maxWight, phLevel, ect.):";
		//data type
		break;

	default:
		menu();
		break;
	}
}