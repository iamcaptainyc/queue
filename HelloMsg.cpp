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
				TEXT("第一个程序"),//window titlename
				WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL,//WINDOW STYLE
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
	static int cxChar,cxCaps,cyChar,cxClient,cyClient,iMaxWidth;//静态变量自动初始化为零 
	int i,x,y,iVertPos,iHorzPos,iPaintBeg,iPaintEnd;
	TCHAR szBuffer[10];
	TEXTMETRIC tm;
	HDC hdc;
	PAINTSTRUCT ps; 
	SCROLLINFO si;
	
	switch(message)
	{
		case WM_CREATE:
			hdc=GetDC(hwnd);
			
			GetTextMetrics(hdc,&tm);
			cxChar=tm.tmAveCharWidth;
			cxCaps=(tm.tmPitchAndFamily&1?3:2)*cxChar/2;
			cyChar=tm.tmHeight+tm.tmExternalLeading;
			
			ReleaseDC(hwnd,hdc);
			  //save the width of the three columns
			iMaxWidth=40*cxChar+22*cxCaps;
			return 0;
			
		case WM_SIZE:
			cyClient=HIWORD(lParam);//获得显示区域的高度，即高位数值 
			cxClient=LOWORD(lParam);
			//set vertical scroll bar range and page size
			si.cbSize=sizeof(si);
			si.fMask=SIF_RANGE|SIF_PAGE;
			si.nMin=0;
			si.nMax=NUMLINES-1;
			si.nPage=cyClient/cyChar;
			SetScrollInfo(hwnd,SB_VERT,&si,TRUE);
			
			si.cbSize=sizeof(si);
			si.fMask=SIF_RANGE|SIF_PAGE;
			si.nMin=0;
			si.nMax=2+iMaxWidth/cxChar;
			si.nPage=cxClient/cxChar;
			SetScrollInfo(hwnd,SB_HORZ,&si,TRUE);
			return 0;
			
		case WM_VSCROLL:
			//get all the vertical scroll bar information
			si.cbSize=sizeof(si);
			si.fMask=SIF_ALL;
			GetScrollInfo(hwnd,SB_VERT,&si);
			//save the position foe comparison later on
			iVertPos=si.nPos;
			switch(LOWORD(wParam))//获得低位数值 
			{
				case SB_TOP:
					si.nPos=si.nMin;
					break;
				case SB_BOTTOM:
					si.nPos=si.nMax;
					break;
				case SB_LINEUP:
					si.nPos-=1;
					break;
				case SB_LINEDOWN:
					si.nPos+=1;
					break;
				case SB_PAGEUP://点击卷动列空白部分时翻一页 
					si.nPos-=si.nPage;//一页的显示行数 
					break;
				case SB_PAGEDOWN:
					si.nPos+=si.nPage;
					break;
				case SB_THUMBTRACK:
					si.nPos=si.nTrackPos;
					break;
					
				default:
					break;
			}
			
			//set the position
			si.fMask=SIF_POS;
			SetScrollInfo(hwnd,SB_VERT,&si,TRUE);//范围已设定好，不会超出 
			GetScrollInfo(hwnd,SB_VERT,&si);
	
			if(si.nPos!=iVertPos)
			{
				ScrollWindow(hwnd,0,cyChar*(iVertPos-si.nPos),NULL,NULL);
				UpdateWindow(hwnd);
			}
			return 0;
		case WM_HSCROLL:
			si.cbSize=sizeof(si);
			si.fMask=SIF_ALL;
			
			GetScrollInfo(hwnd,SB_HORZ,&si);
			iHorzPos=si.nPos;
			
			switch(LOWORD(wParam))
			{
				case SB_LINELEFT:
					si.nPos-=1;
					break;
				case SB_LINERIGHT:
					si.nPos+=1;
					break;
				case SB_PAGELEFT:
					si.nPos-=si.nPage;
					break;
				case SB_PAGERIGHT:
					si.nPos+=si.nPage;
					break;
				case SB_THUMBTRACK:
					si.nPos=si.nTrackPos;
					break;
				default:
					break;
			}
			
			si.fMask=SIF_POS;
			SetScrollInfo(hwnd,SB_HORZ,&si,TRUE);//更新滑块位置 
			GetScrollInfo(hwnd,SB_HORZ,&si);
			
			if(si.nPos!=iHorzPos)//更新窗口内容 
			{
				ScrollWindow(hwnd,cxChar*(iHorzPos-si.nPos),0,NULL,NULL);//第二个参数正往左移，负往右移 
			}
			return 0;
			
		case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);
			
			si.cbSize=sizeof(si);
			si.fMask=SIF_POS;
			GetScrollInfo(hwnd,SB_VERT,&si);
			iVertPos=si.nPos;//获得当前位置 
			
			GetScrollInfo(hwnd,SB_HORZ,&si);
			iHorzPos=si.nPos;
			//find painting limits
			iPaintBeg=max(0,iVertPos+ps.rcPaint.top/cyChar); 
			iPaintEnd=min(NUMLINES-1,iVertPos+ps.rcPaint.bottom/cyChar);//即限制后不绘制超出显示范围的内容减少资源消耗 
			
			for(i=iPaintBeg;i<=iPaintEnd;i++){
				x=cxChar*(1-iHorzPos);
				y=cyChar*(i-iVertPos);//设置输出位置，滑块位置为正数则原来第一行的内容会被定位到第负几行，即超出打印范围，而对应于滑块位置的行则会在第一行被打印 
				 
				TextOut(hdc,x,y,
						sysmetrics[i].szLabel,
						lstrlen(sysmetrics[i].szLabel));
				TextOut(hdc,x+22*cxCaps,y,
						sysmetrics[i].szDesc,
						lstrlen(sysmetrics[i].szDesc));
				SetTextAlign(hdc,TA_RIGHT|TA_TOP);
				TextOut(hdc,x+22*cxCaps+40*cxChar,y,szBuffer,
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

