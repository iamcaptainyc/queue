#include <windows.h>
#define UNICODE

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);//此为windowproc函数,用于处理发送给窗口的消息 

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	static TCHAR szAppName[]=TEXT("HelloWin");//创建了一个TCHAR型的字符数组，存储字符串以用作后来的名字
	//以下为窗口类的初始化 
	HWND hwnd;
	MSG msg;//MSG为结构体用来表示消息 
	WNDCLASS wndclass;//创建一个WNDCLASS实例，其用于储存窗口的信息，是一个基本数据结构
	
	wndclass.style=CS_HREDRAW|CS_VREDRAW;//设置窗口类型，0为默认值 
	wndclass.lpfnWndProc=WndProc;//定义窗口处理函数 
	wndclass.cbClsExtra=0;//窗口类无扩展 
	wndclass.cbWndExtra=0;//窗口实例无扩展
	wndclass.hInstance=hInstance;//当前实例句柄 
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);//窗口的最小化图标为默认图标 
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);//窗口采用箭头光标
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//窗口背景为白色
	wndclass.lpszMenuName=NULL;//窗口无菜单 
	wndclass.lpszClassName=szAppName;//设置窗口类名 
	
	if(!RegisterClass(&wndclass))//如果注册失败发出警告 
	{
		MessageBox(NULL,TEXT("This program requires Windows NT!"),szAppName,MB_ICONERROR);
		return 0;
	 }
	hwnd=CreateWindow(szAppName,//window class name
				TEXT("The Hello Program"),//window titlename
				WS_OVERLAPPEDWINDOW,//WINDOW STYLE
				CW_USEDEFAULT,//INITIAL X POSITION
				CW_USEDEFAULT,//INITIAL Y POSITION
				CW_USEDEFAULT,//INITIAL X SIZE
				CW_USEDEFAULT,//INITIAL Y SIZE
				NULL,//parent window handle 此窗口无父窗口
				NULL,//window menu handle 无子菜单
				hInstance,//program instance handle 创建此窗口的应用程序的当前句柄
				NULL);//creation parameters
	 
	 ShowWindow(hwnd,iCmdShow);
	 UpdateWindow(hwnd);//绘制用户区
	 //消息循环
	 while(GetMessage(&msg,NULL,0,0))
	 {
	 	TranslateMessage(&msg);//将虚拟键消息转换为字符消息 
	 	DispatchMessage(&msg);// 该函数调度一个消息给窗口程序。通常调度从GetMessage获取的消息。消息被调度到WindowProc函数 
	  } 
	 return msg.wParam;//将信息返回系统 
 }
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	RECT rect;
	
	switch(message)
	{
		case WM_CREATE:
			//PlaySound (TEXT("hellowin.wav"),NULL,SND_FILENAME|SND_ASYNC);
			return 0;
		
		/*case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);
			
			GetClientRect(hwnd,&rect);
			
			DrawText(hdc,TEXT("Hello,Windows 98!  于畅你好"),-1,&rect,
					DT_SINGLELINE|DT_CENTER|DT_VCENTER);
					EndPaint(hwnd,&ps);
					return 0;*/ 
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}

