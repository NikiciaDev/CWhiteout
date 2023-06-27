#include "DownloadUtil.h"

namespace dul {
	bool download_file_from_url(const LPCWSTR url, const LPCWSTR location) {
		return S_OK == URLDownloadToFile(0, url, location, 0, NULL);
	}

	void download_fonts(const LPCWSTR location) {
		const LPCWSTR rmb((LPCWSTR) L"https://cdn.discordapp.com/attachments/1123271177838796860/1123271219282726934/RobotoMono-Bold.ttf");
		const LPCWSTR rmm((LPCWSTR) L"https://cdn.discordapp.com/attachments/1123271177838796860/1123271219672784957/RobotoMono-Medium.ttf");
		const LPCWSTR rmr((LPCWSTR) L"https://cdn.discordapp.com/attachments/1123271177838796860/1123271220213842010/RobotoMono-Regular.ttf");
		const LPCWSTR rmt((LPCWSTR) L"https://cdn.discordapp.com/attachments/1123271177838796860/1123271220796858589/RobotoMono-Thin.ttf");

		std::wstring l1(location); l1 += L"\\RobotoMono-Bold.ttf";
		std::wstring l2(location); l2 += L"\\RobotoMono-Medium.ttf";
		std::wstring l3(location); l3 += L"\\RobotoMono-Regular.ttf";
		std::wstring l4(location); l4 += L"\\RobotoMono-Thin.ttf";

		download_file_from_url(rmb, l1.c_str());
		download_file_from_url(rmm, l2.c_str());
		download_file_from_url(rmr, l3.c_str());
		download_file_from_url(rmt, l4.c_str());
	}
}