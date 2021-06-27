#pragma once

#include <iostream>
#include <string>
#include <vector>

#include "WaterBody.h"
#include "Logframework.h"
#include "CtHframework.h"

void menu();

void menu_indev();

void Random(std::vector<WaterBody*>& vec);

void Add(std::vector<WaterBody*>& vec);

void Delete(std::vector<WaterBody*>& vec);

void Edit(std::vector<WaterBody*>& vec);

void Print(std::vector<WaterBody*>& vec);

void Sort(std::vector<WaterBody*>& vec);

void Upload(std::vector<WaterBody*>& vec, HTML& page);

void Unload(std::vector<WaterBody*>& vec, HTML& page);

void Save(std::vector<WaterBody*>& vec);

void Load(std::vector<WaterBody*>& vec);

void CheckStingInput(std::string &test);

void CheckNumberInput(float &test);

void CheckBoolInput(bool &test);

void ErrorMessageForInput();

void RepairIfCinFail();