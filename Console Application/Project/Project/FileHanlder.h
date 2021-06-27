#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "WaterBody.h"

std::string createTable(std::vector<WaterBody*>& vec, const std::string& __class = "", const std::string& __style = "");

bool saveWaterBodiesToFile(std::vector<WaterBody*>& vec, const std::string& path, const std::string& filename);

bool loadWaterBodiesFromFile(std::vector<WaterBody*>& vec, const std::string& path, const std::string& filename);
