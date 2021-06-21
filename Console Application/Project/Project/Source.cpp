#include <iostream>

#include "WaterBody.h"

int main()
{
	std::string name = "mitko";
	Coordinates coord(100.0f, 2.2f, 21569.0f);
	coord.print();

	WaterBody wb;
	WaterBody wb2(name, coord, 10000.0f, 9.0f, 10.0f, 300.0f, true, -10.0f, 1000.0f, name);

	wb.print();
	std::cout << "\n\n\n\n";
	wb2.print();

	std::cout << "\n\n\n\n";
	coord(1.0f, 340000.0f, 1.0013f);
	wb(name, coord, 10000.0f, 9.0f, 10.0f, 300.0f, true, -10.0f, 1000.0f, name);
	wb.print();
}