#include "WebsiteElement.h"

WebsiteElement::WebsiteElement()
{
	_tag   = "br";
	_class = "";
	_style = "";
}

WebsiteElement::WebsiteElement(const std::string& __tag, const std::string& __class, const std::string& __style)
{
	_tag   = __tag;
	_class = __class;
	_style = __style;
}

void WebsiteElement::setTag(const std::string& in)
{
	_tag = in;
}

std::string WebsiteElement::getTag()
{
	return _tag;
}

void WebsiteElement::setClass(const std::string& in)
{
	_class = in;
}

std::string WebsiteElement::getClass()
{
	return _class;
}

void WebsiteElement::setStlye(const std::string& in)
{
	_style = in;
}

std::string WebsiteElement::getStyle()
{
	return _style;
}

std::string WebsiteElement::toString(const std::string& customTag)
{
	return ("<" + (customTag.empty() ? _tag : customTag) + " class=\"" + _class + "\" style=\"" + _style + "\"> </" + _tag + ">");
}
