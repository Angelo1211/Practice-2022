#include "unity.c"

#define WIN_LEAN_AND_MEAN
#include <windows.h>

#pragma comment(lib, "user32.lib")

void Console_Init()
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
	LRESULT result = 0;
	switch(msg)
	{
		case WM_DESTROY: PostQuitMessage(0); break;

		default: result = DefWindowProc(hwnd, msg, wp, lp);
	}
	return result;
}

INT WINAPI
WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	Console_Init();
	printf("Engine start!\n");

	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.hInstance = hInstance;
	wc.lpszClassName = "Default";
	wc.lpfnWndProc = WindowProc;

	RegisterClassEx(&wc);

	HWND hwnd = CreateWindowEx(0, wc.lpszClassName, "Hello World", WS_OVERLAPPEDWINDOW,
							   100, 100, 1280, 720, 0, 0, hInstance, 0);
	assert(hwnd);

	ShowWindow(hwnd, 1);

	b32 running = true;
	while(running)
	{
		MSG msg;
		while(PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT) running = false;
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}