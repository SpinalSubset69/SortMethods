#pragma once

#include "FileHandler.h"
#include "ReportRepository.h"

namespace SortMehotds {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;		

	/// <summary>
	/// Resumen de Chart
	/// </summary>
	public ref class Chart : public System::Windows::Forms::Form
	{
	private: ReportRepository^ _repo;
	public:
		Chart(void)
		{
			fHandler = gcnew FileHandler();
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Chart()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::DataVisualization::Charting::Chart^ chart1;

	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: FileHandler^ fHandler;

	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{			
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Title^ title1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::Windows::Forms::DataVisualization::Charting::Title^ title2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Title());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Chart::typeid));
			this->chart1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// chart1
			// 
			this->chart1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(254)), static_cast<System::Int32>(static_cast<System::Byte>(241)),
				static_cast<System::Int32>(static_cast<System::Byte>(230)));
			this->chart1->BackGradientStyle = System::Windows::Forms::DataVisualization::Charting::GradientStyle::Center;
			this->chart1->BackSecondaryColor = System::Drawing::Color::White;
			this->chart1->BorderlineWidth = 0;
			this->chart1->BorderSkin->BackColor = System::Drawing::Color::Transparent;
			this->chart1->BorderSkin->BackSecondaryColor = System::Drawing::Color::White;
			chartArea1->Name = L"ChartArea1";
			this->chart1->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			this->chart1->Legends->Add(legend1);
			this->chart1->Location = System::Drawing::Point(0, 64);
			this->chart1->Name = L"chart1";
			this->chart1->Palette = System::Windows::Forms::DataVisualization::Charting::ChartColorPalette::Excel;
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
			series1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			series1->Legend = L"Legend1";
			series1->Name = L"Burbuja";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Bar;
			series2->Legend = L"Legend1";
			series2->Name = L"Insercion";
			this->chart1->Series->Add(series1);
			this->chart1->Series->Add(series2);
			this->chart1->Size = System::Drawing::Size(1346, 642);
			this->chart1->TabIndex = 0;
			this->chart1->Text = L"Gráfica";
			title1->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Left;
			title1->Font = (gcnew System::Drawing::Font(L"Consolas", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title1->Name = L"t_ejecucion";
			title1->Text = L"Tiempo de Ejecución";
			title2->Docking = System::Windows::Forms::DataVisualization::Charting::Docking::Bottom;
			title2->Font = (gcnew System::Drawing::Font(L"Consolas", 10.2F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			title2->Name = L"Title1";
			title2->Text = L"Elementos ordenados";
			this->chart1->Titles->Add(title1);
			this->chart1->Titles->Add(title2);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Consolas", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(56, 20);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(322, 24);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Gráfica Ejecución Métodos:";
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1285, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 3;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &Chart::pictureBox1_Click);
			// 
			// Chart
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(1347, 706);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->chart1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Name = L"Chart";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Chart";
			this->Load += gcnew System::EventHandler(this, &Chart::Chart_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &Chart::Chart_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &Chart::Chart_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &Chart::Chart_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->chart1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
		
		
#pragma endregion
#pragma region Draggin
		bool draggin;
		Point offset;
		private: System::Void Chart_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
			draggin = true;
			offset = Point(e->X, e->Y);
		}
private: System::Void Chart_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	if (draggin) {
		Point currentScreenPos = PointToScreen(e->Location);
		Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);//Evitamos que el form se mueva a un lado del cursor
	}
}
private: System::Void Chart_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
	draggin = false;
}
#pragma endregion

	private: System::Void Chart_Load(System::Object^ sender, System::EventArgs^ e) {
		draggin = false;	
		
	}


private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
	this->Hide();
}
public: void  LoadData() {	
	this->_repo = gcnew ReportRepository();
	for each (Report ^ report in _repo->GetReports()) {		
		//System::Windows::Forms::MessageBox::Show("Total Time: " + report->getTotalTime());
		this->chart1->Series["Burbuja"]->Points->AddXY(report->getTotalTime() + " Segundos", report->getElements().ToString());
	}
}
};
}
