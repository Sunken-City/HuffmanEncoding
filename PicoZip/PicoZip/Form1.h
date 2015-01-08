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




	private: System::Windows::Forms::Button^  decompressButton;








	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Label^  decompressFileNameLabel;
	private: System::Windows::Forms::TextBox^  decompressFileNameBox;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;

	private: System::Windows::Forms::SaveFileDialog^  saveFileDialog1;
	private: System::Windows::Forms::Button^  button2;




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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->Compress = (gcnew System::Windows::Forms::TabPage());
			this->compressButton = (gcnew System::Windows::Forms::Button());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->compressFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->compressFileNameBox = (gcnew System::Windows::Forms::TextBox());
			this->Decompress = (gcnew System::Windows::Forms::TabPage());
			this->decompressButton = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->decompressFileNameLabel = (gcnew System::Windows::Forms::Label());
			this->decompressFileNameBox = (gcnew System::Windows::Forms::TextBox());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->saveFileDialog1 = (gcnew System::Windows::Forms::SaveFileDialog());
			this->tabControl->SuspendLayout();
			this->Compress->SuspendLayout();
			this->panel1->SuspendLayout();
			this->Decompress->SuspendLayout();
			this->panel4->SuspendLayout();
			this->SuspendLayout();
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->Compress);
			this->tabControl->Controls->Add(this->Decompress);
			this->tabControl->Dock = System::Windows::Forms::DockStyle::Fill;
			this->tabControl->Location = System::Drawing::Point(0, 0);
			this->tabControl->Margin = System::Windows::Forms::Padding(4);
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			this->tabControl->Size = System::Drawing::Size(379, 322);
			this->tabControl->TabIndex = 0;
			// 
			// Compress
			// 
			this->Compress->Controls->Add(this->compressButton);
			this->Compress->Controls->Add(this->panel1);
			this->Compress->Location = System::Drawing::Point(4, 25);
			this->Compress->Margin = System::Windows::Forms::Padding(4);
			this->Compress->Name = L"Compress";
			this->Compress->Padding = System::Windows::Forms::Padding(4);
			this->Compress->Size = System::Drawing::Size(371, 293);
			this->Compress->TabIndex = 0;
			this->Compress->Text = L"Compress";
			this->Compress->UseVisualStyleBackColor = true;
			// 
			// compressButton
			// 
			this->compressButton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->compressButton->Location = System::Drawing::Point(4, 261);
			this->compressButton->Margin = System::Windows::Forms::Padding(4);
			this->compressButton->Name = L"compressButton";
			this->compressButton->Size = System::Drawing::Size(363, 28);
			this->compressButton->TabIndex = 4;
			this->compressButton->Text = L"Compress";
			this->compressButton->UseVisualStyleBackColor = true;
			this->compressButton->Click += gcnew System::EventHandler(this, &Form1::compressButton_Click);
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->button1);
			this->panel1->Controls->Add(this->compressFileNameLabel);
			this->panel1->Controls->Add(this->compressFileNameBox);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel1->Location = System::Drawing::Point(4, 4);
			this->panel1->Margin = System::Windows::Forms::Padding(4);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(363, 123);
			this->panel1->TabIndex = 2;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(206, 78);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Browse";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// compressFileNameLabel
			// 
			this->compressFileNameLabel->AutoSize = true;
			this->compressFileNameLabel->Location = System::Drawing::Point(-4, 53);
			this->compressFileNameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->compressFileNameLabel->Name = L"compressFileNameLabel";
			this->compressFileNameLabel->Size = System::Drawing::Size(117, 17);
			this->compressFileNameLabel->TabIndex = 1;
			this->compressFileNameLabel->Text = L"File to Compress:";
			// 
			// compressFileNameBox
			// 
			this->compressFileNameBox->Location = System::Drawing::Point(129, 49);
			this->compressFileNameBox->Margin = System::Windows::Forms::Padding(4);
			this->compressFileNameBox->Name = L"compressFileNameBox";
			this->compressFileNameBox->Size = System::Drawing::Size(225, 22);
			this->compressFileNameBox->TabIndex = 0;
			// 
			// Decompress
			// 
			this->Decompress->Controls->Add(this->decompressButton);
			this->Decompress->Controls->Add(this->panel4);
			this->Decompress->Location = System::Drawing::Point(4, 25);
			this->Decompress->Margin = System::Windows::Forms::Padding(4);
			this->Decompress->Name = L"Decompress";
			this->Decompress->Padding = System::Windows::Forms::Padding(4);
			this->Decompress->Size = System::Drawing::Size(371, 293);
			this->Decompress->TabIndex = 1;
			this->Decompress->Text = L"Decompress";
			this->Decompress->UseVisualStyleBackColor = true;
			// 
			// decompressButton
			// 
			this->decompressButton->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->decompressButton->Location = System::Drawing::Point(4, 261);
			this->decompressButton->Margin = System::Windows::Forms::Padding(4);
			this->decompressButton->Name = L"decompressButton";
			this->decompressButton->Size = System::Drawing::Size(363, 28);
			this->decompressButton->TabIndex = 7;
			this->decompressButton->Text = L"Decompress";
			this->decompressButton->UseVisualStyleBackColor = true;
			this->decompressButton->Click += gcnew System::EventHandler(this, &Form1::decompressButton_Click);
			// 
			// panel4
			// 
			this->panel4->Controls->Add(this->button2);
			this->panel4->Controls->Add(this->decompressFileNameLabel);
			this->panel4->Controls->Add(this->decompressFileNameBox);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(4, 4);
			this->panel4->Margin = System::Windows::Forms::Padding(4);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(363, 123);
			this->panel4->TabIndex = 5;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(197, 78);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 3;
			this->button2->Text = L"Browse";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click_1);
			// 
			// decompressFileNameLabel
			// 
			this->decompressFileNameLabel->AutoSize = true;
			this->decompressFileNameLabel->Location = System::Drawing::Point(-4, 53);
			this->decompressFileNameLabel->Margin = System::Windows::Forms::Padding(4, 0, 4, 0);
			this->decompressFileNameLabel->Name = L"decompressFileNameLabel";
			this->decompressFileNameLabel->Size = System::Drawing::Size(133, 17);
			this->decompressFileNameLabel->TabIndex = 1;
			this->decompressFileNameLabel->Text = L"File to Decompress:";
			// 
			// decompressFileNameBox
			// 
			this->decompressFileNameBox->Location = System::Drawing::Point(129, 49);
			this->decompressFileNameBox->Margin = System::Windows::Forms::Padding(4);
			this->decompressFileNameBox->Name = L"decompressFileNameBox";
			this->decompressFileNameBox->Size = System::Drawing::Size(225, 22);
			this->decompressFileNameBox->TabIndex = 0;
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(379, 322);
			this->Controls->Add(this->tabControl);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Margin = System::Windows::Forms::Padding(4);
			this->Name = L"Form1";
			this->Text = L"Pico Zip";
			this->tabControl->ResumeLayout(false);
			this->Compress->ResumeLayout(false);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->Decompress->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			this->panel4->PerformLayout();
			this->ResumeLayout(false);

		}
