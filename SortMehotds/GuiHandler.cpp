#include "GuiHandler.h"


GuiHandler::GuiHandler() {
	this->fHandler = gcnew FileHandler();
}

void GuiHandler::paintNumbersInTextArea(ListView^ reports_view) {
	List<Report^>^ reports = this->fHandler->GetReports();	
		
}
