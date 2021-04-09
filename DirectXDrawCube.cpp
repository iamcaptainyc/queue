#include "d3dUtility.h"
 
//初始化设备
IDirect3DDevice9* device = NULL;
 
//初始化顶点缓存和索引缓存
IDirect3DVertexBuffer9* VB = 0;
IDirect3DIndexBuffer9* IB = 0;
 
//定义屏幕分辨率
const int width = 640;
const int height = 480;
 
//定义顶点结构和灵活顶点格式
typedef struct Vertex {
	Vertex() {}
	Vertex(float x, float y, float z) {
		_x = x;
		_y = y;
		_z = z;
	}
 
	float _x, _y, _z;
	static const DWORD FVF;  //灵活顶点格式
    
}vertex;
const DWORD vertex::FVF = D3DFVF_XYZ;
 
//setup
bool setup()
{
	//创建顶点缓存
	device->CreateVertexBuffer(8 * sizeof(vertex), D3DUSAGE_WRITEONLY, vertex::FVF, D3DPOOL_MANAGED, &VB, 0);
	//HRESULT CreateVertexBuffer(
	//	  UINT Length,                                //为缓存分配的字节数  
	//	  DWORD Usage,                                //顶点缓冲区的附加属性，D3DUSAGE_WRITEONLY为"只写"  
	//	  DWORD FVF,                                  //灵活顶点格式  
	//	  D3DPOOL Pool,                               //顶点缓冲的内存池  
	//	  IDirect3DVertexBuffer9** ppVertexBuffer,    //顶点缓冲指针  
	//	  HANDLE* pSharedHandle                       //保留参数，置为0  
	//);
 
	//创建索引缓存
	device->CreateIndexBuffer(36 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16/*索引大小*/, D3DPOOL_MANAGED, &IB, 0);
 
	//填充顶点缓存
	vertex* vertices;
	VB->Lock(0, 0, (void**)&vertices, 0);
 
	vertices[0] = vertex(-1.0f, -1.0f, -1.0f);
	vertices[1] = vertex(-1.0f,  1.0f, -1.0f);
	vertices[2] = vertex( 1.0f,  1.0f, -1.0f);
	vertices[3] = vertex( 1.0f, -1.0f, -1.0f);
	vertices[4] = vertex(-1.0f, -1.0f,  1.0f);
	vertices[5] = vertex(-1.0f,  1.0f,  1.0f);
	vertices[6] = vertex( 1.0f,  1.0f,  1.0f);
	vertices[7] = vertex( 1.0f, -1.0f,  1.0f);
 
	VB->Unlock();
 
	//填充索引缓存
	WORD* indices = 0;
	IB->Lock(0, 0, (void**)&indices, 0);
 
	indices[ 0] = 0; indices[ 1] = 1; indices[ 2] = 2;
	indices[ 3] = 0; indices[ 4] = 2; indices[ 5] = 3;
 
	indices[ 6] = 4; indices[ 7] = 6; indices[ 8] = 5;
	indices[ 9] = 4; indices[10] = 7; indices[11] = 6;
 
	indices[12] = 4; indices[13] = 5; indices[14] = 1;
	indices[15] = 4; indices[16] = 1; indices[17] = 0;
 
	indices[18] = 3; indices[19] = 2; indices[20] = 6;
	indices[21] = 3; indices[22] = 6; indices[23] = 7;
 
	indices[24] = 1; indices[25] = 5; indices[26] = 6;
	indices[27] = 1; indices[28] = 6; indices[29] = 2;
 
	indices[30] = 4; indices[31] = 0; indices[32] = 3;
	indices[33] = 4; indices[34] = 3; indices[35] = 7;
 
	IB->Unlock();
 
	//创建观察坐标系变换矩阵并设定变换
	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX v;
	D3DXMatrixLookAtLH(&v, &position, &target, &up);
	device->SetTransform(D3DTS_VIEW, &v);
 
	//创建投影变换矩阵并设定变换
	D3DXMATRIX projection;
	D3DXMatrixPerspectiveFovLH(&projection, D3DX_PI*0.5f, (float)width / (float)height, 1.0, 1000.0f);
	device->SetTransform(D3DTS_PROJECTION, &projection);
 
	//设定绘制状态为线框模式
	device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
 
	return true;
}
 
