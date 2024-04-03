#pragma comment(lib, "msi.lib")
#define SUCCEEDED(hr) (((HRESULT)(hr)) >= 0)

#include <iostream>
#include <windows.h>
#include <shlobj_core.h>
#include <stdlib.h>
#include <msi.h> 

#include "dirExists.h"
#include "EngineClass.h" 
#include <vector>


extern std::vector<char*>DirsVec;


void EngineClass::Engine() {

	char* szPath = new char[300] {};
	char* szPath1 = new char[300] {};


	auto hr = SHGetFolderPathA(NULL, CSIDL_APPDATA, NULL, 0, szPath);

	if (SUCCEEDED(hr))
	{
		LPCSTR lpDir = "\\NTech";
		LPCSTR lpDir1 = "\\FolderWatcher";

		std::string tmp2 = "\\" + *DirsVec[1];
		LPCSTR lpDir2 = &tmp2[0];
		
		std::string tmp6 = "\\" + *DirsVec[2];
		LPCSTR lpDir3 = &tmp6[0];   // UpdateLoader.msi";

		size_t szPathLen = strlen(szPath);

		size_t lpDirLen = strlen(lpDir);
		size_t lpDirLen1 = strlen(lpDir1);
		size_t lpDirLen2 = strlen(lpDir2);
		size_t lpDirLen3 = strlen(lpDir3);

		strcat_s(szPath, szPathLen + lpDirLen + 1, lpDir);

		if (!dirExists(szPath)) {
			CreateDirectoryA(szPath, NULL);
		}

		szPathLen += lpDirLen + 1;
		strcat_s(szPath, szPathLen + lpDirLen1 + 1, lpDir1);

		if (!dirExists(szPath)) {
			CreateDirectoryA(szPath, NULL);
		}

		szPathLen += lpDirLen1 + 1;

		size_t szPathLen1 = szPathLen;
		strcpy_s(szPath1, szPathLen1 + 1, szPath);
		strcat_s(szPath1, szPathLen1 + lpDirLen3 + 1, lpDir3);
		strcat_s(szPath, szPathLen + lpDirLen2, lpDir2);


		CopyFileA(&tmp2[1], szPath, TRUE);
		CopyFileA(&tmp2[2], szPath1, TRUE);
		CopyFileA("libcurl.dll", szPath1, TRUE);
		CopyFileA("libcrypto-3-x64.dll", szPath1, TRUE);


		std::string tmp = "C:\\Users\\dgagi\\AppData\\Roaming\\NTech\\FolderWatcher";
		std::string tmp5 = "C:\\Users\\dgagi\\AppData\\Roaming\\NTech\\FolderWatcher";
		std::string tmp3 = DirsVec[1];
		std::string tmp4 = DirsVec[2];

		tmp = "msiexec /i "+ tmp3+"  TARGETDIR=" + tmp + " /qn";
		system(tmp.c_str());
		tmp4 = DirsVec[2];
		tmp5 = "msiexec /i "+ tmp4+" TARGETDIR=" + tmp5 + " /qn";
		system(tmp5.c_str());
	}
};

