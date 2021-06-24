#include "WaterBody.h"
using namespace std;

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
	this->volume    = this->area * maxDepth;

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

WaterBody WaterBody::getFromString(const std::string& in)
{
	vector<string> vec;
	string temp;
	size_t count = 0;
	for (size_t i = 0; i < in.length(); i++)
	{
		switch (in[i])
		{
		case delimeterC:
			vec.push_back(temp);
			temp.clear();
			continue;
		default:
			temp.push_back(in[i]);
			break;
		}
	}
	vec.push_back(temp);

	WaterBody out(
		vec[0],
			Coordinates(
				stof(vec[1]),
				stof(vec[2]),
				stof(vec[3])
		),
		stof(vec[4]),
		stof(vec[5]),
		stof(vec[6]),
		stof(vec[7]),
		stof(vec[8]),
		stof(vec[9]),
		stof(vec[10]),
		vec[11]
	);
	return out;
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

std::string WaterBody::toString()
{
	return std::string(
		name + delimeterS +
		to_string(position.longitude) + delimeterS +
		to_string(position.latitude) + delimeterS +
		to_string(position.altitude) + delimeterS +
		to_string(maxLength) + delimeterS +
		to_string(maxWidth) + delimeterS +
		to_string(maxDepth) + delimeterS +
		//to_string(perimeter) + delimeterS +
		//to_string(area) + delimeterS +
		//to_string(volume) + delimeterS +
		to_string(temperature) + delimeterS +
		to_string(isFreshWater) + delimeterS +
		to_string(phLevel) + delimeterS +
		to_string(polutionLevel) + delimeterS +
		contributorName
	);
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
