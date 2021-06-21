#include "WaterBody.h"

Coordinates::Coordinates()
{
	longitude = 0;
	latidute  = 0;
	altitude  = 0;
}

Coordinates::Coordinates(float newLon, float newLat, float newAlt)
{
	longitude = newLon;
	latidute  = newLat;
	altitude  = newAlt;
}

void Coordinates::print()
{
	std::cout << "lon: " << longitude << " | lat: " << latidute << " | alt: " << altitude << 'm';
}

void Coordinates::operator()(float newLon, float newLat, float newAlt)
{
	longitude = newLon;
	latidute  = newLat;
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

void WaterBody::print()
{
	std::cout << name << ": \n\t";
	position.print();
	std::cout << "\n\tMax Length: " << maxLength << "m | Max Width: " << maxWidth << "m | Max Depth: " << maxDepth;
	std::cout << "\n\tPerimeter: " << perimeter << "m | Area: " << area << "m^2 | Volume: " << volume << "m^3";
	std::cout << "\n\tTemperature: " << temperature << "oC | " << (isFreshWater ? "Fresh Water Body" : "Salt Water Body") << " | ph: " << phLevel << " | Polution Level:" << polutionLevel << '\n';
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
