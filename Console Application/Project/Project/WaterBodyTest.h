#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include "WaterBody.h"
#include "framework.h"

using namespace std;

string createTable(vector<WaterBody>& vec, const std::string& __class = "", const std::string& __style = "")
{
	Paragraph out(__class, __style,
			Paragraph("","",
			Paragraph("", "", "Name").toString("th") + "\n" +
			Paragraph("", "", "Longitude (&deg)").toString("th") + "\n" +
			Paragraph("", "", "Latitude (&deg)").toString("th") + "\n" +
			Paragraph("", "", "Altitude (m)").toString("th") + "\n" +
			Paragraph("", "", "Max Length (m)").toString("th") + "\n" +
			Paragraph("", "", "Max Width (m)").toString("th") + "\n" +
			Paragraph("", "", "Max Depth (m)").toString("th") + "\n" +
			Paragraph("", "", "Perimeter (m)").toString("th") + "\n" +
			Paragraph("", "", "Area (m&sup2)").toString("th") + "\n" +
			Paragraph("", "", "Volume (m&sup3)").toString("th") + "\n" +
			Paragraph("", "", "Temperature (&deg)").toString("th") + "\n" +
			Paragraph("", "", "Water").toString("th") + "\n" +
			Paragraph("", "", "Ph Level").toString("th") + "\n" +
			Paragraph("", "", "PolutionLevel (%)").toString("th") + "\n" +
			Paragraph("", "", "Contributor's Name").toString("th") + "\n"
		).toString("tr", true) + "\n");
	for (size_t i = 0; i < vec.size(); i++)
		out.addContent(vec[i].toHtmlTableRow() + "\n");
	return out.toString("table", true);
}

void waterBodyTest()
{
	string name = "mitko";
	Coordinates coord(100.0f, 2.2f, 21569.0f);
	coord.print();

	WaterBody wb;
	WaterBody wb2(name, coord, 10000.0f, 9.0f, 10.0f, 300.0f, true, -10.0f, 1000.0f, name);

	wb.print();
	cout << "\n\n\n\n";
	wb2.print();

	cout << "\n\n\n\n";
	coord(1.0f, 340000.0f, 1.0013f);
	wb(name, coord, 10000.0f, 9.0f, 10.0f, 300.0f, true, -10.0f, 1000.0f, name);
	wb.print();

	cout << "\n\n\n\n";
	cout << "\n\n\n\n";

	srand(unsigned(time(NULL)));

	vector<WaterBody> vec;
	vec.push_back(WaterBody::getRandomWaterBody());
	vec[0].print();
	cout << "\370";
	vec.push_back(WaterBody::getRandomWaterBody());
	vec.push_back(WaterBody::getRandomWaterBody());
	vec.push_back(WaterBody::getRandomWaterBody());
	vec.push_back(WaterBody::getRandomWaterBody());
	vec.push_back(WaterBody::getRandomWaterBody());
	vec.push_back(WaterBody::getRandomWaterBody());
	vec.push_back(WaterBody::getRandomWaterBody());
	vec.push_back(WaterBody::getRandomWaterBody());

	HTML page("../../../Website/Pages/Results", "results", "Results");
	CSS sheet("../../../Website/Style", "results");

	sheet.addContent(
		"body\n\
		{\n\
			background-color: white;\n\
			color: black;\n\
		}\n\
		\n\
		table, th, td {\n\
			border: 1px solid black;\n\
			margin: 5px\n\
		}\n\
		"
		);

	page.addStyleSheet(sheet.getNamePath());
	page.addElement(Paragraph("", "", createTable(vec)).toString("center", true));

	sheet.makeFile();
	page.makeFile(60000);
}