#pragma endregion

	private:
		std::string StdStr(String^ RTstring)
		{
			return msclr::interop::marshal_as<std::string>(RTstring);
		}

		System::Void compressButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Displays a SaveFileDialog so the user can pick where to output the compressed file.
			SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "PicoZip Compressed File|*.pico";
			saveFileDialog1->Title = "Compress a File";
			saveFileDialog1->ShowDialog();
			// If the file name is not an empty string, open it for saving.
			if (saveFileDialog1->FileName != "")
			{
				FileCompressor file = FileCompressor(StdStr(this->compressFileNameBox->Text), StdStr(saveFileDialog1->FileName));
				file.compress();
			}
			else
			{
				MessageBox::Show("Error: Please choose a valid name to save the file as.");
			}
		}

		System::Void decompressButton_Click(System::Object^  sender, System::EventArgs^  e)
		{
			// Displays a SaveFileDialog so the user can pick where to output the compressed file.
			SaveFileDialog ^ saveFileDialog1 = gcnew SaveFileDialog();
			saveFileDialog1->Filter = "Any File|*.*";
			saveFileDialog1->Title = "Decompress a File";
			saveFileDialog1->ShowDialog();
			// If the file name is not an empty string, open it for saving.
			if (saveFileDialog1->FileName != "")
			{
				FileCompressor file = FileCompressor(StdStr(this->decompressFileNameBox->Text), StdStr(saveFileDialog1->FileName));
				file.decompress();
			}
			else
			{
				MessageBox::Show("Error: Please choose a valid name to save the file as.");
			}
		}

	private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e)
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->compressFileNameBox->Text = openFileDialog1->FileName;
		}
	}

	private: System::Void button2_Click_1(System::Object^  sender, System::EventArgs^  e) 
	{
		if (openFileDialog1->ShowDialog() == System::Windows::Forms::DialogResult::OK)
		{
			this->decompressFileNameBox->Text = openFileDialog1->FileName;
		}
	}
};
}
