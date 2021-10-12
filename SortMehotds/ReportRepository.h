#pragma once
#include "Report.h"
#include "FileHandler.h"

using namespace System::Collections::Generic;
ref class ReportRepository
{
private: List<Report^>^ lst_reports;
private: FileHandler^ fileHandler;

public: ReportRepository();

private: List<Report^>^ GetInstanceOfRepository();
public: void AddReport(Report^);
public: List<Report^>^ GetReports();
public: void DeleteReports();

};

