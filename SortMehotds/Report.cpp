#include "Report.h"


Report::Report() {

}

Report::Report(String^ method, int nElements, String^ totalTime) {
	this->method = method;
	this->nElements = nElements;
	this->total_time = totalTime;
}

void Report::setMethod(String^ method) {
	this->method = method;
}

void Report::setElements(int elements) {
	this->nElements = elements;
}

void Report::setTotalTime(String^ total) {
	this->total_time = total;
}

String^ Report::getMethod() {
	return this->method;
}

int Report::getElements() {
	return this->nElements;
}

String^ Report::getTotalTime() {
	return this->total_time;
}