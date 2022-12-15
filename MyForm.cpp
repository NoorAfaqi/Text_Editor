#include "MyForm.h"
using namespace System;
using namespace System::Windows::Forms;
[STAThread]
void main(cli::array<System::String^>^ args) {
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    ProjectGUI::MyForm form;
    Application::Run(% form);
}