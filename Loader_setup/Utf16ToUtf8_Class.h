#pragma once
#include <string>

class Utf16ToUtf8_Class {
public:
	Utf16ToUtf8_Class(wchar_t* utf16Char) : _utf16Char(utf16Char) {};
	static char* Utf16ToUtf8_Void(wchar_t* _utf8Char);
private:
	wchar_t* _utf16Char;
};
