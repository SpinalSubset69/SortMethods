#pragma once
#include<fstream>
#include<iostream>
#include<string>
#include <chrono>

#include "Report.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace std::chrono;

ref class FileHandler
{	
private: 
	int count = 0;
	String^ file_name;
	String^ folder_path;

public:
	FileHandler();

public:
	void WriteInfo(String^, int, String^);
	List<Report^>^ GetReports();
private: Report^ getReportFromDocument(array<String^>^);
private: int getCountArchives(String^ method);
};

