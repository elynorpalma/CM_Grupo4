#pragma once
#include "Funcionamiento.h"
namespace CMGrupo4 {
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    public ref class Resultados : public System::Windows::Forms::Form {
    public:
        Resultados(int nDias) {
            InitializeComponent();
            float matrizElevada[5][5];
            float probabilidades[5];
            calcularMatrizDeTransicion();
            calcularProbabilidades(nDias);
            
            textBox1->Text = gcnew String((
                "\r\r\n\nMatriz de transcion original:\r\r\n\n" +
                imprimirMatrizDeTransicion() + "\r\r\n\n"
                "\r\r\n\nMatriz elevada a la " + to_string(nDias) + ":\r\r\n" +
                imprimirMatrizPersonalizada(matrizElevada)).c_str());

            textBox2->Text = gcnew String((
                "Vector unitario:\n" +
                imprimirVectorUnitario()).c_str());

            textBox3->Text = gcnew String((
                imprimirProbabilidades(nDias)).c_str());
            

            textBox4->Text = gcnew String(("Recomendaciones:\n" + generarRecomendaciones()).c_str());
        }

    protected:
        ~Resultados() {
            if (components) delete components;
        }

    private:
        System::Windows::Forms::TextBox^ textBox1;
        System::Windows::Forms::TextBox^ textBox2;
        System::Windows::Forms::TextBox^ textBox3;
        System::Windows::Forms::TextBox^ textBox4;

        System::ComponentModel::IContainer^ components;

#pragma region Windows Form Designer generated code
        void InitializeComponent() {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Resultados::typeid));
            this->textBox1 = (gcnew System::Windows::Forms::TextBox());
            this->textBox2 = (gcnew System::Windows::Forms::TextBox());
            this->textBox3 = (gcnew System::Windows::Forms::TextBox());
            this->textBox4 = (gcnew System::Windows::Forms::TextBox());
            this->SuspendLayout();
            // 
            // textBox1
            // 
            this->textBox1->BackColor = System::Drawing::Color::Navy;
            this->textBox1->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox1->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
            this->textBox1->ForeColor = System::Drawing::Color::White;
            this->textBox1->Location = System::Drawing::Point(46, 36);
            this->textBox1->Margin = System::Windows::Forms::Padding(2);
            this->textBox1->Multiline = true;
            this->textBox1->Name = L"textBox1";
            this->textBox1->Size = System::Drawing::Size(527, 678);
            this->textBox1->TabIndex = 4;
            // 
            // textBox2
            // 
            this->textBox2->BackColor = System::Drawing::Color::Navy;
            this->textBox2->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox2->Font = (gcnew System::Drawing::Font(L"Arial", 16, System::Drawing::FontStyle::Bold));
            this->textBox2->ForeColor = System::Drawing::Color::White;
            this->textBox2->Location = System::Drawing::Point(597, 41);
            this->textBox2->Margin = System::Windows::Forms::Padding(2);
            this->textBox2->Multiline = true;
            this->textBox2->Name = L"textBox2";
            this->textBox2->Size = System::Drawing::Size(226, 355);
            this->textBox2->TabIndex = 3;
            // 
            // textBox3
            // 
            this->textBox3->BackColor = System::Drawing::Color::Navy;
            this->textBox3->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox3->Font = (gcnew System::Drawing::Font(L"Arial", 11, System::Drawing::FontStyle::Bold));
            this->textBox3->ForeColor = System::Drawing::Color::White;
            this->textBox3->Location = System::Drawing::Point(844, 41);
            this->textBox3->Margin = System::Windows::Forms::Padding(2);
            this->textBox3->Multiline = true;
            this->textBox3->Name = L"textBox3";
            this->textBox3->Size = System::Drawing::Size(270, 355);
            this->textBox3->TabIndex = 2;
            // 
            // textBox4
            // 
            this->textBox4->BackColor = System::Drawing::Color::Navy;
            this->textBox4->BorderStyle = System::Windows::Forms::BorderStyle::None;
            this->textBox4->Font = (gcnew System::Drawing::Font(L"Arial", 14, System::Drawing::FontStyle::Bold));
            this->textBox4->ForeColor = System::Drawing::Color::White;
            this->textBox4->Location = System::Drawing::Point(597, 432);
            this->textBox4->Margin = System::Windows::Forms::Padding(2);
            this->textBox4->Multiline = true;
            this->textBox4->Name = L"textBox4";
            this->textBox4->Size = System::Drawing::Size(517, 211);
            this->textBox4->TabIndex = 1;
            // 
            // Resultados
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
            this->ClientSize = System::Drawing::Size(1152, 771);
            this->Controls->Add(this->textBox4);
            this->Controls->Add(this->textBox3);
            this->Controls->Add(this->textBox2);
            this->Controls->Add(this->textBox1);
            this->Margin = System::Windows::Forms::Padding(2);
            this->Name = L"Resultados";
            this->Text = L"Resultados";
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion

    private:
        System::Void button1_Click(System::Object^ sender, System::EventArgs^ e) {
           
        }
    };
}