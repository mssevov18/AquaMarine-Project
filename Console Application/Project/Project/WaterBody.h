#pragma once

#include <iostream>
#include <string>
#include <ctime>

#include "CtHframework.h"


void menu();

struct Coordinates
{
	//TODO Reasearch on ways to properly display (ie: degrees, minutes, seconds)
	Coordinates();
	Coordinates(float newLon, float newLat, float newAlt);

	float longitude;
	float latitude;
	float altitude;

	void print();

	std::string toHtmlTableRow();
	std::string toHtmlTableData();

	void operator()(float newLon, float newLat, float newAlt);
};

#define s_name      0
#define c_pos       1
#define f_lon       2
#define f_lat       3
#define f_alt       4
#define f_len       5
#define f_wid       6
#define f_dep       7
#define f_per       8
#define f_area      9
#define f_vol       10
#define f_temp      11
#define b_isfresh   12
#define f_ph        13
#define f_pollution 14
#define s_cname     15

#define delimeterC '|'

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
		float pollutionLevel,
		std::string contributorName
	);

	static WaterBody getRandomWaterBody();
	static WaterBody getFromString(const std::string& in);

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
	float pollutionLevel; // Percentage of pollution

	std::string contributorName; // Contributor Name
	//tm          logTimeStamp;    // Date and time of the last edit
	//TODO implement the timestamp

public:
	std::string toHtmlTableRow(const int& id = -10);
	std::string toString(bool ommit = true);
	void print(const int& id = -10);

	void operator() (
		std::string name,
		Coordinates position,
		float maxLength,
		float maxWidth,
		float maxDepth,
		float temperature,
		bool  isFreshWater,
		float phLevel,
		float pollutionLevel,
		std::string contributorName
		);

	void fChange(int field, const float& newData);
	void cChange(int field, const Coordinates& newData);
	void bChange(int field, const bool& newData);
	void sChange(int field, const std::string& newData);

private:
	void calculate();
};