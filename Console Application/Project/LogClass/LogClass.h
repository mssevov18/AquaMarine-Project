#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>

std::string AddLeadingZeroes(int num);

tm getTimeStamp();

std::string TmToDateString(tm tm, char delimiter = '-');

std::string TmToTimeString(tm tm, char delimiter = ':');

enum class SEVERITY
{
	CRITICAL = 0,
	ERROR = 1,
	WARNING = 2,
	DEBUG = 3,
	INFO = 4,
	TEXT = 5
};

#define $critical SEVERITY::CRITICAL
#define $error    SEVERITY::ERROR
#define $warning  SEVERITY::WARNING
#define $debug    SEVERITY::DEBUG
#define $info     SEVERITY::INFO
#define $text     SEVERITY::TEXT

std::string SeverityToString(SEVERITY severity);

//Date Time Severity Message
class LOG
{
public:
	LOG(bool ornamental = false);
	LOG(const std::string& path, bool ornamental = false);

	static void CreateSaveDir();

private:
	tm            timeStamp; //Log's time stamp
	enum SEVERITY severity;  //Log's severity
	std::string   message;   //Log's message

	bool         ornamental;
	std::fstream logFstream;

public:
	void PrintLog();
	void Log(SEVERITY severity, const std::string& message);

	std::string LogToString(char delimiter = ' ');

	void operator()(SEVERITY severity, std::string message);

	void Close();
	bool Open(const std::string& path);
	bool Is_Open();
	void Clear(const std::string& path);
};