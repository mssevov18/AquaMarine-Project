#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

#include "Website.h"

HTML::HTML()
{
	path = "C:/Users/mssevov18/Documents";
	filename = "temp";
	pagename = "Temporary";
}

HTML::HTML(const std::string& path, const std::string& filename, const std::string& pagename)
{
	this->path = path;
	this->filename = filename;
	this->pagename = pagename;
}

HTML::~HTML()
{
	if (!elements.empty() and !path.empty() and !filename.empty() and !pagename.empty())
		makeFile(3600000);
}

void HTML::addElement(const std::string& element)
{
	elements.push_back(element + '\n');
}

void HTML::addLine(const int& amount)
{
	for (int i = 0; i < amount; i++)
		elements.push_back("\n");
}

void HTML::removeElement()
{
	elements.pop_back();
}

void HTML::removeElement(const size_t& index)
{
	elements.erase(elements.begin() + index);
}

void HTML::eraseElements()
{
	elements.clear();
}

void HTML::addStyleSheet(const std::string& styleSheet, const std::string& styleSheetPath)
{
	styleSheets.push_back(std::string(styleSheetPath + "/" + styleSheet));
}

void HTML::addStyleSheet(const std::string& styleSheetPath)
{
	styleSheets.push_back(styleSheetPath);
}

std::string HTML::getFilePath()
{
	return std::string(path + "/" + filename + ".html");
}

bool HTML::makeFile(int refreshRate)
{
	fstream file;
	file.open(path + "/" + filename + ".html", fstream::out, fstream::trunc);

	if (!file.is_open())
		return false;

	file << "\
<!DOCTYPE html>\n\
<html lang=\"en\">\n\
\n\
<head>\n\
	<meta charset=\"UTF-8\">\n\
	<meta name=\"viewport\" content=\"width=device-width, initial-scale=1.0\">\n\
\n";

	for (size_t i = 0; i < styleSheets.size(); i++)
		file << "<link rel = \"stylesheet\" type = \"text/css\" href = \"" << styleSheets[i] + ".css" << "\">\n";

	file << "\
	<link rel = \"stylesheet\" type = \"text/css\" href = \"../../Style/About.css\">\n\
	<link rel=\"preconnect\" href=\"https://fonts.gstatic.com\">\n\
	<link href=\"https://fonts.googleapis.com/css2?family=Comfortaa:wght@400;600&display=swap\" rel=\"stylesheet\">\n\
	<link rel=\"shortcut icon\"  type=\"image/x-icon\" href=\"../../Illustration/Favicon/Favicon.svg\">\n\
\n";

	file << "\
<script type = \"text/JavaScript\">\n\
	function AutoRefresh(t) {\n\
		setTimeout(\"location.reload(true);\", t);\n\
	}\n\
</script>\n\
</head>\n\
\n";

	file << "<body onload = \"JavaScript:AutoRefresh(" + to_string(refreshRate) + ");\">\n";

	file << "\
	<div class=\"illustration1\">\n\
		<!-- This is navigation bar-->\n\
		<nav class=\"positio_nav\">\n\
			<div class=\"navbar\">\n\
				<a href=\"#\">\n\
					<img src=\"../../Illustration/Logo/Logo.svg\" class=\"logo\">\n\
				</a>\n\
\n\
				<ul class=\"menu\">\n\
					<li ><a href=\"../../index.html\">Home</a></li>\n\
					<li><a href=\"../About us/About.html\">About us</a></li>\n\
					<li class=\"active\"><a href=\"#\">Results</a></li>\n\
					<li><a href=\"#\">Contact</a></li>\n\
				</ul>\n\
\n\
			</div>\n\
		</nav>\n\
	</div>\n\
\n\
<br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br><br>\n\
\n\
	<div>\n\
\n";

	for (size_t i = 0; i < elements.size(); i++)
		file << "\t\t" + elements[i];

	file << "\
\n\
</div>\n\
</body>\n\
</html>\n\
";
	file.close();
	return true;
}

CSS::CSS()
{
	path = "C:/Users/mssevov18/Documents";
	filename = "temp";
}

CSS::CSS(const std::string& path, const std::string& filename)
{
	this->path = path;
	this->filename = filename;
}

void CSS::addContent(const std::string& newContent)
{
	content += newContent + '\n';
}

void CSS::replaceContent(const std::string& newContent)
{
	content = newContent;
}

std::string CSS::getName()
{
	return filename;
}

std::string CSS::getPath()
{
	return path;
}

std::string CSS::getNamePath()
{
	return std::string(path + "/" + filename);
}

bool CSS::makeFile()
{
	fstream file;
	file.open(path + "/" + filename + ".css", fstream::out, fstream::trunc);

	if (!file.is_open())
		return false;

	file << content;
	file.close();

	return true;
}
