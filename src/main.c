#pragma comment(lib, "user32.lib")

LRESULT CALLBACK
WindowProc(HWND handle, UINT msg, WPARAM wp, LPARAM lp)
{
	switch(msg)
	{
		case WM_DESTROY:
		{
			PostQuitMessage(0);
			return 0;
		}break;
	}

	return DefWindowProc(handle, msg, wp, lp);
}

int main(int argc, char *argv[])
{
	WNDCLASSEX wc = {0};
	wc.cbSize = sizeof(wc);
	wc.lpfnWndProc = WindowProc;
	wc.lpszClassName = "Default Window Class";
	wc.hInstance = GetModuleHandle(0);

	RegisterClassEx(&wc);

	HWND hwnd = CreateWindowEx(0, wc.lpszClassName,
							   "Hello World!", WS_OVERLAPPEDWINDOW,
							   100, 100, 1280, 720, 0, 0, wc.hInstance, 0);
	assert(hwnd);

	ShowWindow(hwnd, 1);

	b32 running = true;
	while(running)
	{
		MSG msg;
		while (PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			if(msg.message == WM_QUIT) 
				running = false;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	printf("Hello World!\n");
}
