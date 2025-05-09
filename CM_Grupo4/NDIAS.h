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
		Label^ label1;
		TextBox^ textBox1;
		Button^ button1;
		int nDias;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(50, 50);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(550, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingrese el número de días:";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(260, 47);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(100, 22);
			this->textBox1->TabIndex = 1;
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(380, 45);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(100, 26);
			this->button1->TabIndex = 2;
			this->button1->Text = L"Crear días";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &NDIAS::button1_Click);
			// 
			// NDIAS
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(8, 16);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(1600, 1200);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
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
	};
}
