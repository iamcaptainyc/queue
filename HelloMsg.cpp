#include <windows.h>
#define max(a,b) (((a) > (b)) ? (a) : (b))
#define min(a,b) (((a) < (b)) ? (a) : (b))
#include "sysmets.h"

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);//��Ϊwindowproc����,���ڴ����͸����ڵ���Ϣ 

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	static TCHAR szAppName[]=TEXT("���ֱ�-1");//������һ��TCHAR�͵��ַ����飬�洢�ַ�������������������
	//����Ϊ������ĳ�ʼ�� 
	HWND hwnd;
	MSG msg;//MSGΪ�ṹ��������ʾ��Ϣ 
	WNDCLASS wndclass;//����һ��WNDCLASSʵ���������ڴ��洰�ڵ���Ϣ����һ���������ݽṹ
	
	wndclass.style=CS_HREDRAW|CS_VREDRAW;//���ô������ͣ�0ΪĬ��ֵ 
	wndclass.lpfnWndProc=WndProc;//���崰�ڴ����� 
	wndclass.cbClsExtra=0;//����������չ 
	wndclass.cbWndExtra=0;//����ʵ������չ 
	wndclass.hInstance=hInstance;//��ǰʵ�����
	wndclass.hIcon=LoadIcon(NULL,IDI_APPLICATION);//���ڵ���С��ͼ��ΪĬ��ͼ�� 
	wndclass.hCursor=LoadCursor(NULL,IDC_ARROW);//���ڲ��ü�ͷ��� 
	wndclass.hbrBackground=(HBRUSH)GetStockObject(WHITE_BRUSH);//���ڱ���Ϊ��ɫ  
	wndclass.lpszMenuName=NULL;//�����޲˵� 
	wndclass.lpszClassName=szAppName;//���ô������� 
	
	if(!RegisterClass(&wndclass))//���ע��ʧ�ܷ������� 
	{
		MessageBox(NULL,TEXT("This program requires Windows NT!"),szAppName,MB_ICONERROR);
		return 0;
	 }
	hwnd=CreateWindow(szAppName,//window class name
				TEXT("��һ������"),//window titlename
				WS_OVERLAPPEDWINDOW|WS_VSCROLL|WS_HSCROLL,//WINDOW STYLE
				CW_USEDEFAULT,//INITIAL X POSITION
				CW_USEDEFAULT,//INITIAL Y POSITION
				CW_USEDEFAULT,//INITIAL X SIZE
				CW_USEDEFAULT,//INITIAL Y SIZE
				NULL,//parent window handle �˴����޸�����
				NULL,//window menu handle ���Ӳ˵�
				hInstance,//program instance handle �����˴��ڵ�Ӧ�ó���ĵ�ǰ���
				NULL);//creation parameters
	 
	 ShowWindow(hwnd,iCmdShow);
	 UpdateWindow(hwnd);//�����û���
	 //��Ϣѭ��
	 while(GetMessage(&msg,NULL,0,0))
	 {
	 	TranslateMessage(&msg);//���������Ϣת��Ϊ�ַ���Ϣ 
	 	DispatchMessage(&msg);// �ú�������һ����Ϣ�����ڳ���ͨ�����ȴ�GetMessage��ȡ����Ϣ����Ϣ�����ȵ�WindowProc���� 
	  } 
	 return msg.wParam;//����Ϣ����ϵͳ 
 }
LRESULT CALLBACK WndProc(HWND hwnd,UINT message,WPARAM wParam,LPARAM lParam)
{
	static int cxChar,cxCaps,cyChar,cxClient,cyClient,iMaxWidth;//��̬�����Զ���ʼ��Ϊ�� 
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
			cyClient=HIWORD(lParam);//�����ʾ����ĸ߶ȣ�����λ��ֵ 
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
			switch(LOWORD(wParam))//��õ�λ��ֵ 
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
				case SB_PAGEUP://������пհײ���ʱ��һҳ 
					si.nPos-=si.nPage;//һҳ����ʾ���� 
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
			SetScrollInfo(hwnd,SB_VERT,&si,TRUE);//��Χ���趨�ã����ᳬ�� 
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
			SetScrollInfo(hwnd,SB_HORZ,&si,TRUE);//���»���λ�� 
			GetScrollInfo(hwnd,SB_HORZ,&si);
			
			if(si.nPos!=iHorzPos)//���´������� 
			{
				ScrollWindow(hwnd,cxChar*(iHorzPos-si.nPos),0,NULL,NULL);//�ڶ��������������ƣ��������� 
			}
			return 0;
			
		case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);
			
			si.cbSize=sizeof(si);
			si.fMask=SIF_POS;
			GetScrollInfo(hwnd,SB_VERT,&si);
			iVertPos=si.nPos;//��õ�ǰλ�� 
			
			GetScrollInfo(hwnd,SB_HORZ,&si);
			iHorzPos=si.nPos;
			//find painting limits
			iPaintBeg=max(0,iVertPos+ps.rcPaint.top/cyChar); 
			iPaintEnd=min(NUMLINES-1,iVertPos+ps.rcPaint.bottom/cyChar);//�����ƺ󲻻��Ƴ�����ʾ��Χ�����ݼ�����Դ���� 
			
			for(i=iPaintBeg;i<=iPaintEnd;i++){
				x=cxChar*(1-iHorzPos);
				y=cyChar*(i-iVertPos);//�������λ�ã�����λ��Ϊ������ԭ����һ�е����ݻᱻ��λ���ڸ����У���������ӡ��Χ������Ӧ�ڻ���λ�õ�������ڵ�һ�б���ӡ 
				 
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
				SetTextAlign(hdc,TA_LEFT|TA_TOP);//���ö��� 
			}
			EndPaint(hwnd,&ps);
			return 0;
			
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0; 
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}

