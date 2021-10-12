#include "FileHandler.h"

FileHandler::FileHandler() {
	String^ root_path = System::Reflection::Assembly::GetExecutingAssembly()->Location;
	char split = '\\';
	array<String^>^ folder_path_split = root_path->Split(split);
	String^ new_folder_path = "";
	for (int i = 0; i < folder_path_split->Length; i++) {
		if (folder_path_split[i] == "Debug") {
			break;
		}
		new_folder_path += folder_path_split[i] + "\\";
	}
	String^ archives_folder_path = IO::Path::Combine(new_folder_path, "\Archives");	
	if (!IO::Directory::Exists(archives_folder_path)) {
		IO::Directory::CreateDirectory(archives_folder_path);
	}
	this->folder_path = archives_folder_path;
}

void FileHandler::WriteInfo(String^ method, int nElements, String^ time) {		
	int archive_number = this->getCountArchives(method);
	String^ new_file_name = method + archive_number + ".txt";	
	this->file_name = IO::Path::Combine(this->folder_path, new_file_name);	
	try {
		IO::StreamWriter^ myFile = gcnew IO::StreamWriter(this->file_name);
		myFile->WriteLine("--------------Métodos de ordenamiento--------------");
		myFile->WriteLine("Method: " + method);
		myFile->WriteLine("Elements: " + nElements);
		myFile->WriteLine("Time Execution: " + time);
		myFile->Close();
	}
	catch (System::Exception^ ex) {
		System::Windows::Forms::MessageBox::Show("Error" + ex->StackTrace);
	}
	this->count = 0;	
}

List<Report^>^ FileHandler::GetReports() {
	List<Report^>^ lst_reports = gcnew List<Report^>();	
	IEnumerable<String^>^ archives = IO::Directory::EnumerateFiles(this->folder_path);	
	for each (auto archive in archives)
	{
		if (!String::IsNullOrEmpty(archive)) {
			try {
				IO::StreamReader^ sreader = gcnew IO::StreamReader(archive);
				String^ buffer = "";
				buffer += sreader->ReadToEnd();
				char split = '\n';
				array<String^>^ buffer_split = buffer->Split(split);				
				lst_reports->Add(getReportFromDocument(buffer_split));
				sreader->Close();
			}
			catch (System::Exception^ ex) {
				System::Windows::Forms::MessageBox::Show("Error = " + ex->StackTrace);
			}			
		}		
	}
	return lst_reports;
}

Report^ FileHandler::getReportFromDocument(array<String^>^ buffer_split) {
	Report^ report = gcnew Report();
	for (int i = 1; i < buffer_split->Length; i++) {
		char split_space = ' ';
		int elements = 0;
		switch (i) {
		case 1:
			report->setMethod(buffer_split[i]->Split(split_space)[1]);
			break;
		case 2:
			Int32::TryParse(buffer_split[i]->Split(split_space)[1], elements);
			report->setElements(elements);
			break;
		case 3:
			report->setTotalTime(buffer_split[i]->Split(split_space)[2]);
			break;
		default:
			break;

		}
	}
	return report;
}

int FileHandler::getCountArchives(String^ method) {
	IEnumerable<String^>^ archives = IO::Directory::EnumerateFiles(this->folder_path);
	for each (auto archive in archives)
	{
		if (archive->Contains(method)) {
			this->count++;
		}

	}
	return this->count + 1;
}