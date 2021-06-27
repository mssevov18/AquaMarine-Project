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
	std::string toHtmlTableData(const std::string& _class = "", const std::string& _style = "");

	void operator()(float newLon, float newLat, float newAlt);
};

constexpr int s_name      =  0;
constexpr int c_pos       =  1;
constexpr int f_lon       =  2;
constexpr int f_lat       =  3;
constexpr int f_alt       =  4;
constexpr int f_len       =  5;
constexpr int f_wid       =  6;
constexpr int f_dep       =  7;
constexpr int f_per       =  8;
constexpr int f_area      =  9;
constexpr int f_vol       = 10;
constexpr int f_temp      = 11;
constexpr int b_isfresh   = 12;
constexpr int f_ph        = 13;
constexpr int f_pollution = 14;
constexpr int s_cname     = 15;

constexpr char delimeterC = '|';

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

	//TODO add these vvv for sort func
	bool isEqual(const WaterBody& rhs, int mode);
	bool isGreater(const WaterBody& rhs, int mode);
	bool isLesser(const WaterBody& rhs, int mode);

	void fChange(int field, const float& newData);
	void cChange(int field, const Coordinates& newData);
	void bChange(int field, const bool& newData);
	void sChange(int field, const std::string& newData);

private:
	void calculate();
};