#pragma once

#include<time.h>
#include <stdlib.h>
#include<chrono>
#include "ReportRepository.h"
#include "Report.h"
#include "SortMethods.h"

using namespace std::chrono;
ref class ArrayHandler {
private: ReportRepository^ _repo;
private: Report^ report;
private: SortMethods^ sort;
public:
	ArrayHandler();
	/// <summary>
	/// Rellena un array con números aleatorios
	/// </summary>
	/// <param name="array">Arreglo a rellenar</param>
	/// <param name="nElements">Númnero de elementos para el array</param>
	void generateRandomNumbersArray(int*, int);
	void SortArrayBasedOnMethod(int*, int, int);
};