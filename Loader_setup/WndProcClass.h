#pragma once
#include <string.h>
#include <tchar.h>
#include <iostream>
#include <windows.h>

class WndProcClass
{
public:
	static 	LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam);
};

