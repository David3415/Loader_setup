#include <string>
#include <windows.h>

#include "dirExists.h"

bool dirExists(const std::string& dirName_in)
{
	DWORD ftyp = GetFileAttributesA(&dirName_in[0]);
	if (ftyp == INVALID_FILE_ATTRIBUTES)
		return false;  //something is wrong with your path!

	if (ftyp & FILE_ATTRIBUTE_DIRECTORY)
		return true;   // this is a directory!
	return false;    // this is not a directory!
}
/////////////////////////////////