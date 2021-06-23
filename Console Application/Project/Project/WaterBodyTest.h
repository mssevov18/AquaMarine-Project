#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include "WaterBody.h"
#include "framework.h"

using namespace std;

string createTable(vector<WaterBody>& vec)
{
	Paragraph out("", "",
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
			Paragraph("", "", "IsFreshWater").toString("th") + "\n" +
			Paragraph("", "", "Ph Level").toString("th") + "\n" +
			Paragraph("", "", "PolutionLevel (%)").toString("th") + "\n" +
			Paragraph("", "", "Contributor's Name").toString("th") + "\n"
		).toString("tr") + "\n");
	for (size_t i = 0; i < vec.size(); i++)
		out.addContent(vec[i].toHtmlTableRow() + "\n");
	return out.toString("table");
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

	HTML page;

	page.addElement(createTable(vec));

	page.makeFile();
}