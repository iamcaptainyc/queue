#include <windows.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#include "sysmets.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);//此为windowproc函数,用于处理发送给窗口的消息 

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	static TCHAR szAppName[]=TEXT("文字表-1");//创建了一个TCHAR型的字符数组，存储字符串以用作后来的名字
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
				TEXT("接下来将显示一段文字。"),//window titlename
				WS_OVERLAPPEDWINDOW|WS_VSCROLL,//WINDOW STYLE
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
	static int cxChar,cxCaps,cyChar,cyClient,iVscrollPos;//静态变量自动初始化为零 
	int i,y;
	TCHAR szBuffer[10];
	TEXTMETRIC tm;
	HDC hdc;
	PAINTSTRUCT ps; 
	
	switch(message)
	{
		case WM_CREATE:
			hdc=GetDC(hwnd);
			
			GetTextMetrics(hdc,&tm);
			cxChar=tm.tmAveCharWidth;
			cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2;
			cyChar=tm.tmHeight+tm.tmExternalLeading;
			
			ReleaseDC(hwnd,hdc);
			SetScrollRange(hwnd,SB_VERT,0,NUMLINES-1,FALSE);
			SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);//设置位置为零 
			return 0;
		case WM_SIZE:
			cyClient=HIWORD(lParam);//获得显示区域的高度，即高位数值 
			return 0;
			
		case WM_VSCROLL:
			switch(LOWORD(wParam))//获得低位数值 
			{
				case SB_LINEUP:
					iVscrollPos-=1;
					break;
				case SB_LINEDOWN:
					iVscrollPos+=1;
					break;
				case SB_PAGEUP://点击卷动列空白部分时翻一页 
					iVscrollPos-=cyClient/cyChar;//一页的显示行数 
					break;
				case SB_PAGEDOWN:
					iVscrollPos+=cyClient/cyChar;
					break;
				case SB_THUMBPOSITION:
					iVscrollPos=HIWORD(wParam);//当wParam低位为该通识符时，高位显示卷动方块的位置 
					break;
					
				default:
					break;
			}
			iVscrollPos=max(0,min(iVscrollPos,NUMLINES-1));//上方函数有可能会使滑块超出范围，此语句用来矫正位置 
			if(iVscrollPos!=GetScrollPos(hwnd,SB_VERT))
			{
				SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);//重新设置滑块位置并重画 
				InvalidateRect(hwnd,NULL,TRUE);//立即使画面无效，发送WM_PAINT消息更新窗口 
				//UpdateWindow(hwnd);
			}
			return 0;
		
		case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);
			
			for(i=0;i<NUMLINES;i++){
				y=cyChar*(i-iVscrollPos);//设置输出位置，滑块位置为正数则原来第一行的内容会被定位到第负几行，即超出打印范围，而对应于滑块位置的行则会在第一行被打印 
				 
				TextOut(hdc,0,y,
						sysmetrics[i].szLabel,
						lstrlen(sysmetrics[i].szLabel));
				TextOut(hdc,22*cxCaps,y,
						sysmetrics[i].szDesc,
						lstrlen(sysmetrics[i].szDesc));
				SetTextAlign(hdc,TA_RIGHT|TA_TOP);
				TextOut(hdc,22*cxCaps+40*cxChar,y,szBuffer,
						wsprintf(szBuffer,TEXT("%5d"),
						GetSystemMetrics(sysmetrics[i].Index)));
				SetTextAlign(hdc,TA_LEFT|TA_TOP);//设置对齐 
			}
			EndPaint(hwnd,&ps);
			return 0;
			
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}

