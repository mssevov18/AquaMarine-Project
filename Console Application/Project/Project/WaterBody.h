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


enum class wbData
{
	NAME,
	POSITION,
	LONGITUDE,
	LATITUDE,
	ALTITUDE,
	MAXLENGTH,
	MAXWIDTH,
	MAXDEPTH,
	PERIMETER,
	AREA,
	VOLUME,
	TEMPERATURE,
	ISFRESHWATER,
	PHLEVEL,
	POLLUTIONLEVEL,
	CONTRIBUTORNAME
};

#define s_name      wbData::NAME
#define c_pos       wbData::POSITION
#define f_lon       wbData::LONGITUDE
#define f_lat       wbData::LATITUDE
#define f_alt       wbData::ALTITUDE
#define f_len       wbData::MAXLENGTH
#define f_wid       wbData::MAXWIDTH
#define f_dep       wbData::MAXDEPTH
#define f_per       wbData::PERIMETER
#define f_area      wbData::AREA
#define f_vol       wbData::VOLUME
#define f_temp      wbData::TEMPERATURE
#define b_isfresh   wbData::ISFRESHWATER
#define f_ph        wbData::PHLEVEL
#define f_pollution wbData::POLLUTIONLEVEL
#define s_cname     wbData::CONTRIBUTORNAME

#define delimeterC '|'

struct StructWaterBody
{
	std::string name; // Name

	Coordinates position; // Location of the Water Body

	float maxLength; // Lenght from the northmost point to the southmost point
	float maxWidth;  // Lenght from the eastmost point to the westmost point
	float maxDepth;  // Lenght from deepest point of the Body to it's surface

	float temperature;   // Average water temperature
	bool  isFreshWater;  // true - it's a Fresh Water Body | false - it's a Salt Water Body
	float phLevel;       // Average Ph Level
	float pollutionLevel; // Percentage of pollution

	std::string contributorName; // Contributor Name
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
		float pollutionLevel,
		std::string contributorName
	);

	static WaterBody getRandomWaterBody();
	static WaterBody getFromString(const std::string& in);
	static WaterBody getFromStruct(StructWaterBody in);

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

	void fChange(wbData field, const float& newData);
	void cChange(wbData field, const Coordinates& newData);
	void bChange(wbData field, const bool& newData);
	void sChange(wbData field, const std::string& newData);

private:
	void calculate();
};