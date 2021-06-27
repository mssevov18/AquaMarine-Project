#include <iostream>
#include <ctime>
#include <vector>
#include <string>

#include "WaterBody.h"
#include "CtHframework.h"
#include "Logframework.h"
#include "FileHanlder.h"


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

	vector<WaterBody*> vec;
	vec.push_back(new WaterBody(WaterBody::getRandomWaterBody()));
	vec[0]->print();
	cout << "\370";
	for (size_t i = 0; i < 40; i++)
		vec.push_back(new WaterBody(WaterBody::getRandomWaterBody()));
	HTML page("../../../Website/Pages/Results", "results", "Results");
	CSS sheet("../../../Website/Style", "results");

	sheet.addContent(
"body\n\
{\n\
	background-color: white;\n\
	color: black;\n\
}\n\
\n\
table, th, td\n\
{\n\
	border: 1px solid black;\n\
	margin: 5px;\n\
	font-size: 14pt;\n\
}\n\
"
		);

	page.addStyleSheet(sheet.getNamePath());
	page.addElement(Paragraph("", "", createTable(vec)).toString("center", true));

	sheet.makeFile();
	page.makeFile(60000);

	vec[0]->print();
	cout << "\n\n\n";
	string a = vec[0]->toString();
	WaterBody A = WaterBody::getFromString(a);
	A.print();

	saveWaterBodiesToFile(vec, "", "../data.txt");
	vec.clear();
	loadWaterBodiesFromFile(vec, "", "../data.txt");

	A.sChange(s_name, "mitko12");
	A.fChange(f_dep, 1000);
	A.bChange(b_isfresh, false);
	A.cChange(c_pos, Coordinates(100, 1000, 20000));
	A.print();
}