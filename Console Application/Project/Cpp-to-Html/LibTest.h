#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "conio.h"

using namespace std;

#include "Website.h"
#include "WebsiteElement.h"
#include "InheritedWebsiteEliments.h"

#define _path "C:/Users/mssevov18/Documents/Website"

void cppToHtmlTest()
{
	vector<HTML> pages;
	vector<CSS> styleSheets;

	styleSheets.push_back(CSS(_path, "mainSheet"));
	styleSheets[0].addContent(
		"BODY\
		{\
			background-color: black;\
			color: white;\
		}\
		"
	);

	pages.push_back(HTML(_path, "index", "Main Page"));
	pages[0].addStyleSheet(styleSheets[0].getName(), _path);
	pages[0].addElement(Paragraph("", "", "Hello World").toString());
	pages[0].addElement(Link("", "", "GOOGLE","https://www.google.com/").toString());
	pages[0].addElement(Paragraph::UnorderedList("", "",
		Paragraph::ListItem("", "", "500", "100").toString() + "\n" +
		Paragraph::ListItem("", "", "50", "").toString() + "\n" +
		Paragraph::ListItem("", "", "522", "").toString() + "\n" +
		Paragraph::ListItem("", "", "00", "2").toString() + "\n"
	).toString());
	pages[0].addElement(Paragraph("", "", "fucl").toString("a"));

	for (size_t i = 0; i < styleSheets.size(); i++)
		styleSheets[i].makeFile();

	for (size_t i = 0; i < pages.size(); i++)
		pages[i].makeFile(100);

	pages[0].addElement(Paragraph("", "", "hi").toString());
	
	char a=0;
	string temp = "";
	while (a != 27)
	{
		a = _getch();
		switch (a)
		{
		case 8:
			if (temp.empty())
				break;
			temp.pop_back();
			_putch(a);
			_putch(' ');
			_putch(a);
			break;
		case 13:
			pages[0].removeElement();
			pages[0].addElement(Paragraph("", "", temp).toString());
			pages[0].makeFile(100);
			temp = "";
			cout << endl;
			break;
		default:
			temp.push_back(a);
			_putch(a);
			break;
		}
	}

	pages[0].eraseElements();
	pages[0].addElement(Paragraph("", "", "Hello World").toString());
	pages[0].makeFile();
}