#define WINVER 0x0500
#include <iostream>
#include <cctype>
#include "Windows.h"
INPUT in; // bad convention but we aight
void pressKey(WORD hexNum) {
	in.ki.wVk = hexNum; // hex squad
	in.ki.dwFlags = 0;
	SendInput(1, &in, sizeof(INPUT));

	// Release
	in.ki.dwFlags = KEYEVENTF_KEYUP;
	SendInput(1, &in, sizeof(INPUT));
}

int main()
{

	in.type = INPUT_KEYBOARD;
	in.ki.wScan = 0; // hardware scan code for key
	in.ki.time = 0;
	in.ki.dwExtraInfo = 0;

	char printString[100] = "printThisOut";

	Sleep(10000);
	for (auto i : printString) {
		WORD printChar = static_cast<WORD>(tolower(i));
		pressKey(printChar - 32);
	}

	return 0;
}