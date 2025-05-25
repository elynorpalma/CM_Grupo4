#pragma once
#include "Funcionamiento.h"	
#include "Resultados.h"			

namespace CMGrupo4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class NDIAS : public System::Windows::Forms::Form
	{
	public:
		NDIAS(void)
		{
			InitializeComponent();
		}

	protected:
		~NDIAS()
		{
			if (components)
			{
				delete components;
			}
		}

	private:
		System::ComponentModel::Container^ components;
		System::Windows::Forms::Label^ label1;
		System::Windows::Forms::TextBox^ textBox1;
		System::Windows::Forms::Button^ button1;
		int nDias;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(NDIAS::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// label1
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label1->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->label1->ForeColor = System::Drawing::Color::White; // texto blanco
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->Location = System::Drawing::Point(363, 197);
			this->label1->Margin = System::Windows::Forms::Padding(2, 0, 2, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(218, 48);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingrese el número de días:";
			this->label1->Click += gcnew System::EventHandler(this, &NDIAS::label1_Click);

			// textBox1
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->textBox1->ForeColor = System::Drawing::Color::White;  // texto blanco
			this->textBox1->BackColor = System::Drawing::Color::FromArgb(0, 0, 64);
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::FixedSingle;
			this->textBox1->Location = System::Drawing::Point(366, 225);
			this->textBox1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(227, 32);
			this->textBox1->TabIndex = 1;

			// button1
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button1->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->button1->ForeColor = System::Drawing::Color::FromArgb(0, 0, 64);  // texto azul oscuro
			this->button1->BackColor = System::Drawing::Color::White;
			this->button1->Location = System::Drawing::Point(366, 307);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(227, 87);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Crear días";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &NDIAS::button1_Click);

			// Form NDIAS
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(966, 581);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->Name = L"NDIAS";
			this->Text = L"NDIAS";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion

	private:
		System::Void button1_Click(System::Object^ sender, System::EventArgs^ e)
		{
			if (Int32::TryParse(textBox1->Text, nDias) && nDias > 0) {
				this->Hide();
				Resultados^ resultadosForm = gcnew Resultados(nDias);
				resultadosForm->Text = "Resultados después de " + nDias.ToString() + " días";
				resultadosForm->ShowDialog();
				this->Show();
			}
			else {
				MessageBox::Show("Por favor ingrese un número entero válido mayor que 0",
					"Error de entrada",
					MessageBoxButtons::OK,
					MessageBoxIcon::Error);
			}
		}
	private: System::Void label1_Click(System::Object^ sender, System::EventArgs^ e) {
	}
	};

}