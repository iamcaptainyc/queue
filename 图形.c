#ifndef __d3dUtilityH__  
#define __d3dUtilityH__  
 
#include <d3dx9.h>   
 
namespace d3d
{
	//初始化DirectX3D
	bool InitD3D(                     
		HINSTANCE hInstance,       // [in] Application instance 
		int width, int height,     // [in] Backbuffer dimensions
		bool windowed,             // [in] Windowed (true)or full screen (false)
		D3DDEVTYPE deviceType,     // [in] HAL or REF  
		IDirect3DDevice9** device);// [out]The created device
 
        //消息循环
	int EnterMsgLoop(   
		bool(*ptr_display)(float timeDelta));
 
	LRESULT CALLBACK Wnd_Proc(
		HWND hwnd,
		UINT msg,
		WPARAM wParam,
		LPARAM lParam);
 
	template<class T> void Release(T t)
	{
		if (t)
		{
			t->Release();
			t = 0;
		}
	}
 
	template<class T> void Delete(T t)
	{
		if (t)
		{
			delete t;
			t = 0;
		}
	}
}
 
#endif 
