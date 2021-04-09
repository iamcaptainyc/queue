#include "d3dUtility.h"
 
//��ʼ���豸
IDirect3DDevice9* device = NULL;
 
//��ʼ�����㻺�����������
IDirect3DVertexBuffer9* VB = 0;
IDirect3DIndexBuffer9* IB = 0;
 
//������Ļ�ֱ���
const int width = 640;
const int height = 480;
 
//���嶥��ṹ�������ʽ
typedef struct Vertex {
	Vertex() {}
	Vertex(float x, float y, float z) {
		_x = x;
		_y = y;
		_z = z;
	}
 
	float _x, _y, _z;
	static const DWORD FVF;  //�����ʽ
    
}vertex;
const DWORD vertex::FVF = D3DFVF_XYZ;
 
//setup
bool setup()
{
	//�������㻺��
	device->CreateVertexBuffer(8 * sizeof(vertex), D3DUSAGE_WRITEONLY, vertex::FVF, D3DPOOL_MANAGED, &VB, 0);
	//HRESULT CreateVertexBuffer(
	//	  UINT Length,                                //Ϊ���������ֽ���  
	//	  DWORD Usage,                                //���㻺�����ĸ������ԣ�D3DUSAGE_WRITEONLYΪ"ֻд"  
	//	  DWORD FVF,                                  //�����ʽ  
	//	  D3DPOOL Pool,                               //���㻺����ڴ��  
	//	  IDirect3DVertexBuffer9** ppVertexBuffer,    //���㻺��ָ��  
	//	  HANDLE* pSharedHandle                       //������������Ϊ0  
	//);
 
	//������������
	device->CreateIndexBuffer(36 * sizeof(WORD), D3DUSAGE_WRITEONLY, D3DFMT_INDEX16/*������С*/, D3DPOOL_MANAGED, &IB, 0);
 
	//��䶥�㻺��
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
 
	//�����������
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
 
	//�����۲�����ϵ�任�����趨�任
	D3DXVECTOR3 position(0.0f, 0.0f, -5.0f);
	D3DXVECTOR3 target(0.0f, 0.0f, 0.0f);
	D3DXVECTOR3 up(0.0f, 1.0f, 0.0f);
	D3DXMATRIX v;
	D3DXMatrixLookAtLH(&v, &position, &target, &up);
	device->SetTransform(D3DTS_VIEW, &v);
 
	//����ͶӰ�任�����趨�任
	D3DXMATRIX projection;
	D3DXMatrixPerspectiveFovLH(&projection, D3DX_PI*0.5f, (float)width / (float)height, 1.0, 1000.0f);
	device->SetTransform(D3DTS_PROJECTION, &projection);
 
	//�趨����״̬Ϊ�߿�ģʽ
	device->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
 
	return true;
}
 
//cleanup
void cleanup()
{
	// �ͷŶ��㻺�����������
	d3d::Release<IDirect3DVertexBuffer9*>(VB);
	d3d::Release<IDirect3DIndexBuffer9*>(IB);
}
 
//display
bool display(float timeDelta)
{
	if (device == NULL)
		return false;
	
	//ƽ�ƾ���
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
 
	//��ת����
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
	//	  DWORD Count,                 //pRects�����о��ε���Ŀ
	//	  const D3DRECT *pRects,       //��Ҫִ�������������Ļ��������
	//	  DWORD Flags,                 //��Ҫ����ı��棬����D3DCLEAR_TARGET(��̨����), D3DCLEAR_ZBUFFER(Z��Ȼ���), D3DCLEAR_STENCIL(ģ��ƽ�滺��)
	//	  D3DCOLOR Color,              //ָ��������Ŀ��������Ϊ������ɫ
	//	  float Z,                     // �趨��Ȼ��棬[0,1]
	//	  DWORD Stencil                // ģ�建����Ҫ�趨��ֵ
	//);
 
	device->BeginScene();
	
	//����֮ǰ��׼������
	device->SetStreamSource(0, VB, 0, sizeof(vertex));      //ָ������������Դ
	device->SetFVF(vertex::FVF);                            //���ö����ʽ
	device->SetIndices(IB);                                 //������������(����ʱ��ֻ����ʹ��һ����������)
 
	device->DrawIndexedPrimitive(D3DPT_TRIANGLELIST, 0, 0, 8, 0, 12);   //����������
	//HRESULT DrawIndexedPrimitive(
	//	  D3DPRIMITIVETYPE Type,     //��Ҫ���Ƶ�ͼԪ����
	//	  INT BaseVertexIndex,       //��ʼ��������
	//	  UINT MinIndex,             //��С����(�������ʼ��������)
	//	  UINT NumVertices,          //ʹ�õĶ�������
	//	  UINT StartIndex,           //���������е���ʼ����
	//	  UINT PrimitiveCount        //��Ҫ���Ƶ�ͼԪ����
	//);
 
	device->EndScene();
 
	// �ύ��̨����(���潻��)
	device->Present(NULL, NULL, NULL, NULL);
 
	return true;
}
 
//���ڹ��̺���
LRESULT CALLBACK d3d::Wnd_Proc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam)
{
	switch (msg)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
 
	case WM_KEYDOWN:
		//����esc�˳�
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
