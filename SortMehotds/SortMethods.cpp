#include "SortMethods.h"

 SortMethods::SortMethods() {	
}

 void SortMethods::SortArrayBaseOnMethod(int* array, int nElements, int method) {
	 switch (method) {
	 case 0:
		 this->BurbleSort(array, nElements);
		 break;
	 }
 }

void SortMethods::BurbleSort(int* array, int nElements) {
	for (int i = 0; i < nElements; i++) {
		for (int j = 0; j < nElements - 1; j++) {
			if (*(array + j + 1) < *(array + j)){					
				this->Exchange(*(array + j), *(array + j + 1 ));
			}
		}
	}
}

void SortMethods::Exchange(int & x, int &y) {
	int aux = x;
	x = y;
	y = aux;
}