//cleanup
void cleanup()
{
	// 释放顶点缓存和索引缓存
	d3d::Release<IDirect3DVertexBuffer9*>(VB);
	d3d::Release<IDirect3DIndexBuffer9*>(IB);
}
 
//display
bool display(float timeDelta)
{
	if (device == NULL)
		return false;
	
	//平移矩阵
	D3DXMATRIX translation;
	
	static float tx = -3.0f;
	static float ty = 0.0f;
	static const float multi = 1.0f;
	static float multix = multi;
	static float multiy = multi;
 
	tx += multix*timeDelta;
	ty += multiy*timeDelta;
 
    D3DXMatrixTranslation(&translation, tx, ty, 0);
 
	if (tx >= 3.0f)
		multix = -1.0f*multi;
	else if (tx <= -3.0f)
		multix = 1.0f*multi;
	
	if (ty >= 3.0f)
		multiy = -1.0f*multi;
	else if (ty <= -3.0f)
		multiy = 1.0f*multi;
 
	//旋转矩阵
	D3DXMATRIX rotationXM, rotationYM;
 
	static float r = 0.0f;
	D3DXMatrixRotationX(&rotationXM, r);
	D3DXMatrixRotationY(&rotationYM, r);
	r += timeDelta;
 
	if (r >= 6.28)
		r = 0.0f;
 
	D3DXMATRIX p = rotationXM*rotationYM*translation;
	device->SetTransform(D3DTS_WORLD, &p);
 
	
	device->Clear(0, 0, D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 0xffffffff, 1.0f, 0);
	//HRESULT Clear(
	//	  DWORD Count,                 //pRects数组中矩形的数目
	//	  const D3DRECT *pRects,       //所要执行清除操作的屏幕矩形数组
	//	  DWORD Flags,                 //所要清除的表面，包括D3DCLEAR_TARGET(后台缓存), D3DCLEAR_ZBUFFER(Z深度缓存), D3DCLEAR_STENCIL(模板平面缓存)
	//	  D3DCOLOR Color,              //指定将绘制目标体设置为何种颜色
	//	  float Z,                     // 设定深度缓存，[0,1]
	//	  DWORD Stencil                // 模板缓存所要设定的值
	//);
 
	device->BeginScene();
	
	//绘制之前的准备工作
	device->SetStreamSource(0, VB, 0, sizeof(vertex));      //指定数据流输入源
	device->SetFVF(vertex::FVF);                            //设置顶点格式
	device->SetIndices(IB);                                 //设置索引缓存(任意时刻只允许使用一个索引缓存)
 
	device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);   //绘制三角形
	//HRESULT DrawIndexedPrimitive(
	//	  D3DPRIMITIVETYPE Type,     //所要绘制的图元类型
	//	  INT BaseVertexIndex,       //起始顶点索引
	//	  UINT MinIndex,             //最小索引(相对于起始顶点索引)
	//	  UINT NumVertices,          //使用的顶点数量
	//	  UINT StartIndex,           //索引缓存中的起始索引
	//	  UINT PrimitiveCount        //所要绘制的图元数量
	//);
 
	device->EndScene();
 
	// 提交后台缓存(表面交换)
	device->Present(NULL, NULL, NULL, NULL);
 
	return true;
}
 
//窗口过程函数
LRESULT CALLBACK d3d::Wnd_Proc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
 
	case WM_KEYDOWN:
		//按下esc退出
		if (wParam == VK_ESCAPE)
			DestroyWindow(hwnd);
		break;
	}
 
	return DefWindowProc(hwnd, msg, wParam, lParam);
}
 
//WinMain
int WINAPI WinMain(HINSTANCE inst, HINSTANCE, PSTR cmd_line, int cmd_show)
{
	if (!d3d::InitD3D(inst, 640, 480, true, D3DDEVTYPE_HAL, &device))
	{
		MessageBox(NULL, "init_d3d() - failed.", 0, MB_OK);
		return 0;
	}
 
	if (!setup())
	{
		MessageBox(NULL, "Steup() - failed.", 0, MB_OK);
		return 0;
	}
 
	d3d::EnterMsgLoop(display);
 
	cleanup();
	device->Release();
 
	return 0;
}
