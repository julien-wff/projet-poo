#include "pch.h"
#include "WindowForm.h"

int main() {
	// Windows forms
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	WindowForm windowForm;
	Application::Run(%windowForm);
	return 0;
}
