#include "conio.h"
#include "windows.h"

#include "UserInterface.h"
#include "FileHanlder.h"

using namespace std;

void menu()
{
	system("cls");
	cout << "Aquamarine" << endl;
	cout << "1.Add waterbody stats" << endl;
	cout << "2.Delete waterbody stats" << endl;
	cout << "3.View waterbody stats" << endl;
	cout << "4.Edit waterbody stats" << endl;
	cout << "Press 1, 2, 3 or 4 to continue";
	char choice = _lgetch();

	switch (choice)
	{
	case '1':
		system("cls");
		cout << "Enter name, position(Lon, Lat, alt),";
		cout << "Length, Width, Depth, temp, IsFreshWater(0/1), Ph lvl, pollution lvl";
		cout << "and username:" << endl;
		break;

	case '2':
		system("cls");
		cout << "Enter the name of the waterbody you want to delete:";
		break;

	case '3':
		system("cls");
		cout << "Enter the name of the waterbody you want to view:";
		break;

	case '4':
		system("cls");
		cout << "Enter the name of the waterbody you want to edit:";
		//name
		cout << "Enter the data you want to edit(maxLength, maxWight, phLevel, ect.):";
		//data type
		break;

	default:
		menu();
		break;
	}
}

void printMenuOptions(vector<WaterBody*> vec)
{
	system("CLS");

	cout << "\
Main Menu\n\
A. Add\n\
W. Open Webpage\n\
";

	if (!vec.empty())
		cout << "\
D. Delete\n\
E. Edit\n\
Q. Print\n\
S. Sort\n\
Enter. Upload To Site\n\
Ctrl + S. Save to file\n\
";

	cout << "\
Ctrl + L. Load from file\n\
Ctrl + W. Unload from Webpage\n\
Esc. Stop the program\n\n\
";
}

void menu_indev()
{
	HTML page("../../../Website/Pages/Results", "results", "Results");
	CSS sheet("../../../Website/Style", "results");

	sheet.addContent("\
body\n\
{\n\
	background-color: white;\n\
	color: black;\n\
}\n\
\n\
h1, h2 { text-align: center; }\n\
\n\
hr\n\
{\n\
	width: 80%;\n\
	border: 5px dashed #6930c3;\n\
}\n\
\n\
table { font-family: 'Comfortaa'; }\n\
\n\
.table\n\
{\n\
	max-width: 100%;\n\
	margin: 20px;\n\
	padding-top: 10px;\n\
}\n\
\n\
.content-table\n\
{\n\
	border-collapse: collapse;\n\
	margin: 25px 0; \n\
	font-size: 0.9em;\n\
	min-width: 400px;\n\
	border-radius: 5px 5px 0 0;\n\
	overflow: hidden;\n\
	box-shadow: 0 0 20px rgba(0, 0, 0, 0.15);\n\
	text-align: center;\n\
}\n\
\n\
thead, th\n\
{\n\
	background-color: #6930c3;\n\
	color: #ffffff;\n\
	text-align: left;\n\
	font-weight: bold;\n\
	text-align: center;\n\
}\n\
\n\
th, td { padding: 12px 15px; }\n\
\n\
.content-table, tbody, tr { border-bottom: 1px solid #d3d3d3; }\n\
\n\
.banded-data { background-color: #D9CFF6 }\n\
\n\
td { background-color: #EDF0FC }\n\
\n\
tr { height: 60px; }\n\
\n\
td:hover\n\
{\n\
	background: #B5F4E5;\n\
	font-weight: bold;\n\
	color: black;\n\
}\n\
\n\
.column\n\
{\n\
	background: rgba(143, 82, 255, 0.835);\n\
	font-weight: bold;\n\
	color: white;\n\
}\n\
"
);
	sheet.makeFile();
	page.addStyleSheet(sheet.getNamePath());



	char choice;
	bool inLoop = true;
	vector<WaterBody*> vec;
	string temp;
	
	while (inLoop)
	{
		// Add
		// Del
		// Edit
		// Print
		// Sort
		// UploadToSite
		// Save
		// Load

		printMenuOptions(vec);

		choice = _lgetch();
		switch (choice)
		{
		case 'R':
		case 'r':
			Random(vec);
			break;
		case 'A': // Add
		case 'a':
			Add(vec);
			break;
		case 'D': // Delete
		case 'd':
			if (!vec.empty())
				Delete(vec);
			break;
		case 'E': // Edit
		case 'e':
			//if (!vec.empty())
			//{
			//}
			break;
		case 'Q': // Print
		case 'q':
			if (!vec.empty())
				Print(vec);
			break;
		case 'S': // Sort
		case 's':
			//if (!vec.empty())
			//	Sort(vec);
			break;
		case 'W': // Website
		case 'w':
			system("start ../../../Website/Pages/Results/results.html");
			break;
		case 13:  // Enter - Upload
			if (!vec.empty())
				Upload(vec, page);
			break;
		case 19:  // Ctrl + S - Save
			if (!vec.empty())
				Save(vec);
			break;
		case 12:  // Ctrl + L - Load
			Load(vec);
			break;
		case 23:  // Ctrl + W - Unload from Webpage
			Unload(vec, page);
			break;
		case 27:  // Escape - Stop
			inLoop = false;
			break;
		default:
			throw;
			break;
		}
	}
}

