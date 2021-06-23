#include "WaterBody.h"
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



Coordinates::Coordinates()
{
	longitude = 0;
	latitude  = 0;
	altitude  = 0;
}

Coordinates::Coordinates(float newLon, float newLat, float newAlt)
{
	longitude = newLon;
	latitude  = newLat;
	altitude  = newAlt;
}

void Coordinates::print()
{
	cout << "lon: " << longitude << "\370 | lat: " << latitude << "\370 | alt: " << altitude << 'm';
}

std::string Coordinates::toHtmlTableRow()
{
	return Paragraph("", "",
		Paragraph("", "", std::to_string(longitude)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(latitude)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(altitude)).toString("td") + "\n"
	).toString("tr");
}

std::string Coordinates::toHtmlTableData()
{
	return (Paragraph("", "", std::to_string(longitude)).toString("td") + "\n" +
			Paragraph("", "", std::to_string(latitude)).toString("td") + "\n" +
			Paragraph("", "", std::to_string(altitude)).toString("td") + "\n");
}

void Coordinates::operator()(float newLon, float newLat, float newAlt)
{
	longitude = newLon;
	latitude  = newLat;
	altitude  = newAlt;
}

WaterBody::WaterBody()
{
	name = "";

	maxLength = 0;
	maxWidth  = 0;
	maxDepth  = 0;
	perimeter = 0;
	area      = 0;
	volume    = 0;

	temperature   = 0;
	isFreshWater  = 0;
	phLevel       = 0;
	polutionLevel = 0;
					
	contributorName = "";
}

WaterBody::WaterBody(std::string name, Coordinates position, float maxLength, float maxWidth, float maxDepth, float temperature, bool isFreshWater, float phLevel, float polutionLevel, std::string contributorName)
{
	this->name = name;

	this->position = position;

	//TODO add input proccessing eg: (length>0)

	this->maxLength = maxLength;
	this->maxWidth  = maxWidth;
	this->maxDepth  = maxDepth;

	// We are assuming that the shape is a square
	this->perimeter = 2 * (maxWidth + maxLength);
	this->area      = maxWidth * maxLength;
	this->volume    = this->area;

	this->temperature   = temperature;
	this->isFreshWater  = isFreshWater;
	this->phLevel       = phLevel;
	this->polutionLevel = polutionLevel;

	this->contributorName = contributorName;
}

//Testing purposes only
float rngF(int limit = 100, float multiplier = 1)
{
	return float(float(rand() % limit) * multiplier);
}

WaterBody WaterBody::getRandomWaterBody()
{
	return WaterBody(
		"Test" + std::to_string(rand() % 100),
		Coordinates(
			float(rngF(100, 1.5f)),
			float(rngF(100, 6.3f)),
			float(rngF(100, 0.3f))),
		rngF(100, 0.2f),
		rngF(100, 0.5f),
		rngF(100, 4.2f),
		rngF(20, 0.99f) + 20,
		rngF(2),
		rngF(15, 0.3f),
		rngF(100, 1.5f),
		"Contributor" + std::to_string(rand() % 100));
}

std::string WaterBody::toHtmlTableRow()
{
	return Paragraph("", "",
		Paragraph("", "", name).toString("td") + "\n" +
		position.toHtmlTableData() +
		Paragraph("", "", std::to_string(maxLength)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(maxWidth)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(maxDepth)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(perimeter)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(area)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(volume)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(temperature)).toString("td") + "\n" +
		Paragraph("", "", (isFreshWater ? "Fresh Water" : "Salt Water")).toString("td") + "\n" +
		Paragraph("", "", std::to_string(phLevel)).toString("td") + "\n" +
		Paragraph("", "", std::to_string(polutionLevel)).toString("td") + "\n" +
		Paragraph("", "", contributorName).toString("td") + "\n"
	).toString("tr");
}

void WaterBody::print()
{
	cout << name << ": \n\t";
	position.print();
	cout << "\n\tMax Length: " << maxLength << "m | Max Width: " << maxWidth << "m | Max Depth: " << maxDepth;
	cout << "\n\tPerimeter: " << perimeter << "m | Area: " << area << "m^2 | Volume: " << volume << "m^3";
	cout << "\n\tTemperature: " << temperature << "\370C | " << (isFreshWater ? "Fresh Water Body" : "Salt Water Body") << " | ph: " << phLevel << " | Polution Level:" << polutionLevel << '\n';
}

void WaterBody::operator() (std::string name, Coordinates position, float maxLength, float maxWidth, float maxDepth, float temperature, bool isFreshWater, float phLevel, float polutionLevel, std::string contributorName)
{
	this->name = name;

	this->position = position;

	//TODO add input proccessing eg: (length>0)

	this->maxLength = maxLength;
	this->maxWidth  = maxWidth;
	this->maxDepth  = maxDepth;

	// We are assuming that the shape is a square
	this->perimeter = 2 * (maxWidth + maxLength);
	this->area = maxWidth * maxLength;
	this->volume = this->area;

	this->temperature   = temperature;
	this->isFreshWater  = isFreshWater;
	this->phLevel       = phLevel;
	this->polutionLevel = polutionLevel;

	this->contributorName = contributorName;
}
