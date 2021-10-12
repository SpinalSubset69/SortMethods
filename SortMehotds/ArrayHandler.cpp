#include "ArrayHandler.h"

ArrayHandler::ArrayHandler() {
	this->_repo = gcnew ReportRepository();
	this->sort = gcnew SortMethods();
}

void ArrayHandler::generateRandomNumbersArray(int* array, int nElements) {
	
	auto start = high_resolution_clock::now();
	srand(time(0));
	for (int i = 0; i < nElements; i++) {
		*(array + i) = rand() % 10000000;
	}
	auto end = high_resolution_clock::now();
	duration<double> total_time = end - start;
	System::Windows::Forms::MessageBox::Show("El array se lleno en " + total_time.count() + " segundos");
}

void ArrayHandler::SortArrayBasedOnMethod(int* array, int nElements, int method) {
	String^ methodName = "";
	switch (method) {
	case 0:
		methodName = "Burbuja";
		break;
	case 1:
		methodName = "Insercion";
		break;
	}

	auto start = high_resolution_clock::now();
	this->sort->SortArrayBaseOnMethod(array, nElements, 0);
	auto end = high_resolution_clock::now();
	duration<double> total_time = end - start;
	System::Windows::Forms::MessageBox::Show("Total time= " + total_time.count());
	this->report = gcnew Report(methodName, nElements, total_time.count().ToString());
	this->_repo->AddReport(report);
}