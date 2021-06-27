
#include <iostream>

#include "WaterBody.h"
#include "CtHframework.h"
#include "Logframework.h"
#include "UserInterface.h"
#include "FileHanlder.h"

int main()
{
	addlog($start, "Program has started");

	//menu();
	//cout << "\n\n:)  Menu ends here  (:\n\n\n\n\n\n";
	menu_indev();

	addKeyLog();
	addline();
	addlog($end, "Program has ended");
	addline();
}