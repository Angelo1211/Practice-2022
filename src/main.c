#ifndef WIN32
#error This is only valid for windows
#endif

#define _CRT_SECURE_NO_WARNINGS
#define WIN_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "User32.lib")

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

int main(int argc, char *argv[])
{
	DWORD last_error;
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = "Basic Window Class";
	wc.hInstance = GetModuleHandle(0);

	if ( !RegisterClassEx(&wc) )
		last_error = GetLastError();

	HWND hwnd = CreateWindowEx(0,
							   wc.lpszClassName,
							   "Hello World",
							   WS_OVERLAPPEDWINDOW,
							   100, 50, 1280, 720,
							   0, 0, wc.hInstance, 0);
	if (!hwnd)
		last_error = GetLastError();

	assert(hwnd);

	ShowWindow(hwnd, SW_SHOW);

	MSG msg = {0};
	while (GetMessage(&msg, NULL, 0, 0) > 0)
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}