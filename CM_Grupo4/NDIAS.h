#pragma once
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
			this->label1->Size = System::Drawing::Size(200, 20);
			this->label1->TabIndex = 0;
			this->label1->Text = L"Ingrese el n�mero de d�as:";
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
			this->button1->Text = L"Crear d�as";
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
			if (Int32::TryParse(textBox1->Text, nDias) && nDias > 0)
			{
				Form^ diaForm = gcnew Form();
				diaForm->Text = "D�a " + nDias.ToString();
				diaForm->Size = System::Drawing::Size(1200,800);

				Label^ diaLabel = gcnew Label();
				diaLabel->Text = "Este es el d�a " + nDias.ToString();
				diaLabel->Location = System::Drawing::Point(150, 130);
				diaLabel->AutoSize = true;
				diaForm->Controls->Add(diaLabel);

				diaForm->Show();
			}
			else
			{
				MessageBox::Show("Por favor ingrese un n�mero v�lido mayor a 0.", "Error", MessageBoxButtons::OK, MessageBoxIcon::Error);
			}
		}
	};
}
