#pragma once
#include "Funcionamiento.h"
#include "iostream"
#include <string>
namespace CMGrupo4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de IA
	/// </summary>
	public ref class IA : public System::Windows::Forms::Form
	{
	public:
		IA(void)
		{
			InitializeComponent();
			baseDeDatos();

			string datos = imprimirBase();
			string suma = cantidadIndicadores();
			compararTransición();
			string transiciones = imprimirTransiciones();
			calcularMatrizDeTransicion();
			string matriz = imprimirMatrizDeTransicion();
			string vector = calcularVectorUnitario();

			this->textBox1->Text = gcnew System::String(datos.c_str());
			this->textBox2->Text = gcnew System::String(suma.c_str());
			this->textBox3->Text = gcnew System::String(transiciones.c_str());
			this->textBox4->Text = gcnew System::String(matriz.c_str());
			this->textBox5->Text = gcnew System::String(vector.c_str());
		}


	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
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
	private: System::ComponentModel::IContainer^ components;

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(IA::typeid));
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->textBox5 = (gcnew System::Windows::Forms::TextBox());
			this->SuspendLayout();
			// 
			// textBox1
			// 
			this->textBox1->BackColor = System::Drawing::Color::Navy;
			this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 21, System::Drawing::FontStyle::Bold));
			this->textBox1->ForeColor = System::Drawing::Color::White;
			this->textBox1->Location = System::Drawing::Point(71, 329);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(488, 453);
			this->textBox1->TabIndex = 0;
			this->textBox1->TextChanged += gcnew System::EventHandler(this, &IA::textBox1_TextChanged);
			// 
			// textBox2
			// 
			this->textBox2->BackColor = System::Drawing::Color::Navy;
			this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox2->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold));
			this->textBox2->ForeColor = System::Drawing::Color::White;
			this->textBox2->Location = System::Drawing::Point(718, 98);
			this->textBox2->Multiline = true;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(314, 280);
			this->textBox2->TabIndex = 1;
			this->textBox2->TextChanged += gcnew System::EventHandler(this, &IA::textBox2_TextChanged);
			// 
			// textBox3
			// 
			this->textBox3->BackColor = System::Drawing::Color::Navy;
			this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox3->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
			this->textBox3->ForeColor = System::Drawing::Color::White;
			this->textBox3->Location = System::Drawing::Point(642, 405);
			this->textBox3->Multiline = true;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(472, 217);
			this->textBox3->TabIndex = 2;
			this->textBox3->TextChanged += gcnew System::EventHandler(this, &IA::textBox3_TextChanged);
			// 
			// textBox4
			// 
			this->textBox4->BackColor = System::Drawing::Color::Navy;
			this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 19, System::Drawing::FontStyle::Bold));
			this->textBox4->ForeColor = System::Drawing::Color::White;
			this->textBox4->Location = System::Drawing::Point(642, 674);
			this->textBox4->Multiline = true;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(468, 316);
			this->textBox4->TabIndex = 3;
			this->textBox4->TextChanged += gcnew System::EventHandler(this, &IA::textBox4_TextChanged);
			// 
			// textBox5
			// 
			this->textBox5->BackColor = System::Drawing::Color::Navy;
			this->textBox5->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->textBox5->Font = (gcnew System::Drawing::Font(L"Arial", 20, System::Drawing::FontStyle::Bold));
			this->textBox5->ForeColor = System::Drawing::Color::White;
			this->textBox5->Location = System::Drawing::Point(1186, 131);
			this->textBox5->Multiline = true;
			this->textBox5->Name = L"textBox5";
			this->textBox5->Size = System::Drawing::Size(292, 449);
			this->textBox5->TabIndex = 4;
			this->textBox5->TextChanged += gcnew System::EventHandler(this, &IA::textBox5_TextChanged);
			// 
			// IA
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1526, 1025);
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
	char estadoFinal = Convert::ToChar(textBox5->Text[0]);
	string resultado = calcularVectorUnitario();
}
};
}
