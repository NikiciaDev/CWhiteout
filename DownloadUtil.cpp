#include "DownloadUtil.h"
#include <iostream>

namespace dul {
	bool download_file_from_url(LPCWSTR url, LPCWSTR location) {
		return S_OK == URLDownloadToFile(0, url, location, 0, NULL);
	}
}