void Random(std::vector<WaterBody*>& vec)
{
	int choice;
	cout << "Amount: ";
	cin >> choice;
	for (int i = 0; i < choice; i++)
		vec.push_back(new WaterBody(WaterBody::getRandomWaterBody()));
	cout << choice << " random Water Bodies have been generated\n";
	_lgetch();
}

void Add(vector<WaterBody*>& vec)
{
	std::string name;
	Coordinates position;
	float maxLength;
	float maxWidth;
	float maxDepth;
	float temperature;
	bool  isFreshWater;
	float phLevel;
	float pollutionLevel;
	std::string contributorName;

	cout << "WaterBody:\n- - Name (word): ";
	getline(cin, name);
	CheckStingInput(name);
	cout << "- - Longitude (float): ";
	cin >> position.longitude;
	CheckNumberInput(position.longitude);
	cout << "- - Latitude (float): ";
	cin >> position.latitude;
	CheckNumberInput(position.latitude);
	cout << "- - Altitude (float): ";
	cin >> position.altitude;
	CheckNumberInput(position.altitude);
	cout << "- - Length (float): ";
	cin >> maxLength;
	CheckNumberInput(maxLength);
	cout << "- - Width (float): ";
	cin >> maxWidth;
	CheckNumberInput(maxWidth);
	cout << "- - Depth (float): ";
	cin >> maxDepth;
	CheckNumberInput(maxDepth);
	cout << "- - Temperature (float): ";
	cin >> temperature;
	CheckNumberInput(temperature);
	cout << "- - Is Fresh Water (1, 0): ";
	cin >> isFreshWater;
	CheckBoolInput(isFreshWater);
	cout << "- - Ph Level (float): ";
	cin >> phLevel;
	CheckNumberInput(phLevel);
	cout << "- - Pollution level (float %): ";
	cin >> pollutionLevel;
	CheckNumberInput(pollutionLevel);
	cout << "- - Contributor Name (word): ";
	cin.ignore();
	getline(cin, contributorName);
	CheckStingInput(contributorName);

	vec.push_back(new WaterBody(WaterBody(name, position, maxLength, maxWidth, maxDepth, temperature, isFreshWater, phLevel, pollutionLevel, contributorName	)));
	cout << "\nSuccessfully added:\n";
	vec[vec.size() - 1]->print();

	_lgetch();
}

void Delete(vector<WaterBody*>& vec)
{
	printMenuOptions(vec);

	cout << "\
\nA. Delete all\
\n(num { 0 -> " << vec.size() - 1 << "}). Delete by index\
\nE. Go Back\n\n";
	std::string input;
	cin >> input;
	switch (input[0])
	{
	case 'A': //All
	case 'a':
		vec.clear();
		cout << "All Data has been Deleted\n";
		break;
	case 'E':
	case 'e':
		return;
	default:
		int choice = std::stoi(input);
		if (choice < 0)
			throw "Under 0";
		if (choice >= vec.size())
			throw "Over vector range";
		vec[choice]->print(choice);
		cout << "\nEnter to delete, Escape to cancel\n";
		switch (_lgetch())
		{
		case 13: // Enter
			cout << "Deleted\n";
			vec.erase(vec.begin() + choice);
		case 27: // Esc
			return;
		default:
			throw;
			break;
		}
		break;
	}
	if (vec.size() > 0)
		Delete(vec);
}

