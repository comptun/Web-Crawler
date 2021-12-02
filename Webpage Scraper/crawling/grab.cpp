#include <windows.h>
#include <tchar.h>
#include <wininet.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>

#pragma comment (lib, "wininet.lib")

#include "grab.h"
#include "tokenize.h"

std::string swc::grab(std::string address)
{
    std::string link, dir;
    bool first = true;
    for (size_t i = 0; i < address.size(); ++i) {
        if (address.at(i) == '/') {
            first = false;
        }
        if (first) {
            link += address.at(i);
        }
        else {
            dir += address.at(i);
        }
    }
    LPCSTR link2 = link.c_str();
    LPCSTR dir2 = dir.c_str();
    HINTERNET hInternet = InternetOpenA("InetURL/1.0", INTERNET_OPEN_TYPE_PRECONFIG, NULL, NULL, 0);
    HINTERNET hConnection = InternetConnectA(hInternet, link2, 80, " ", " ", INTERNET_SERVICE_HTTP, 0, 0); //enter url here
    HINTERNET hData = HttpOpenRequestA(hConnection, "GET", dir2, NULL, NULL, NULL, INTERNET_FLAG_KEEP_CONNECTION, 0);

    char buf[2048];

    BOOL success = HttpSendRequestA(hData, NULL, 0, NULL, 0);
    std::string total;
    DWORD bytesRead = 0;
    DWORD totalBytesRead = 0;

    while (InternetReadFile(hData, buf, 2000, &bytesRead) && bytesRead != 0)
    {
        buf[bytesRead] = 0; // insert the null terminator.
        total = total + buf;

        totalBytesRead += bytesRead;
    }

    InternetCloseHandle(hData);
    InternetCloseHandle(hConnection);
    InternetCloseHandle(hInternet);
    return total;
}

std::string swc::getWebsiteTitle(std::string address)
{
    std::string text = swc::grab(address);
    std::string title;
    for (size_t i = 0; i < text.size(); ++i) {
        if (i > 1000)
            break;
        if (swc::isAhead("<title>", text, i)) {
            i += 7;
            for (; !swc::isAhead("</title>", text, i); ++i)
                title += text.at(i);
            return title;
        }
    }
    return title;
}