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

constexpr int $critical = 0;
constexpr int $error    = 1;
constexpr int $warning  = 2;
constexpr int $debug    = 3;
constexpr int $info     = 4;
constexpr int $text     = 5;
constexpr int $start    = 6;
constexpr int $end      = 7;

std::string SeverityToString(int severity);

const std::string _logpath = "../log.log";

void addlog(const int& severity, const std::string& message);

void addline(const int& amount = 1);

char _lgetch();

void addKeyLog();
