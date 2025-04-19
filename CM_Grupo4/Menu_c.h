#pragma once
#include"PrediceLaIA.h"
#include"Creditos.h"
using namespace std;
namespace CMGrupo4 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de Menu_c
	/// </summary>
	public ref class Menu_c : public System::Windows::Forms::Form
	{
	public:
		Menu_c(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~Menu_c()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ btn_comenzar;
	private: System::Windows::Forms::Button^ btn_creditos;
	private: System::Windows::Forms::Button^ btn_salir;
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
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Menu_c::typeid));
			this->btn_comenzar = (gcnew System::Windows::Forms::Button());
			this->btn_creditos = (gcnew System::Windows::Forms::Button());
			this->btn_salir = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// btn_comenzar
			// 
			this->btn_comenzar->BackColor = System::Drawing::Color::Transparent;
			this->btn_comenzar->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_comenzar->ForeColor = System::Drawing::Color::Transparent;
			this->btn_comenzar->Location = System::Drawing::Point(270, 729);
			this->btn_comenzar->Name = L"btn_comenzar";
			this->btn_comenzar->Size = System::Drawing::Size(266, 113);
			this->btn_comenzar->TabIndex = 0;
			this->btn_comenzar->UseVisualStyleBackColor = true;
			this->btn_comenzar->UseWaitCursor = true;
			this->btn_comenzar->Click += gcnew System::EventHandler(this, &Menu_c::btn_comenzar_Click);
			// 
			// btn_creditos
			// 
			this->btn_creditos->BackColor = System::Drawing::Color::Transparent;
			this->btn_creditos->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_creditos->ForeColor = System::Drawing::Color::Transparent;
			this->btn_creditos->Location = System::Drawing::Point(609, 729);
			this->btn_creditos->Name = L"btn_creditos";
			this->btn_creditos->Size = System::Drawing::Size(314, 113);
			this->btn_creditos->TabIndex = 1;
			this->btn_creditos->UseVisualStyleBackColor = false;
			this->btn_creditos->Click += gcnew System::EventHandler(this, &Menu_c::btn_creditos_Click);
			// 
			// btn_salir
			// 
			this->btn_salir->BackColor = System::Drawing::Color::Transparent;
			this->btn_salir->FlatStyle = System::Windows::Forms::FlatStyle::Popup;
			this->btn_salir->ForeColor = System::Drawing::Color::Transparent;
			this->btn_salir->Location = System::Drawing::Point(1001, 729);
			this->btn_salir->Name = L"btn_salir";
			this->btn_salir->Size = System::Drawing::Size(265, 113);
			this->btn_salir->TabIndex = 2;
			this->btn_salir->UseVisualStyleBackColor = false;
			this->btn_salir->Click += gcnew System::EventHandler(this, &Menu_c::btn_salir_Click);
			// 
			// Menu_c
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"$this.BackgroundImage")));
			this->ClientSize = System::Drawing::Size(1520, 985);
			this->Controls->Add(this->btn_salir);
			this->Controls->Add(this->btn_creditos);
			this->Controls->Add(this->btn_comenzar);
			this->Name = L"Menu_c";
			this->Text = L"Menu_c";
			this->Load += gcnew System::EventHandler(this, &Menu_c::Menu_c_Load);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void btn_comenzar_Click(System::Object^ sender, System::EventArgs^ e) {
		Comenzar^ prediceLaIa = gcnew Comenzar();
		this->Visible = false;
		prediceLaIa->ShowDialog();
		this->Visible = true;
	}
	private: System::Void Menu_c_Load(System::Object^ sender, System::EventArgs^ e) {
	}
	private: System::Void btn_salir_Click(System::Object^ sender, System::EventArgs^ e) {
		Application::Exit();
	}
	private: System::Void btn_creditos_Click(System::Object^ sender, System::EventArgs^ e) {
		Creditos^ creditos = gcnew Creditos();
		this->Visible = false;
		creditos->ShowDialog();
		this->Visible = true;
	}
};
}
