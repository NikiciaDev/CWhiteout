#pragma once
#include <urlmon.h>
#pragma comment(lib, "urlmon.lib")

namespace dul {
	// This method returns false if the operation fails otherwise non zero.
	bool download_file_from_url(LPCWSTR url, LPCWSTR location);
}