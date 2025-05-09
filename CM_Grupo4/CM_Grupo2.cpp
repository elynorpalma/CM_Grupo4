#include "pch.h"
#include "Menu_c.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace CMGrupo4;

int main()

{
    srand(time(NULL));
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew CMGrupo4::Menu_c);
}
