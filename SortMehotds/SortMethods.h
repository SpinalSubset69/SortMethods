#pragma once
using namespace System;

ref class SortMethods
{
public:
	SortMethods();
	public:
		void BurbleSort(int*, int);			
		void SortArrayBaseOnMethod(int*, int, int);
	private: 
		void Exchange(int&, int&);
};

