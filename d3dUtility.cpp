#include "d3dUtility.h"
//#pragma comment(lib,"d3d9.lib")  
//#pragma comment(lib,"d3dx9.lib")  
//#pragma comment(lib,"winmm.lib")  
 
bool d3d::InitD3D(
	HINSTANCE hInstance,
	int width, int height,
	bool windowed,
	D3DDEVTYPE deviceType,
	IDirect3DDevice9** device)
{
	//  
	// Create the main application window.  
	//  
 
	WNDCLASS wc;
 
	wc.style = CS_HREDRAW | CS_VREDRAW;
	wc.lpfnWndProc = (WNDPROC)d3d::Wnd_Proc;
	wc.cbClsExtra = 0;
	wc.cbWndExtra = 0;
	wc.hInstance = hInstance;
	wc.hIcon = LoadIcon(0, IDI_APPLICATION);
	wc.hCursor = LoadCursor(0, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wc.lpszMenuName = 0;
	wc.lpszClassName = "Direct3D9App";
 
	if (!RegisterClass(&wc))
	{
		::MessageBox(0, "RegisterClass() - FAILED", 0, 0);
		return false;
	}
	     
	HWND hwnd = 0;
	hwnd = ::CreateWindow(
		"Direct3D9App", 
		"Direct3D9App",
		WS_EX_APPWINDOW,
		0, 0, width, height,
		0 /*parent hwnd*/, 0 /* menu */, hInstance, 0 /*extra*/);
 
	//HWND CreateWindow(            
	//  LPCTSTR lpWindowName,      // ���ڱ���
	//  DWORD dwStyle,             // ���ڷ��
	//  int x,                     // ��ʼ x ����
	//  int y,                     // ��ʼ y ����
	//  int nWidth,                // ��ʼ x ����ߴ�
	//  int nHeight,               // ��ʼ y ����ߴ�
	//  HWND hWndParent,           // �����ھ��
	//  HMENU hMenu,               // ���ڲ˵����
	//  HINSTANCE hInstance,       // ����ʵ�����
	//  LPVOID lpParam             // ��������
	//); 
 
	if (!hwnd)
	{
		::MessageBox(0, "CreateWindow() - FAILED", 0, 0);
		return false;
	}
 
	::ShowWindow(hwnd, SW_SHOW);
	::UpdateWindow(hwnd);
 
 
	// Init D3D:    
 
	HRESULT hr = 0;
 
	//Ҫ��ʼ��IDirect3D�����ȱ����ȡָ��ӿ�IDrect3D9��ָ�롣ʹ��һ��ר�ŵ�Direct3D�������Ժ���������  
	IDirect3D9* d3d9 = 0;
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
 
	if (!d3d9)
	{
		::MessageBox(0, "Direct3DCreate9() - FAILED", 0, 0);
		return false;
	}
 
	//����ͼ�ο��Ƿ�֧�ָ�Ӳ����������  
	D3DCAPS9 caps;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);
 
	int vp = 0;
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		//Ӳ����������
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;  
	else
		//�����������
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  
	 
	//���D3DPRESENT_PARAMETERS�ṹ��
	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth = width;                 //��̨�����б���Ŀ�ȣ���λΪ����  
	d3dpp.BackBufferHeight = height;               //��̨�����б���ĸ߶ȣ���λΪ����  
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;      //��̨��������ظ�ʽ(��32λ���ظ�ʽ��D3DFMT_A8R8G8B8)  
	d3dpp.BackBufferCount = 1;                     //����ʹ�õĺ�̨����ĸ�����ͨ����1����Ҫһ����̨����  
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;   //���ز�������  
	d3dpp.MultiSampleQuality = 0;                  //���ز���������ˮƽ  
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;      //ö������ָ���������еĻ����ҳ�����÷�ʽ��  
	d3dpp.hDeviceWindow = hwnd;                    //���豸��صĴ��ھ����ָ�������н��л��Ƶ�Ӧ�ó��򴰿�  
	d3dpp.Windowed = windowed;                     //����ģʽ��Ϊfalseʱ��ʾȫ��ģʽ
	d3dpp.EnableAutoDepthStencil = true;           //Ϊtrueʱ���Զ�������ά����Ȼ����ģ�建��  
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;   //��Ȼ����ģ�建������ظ�ʽ  
	d3dpp.Flags = 0;                               //�������� 
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;   //ˢ��Ƶ��
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   //һ��Ϊ�����ύ����Direct3D��ѡ���ύ
 
	// ����IDrect3Device9�ӿ�
	hr = d3d9->CreateDevice(
		D3DADAPTER_DEFAULT,  
		deviceType,           
		hwnd,                
		vp,                
		&d3dpp,              
		device);             
 
	//HRESULT CreateDevice(
    //    UINT Adapter,                                    // ϣ������������Կ�
    //    D3DDEVTYPE DeviceType,                           // �豸����
	//    HWND hFocusWindow,                               // ���ھ����ָ�豸Ҫ���Ƶ�Ŀ�괰�� 
	//    DWORD BehaviorFlags,                             // ������������
	//    D3DPRESENT_PARAMETERS *pPresentationParameters,  // ��ɳ�ʼ����D3DPRESENT_PARAMETERS�ṹ��
	//    IDirect3DDevice9 **ppReturnedDeviceInterface     // �������������豸
	//);
 
	if (FAILED(hr))
	{
		// �ٴ�ʹ��16λ��Ȼ��波�� 
		d3dpp.AutoDepthStencilFormat = D3DFMT_D16;
 
		hr = d3d9->CreateDevice(
			D3DADAPTER_DEFAULT,
			deviceType,
			hwnd,
			vp,
			&d3dpp,
			device); 
 
		if (FAILED(hr))
		{
			d3d9->Release();  
			::MessageBox(0, "CreateDevice() - FAILED", 0, 0);
			return false;
		}
	}
 
	d3d9->Release();  
 
	return true;
}
 
//��Ϣѭ��  
int d3d::EnterMsgLoop(bool(*ptr_display)(float timeDelta))
{
	MSG msg;
	::ZeroMemory(&msg, sizeof(MSG));
 
	static float lastTime = (float)timeGetTime();
 
	while (msg.message != WM_QUIT)
	{
		if (::PeekMessage(&msg, 0, 0, 0, PM_REMOVE))
		{
			::TranslateMessage(&msg);
			::DispatchMessage(&msg);
		}
		else
		{
			float currTime = (float)timeGetTime();
			//�����������ε���ptr_display��ʱ���� 
			float timeDelta = (currTime - lastTime)*0.001f;
			//����ָ��display����
			ptr_display(timeDelta);
 
			lastTime = currTime;
		}
	}
	return msg.wParam;
}
