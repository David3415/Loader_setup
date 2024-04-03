#define _CRT_SECURE_NO_WARNINGS

#define OK_BTN 1010
#define EXIT_BTN 1009

#include <string.h>
#include <tchar.h>
#include <iostream>
#include <windowsx.h>
#include <ShlObj_core.h>
#include <vector>

#include "WndProcClass.h"
#include "OpenFileDlgClass.h"
#include  "EngineClass.h"
#include "Utf16ToUtf8_Class.h"


HWND hWndTextFields[3]{};


char* FilePath{};
std::vector<char*>DirsVec{};////Vector для хранения путей выбранных .MSI и .EXE файлов


LRESULT CALLBACK WndProcClass::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	POINT pt{};
	HDC hdc;
	TCHAR greeting[] = _T("Hello, Windows desktop!");

	std::vector<const  wchar_t*>textPlacehHolders = { L"Specify the Setup.EXE file" ,
												  L"Specify the first .MSI file",
												  L"Specify the second .MSI file" };
	switch (wParam)
	{
	case OK_BTN:
	{
		;
		wchar_t fileNameReceived[150]{};
		DirsVec.resize(3);
		for (int i = 0; i < 3; i++) {
			GetWindowTextW(hWndTextFields[i], fileNameReceived, 200);

			DirsVec[i] = Utf16ToUtf8_Class::Utf16ToUtf8_Void(fileNameReceived);

		}
		EngineClass::Engine();
		return 0;
	}
	case EXIT_BTN:
	{
		exit(0);
	}
	}

	switch (message)
	{
	case WM_CREATE:
	{

		//////----------------------	TITLE	-----------------
		HWND hWndTitle = CreateWindowExW(0, L"EDIT", L"DB is empty, choose at least one folder", // Заголовок 
			WS_CHILD | WS_DISABLED | BS_FLAT,
			50, 10, 300, 30, hWnd, reinterpret_cast<HMENU>(1012), NULL, NULL);



		//////----------------------Делаем Текстовые поля-----------------
		int lineNumber;
		for (lineNumber = 0; lineNumber < 3; lineNumber++) {
			hWndTextFields[lineNumber] = CreateWindowExW(0, L"EDIT", L"",
				WS_CHILD | WS_VISIBLE | WS_BORDER | WS_DISABLED,
				30, 30 + lineNumber * 47, 720, 30, hWnd, reinterpret_cast<HMENU>(1002), NULL, NULL);
		}


		//////----------------------заполняем PlaceHolders -----------------
		for (int i = 0; i < textPlacehHolders.size(); i++) {
			SetWindowTextW(hWndTextFields[i], textPlacehHolders[i]);
		}



		/////---------------------- Делаем Buttons   --------------------
		HWND hWndExitButt = CreateWindowExW(0, L"BUTTON", L"EDIT ", // 
			WS_CHILD | WS_VISIBLE | BS_FLAT,
			550, 170, 90, 30, hWnd, reinterpret_cast<HMENU>(1009), NULL, NULL);
		HWND hWndOK = CreateWindowExW(0, L"BUTTON", L"OK ", // 
			WS_CHILD | WS_VISIBLE | BS_FLAT,
			660, 170, 90, 30, hWnd, reinterpret_cast<HMENU>(1010), NULL, NULL);
	}
	return 0;


	case WM_COMMAND:
	{
	case WM_LBUTTONDOWN:
	{
		pt.x = GET_X_LPARAM(lParam);//windowsx.h
		pt.y = GET_Y_LPARAM(lParam);

		//////Устанавливаем значения выбранных полей
		LPWSTR temp{};
		if (pt.x > 13 && pt.x < 750 && pt.y>30 && pt.y < 60) {
			SetWindowTextW(hWndTextFields[0], OpenFileDlgClass::OpenFileDlgVoid());
		}
		if (pt.x > 13 && pt.x < 750 && pt.y>70 && pt.y < 100) {
			SetWindowTextW(hWndTextFields[1], OpenFileDlgClass::OpenFileDlgVoid());
		}
		if (pt.x > 13 && pt.x < 750 && pt.y>110 && pt.y < 140) {
			SetWindowTextW(hWndTextFields[2], OpenFileDlgClass::OpenFileDlgVoid());
		}
	}
	return 0;
	}

	case WM_PAINT:

		hdc = BeginPaint(hWnd, &ps);
		TextOut(hdc,
			5, 5,
			greeting, _tcslen(greeting));
		EndPaint(hWnd, &ps);
		break;

	case WM_SIZE:
		InvalidateRect(hWnd, NULL, true);
		break;
	case WM_CLOSE:
		if (IDYES != MessageBox(hWnd, L"Wanna Exit?", L"Question", MB_YESNO | MB_ICONQUESTION))
			break;
	case WM_DESTROY: {
		PostQuitMessage(0);
	}
				   break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}return 0;

	return DefWindowProc(hWnd, message, wParam, lParam);
}