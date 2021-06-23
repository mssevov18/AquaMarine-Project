#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "WebsiteElement.h"
#include "InheritedWebsiteEliments.h"

class HTML
{
public:
	HTML();
	HTML(const std::string& path, const std::string& filename, const std::string& pagename);

private:
	std::string path;
	std::string filename;
	std::string pagename;
	std::vector<std::string> elements;
	std::vector<std::string> styleSheets;

public:
	void addElement(const std::string& element);
	void removeElement(void);
	void removeElement(const size_t& index);
	void eraseElements();
	void addStyleSheet(const std::string& styleSheet);
	std::string getFilePath();

	void makeFile(int refreshRate = 1000);
};

class CSS
{
public:
	CSS();
	CSS(const std::string& path, const std::string& filename);

private:
	std::string path;
	std::string filename;
	std::string content;

public:
	void addContent(const std::string& newContent);
	void replaceContent(const std::string& newContent);

	std::string getName();

	void makeFile();
};