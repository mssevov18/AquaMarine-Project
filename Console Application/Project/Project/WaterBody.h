#pragma once

#include <iostream>
#include <string>
#include <ctime>

struct Coordinates
{
	//TODO Reasearch on ways to properly display (ie: degrees, minutes, seconds)
	Coordinates();
	Coordinates(float newLon, float newLat, float newAlt);

	float longitude;
	float latidute;
	float altitude;

	void print();
	void operator()(float newLon, float newLat, float newAlt);
};

class WaterBody
{
public:
	WaterBody();
	WaterBody(
		std::string name,
		Coordinates position,
		float maxLength,
		float maxWidth,
		float maxDepth,
		float temperature,
		bool  isFreshWater,
		float phLevel,
		float polutionLevel,
		std::string contributorName
	);

private:
	std::string name; // Name

	Coordinates position; // Location of the Water Body

	float maxLength; // Lenght from the northmost point to the southmost point
	float maxWidth;  // Lenght from the eastmost point to the westmost point
	float maxDepth;  // Lenght from deepest point of the Body to it's surface
	float perimeter; // Approximate Perimeter of the surface
	float area;      // Approximate Area of the surface
	float volume;    // Approximate Volume of the Body

	float temperature;   // Average water temperature
	bool  isFreshWater;  // true - it's a Fresh Water Body | false - it's a Salt Water Body
	float phLevel;       // Average Ph Level
	float polutionLevel; // Percentage of polution

	std::string contributorName; // Contributor Name
	tm          logTimeStamp;    // Date and time of the last edit

public:
	void print();

	void operator() (
		std::string name,
		Coordinates position,
		float maxLength,
		float maxWidth,
		float maxDepth,
		float temperature,
		bool  isFreshWater,
		float phLevel,
		float polutionLevel,
		std::string contributorName
		);
};