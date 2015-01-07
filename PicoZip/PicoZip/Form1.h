#pragma once

namespace PicoZip {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TabControl^  tabControl;
	protected: 

	protected: 
	private: System::Windows::Forms::TabPage^  Compress;
	private: System::Windows::Forms::Label^  compressFileNameLabel;
	private: System::Windows::Forms::TextBox^  compressFileNameBox;


	private: System::Windows::Forms::TabPage^  Decompress;
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  compressButton;

	private: System::Windows::Forms::Panel^  panel2;
	private: System::Windows::Forms::Label^  compressSaveLabel;
	private: System::Windows::Forms::TextBox^  compressSaveBox;
	private: System::Windows::Forms::Button^  decompressButton;



	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Label^  decompressSaveLabel;
	private: System::Windows::Forms::TextBox^  decompressSaveBox;


	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  decompressFileNameLabel;
	private: System::Windows::Forms::TextBox^  decompressFileNameBox;



	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->Compress = (gcnew System::Windows::Forms::TabPage());
			this->compressButton = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->compressSaveLabel = (gcnew System::Windows::Forms::Label());
			this->compressSaveBox = (gcnew System::Windows::Forms::TextBox());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->compressFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->compressFileNameBox = (gcnew System::Windows::Forms::TextBox());
			this->Decompress = (gcnew System::Windows::Forms::TabPage());
			this->decompressButton = (gcnew System::Windows::Forms::Button());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->decompressSaveLabel = (gcnew System::Windows::Forms::Label());
			this->decompressSaveBox = (gcnew System::Windows::Forms::TextBox());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->decompressFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->decompressFileNameBox = (gcnew System::Windows::Forms::TextBox());
			this->tabControl->SuspendLayout();
			this->Compress->SuspendLayout();
			this->panel2->SuspendLayout();
			this->panel1->SuspendLayout();
			this->Decompress->SuspendLayout();
			this->panel3->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->Compress);
			this->tabControl->Controls->Add(this->Decompress);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(284, 262);
			this->tabControl->TabIndex = 0;
			// 
			// Compress
			// 
			this->Compress->Controls->Add(this->compressButton);
			this->Compress->Controls->Add(this->panel2);
			this->Compress->Controls->Add(this->panel1);
			this->Compress->Location = System::Drawing::Point(4, 22);
			this->Compress->Name = L"Compress";
			this->Compress->Padding = System::Windows::Forms::Padding(3);
			this->Compress->Size = System::Drawing::Size(276, 236);
			this->Compress->TabIndex = 0;
			this->Compress->Text = L"Compress";
			this->Compress->UseVisualStyleBackColor = true;
			// 
			// compressButton
			// 
			this->compressButton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->compressButton->Location = System::Drawing::Point(3, 210);
			this->compressButton->Name = L"compressButton";
			this->compressButton->Size = System::Drawing::Size(270, 23);
			this->compressButton->TabIndex = 4;
			this->compressButton->Text = L"Compress";
			this->compressButton->UseVisualStyleBackColor = true;
			this->compressButton->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// panel2
			// 
			this->panel2->Controls->Add(this->compressSaveLabel);
			this->panel2->Controls->Add(this->compressSaveBox);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(3, 103);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(270, 100);
			this->panel2->TabIndex = 3;
			// 
			// compressSaveLabel
			// 
			this->compressSaveLabel->AutoSize = true;
			this->compressSaveLabel->Location = System::Drawing::Point(-3, 43);
			this->compressSaveLabel->Name = L"compressSaveLabel";
			this->compressSaveLabel->Size = System::Drawing::Size(82, 13);
			this->compressSaveLabel->TabIndex = 1;
			this->compressSaveLabel->Text = L"Save output as:";
			this->compressSaveLabel->Click += gcnew System::EventHandler(this, &Form1::label2_Click);
			// 
			// compressSaveBox
			// 
			this->compressSaveBox->Location = System::Drawing::Point(97, 40);
			this->compressSaveBox->Name = L"compressSaveBox";
			this->compressSaveBox->Size = System::Drawing::Size(170, 20);
			this->compressSaveBox->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->compressFileNameLabel);
			this->panel1->Controls->Add(this->compressFileNameBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(3, 3);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(270, 100);
			this->panel1->TabIndex = 2;
			// 
			// compressFileNameLabel
			// 
			this->compressFileNameLabel->AutoSize = true;
			this->compressFileNameLabel->Location = System::Drawing::Point(-3, 43);
			this->compressFileNameLabel->Name = L"compressFileNameLabel";
			this->compressFileNameLabel->Size = System::Drawing::Size(87, 13);
			this->compressFileNameLabel->TabIndex = 1;
			this->compressFileNameLabel->Text = L"File to Compress:";
			this->compressFileNameLabel->Click += gcnew System::EventHandler(this, &Form1::label1_Click);
			// 
			// compressFileNameBox
			// 
			this->compressFileNameBox->Location = System::Drawing::Point(97, 40);
			this->compressFileNameBox->Name = L"compressFileNameBox";
			this->compressFileNameBox->Size = System::Drawing::Size(170, 20);
			this->compressFileNameBox->TabIndex = 0;
			this->compressFileNameBox->TextChanged += gcnew System::EventHandler(this, &Form1::textBox1_TextChanged);
			// 
			// Decompress
			// 
			this->Decompress->Controls->Add(this->decompressButton);
			this->Decompress->Controls->Add(this->panel3);
			this->Decompress->Controls->Add(this->panel4);
			this->Decompress->Location = System::Drawing::Point(4, 22);
			this->Decompress->Name = L"Decompress";
			this->Decompress->Padding = System::Windows::Forms::Padding(3);
			this->Decompress->Size = System::Drawing::Size(276, 236);
			this->Decompress->TabIndex = 1;
			this->Decompress->Text = L"Decompress";
			this->Decompress->UseVisualStyleBackColor = true;
			// 
			// decompressButton
			// 
			this->decompressButton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->decompressButton->Location = System::Drawing::Point(3, 210);
			this->decompressButton->Name = L"decompressButton";
			this->decompressButton->Size = System::Drawing::Size(270, 23);
			this->decompressButton->TabIndex = 7;
			this->decompressButton->Text = L"Decompress";
			this->decompressButton->UseVisualStyleBackColor = true;
			this->decompressButton->Click += gcnew System::EventHandler(this, &Form1::decompressButton_Click);
			// 
			// panel3
			// 
			this->panel3->Controls->Add(this->decompressSaveLabel);
			this->panel3->Controls->Add(this->decompressSaveBox);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel3->Location = System::Drawing::Point(3, 103);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(270, 100);
			this->panel3->TabIndex = 6;
			// 
			// decompressSaveLabel
			// 
			this->decompressSaveLabel->AutoSize = true;
			this->decompressSaveLabel->Location = System::Drawing::Point(-3, 43);
			this->decompressSaveLabel->Name = L"decompressSaveLabel";
			this->decompressSaveLabel->Size = System::Drawing::Size(82, 13);
			this->decompressSaveLabel->TabIndex = 1;
			this->decompressSaveLabel->Text = L"Save output as:";
			// 
			// decompressSaveBox
			// 
			this->decompressSaveBox->Location = System::Drawing::Point(97, 40);
			this->decompressSaveBox->Name = L"decompressSaveBox";
			this->decompressSaveBox->Size = System::Drawing::Size(170, 20);
			this->decompressSaveBox->TabIndex = 0;
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->decompressFileNameLabel);
			this->panel4->Controls->Add(this->decompressFileNameBox);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(3, 3);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(270, 100);
			this->panel4->TabIndex = 5;
			// 
			// decompressFileNameLabel
			// 
			this->decompressFileNameLabel->AutoSize = true;
			this->decompressFileNameLabel->Location = System::Drawing::Point(-3, 43);
			this->decompressFileNameLabel->Name = L"decompressFileNameLabel";
			this->decompressFileNameLabel->Size = System::Drawing::Size(100, 13);
			this->decompressFileNameLabel->TabIndex = 1;
			this->decompressFileNameLabel->Text = L"File to Decompress:";
			// 
			// decompressFileNameBox
			// 
			this->decompressFileNameBox->Location = System::Drawing::Point(97, 40);
			this->decompressFileNameBox->Name = L"decompressFileNameBox";
			this->decompressFileNameBox->Size = System::Drawing::Size(170, 20);
			this->decompressFileNameBox->TabIndex = 0;
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 262);
			this->Controls->Add(this->tabControl);
			this->Name = L"Form1";
			this->Text = L"Pico Zip";
			this->tabControl->ResumeLayout(false);
			this->Compress->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->Decompress->ResumeLayout(false);
			this->panel3->ResumeLayout(false);
			this->panel3->PerformLayout();
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void textBox1_TextChanged(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void label2_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
		 {
		 }
private: System::Void decompressButton_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}

