#pragma once
#include<fstream>
#include<string.h>
#include<string>
#include<sstream>
#include<vector>
#include<iostream>
#include<time.h>
#include<stdlib.h>
#include"Trees.h"

namespace ProjectGUI {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace std;
	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
			dictionary.readFile();
		}
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label2;

	
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button3;
	private: System::Windows::Forms::Button^ button4;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::ErrorProvider^ errorProvider1;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::Button^ button5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Button^ button6;
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->errorProvider1 = (gcnew System::Windows::Forms::ErrorProvider(this->components));
			this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->button6 = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::SystemColors::Info;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Mistral", 26.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(94, 6);
			this->label1->Name = L"label1";
			this->label1->Padding = System::Windows::Forms::Padding(330, 10, 300, 10);
			this->label1->Size = System::Drawing::Size(771, 64);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Text Editor";
			this->label1->TextAlign = System::Drawing::ContentAlignment::TopCenter;
			this->label1->Click += gcnew System::EventHandler(this, &MyForm::label1_Click);
			// 
			// textBox1
			// 
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Calibri", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox1->Location = System::Drawing::Point(94, 74);
			this->textBox1->Margin = System::Windows::Forms::Padding(10);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(670, 484);
			this->textBox1->TabIndex = 1;
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::SystemColors::InactiveBorder;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Font = (gcnew System::Drawing::Font(L"MV Boli", 15.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(766, 74);
			this->label2->Name = L"label2";
			this->label2->Padding = System::Windows::Forms::Padding(18, 0, 18, 0);
			this->label2->Size = System::Drawing::Size(206, 30);
			this->label2->TabIndex = 2;
			this->label2->Text = L"Suggested Word";
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button2->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->button2->Location = System::Drawing::Point(876, 127);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(96, 24);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Next";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &MyForm::button2_Click);
			// 
			// button3
			// 
			this->button3->Font = (gcnew System::Drawing::Font(L"Modern No. 20", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->button3->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->button3->Location = System::Drawing::Point(876, 47);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(75, 23);
			this->button3->TabIndex = 6;
			this->button3->Text = L"Save";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &MyForm::button3_Click);
			// 
			// button4
			// 
			this->button4->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->button4->Location = System::Drawing::Point(876, 6);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(75, 23);
			this->button4->TabIndex = 7;
			this->button4->Text = L"Load";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &MyForm::button4_Click);
			// 
			// textBox2
			// 
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Calibri", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox2->Location = System::Drawing::Point(768, 105);
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(204, 23);
			this->textBox2->TabIndex = 8;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &MyForm::textBox2_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->button1->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->button1->Location = System::Drawing::Point(766, 127);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(106, 23);
			this->button1->TabIndex = 9;
			this->button1->Text = L"Previous";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click_1);
			// 
			// errorProvider1
			// 
			this->errorProvider1->BlinkStyle = System::Windows::Forms::ErrorBlinkStyle::AlwaysBlink;
			this->errorProvider1->ContainerControl = this;
			this->errorProvider1->Tag = L"File not open!";
			// 
			// textBox3
			// 
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Calibri", 11.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->textBox3->Location = System::Drawing::Point(768, 233);
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(222, 26);
			this->textBox3->TabIndex = 10;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::SystemColors::MenuBar;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Font = (gcnew System::Drawing::Font(L"Monotype Corsiva", 14.25F, System::Drawing::FontStyle::Italic, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label3->Location = System::Drawing::Point(766, 206);
			this->label3->Name = L"label3";
			this->label3->Padding = System::Windows::Forms::Padding(87, 0, 87, 0);
			this->label3->Size = System::Drawing::Size(224, 24);
			this->label3->TabIndex = 11;
			this->label3->Text = L"Error";
			// 
			// button5
			// 
			this->button5->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->button5->Location = System::Drawing::Point(766, 180);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(206, 23);
			this->button5->TabIndex = 12;
			this->button5->Text = L"Update Status";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &MyForm::button5_Click);
			// 
			// button6
			// 
			this->button6->ForeColor = System::Drawing::Color::CornflowerBlue;
			this->button6->Location = System::Drawing::Point(766, 151);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(206, 23);
			this->button6->TabIndex = 13;
			this->button6->Text = L"Use Word";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &MyForm::button6_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::SystemColors::ScrollBar;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(1002, 585);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->errorProvider1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
	}


		   void Operate1() {
			   int number = textBox1->Text->Length;
			   if (number > 0) {
				   if ((textBox1->Text[number - 1] == ' ') || (textBox1->Text[number - 1] == '\n') || (textBox1->Text[number - 1] == '\t')) {
					   string word, str;
					   char c = NULL;
					   vector<char>arr(number);
					   for (int i = 0; i < number; i++) {
						   c = textBox1->Text[i];
						   str += c;
					   }
					   textBox3->Text = "";
					   stringstream iss(str);
					   while (iss >> word) {}
					   if ((word[0] >= 'a') && (word[0] <= 'z')) {
						   if (!dictionary.search(word)) {
							   String^ str3 = gcnew String(word.data());
							   textBox3->Text = "";
							   textBox3->Text = str3 + " is not in dictionary!";
							   words.clear();
						   }
					   }
				   }
				   else if ((textBox1->Text[number - 1] >= 'a') && (textBox1->Text[number - 1] <= 'z')) {
					   textBox3->Text = "";
					   string word, str;
					   char c = NULL;
					   vector<char>arr(number);
					   for (int i = 0; i < number; i++) {
						   c = textBox1->Text[i];
						   str += c;
					   }
					   stringstream iss(str);
					   while (iss >> word) {}
					   if ((word[0] >= 'a') && (word[0] <= 'z')) {
						   words.clear();
						   dictionary.ReadTree(word, words);
						   selectedWord = word;
						   wordsIndex = 0;
					   }
				   }
			   }
			   else {
				   textBox2->Text = "";
				   textBox3->Text = "";
			   }
		   }

	private: System::Void button3_Click(System::Object^ sender, System::EventArgs^ e) {//save
		int number = textBox1->Text->Length;
		vector<char>tex(9999);
		for (int i = 0; i < number; i++) {
			tex[i] = textBox1->Text[i];
		}
		ofstream fileWrite;
		char str = NULL;
		fileWrite.open("LastWritten.txt", ios::out);
		if (!fileWrite.is_open()) {
			textBox1->Text = "File can not open!";
		}
		for (int i = 0; i < number; i++) {
			str = tex[i];
			fileWrite << str;
		}
		fileWrite.close();


		vector<long long int > Huffman_codemap;
		Huffman_codemap.resize(Char_size);
		long long int Count[Char_size] = { 0 };
		string filename;
		filename = "LastWritten.txt";
		ifstream input_file(filename.c_str(), ios::binary);
		if (!input_file.good()) {
			perror("Error:\t");
			exit(-1);
		}
		char ch;
		while (input_file.get(ch)) {
			Count[static_cast<unsigned char>(ch)]++;
		}
		input_file.clear();
		input_file.seekg(0);
		Node* tree = Huffman(Count);
		ofstream output_file(filename.c_str(), ios::binary);
		output_file << tree->Freq;
		output_file << ',';
		store_tree(output_file, tree);
		output_file << ' ';
		char single_code[16];
		store_codes(tree, single_code, 0, Huffman_codemap);
		Write_compressed(input_file, output_file, Huffman_codemap);
		input_file.close();
		output_file.close();
	}


	private: System::Void button4_Click(System::Object^ sender, System::EventArgs^ e) {//load
		int number = textBox1->Text->Length;
		vector<char>tex(9999);
		for (int i = 0; i < number; i++) {
			tex[i] = textBox1->Text[i];
		}
		string filename;
		vector<char>temArr(9999);
		int iV = 0;
		filename = "LastWritten.txt";
		ifstream input_file(filename.c_str(), ios::binary), tempFile(filename.c_str(), ios::binary);
		if (!input_file.good()) {
			perror("Error:\t");
			exit(-1);
		}
		long long int Total_freq = 0;
		char ch;
		while (tempFile.get(ch)) {
			temArr[iV] = ch;
			iV++;
		}
		tempFile.close();
		while (input_file.get(ch)) {
			if (ch == ',') {
				break;
			}
			Total_freq *= 10;
			Total_freq += ch - '0';
		}
		Node* Huffman_tree = Make_Huffman_tree(input_file);
		input_file.get(ch);
		decode(input_file, filename, Huffman_tree, Total_freq);
		input_file.close();


		ifstream fileRead;
		string str = "";
		char temA[1000] = { 0 };
		fileRead.open("LastWritten.txt", ios::in, ios::binary);
		for (int i = 0; i < number; i++) {
			tex[i] = NULL;
		}
		number = 0;
		if (fileRead) {
			ostringstream ss;
			ss << fileRead.rdbuf();
			str = ss.str();
		}
		textBox1->Text = "";
		textBox2->Text = "";
		textBox3->Text = "";
		String^ str3 = gcnew String(str.data());
		textBox1->Text = str3;
		fileRead.close();


		ofstream fileWrite;
		fileWrite.open("LastWritten.txt", ios::out);
		for (int i = 0; i < iV; i++) {
			ch = temArr[i];
			fileWrite << ch;
		}
		fileWrite.close();
	}

private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void label3_Click(System::Object^ sender, System::EventArgs^ e) {
}
private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e) {//next word
	if (wordsIndex < words.size()) {
		String^ str3 = gcnew String(words[wordsIndex].data());
		textBox2->Text = str3;
		if (wordsIndex < (words.size())) {
			wordsIndex++;
		}
	}
}
private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e) {
}

private: System::Void button1_Click_1(System::Object^ sender, System::EventArgs^ e) {//previous
	if (wordsIndex >= 2) {
		wordsIndex--;
		wordsIndex--;
		String^ str3 = gcnew String(words[wordsIndex].data());
		textBox2->Text = str3;
		wordsIndex++;
	}
}
private: System::Void button5_Click(System::Object^ sender, System::EventArgs^ e) {//update status
	Operate1();
}
private: System::Void button6_Click(System::Object^ sender, System::EventArgs^ e) {//use word
	string str;
	char c = NULL;
	for (int i = 0; i < textBox1->Text->Length; i++) {
		c = textBox1->Text[i];
		str += c;
	}
	if (str.find(selectedWord) != string::npos) {
		size_t p = -1;
		string tempWord = selectedWord + " ";
		while ((p = str.find(selectedWord)) != string::npos) {
			str.replace(p, tempWord.length(), "");
		}
		tempWord = " " + selectedWord;
		while ((p = str.find(selectedWord)) != string::npos) {
			str.replace(p, tempWord.length(), "");
		}
	}
	String^ str3 = gcnew String(str.data());
	textBox1->Text = "";
	textBox1->Text = str3 + textBox2->Text;
}
};
}