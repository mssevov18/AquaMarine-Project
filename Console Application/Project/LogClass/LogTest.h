#include <iostream>

#include "LogClass.h"

using namespace std;

void LogTest()
{
	addlog($debug, "Start of test");
	addline();
	addlog($text, "Textttt :|");
	addline(5);
	addlog($text, "Example severity levels");
	addlog($critical, "Critical");
	addlog($error, "Error");
	addlog($warning, "Warning");
	addlog($debug, "Debug");
	addlog($info, "Info");
	addlog($text, "Text");
	addlog($text, "end of log");
}