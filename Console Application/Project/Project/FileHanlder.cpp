#include "FileHanlder.h"

using namespace std;

string createTable(vector<WaterBody>& vec, const string& __class, const string& __style)
{
	Paragraph out(__class, __style,
		Paragraph("", "",
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

void saveWaterBodiesToFile(vector<WaterBody>& vec, const string& path, const string& filename)
{
	fstream file;
	file.open(path + filename, fstream::out, fstream::trunc);
	if (!file.is_open())
		return;
	for (size_t i = 0; i < vec.size(); i++)
		file << vec[i].toString() << "\n";
	file.close();
}

void loadWaterBodiesFromFile(vector<WaterBody>& vec, const string& path, const string& filename)
{
	fstream file;
	file.open(path + filename, fstream::in);
	string line;
	while (getline(file,line))
		vec.push_back(WaterBody::getFromString(line));
}

void CreateSaveDir()
{
	system("mkdir C:/Logs");
	system("mkdir C:/Logs/Log-class");
	system("cls");
}
