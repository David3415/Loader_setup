#include <iostream>
#include <windows.h>
#include "Utf16ToUtf8_Class.h"

char* Utf16ToUtf8_Class::Utf16ToUtf8_Void(wchar_t* _utf16Char) {

	size_t utf16CharSize = wcslen(_utf16Char) + 100;
	size_t convertedChars = 0;//вообще не ясно чё за
	const size_t utf8CharSize = utf16CharSize * 2 + 10;
	char* Utf8Char = new char[200];
	wcstombs_s(&convertedChars, Utf8Char, 200, _utf16Char, _TRUNCATE);
	return Utf8Char;
};


