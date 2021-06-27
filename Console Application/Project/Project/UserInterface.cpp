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
table { font-family: 'Comfortaa'; }\n\
\n\
.table\n\
{\n\
	max-width: 100%;\n\
	margin: 20px;\n\
	padding-top: 700px;\n\
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
tr { height: 60px; }\n\
\n\
td:hover\n\
{\n\
	background: aquamarine;\n\
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
		cout << "\
Main Menu_indev\n\
A. Add\n\
";

		if (!vec.empty())
			cout << "\
D. Delete\n\
E. Edit\n\
Q. Print\n\
S. Sort\n\
W. Open Website\n\
Enter. Upload To Site\n\
Ctrl + S. Save to file\n\
";

		cout << "\
Ctrl + L. Load from file\n\
Esc. Stop the program\n\n\
";
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
			if (!vec.empty())
			{
			}
			break;
		case 'Q': // Print
		case 'q':
			if (!vec.empty())
				Print(vec);
			break;
		case 'S': // Sort
		case 's':
			break;
		case 'W': // Website
		case 'w':
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
		case 27:  // Escape - Stop
			inLoop = false;
			break;
		default:
			throw;
			break;
		}

		system("CLS");
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
	StructWaterBody tempStruct;
	cout << "WaterBody:\n- - Name (word): ";
	cin >> tempStruct.name;
	cin.clear();
	cout << "- - Longitude (float): ";
	cin >> tempStruct.position.longitude;
	cin.clear();
	cout << "- - Latitude (float): ";
	cin >> tempStruct.position.latitude;
	cin.clear();
	cout << "- - Altitude (float): ";
	cin >> tempStruct.position.altitude;
	cin.clear();
	cout << "- - Length (float): ";
	cin >> tempStruct.maxLength;
	cin.clear();
	cout << "- - Width (float): ";
	cin >> tempStruct.maxWidth;
	cin.clear();
	cout << "- - Depth (float): ";
	cin >> tempStruct.maxDepth;
	cin.clear();
	cout << "- - Temperature (float): ";
	cin >> tempStruct.temperature;
	cin.clear();
	cout << "- - Is Fresh Water (1, 0): ";
	cin >> tempStruct.isFreshWater;
	cin.clear();
	cout << "- - Ph Level (float): ";
	cin >> tempStruct.phLevel;
	cin.clear();
	cout << "- - Pollution level (float %): ";
	cin >> tempStruct.pollutionLevel;
	cin.clear();
	cout << "- - Contributor Name (word): ";
	cin >> tempStruct.contributorName;
	cin.clear();

	vec.push_back(new WaterBody(WaterBody::getFromStruct(tempStruct)));
	cout << "\nSuccessfully added:\n";
	vec[vec.size() - 1]->print();

	_lgetch();
}

void Delete(vector<WaterBody*>& vec)
{
	system("CLS");

	cout << "\
Main Menu_indev\n\
A. Add\n\
D. Delete\n\
E. Edit\n\
Q. Print\n\
S. Sort\n\
W. Open Website\n\
Enter. Upload To Site\n\
Ctrl + S. Save to file\n\
Ctrl + L. Load from file\n\
Esc. Stop the program\n\n\
";

	cout << "\
\nA. Delete all\
\n(num { 0 -> " << vec.size() - 1 << "}). Delete by index\
\nEsc. Go Back\n\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case -1: //All
		vec.clear();
		cout << "All Data has been Deleted\n";
		break;
	case -2:
		return;
	default:
		choice -= 48;
		if (choice >= vec.size())
			throw;
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
		if (vec.size() > 0)
			Delete(vec);
		break;
	}
}

void Edit(vector<WaterBody*>& vec)
{
}

void Print(std::vector<WaterBody*>& vec)
{
	system("CLS");

	cout << "\
Main Menu_indev\n\
A. Add\n\
D. Delete\n\
E. Edit\n\
Q. Print\n\
S. Sort\n\
W. Open Website\n\
Enter. Upload To Site\n\
Ctrl + S. Save to file\n\
Ctrl + L. Load from file\n\
Esc. Stop the program\n\n\
";

	cout << "\
\n-1. Print all\
\n(num { 0 -> " << vec.size() - 1 << "}). Print by index\
\n-2. Go Back\n\n";
	int choice;
	cin >> choice;
	switch (choice)
	{
	case -1: //All
		for (size_t i = 0; i < vec.size(); i++)
		{
			vec[i]->print(i);
			cout << '\n';
		}
		break;
	case -2:
		return;
	default:
		if (choice < 0)
			throw;
		if (choice >= vec.size())
			throw;
		vec[choice]->print(choice);
		if (vec.size() > 0)
			Print(vec);
		break;
	}
	if (_lgetch() == 27)
		return;
}

void Sort(std::vector<WaterBody*>& vec)
{
}

void Upload(std::vector<WaterBody*>& vec, HTML& page)
{
	page.addElement(Paragraph("", "", to_string(vec.size()) + " Entries in the database").toString());
	page.addElement(WebsiteElement("br", "", "").toString());
	page.addElement(Paragraph("", "", createTable(vec)).toString("center", true));
	if (page.makeFile(60000))
		cout << "Successfully uploaded (" << vec.size() << ") Water Bodies to webpage";
	else
		cout << "Upload was unsuccessful";
	_lgetch();
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
