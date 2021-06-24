#pragma once

#include <iostream>
#include <vector>
#include <string>

#include "WaterBody.h"

std::string createTable(std::vector<WaterBody>& vec, const std::string& __class = "", const std::string& __style = "");

void saveWaterBodiesToFile(std::vector<WaterBody>& vec, const std::string& path, const std::string& filename);

void loadWaterBodiesFromFile(std::vector<WaterBody>& vec, const std::string& path, const std::string& filename);
