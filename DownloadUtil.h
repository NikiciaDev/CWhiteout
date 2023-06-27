#pragma once
#include <urlmon.h>
#include <string>
#pragma comment(lib, "urlmon.lib")

namespace dul {
	// This method returns false if the operation fails otherwise non zero.
	bool download_file_from_url(LPCWSTR url, LPCWSTR location);

	// I know i just cba honestly.
	void download_fonts(const LPCWSTR location);
}