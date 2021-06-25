#include <iostream>

#include "LogClass.h"

using namespace std;

void LogTest()
{
	//CreateSaveDir();
	//LOG log;
	//if (log.Open("C:/Users/mssevov18/Documents/Logs/logs.log"))
	//{
	//	log.Log(SEVERITY::INFO, "Program has started successfully");
	//	log.SaveLog();

	//	log.Close();
	//}

	LOG::CreateSaveDir();
	LOG log("C:/Users/mssevov18/Documents/Logs/logs.log", true);
	if (log.Is_Open())
	{
		log($info, "Program has started successfully");
		log($text, "Testing logggg");
		log($text, "(:");
		log($text, "So far so good");

		log.Close();
	}
}