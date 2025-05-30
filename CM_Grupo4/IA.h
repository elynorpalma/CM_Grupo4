#pragma once
#include "Funcionamiento.h"
#include "NDIAS.h"
namespace CMGrupo4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;


	public ref class IA : public System::Windows::Forms::Form
	{
	public:
		IA(int modo)
		{
			InitializeComponent();
			resetearContadoresYTransiciones();
			baseUsuario1();
			baseUsuario2();
			baseUsuario3();
			if (modo == 0) {
				baseDeDatos();
				this->Text = "IA - Modo Aleatorio";
			}
			else if (modo == 1) {
				copiarMatrizUsuarioAMatrizPrincipal(1);  // Usuario 1
				this->Text = "IA - Usuario 1 (Est�tico)";
			}
			else if (modo == 2) {
				copiarMatrizUsuarioAMatrizPrincipal(2);  // Usuario 2
				this->Text = "IA - Usuario 2 (Est�tico)";
			}
			else if (modo == 3) {
				copiarMatrizUsuarioAMatrizPrincipal(3);  // Usuario 3
				this->Text = "IA - Usuario 3 (Est�tico)";
			}

			// El resto del procesamiento es IGUAL para ambos modos
			this->textBox1->Text = "BASE DE DATOS:\r\n\r\n";
			this->textBox2->Text = "CONTEO DE HERRAMIENTAS:\r\n\r\n";
			this->textBox3->Text = "TRANSICIONES:\r\n\r\n";
			this->textBox4->Text = "MATRIZ DE TRANSICI�N (BASE):\r\n\r\n";
			this->textBox5->Text = "VECTOR UNITARIO:\r\n\r\n";

			string datos = imprimirBase();
			string suma = cantidadIndicadores();
			compararTransicion();
			string transiciones = imprimirTransiciones();
			calcularMatrizDeTransicion();
			string matriz = imprimirMatrizDeTransicion();
			string vector = imprimirVectorUnitario();

			this->textBox1->Text += gcnew String(datos.c_str());
			this->textBox2->Text += gcnew String(suma.c_str());
			this->textBox3->Text += gcnew String(transiciones.c_str());
			this->textBox4->Text += gcnew String(matriz.c_str());
			this->textBox5->Text += gcnew String(vector.c_str());
		}


	protected:
		~IA()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::TextBox^ textBox1;
	protected:

	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox3;
	private: System::Windows::Forms::TextBox^ textBox4;
	private: System::Windows::Forms::TextBox^ textBox5;
	private: System::Windows::Forms::Button^ button1;
	private: System::ComponentModel::IContainer^ components;

	private:



#pragma region Windows Form Designer generated code

		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(IA::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Navy;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(55, 238);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(358, 326);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &IA::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Navy;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(534, 68);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(242, 202);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &IA::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Navy;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
			this->textBox3->ForeColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(468, 288);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(369, 167);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &IA::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Navy;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->textBox4->ForeColor = System::Drawing::Color::White;
			this->textBox4->Location = System::Drawing::Point(468, 474);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(369, 240);
			this->textBox4->TabIndex = 3;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &IA::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::Navy;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold));
			this->textBox5->ForeColor = System::Drawing::Color::White;
			this->textBox5->Location = System::Drawing::Point(869, 85);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(240, 342);
			this->textBox5->TabIndex = 4;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &IA::textBox5_TextChanged);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::Transparent;
			this->button1->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->button1->ForeColor = System::Drawing::Color::Transparent;
			this->button1->Location = System::Drawing::Point(921, 589);
			this->button1->Margin = System::Windows::Forms::Padding(2, 2, 2, 2);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(149, 62);
			this->button1->TabIndex = 5;
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &IA::button1_Click);
			// 
			// IA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1152, 771);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->textBox5);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Name = L"IA";
			this->Text = L"IA";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void textBox1_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBox1->Text;
	}
	private: System::Void textBox2_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBox2->Text;
	}
	private: System::Void textBox3_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBox3->Text;
	}
	private: System::Void textBox4_TextChanged(System::Object^ sender, System::EventArgs^ e)
	{
		this->textBox4->Text;
	}
	private: System::Void textBox5_TextChanged(System::Object^ sender, System::EventArgs^ e) {
		this->textBox5->Text;

	}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
		NDIAS^ nuevoDia = gcnew NDIAS();
		this->Hide();
		nuevoDia->ShowDialog();
		this->Show();
	}
	};
}
