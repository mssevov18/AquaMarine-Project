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
table, th, td\n\
{\n\
	border: 1px solid black;\n\
	margin: 5px;\n\
	font-size: 14pt;\n\
}\n\
"
);
	sheet.makeFile();
	page.addStyleSheet(sheet.getNamePath());



	char choice;
	bool inLoop = true;
	bool tempb;
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
A. Add\n";

		if (!vec.empty())
			cout << "\
D. Delete\n\
E. Edit\n\
Q. Print\n\
S. Sort\n\
Enter. Upload To Site\n\
Ctrl + S. Save to file\n\
\n\
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
			Delete(vec);
			break;
		case 'E': // Edit
		case 'e':
			break;
		case 'Q': // Print
		case 'q':
			Print(vec);
			break;
		case 'S': // Sort
		case 's':
			break;
		case 13:  // Enter - Upload
			Upload(vec, page);
			break;
		case 19:  // Ctrl + S - Save
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
A. Add\n";

	if (!vec.empty())
		cout << "\
D. Delete\n\
E. Edit\n\
Q. Print\n\
S. Sort\n\
Enter. Upload To Site\n\
Ctrl + S. Save to file\n\
\n\
";

	cout << "\
Ctrl + L. Load from file\n\
Esc. Stop the program\n\n\
";

	cout << "\
\nA. Delete all\
\n(num). Delete by index\
\nEsc. Go Back\n\n";
	int choice = _lgetch();
	switch (choice)
	{
	case 'A': //All
	case 'a':
		vec.clear();
		cout << "All Data has been Deleted\n";
		break;
	case 27:
		break;
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
A. Add\n";

	if (!vec.empty())
		cout << "\
D. Delete\n\
E. Edit\n\
Q. Print\n\
S. Sort\n\
Enter. Upload To Site\n\
Ctrl + S. Save to file\n\
\n\
";

	cout << "\
Ctrl + L. Load from file\n\
Esc. Stop the program\n\n\
";

	cout << "\
\nA. Print all\
\n(num). Print by index\
\nEsc. Go Back\n\n";
	int choice = _lgetch();
	switch (choice)
	{
	case 'A': //All
	case 'a':
		for (size_t i = 0; i < vec.size(); i++)
		{
			vec[i]->print(i);
			cout << '\n';
		}
		break;
	case 27:
		break;
	default:
		if (choice < 48)
			throw;
		if (choice - 48 >= vec.size())
			throw;
		vec[choice - 48]->print(choice - 48);
		if (_lgetch() == 27)
			return;
		if (vec.size() > 0)
			Print(vec);
		break;
	}
	_lgetch();
}

void Sort(std::vector<WaterBody*>& vec)
{
}

void Upload(std::vector<WaterBody*>& vec, HTML& page)
{
	page.addElement(Paragraph("", "", createTable(vec)).toString("center", true));
	bool tempb = page.makeFile(60000);
	if (tempb)
		cout << "Successfully uploaded (" << vec.size() << ") Water Bodies to webpage";
	else
		cout << "Upload was unsuccessful";
	_lgetch();
}

void Save(std::vector<WaterBody*>& vec)
{
	bool tempb = saveWaterBodiesToFile(vec, "", "../data.txt");
	if (tempb)
		cout << "Successfully saved (" << vec.size() << ") Water Bodies";
	else
		cout << "Save was unsuccessful";
	_lgetch();
}

void Load(std::vector<WaterBody*>& vec)
{
	vec.clear();
	bool tempb = loadWaterBodiesFromFile(vec, "", "../data.txt");
	if (tempb)
		cout << "Successfully loaded (" << vec.size() << ") Water Bodies";
	else
		cout << "Load was unsuccessful";
	_lgetch();
}
