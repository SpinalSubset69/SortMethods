#pragma once
#include "ArrayHandler.h";
#include "GuiHandler.h"
#include<thread>
#include "Chart.h"


namespace SortMehotds {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std::chrono;	
	
	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{	
	public:
		MyForm(void)
		{
			this->hArray = gcnew ArrayHandler();
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::PictureBox^ pictureBox2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::TextBox^ txt_generate;
	private: System::Windows::Forms::Button^ btn_generate;
	private: System::Windows::Forms::ComboBox^ sortOptions;












	private: System::Windows::Forms::Button^ btn_sort;
	private: System::Windows::Forms::Button^ btn_graph;	
	
	//Custom Variables
	private: int* array;
	private: ArrayHandler^ hArray;
	private: GuiHandler^ gHandler = gcnew GuiHandler();
	private: int nElements;	
	private: Chart^ chart = gcnew Chart();

	private: System::Windows::Forms::ListView^ lstview;
	private: System::Windows::Forms::ListView^ list;
	private: System::Windows::Forms::ColumnHeader^ Method;
	private: System::Windows::Forms::ColumnHeader^ Elements;
	private: System::Windows::Forms::ColumnHeader^ TotalTime;





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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->txt_generate = (gcnew System::Windows::Forms::TextBox());
			this->btn_generate = (gcnew System::Windows::Forms::Button());
			this->sortOptions = (gcnew System::Windows::Forms::ComboBox());
			this->btn_sort = (gcnew System::Windows::Forms::Button());
			this->btn_graph = (gcnew System::Windows::Forms::Button());
			this->lstview = (gcnew System::Windows::Forms::ListView());
			this->list = (gcnew System::Windows::Forms::ListView());
			this->Method = (gcnew System::Windows::Forms::ColumnHeader());
			this->Elements = (gcnew System::Windows::Forms::ColumnHeader());
			this->TotalTime = (gcnew System::Windows::Forms::ColumnHeader());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Cursor = System::Windows::Forms::Cursors::Hand;
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(1139, 12);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(50, 50);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->Click += gcnew System::EventHandler(this, &MyForm::pictureBox1_Click);
			// 
			// pictureBox2
			// 
			this->pictureBox2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.Image")));
			this->pictureBox2->Location = System::Drawing::Point(2, 1);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(515, 218);
			this->pictureBox2->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox2->TabIndex = 1;
			this->pictureBox2->TabStop = false;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 27.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label1->Location = System::Drawing::Point(612, 103);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(475, 42);
			this->label1->TabIndex = 2;
			this->label1->Text = L"Métodos de ordenamiento";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label2->Location = System::Drawing::Point(12, 239);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(197, 24);
			this->label2->TabIndex = 3;
			this->label2->Text = L"Números a generar:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->label3->Location = System::Drawing::Point(12, 349);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(171, 24);
			this->label3->TabIndex = 4;
			this->label3->Text = L"Método a Utilizar:";
			// 
			// txt_generate
			// 
			this->txt_generate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->txt_generate->Location = System::Drawing::Point(16, 265);
			this->txt_generate->Multiline = true;
			this->txt_generate->Name = L"txt_generate";
			this->txt_generate->Size = System::Drawing::Size(144, 27);
			this->txt_generate->TabIndex = 5;
			// 
			// btn_generate
			// 
			this->btn_generate->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->btn_generate->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_generate->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_generate->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_generate->Location = System::Drawing::Point(16, 304);
			this->btn_generate->Name = L"btn_generate";
			this->btn_generate->Size = System::Drawing::Size(144, 31);
			this->btn_generate->TabIndex = 6;
			this->btn_generate->Text = L"Generar";
			this->btn_generate->UseVisualStyleBackColor = false;
			this->btn_generate->Click += gcnew System::EventHandler(this, &MyForm::btn_generate_Click);
			// 
			// sortOptions
			// 
			this->sortOptions->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->sortOptions->FormattingEnabled = true;
			this->sortOptions->Items->AddRange(gcnew cli::array< System::Object^  >(5) {
				L"Burbuja", L"Inserción", L"Selección", L"Shell",
					L"Merge"
			});
			this->sortOptions->Location = System::Drawing::Point(16, 375);
			this->sortOptions->Name = L"sortOptions";
			this->sortOptions->Size = System::Drawing::Size(144, 28);
			this->sortOptions->TabIndex = 7;
			// 
			// btn_sort
			// 
			this->btn_sort->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->btn_sort->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_sort->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_sort->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_sort->Location = System::Drawing::Point(16, 408);
			this->btn_sort->Name = L"btn_sort";
			this->btn_sort->Size = System::Drawing::Size(144, 31);
			this->btn_sort->TabIndex = 11;
			this->btn_sort->Text = L"Ordenar";
			this->btn_sort->UseVisualStyleBackColor = false;
			this->btn_sort->Click += gcnew System::EventHandler(this, &MyForm::btn_sort_Click);
			// 
			// btn_graph
			// 
			this->btn_graph->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(30)), static_cast<System::Int32>(static_cast<System::Byte>(49)),
				static_cast<System::Int32>(static_cast<System::Byte>(99)));
			this->btn_graph->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->btn_graph->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->btn_graph->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->btn_graph->Location = System::Drawing::Point(16, 557);
			this->btn_graph->Name = L"btn_graph";
			this->btn_graph->Size = System::Drawing::Size(144, 31);
			this->btn_graph->TabIndex = 12;
			this->btn_graph->Text = L"Graficar";
			this->btn_graph->UseVisualStyleBackColor = false;
			this->btn_graph->Click += gcnew System::EventHandler(this, &MyForm::btn_graph_Click);
			// 
			// lstview
			// 
			this->lstview->HideSelection = false;
			this->lstview->Location = System::Drawing::Point(215, 238);
			this->lstview->Name = L"lstview";
			this->lstview->Size = System::Drawing::Size(384, 350);
			this->lstview->TabIndex = 13;
			this->lstview->UseCompatibleStateImageBehavior = false;
			// 
			// list
			// 
			this->list->Columns->AddRange(gcnew cli::array< System::Windows::Forms::ColumnHeader^  >(3) {
				this->Method, this->Elements,
					this->TotalTime
			});
			this->list->HideSelection = false;
			this->list->Location = System::Drawing::Point(619, 239);
			this->list->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->list->Name = L"list";
			this->list->Size = System::Drawing::Size(570, 350);
			this->list->TabIndex = 14;
			this->list->UseCompatibleStateImageBehavior = false;
			this->list->View = System::Windows::Forms::View::Details;
			// 
			// Method
			// 
			this->Method->Text = L"Method";
			this->Method->Width = 210;
			// 
			// Elements
			// 
			this->Elements->Text = L"Elements";
			this->Elements->Width = 288;
			// 
			// TotalTime
			// 
			this->TotalTime->Text = L"Total Time";
			this->TotalTime->Width = 635;
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(45)), static_cast<System::Int32>(static_cast<System::Byte>(70)),
				static_cast<System::Int32>(static_cast<System::Byte>(185)));
			this->ClientSize = System::Drawing::Size(1199, 600);
			this->Controls->Add(this->list);
			this->Controls->Add(this->lstview);
			this->Controls->Add(this->btn_graph);
			this->Controls->Add(this->btn_sort);
			this->Controls->Add(this->sortOptions);
			this->Controls->Add(this->btn_generate);
			this->Controls->Add(this->txt_generate);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->pictureBox2);
			this->Controls->Add(this->pictureBox1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::None;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Sort Methods";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			this->MouseDown += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseDown);
			this->MouseMove += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseMove);
			this->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::MyForm_MouseUp);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

