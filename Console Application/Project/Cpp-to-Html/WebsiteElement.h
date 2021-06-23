#pragma once

#include <iostream>
#include <string>
#include <vector>

class WebsiteElement
{
public:
	WebsiteElement();
	WebsiteElement(const std::string& __tag, const std::string& __class, const std::string& __style);

protected:
	std::string _tag;
	std::string _class;
	std::string _style;

public:
	void		setTag(const std::string& in);
	std::string getTag();

	void		setClass(const std::string& in);
	std::string getClass();

	void		setStlye(const std::string& in);
	std::string getStyle();



	virtual std::string toString(const std::string& customTag = "");
};