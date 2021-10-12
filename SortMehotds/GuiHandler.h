#pragma once

#include<string>

#include "FileHandler.h"

using namespace System::Windows::Forms;
using namespace System;


ref class GuiHandler {
private:
	FileHandler^ fHandler;;
public:
	GuiHandler();
	void paintNumbersInTextArea(ListView^);
};
