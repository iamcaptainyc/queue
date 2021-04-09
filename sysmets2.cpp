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
				TEXT("����������ʾһ�����֡�"),//window titlename
				WS_OVERLAPPEDWINDOW|WS_VSCROLL,//WINDOW STYLE
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
	static int cxChar,cxCaps,cyChar,cyClient,iVscrollPos;//��̬�����Զ���ʼ��Ϊ�� 
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
			SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);//����λ��Ϊ�� 
			return 0;
		case WM_SIZE:
			cyClient=HIWORD(lParam);//�����ʾ����ĸ߶ȣ�����λ��ֵ 
			return 0;
			
		case WM_VSCROLL:
			switch(LOWORD(wParam))//��õ�λ��ֵ 
			{
				case SB_LINEUP:
					iVscrollPos-=1;
					break;
				case SB_LINEDOWN:
					iVscrollPos+=1;
					break;
				case SB_PAGEUP://������пհײ���ʱ��һҳ 
					iVscrollPos-=cyClient/cyChar;//һҳ����ʾ���� 
					break;
				case SB_PAGEDOWN:
					iVscrollPos+=cyClient/cyChar;
					break;
				case SB_THUMBPOSITION:
					iVscrollPos=HIWORD(wParam);//��wParam��λΪ��ͨʶ��ʱ����λ��ʾ�������λ�� 
					break;
					
				default:
					break;
			}
			iVscrollPos=max(0,min(iVscrollPos,NUMLINES-1));//�Ϸ������п��ܻ�ʹ���鳬����Χ���������������λ�� 
			if(iVscrollPos!=GetScrollPos(hwnd,SB_VERT))
			{
				SetScrollPos(hwnd,SB_VERT,iVscrollPos,TRUE);//�������û���λ�ò��ػ� 
				InvalidateRect(hwnd,NULL,TRUE);//����ʹ������Ч������WM_PAINT��Ϣ���´��� 
				//UpdateWindow(hwnd);
			}
			return 0;
		
		case WM_PAINT:
			hdc=BeginPaint(hwnd,&ps);
			
			for(i=0;i<NUMLINES;i++){
				y=cyChar*(i-iVscrollPos);//�������λ�ã�����λ��Ϊ������ԭ����һ�е����ݻᱻ��λ���ڸ����У���������ӡ��Χ������Ӧ�ڻ���λ�õ�������ڵ�һ�б���ӡ 
				 
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

