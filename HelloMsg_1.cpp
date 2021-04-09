#include <windows.h>
#define UNICODE

LRESULT CALLBACK WndProc(HWND,UINT,WPARAM,LPARAM);//��Ϊwindowproc����,���ڴ����͸����ڵ���Ϣ 

int WINAPI WinMain(HINSTANCE hInstance,HINSTANCE hPrevInstance,PSTR szCmdLine,int iCmdShow)
{
	static TCHAR szAppName[]=TEXT("HelloWin");//������һ��TCHAR�͵��ַ����飬�洢�ַ�������������������
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
				TEXT("The Hello Program"),//window titlename
				WS_OVERLAPPEDWINDOW,//WINDOW STYLE
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
			
			DrawText(hdc,TEXT("Hello,Windows 98!  �ڳ����"),-1,&rect,
					DT_SINGLELINE|DT_CENTER|DT_VCENTER);
					EndPaint(hwnd,&ps);
					return 0;*/ 
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
	}
	return DefWindowProc(hwnd,message,wParam,lParam);
}

