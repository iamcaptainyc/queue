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
	//  LPCTSTR lpWindowName,      // 窗口标题
	//  DWORD dwStyle,             // 窗口风格
	//  int x,                     // 初始 x 坐标
	//  int y,                     // 初始 y 坐标
	//  int nWidth,                // 初始 x 方向尺寸
	//  int nHeight,               // 初始 y 方向尺寸
	//  HWND hWndParent,           // 父窗口句柄
	//  HMENU hMenu,               // 窗口菜单句柄
	//  HINSTANCE hInstance,       // 程序实例句柄
	//  LPVOID lpParam             // 创建参数
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
 
	//要初始化IDirect3D，首先必须获取指向接口IDrect3D9的指针。使得一个专门的Direct3D函数可以很容易做到  
	IDirect3D9* d3d9 = 0;
	d3d9 = Direct3DCreate9(D3D_SDK_VERSION);
 
	if (!d3d9)
	{
		::MessageBox(0, "Direct3DCreate9() - FAILED", 0, 0);
		return false;
	}
 
	//检验图形卡是否支持该硬件顶点运算  
	D3DCAPS9 caps;
	d3d9->GetDeviceCaps(D3DADAPTER_DEFAULT, deviceType, &caps);
 
	int vp = 0;
	if (caps.DevCaps & D3DDEVCAPS_HWTRANSFORMANDLIGHT)
		//硬件顶点运算
		vp = D3DCREATE_HARDWARE_VERTEXPROCESSING;  
	else
		//软件顶点运算
		vp = D3DCREATE_SOFTWARE_VERTEXPROCESSING;  
	 
	//填充D3DPRESENT_PARAMETERS结构体
	D3DPRESENT_PARAMETERS d3dpp;
	d3dpp.BackBufferWidth = width;                 //后台缓存中表面的宽度，单位为像素  
	d3dpp.BackBufferHeight = height;               //后台缓存中表面的高度，单位为像素  
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;      //后台缓存的像素格式(如32位像素格式：D3DFMT_A8R8G8B8)  
	d3dpp.BackBufferCount = 1;                     //所需使用的后台缓存的个数，通常是1，需要一个后台缓存  
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;   //多重采样类型  
	d3dpp.MultiSampleQuality = 0;                  //多重采样的质量水平  
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;      //枚举类型指定交换链中的缓存的页面设置方式。  
	d3dpp.hDeviceWindow = hwnd;                    //与设备相关的窗口句柄。指定了所有进行绘制的应用程序窗口  
	d3dpp.Windowed = windowed;                     //窗口模式，为false时表示全屏模式
	d3dpp.EnableAutoDepthStencil = true;           //为true时，自动创建并维护深度缓存或模板缓存  
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;   //深度缓存或模板缓存的像素格式  
	d3dpp.Flags = 0;                               //附加特性 
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;   //刷新频率
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;   //一般为立即提交或由Direct3D来选择提交
 
	// 创建IDrect3Device9接口
	hr = d3d9->CreateDevice(
		D3DADAPTER_DEFAULT,  
		deviceType,           
		hwnd,                
		vp,                
		&d3dpp,              
		device);             
 
	//HRESULT CreateDevice(
    //    UINT Adapter,                                    // 希望代表的物理显卡
    //    D3DDEVTYPE DeviceType,                           // 设备类型
	//    HWND hFocusWindow,                               // 窗口句柄，指设备要绘制的目标窗口 
	//    DWORD BehaviorFlags,                             // 顶点运算类型
	//    D3DPRESENT_PARAMETERS *pPresentationParameters,  // 完成初始化的D3DPRESENT_PARAMETERS结构体
	//    IDirect3DDevice9 **ppReturnedDeviceInterface     // 返回所创建的设备
	//);
 
	if (FAILED(hr))
	{
		// 再次使用16位深度缓存尝试 
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
 
//消息循环  
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
			//计算相邻两次调用ptr_display的时间间隔 
			float timeDelta = (currTime - lastTime)*0.001f;
			//调用指定display函数
			ptr_display(timeDelta);
 
			lastTime = currTime;
		}
	}
	return msg.wParam;
}
