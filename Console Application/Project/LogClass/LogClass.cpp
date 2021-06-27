#include "LogClass.h"

#include "conio.h"

using namespace std;

string AddLeadingZeroes(int num)
{
	string temp = "";
	if (num < 10 and num >= 0)
		temp += L'0';
	temp += to_string(num);
	return temp;
}

tm getTimeStamp()
{
	tm timeStamp;
	time_t _t;
	time(&_t);
	localtime_s(&timeStamp, &_t);
	return timeStamp;
}

string TmToDateString(tm tm, char delimiter)
{
	return string(
			AddLeadingZeroes(tm.tm_year + 1900) + delimiter +
			AddLeadingZeroes(tm.tm_mon + 1) + delimiter +
			AddLeadingZeroes(tm.tm_mday)
		);
}

string TmToTimeString(tm tm, char delimiter)
{
	return string(
			AddLeadingZeroes(tm.tm_hour) + delimiter +
			AddLeadingZeroes(tm.tm_min) + delimiter + 
			AddLeadingZeroes(tm.tm_sec)
		);
}

string SeverityToString(int severity)
{
	switch (severity)
	{
	case $critical:
		return "<CRITICAL> - ";
	case $error:
		return "|ERROR|    - ";
	case $warning:
		return "{WARNING}  - ";
	case $debug:
		return "[DEBUG]    - ";
	case $info:
		return "(INFO)     - ";
	case $text:
		return "";
	default:
		return "~UNKNOWN~  - ";
	}
}

void addlog(const int& severity, const string& message)
{
	fstream file;
	file.open(_logpath, ios::out | ios::app);
	if (!file.is_open())
		return;
	tm timeStamp = getTimeStamp();
	switch (severity)
	{
	case $text:
		file << message << '\n';
		break;
	case $start:
		file << string(
			"Program has started at: " + 
			TmToDateString(timeStamp) + ' ' +
			TmToTimeString(timeStamp) + '\n'
		);
		break;
	case $end:
		file << string(
			"Program has ended   at: " + 
			TmToDateString(timeStamp) + ' ' +
			TmToTimeString(timeStamp) + '\n'
		);
		break;
	default:
		file << string(
			TmToDateString(timeStamp) + ' ' +
			TmToTimeString(timeStamp) + ' ' +
			SeverityToString(severity) + ' ' +
			message + '\n'
		);
		break;
	}
	file.close();
}

void addline(const int& amount)
{
	fstream file;
	file.open(_logpath, ios::out | ios::app);
	if (!file.is_open())
		return;
	for (int i = 0; i < amount; i++)
		file << '\n';
	file.close();
}

vector<char> keylogger;

char _lgetch()
{
	keylogger.push_back(_getch());
	return keylogger[keylogger.size() - 1];
}

void addKeyLog()
{
	fstream file;
	file.open(_logpath, ios::out | ios::app);
	if (!file.is_open())
		return;
	file << "Keys ASCII (" + to_string(keylogger.size()) + "): ";
	for (size_t i = 0; i < keylogger.size(); i++)
		file << to_string(int(keylogger[i])) + ' ';
	file.close();
}
