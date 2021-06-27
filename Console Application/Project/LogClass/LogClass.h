#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <ctime>
#include <vector>

std::string AddLeadingZeroes(int num);

tm getTimeStamp();

std::string TmToDateString(tm tm, char delimiter = '-');

std::string TmToTimeString(tm tm, char delimiter = ':');

#define $critical 0
#define $error    1
#define $warning  2
#define $debug    3
#define $info     4
#define $text     5
#define $start    6
#define $end      7

std::string SeverityToString(int severity);

const std::string _logpath = "../log.log";

void addlog(const int& severity, const std::string& message);

void addline(const int& amount = 1);

char _lgetch();

void addKeyLog();
