#include "ReportRepository.h"

ReportRepository::ReportRepository() {
	this->lst_reports = gcnew List<Report^>();
	this->fileHandler = gcnew FileHandler();
	this->lst_reports = this->fileHandler->GetReports();
}

List<Report^>^ ReportRepository::GetInstanceOfRepository() {
	if (!this->lst_reports) {
		this->lst_reports = gcnew List<Report^>();
		this->lst_reports = this->fileHandler->GetReports();
	}

	return this->lst_reports;
}

void ReportRepository::AddReport(Report^ report) {
	auto lst = this->GetInstanceOfRepository();
	this->fileHandler->WriteInfo(report->getMethod(), report->getElements(), report->getTotalTime());
	lst->Add(report);
}

void ReportRepository::DeleteReports() {
	this->lst_reports->Clear();
}

List<Report^>^ ReportRepository::GetReports() {
	return this->lst_reports;
}