void Edit(vector<WaterBody*>& vec)
{
}

void Print(std::vector<WaterBody*>& vec)
{
	printMenuOptions(vec);

	cout << "\
\nA. Print all\
\n(num { 0 -> " << vec.size() - 1 << "}). Print by index\
\nE. Go Back\n\n";
	std::string input;
	cin >> input;
	switch (input[0])
	{
	case 'A': //All
	case 'a':
		for (int i = 0; i < vec.size(); i++)
		{
			vec[i]->print(i);
			cout << '\n';
		}
		break;
	case 'E':
	case 'e':
		return;
	default:
		int choice = std::stoi(input);
		if (choice < 0)
			throw "Under 0";
		if (choice >= vec.size())
			throw "Over vector range";
		vec[choice]->print(choice);
		break;
	}
	_lgetch();
	if (vec.size() > 0)
		Print(vec);
}

void Sort(std::vector<WaterBody*>& vec)
{
}

void Upload(std::vector<WaterBody*>& vec, HTML& page)
{
	page.eraseElements();
	page.addElement(Paragraph("", "", "Results from the console application database").toString("h1"));
	page.addElement(WebsiteElement("", "", "").toString("hr"));
	page.addElement(Paragraph("", "", to_string(vec.size()) + " Entries in the database").toString("h2"));
	page.addElement(WebsiteElement("", "", "").toString("br"));
	page.addLine();
	page.addElement(createTable(vec,"table",""));
	page.addLine();
	if (page.makeFile(60000))
		cout << "Successfully uploaded (" << vec.size() << ") Water Bodies to webpage";
	else
		cout << "Upload was unsuccessful";
	_lgetch();
}

void Unload(std::vector<WaterBody*>& vec, HTML& page)
{
	page.eraseElements();
	page.addElement(Paragraph("", "", "No data loaded.").toString("h1"));
	page.addElement(WebsiteElement("", "", "").toString("hr"));
	page.addElement(Paragraph("", "", "0 Entries in the database").toString("h2"));
	page.makeFile(60000);
}

void Save(std::vector<WaterBody*>& vec)
{
	if (saveWaterBodiesToFile(vec, "", "../data.txt"))
		cout << "Successfully saved (" << vec.size() << ") Water Bodies";
	else
		cout << "Save was unsuccessful";
	_lgetch();
}

void Load(std::vector<WaterBody*>& vec)
{
	vec.clear();
	if (loadWaterBodiesFromFile(vec, "", "../data.txt"))
		cout << "Successfully loaded (" << vec.size() << ") Water Bodies";
	else
		cout << "Load was unsuccessful";
	_lgetch();
}

void CheckStingInput(std::string &test)
{
	// first check string < 2 letter
	if (test.length() <= 2)
	{
		ErrorMessageForInput();
		RepairIfCinFail();
		getline(cin, test);
		cout << "\n";
		CheckStingInput(test);
	}
	
	//check if there is space or delimeterC and replace with underscore
	for (int i = 0; i < test.length(); i++)
		if (test[i] == ' ' or test[i] == '|')
			test[i] = '_';

}

void CheckNumberInput(float &test)
{
	// check if number is letter
	if (cin.fail()) {
		ErrorMessageForInput();
		RepairIfCinFail();
		cin >> test;
		cout << "\n";
		CheckNumberInput(test);
	}
}

void CheckBoolInput(bool& test)
{
	// check if bool is 1, 0
	if (cin.fail()) {
		ErrorMessageForInput();
		RepairIfCinFail();
		cin >> test;
		cout << "\n";
		CheckBoolInput(test);
	}
}

void ErrorMessageForInput() 
{
	cout << "\n!Error with input value!\n";
	cout << "- - Try Again: ";
}

void RepairIfCinFail()
{
	cin.clear();
	cin.ignore( INT_MAX , '\n'); // INT_MAX is for igrnore 2147483647 caracteres if cin fail
}