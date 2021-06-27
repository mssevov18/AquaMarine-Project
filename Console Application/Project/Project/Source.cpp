
#include <iostream>

#include "WaterBody.h"
#include "CtHframework.h"
#include "Logframework.h"
#include "UserInterface.h"
#include "FileHanlder.h"

int main()
{
	addline();
	addlog($start, "Program has started");

	try
	{
		menu_indev();
	}
	catch (std::string text)
	{
		std::cout << text;
	}
	catch (...)
	{

	}

	addKeyLog();
	addline();
	addlog($end, "Program has ended");
	addline();
}