#pragma region DragginRegion
		bool draggin;
		Point offset;

	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		draggin = false;
		gHandler->paintNumbersInTextArea(this->list);
	}
	private: System::Void MyForm_MouseDown(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		draggin = true;
		offset = Point(e->X, e->Y);
	}
	private: System::Void MyForm_MouseMove(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		if (draggin) {
			Point currentScreenPos = PointToScreen(e->Location);
			Location = Point(currentScreenPos.X - offset.X, currentScreenPos.Y - offset.Y);//Evitamos que el form se mueva a un lado del cursor
		}
	}
	private: System::Void MyForm_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e) {
		draggin = false;
	}
#pragma endregion
		   
	private: System::Void pictureBox1_Click(System::Object^ sender, System::EventArgs^ e) {
		this->Close();
	}
	private: System::Void btn_generate_Click(System::Object^ sender, System::EventArgs^ e) {
		int convert = 0;
		Int32::TryParse(this->txt_generate->Text, convert);		
		if (convert) {
			this->nElements = convert;			
			array = new int[nElements];
			hArray->generateRandomNumbersArray(this->array, this->nElements);				
			//gHandler->paintNumbersInTextArea(this->lstview, this->array, this->nElements);
		}
	}
		   private: void funct(String^ name) {
			   MessageBox::Show("Hola " + name);
		   }
	private: Void btn_sort_Click(Object^ sender, EventArgs^ e) {
		int optionSelected = this->sortOptions->SelectedIndex;
		hArray->SortArrayBasedOnMethod(this->array, this->nElements, optionSelected);
		return;		
}
private: System::Void btn_graph_Click(System::Object^ sender, System::EventArgs^ e) {	
	this->chart->LoadData();
	this->chart->Show();		
}
};
}
