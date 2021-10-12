#pragma once

using namespace System;

ref class Report
{
private:
	String^ method;
	int nElements;
	String^ total_time;

public:
	Report();
	Report(String^, int, String^);
	void setMethod(String^);
	void setElements(int);
	void setTotalTime(String^);

	String^ getMethod();
	int getElements();
	String^ getTotalTime();
};

