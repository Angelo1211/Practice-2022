#pragma comment(lib, "user32.lib")

LRESULT CALLBACK
WindowProc(HWND hwnd, UINT msg, WPARAM wp, LPARAM lp)
{
	return DefWindowProc(hwnd, msg, wp, lp);
}

int main(int argc, char *argv[])
{
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = WindowProc;
	wc.hInstance = GetModuleHandle(0);
	wc.lpszClassName = "Default Window Class";

	RegisterClassEx(&wc);

	HWND hwnd = CreateWindowEx(0, wc.lpszClassName,
							   "Test Window",
							   WS_OVERLAPPEDWINDOW,
							   0, 0, 1280, 720,
							   0, 0, wc.hInstance, 0);
	assert(hwnd);

	ShowWindow(hwnd, 1);

	b32 running = true;
	while (running)
	{
		MSG msg;
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				running = false;
				break;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
}
