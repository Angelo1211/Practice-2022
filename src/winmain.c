#include "unity.c"

#define WIN_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "user32.lib")

fn void
Enable_Printf()
{
	if (AttachConsole(-1) || AllocConsole())
	{
		freopen("CONIN$", "r", stdin);
		freopen("CONOUT$", "wb", stdout);
	}
}

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	switch (msg)
	{
	case WM_DESTROY:
	{
		PostQuitMessage(0);
		return 0;
	}
	break;
	}
	return DefWindowProc(hwnd, msg, wp, lp);
}

INT WINAPI
WinMain(HINSTANCE instance, HINSTANCE prevInstance, PSTR cmd, INT show)
{

	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.hInstance = instance;
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = "Default class";

	RegisterClassEx(&wc);

	HWND hwnd = CreateWindowEx(0, wc.lpszClassName, "Test Window", WS_OVERLAPPEDWINDOW,
							   100, 100, 1280, 720, 0, 0, instance, 0);
	assert(hwnd);

	ShowWindow(hwnd, 1);

	b32 running = true;
	while (running)
	{
		MSG msg;
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
				running = false;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	Enable_Printf();
	printf("Program is done!\n");
	return 0;
}