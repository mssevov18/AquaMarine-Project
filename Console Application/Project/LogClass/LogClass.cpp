#include "LogClass.h"


std::string AddLeadingZeroes(int num)
{
	std::string temp = "";
	if (num < 10 and num >= 0)
		temp += L'0';
	temp += std::to_string(num);
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

std::string TmToDateString(tm tm, char delimiter)
{
	std::string out = "";
	out += AddLeadingZeroes(tm.tm_year + 1900) + delimiter;
	out += AddLeadingZeroes(tm.tm_mon + 1) + delimiter;
	out += AddLeadingZeroes(tm.tm_mday);
	return out;
}

std::string TmToTimeString(tm tm, char delimiter)
{
	std::string out = "";
	out += AddLeadingZeroes(tm.tm_hour) + delimiter;
	out += AddLeadingZeroes(tm.tm_min) + delimiter;
	out += AddLeadingZeroes(tm.tm_sec);
	return out;
}

std::string SeverityToString(SEVERITY severity)
{
	switch (severity)
	{
	case $critical:
		return "!#CRITICAL#!";
	case $error:
		return "!?ERROR?!";
	case $warning:
		return "?WARNING?";
	case $debug:
		return "$DEBUG$";
	case $info:
		return "-INFO-";
	case $text:
		return "";
	default:
		return "?? UNKNOWN ??";
	}
}

void LOG::Log(SEVERITY severity, const std::string& message)
{
	this->severity = severity;
	this->message = message;
	this->timeStamp = getTimeStamp();
}

void LOG::operator()(SEVERITY severity, std::string message)
{
	this->severity = severity;
	this->message = message;
	this->timeStamp = getTimeStamp();
	logFstream << LogToString() << '\n';
}

std::string LOG::LogToString(char delimiter)
{
	if (severity == $text)
		return (message);
	return (
		TmToDateString(timeStamp) + delimiter +
		TmToTimeString(timeStamp) + delimiter +
		SeverityToString(severity) + delimiter +
		message
		);
}

LOG::LOG(bool ornamental)
{
	this->severity = $info;
	this->message = "";
	this->ornamental = ornamental;
}

LOG::LOG(const std::string& path, bool ornamental)
{
	this->ornamental = ornamental;
	this->Open("C:/Users/mssevov18/Documents/Logs/logs.log");
}

void LOG::CreateSaveDir()
{
	system("mkdir C:/Logs");
	system("mkdir C:/Logs/Log-class");
	system("cls");
}

void LOG::PrintLog()
{
	std::cout << LogToString() << "\n";
}

void LOG::Close()
{
	this->timeStamp = getTimeStamp();
	logFstream << "\n" << TmToDateString(timeStamp) << " " << TmToTimeString(timeStamp) << "\n";
	if (ornamental)
		logFstream << "====  ====  ====| End  of  Log |====  ====  ====\n\n";
	else
		logFstream << "End of Log\n\n";
	logFstream.close();
}

bool LOG::Open(const std::string& path)
{
	logFstream.open(path, std::ios::out | std::ios::app);
	if (logFstream.is_open())
	{
		this->timeStamp = getTimeStamp();
		if (ornamental)
			logFstream << "====  ====  ====| Start of Log |====  ====  ====\n";
		else
			logFstream << "Start of Log\n";
		logFstream << TmToDateString(timeStamp) << " " << TmToTimeString(timeStamp) << "\n\n";
		return true;
	}
	return false;
}

bool LOG::Is_Open()
{
	return logFstream.is_open();
}

void LOG::Clear(const std::string& path)
{
	if (logFstream.is_open())
		logFstream.close();
	logFstream.open(path, std::ios::out | std::ios::trunc);
	logFstream.close();

}
