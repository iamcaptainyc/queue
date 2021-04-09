    #include<stdio.h>
    #include<graphics.h>
    #define INTERVAL 50  //ǰ��ļ��
    #define CHESS_GRID_SIZE 70  //���ӿ��
    #define ROW  10
    #define COL  9
    enum PIECES//ö������
    {
    	܇,�R,��,ʿ,��,�h,��,
    	�e,��,��,��,��,��,��,
    	SPACE,BEGIN,END
    };
    //��ڷ����ӡ�
    int redChess[] = { ܇, �R, ��, ʿ, ��, �h, ��};
    int blackChess[] = { �e, ��, ��, ��, ��, ��, �� };
    const char*chessName[] = { "܇", "�R", "��", "ʿ", "��", "�h", "��", "�e", "��", "��", "��", "��", "��", "��" };
    struct Chess//��������
    {
    	int x;
    	int y;
    	int id;//�ĸ�����
    	int type;//����һ�������� �죬�ڣ�
    	bool river;//�ж�С���Ƿ���˺�
    };
    struct Chess  map[ROW][COL];//�ṹ�����飬��������ÿһ�������Ϣ
    POINT begin = { -1, -1 }, end = { -1, -1 };//����ǰ�����ε���������±�
    int state = BEGIN;
    //��ʼ����Ϸ����
    void GameInit()
    {
    	for (int i = 0; i < ROW; i++)
    	{
    		for (int k = 0; k < COL; k++)
    		{
    			int chessname = SPACE;
    			int mcolor = BLACK;
    			//����
    			if (i <= 4)
    			{
    				mcolor = BLACK;
    				//��ʼ����һ�е����ӣ�
    				if (i == 0)
    				{
    					if (k <= 4)
    					{
    						chessname = blackChess[k];
    					}
    					else
    					{
    						chessname = blackChess[8-k];
    					}
    				}
    				//������
    				if (i == 2 && (k == 1 || k == 7))
    				{
    					chessname = blackChess[�h];
    				}
    				//����С��
    				if (i == 3 && k % 2 == 0)
    				{
    					chessname = blackChess[��];
    				}
     
    			}
    			//�t��
    			else 
    			{
    				mcolor = RED;
    				//��ʼ����һ�е����ӣ�
    				if (i == 9)
    				{
    					if (k <= 4)
    					{
    						chessname = redChess[k];
    					}
    					else
    					{
    						chessname = redChess[8 - k];
    					}
    				}
    				//������
    				if (i == 7 && (k == 1 || k == 7))
    				{
    					chessname = redChess[��];
    				}
    				//����С��
    				if (i == 6 && k % 2 == 0)
    				{
    					chessname = redChess[��];
    				}
    			}
    			map[i][k].id = chessname;
    			map[i][k].river = false;
    			map[i][k].type = mcolor;
    			map[i][k].x = k*CHESS_GRID_SIZE + INTERVAL;
    			map[i][k].y = i*CHESS_GRID_SIZE + INTERVAL;
    		}
    	}
    }
    //��Ϸ�Ļ��ƺ���
    void GameDraw()
    {
    	//���ñ�����ɫ red black 
    	setbkcolor(RGB(252, 215, 162));
    	cleardevice();
     
    	//��������
    	setlinecolor(BLACK);
    	setlinestyle(PS_SOLID, 2);
    	for (int i = 0; i < 10; i++)
    	{
    		//������
    		line(INTERVAL, i*CHESS_GRID_SIZE + INTERVAL, 8 * CHESS_GRID_SIZE + INTERVAL, i*CHESS_GRID_SIZE + INTERVAL);
    		//������
    		if (i < 9)
    		{
    			line(i*CHESS_GRID_SIZE + INTERVAL, INTERVAL, i*CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL);
    		}
    	}
    	rectangle(INTERVAL - 5, INTERVAL - 5, 8 * CHESS_GRID_SIZE + INTERVAL+5, 5+9 * CHESS_GRID_SIZE + INTERVAL);
    	//���Ӻ�����ʾ
    	setfillcolor(RGB(252, 215, 162));
    	fillrectangle(INTERVAL, 4 * CHESS_GRID_SIZE + INTERVAL, 8 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL);
    	//��ʾ����
    	char river[20] = "����        ����";
    	settextstyle(50, 0, "����");
    	settextcolor(BLACK);
    	setbkmode(TRANSPARENT);
    	outtextxy(INTERVAL+100, 4 * CHESS_GRID_SIZE + INTERVAL+10, river);
    	//���Ź���
    		//������
    	line(3 * CHESS_GRID_SIZE + INTERVAL, INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL);
    	line(3 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, INTERVAL);
    	   //������
    	line(3 * CHESS_GRID_SIZE + INTERVAL, 7 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL);
    	line(3 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE+INTERVAL,5*CHESS_GRID_SIZE+INTERVAL,7*CHESS_GRID_SIZE+INTERVAL);
    	//������
    	settextstyle(30, 0, "����");
    	for (int i = 0; i < ROW; i++)
    	{
    		for (int k = 0; k < COL; k++)
    		{
    			if (map[i][k].id != SPACE)
    			{
    				setlinecolor(map[i][k].type);
    				fillcircle(map[i][k].x, map[i][k].y, 30);
    				fillcircle(map[i][k].x, map[i][k].y, 25);
    				settextcolor(map[i][k].type);
    				outtextxy(map[i][k].x-10, map[i][k].y-10, chessName[map[i][k].id]);
    			}
    			
    		}
    	}
    }
    void MouseControl()
    {
    	if (MouseHit())
    	{
    		MOUSEMSG msg = GetMouseMsg();
    		if (msg.uMsg == WM_LBUTTONDOWN)
    		{
    			//��ȡ�������������±�
    			int row = (msg.y-INTERVAL)/CHESS_GRID_SIZE;
    			int col = (msg.x-INTERVAL)/CHESS_GRID_SIZE;
    			if (state == BEGIN)
    			{
    				state = END;
    				begin.x = row;
    				begin.y = col;
    			}
    			else if (state == END)
    			{
    				state = BEGIN;
    				begin.x = row;
    				begin.y = col;
    			}
    			printf("%d,%d  %d\n", row, col, state);
    		}
    	}
    }
    void chessMove()
    {
    	if (begin.x != -1 && end.x != -1 && !(begin.x == end.x &&begin.y == end.y))
    	{
    		map[end.x][end.y].id = map[begin.x][begin.y].id;
    		map[end.x][end.y].type = map[begin.x][begin.y].type;
    		map[end.x][end.y].river = map[begin.x][begin.y].river;
    		map[begin.x][begin.y].id = SPACE;
    	}
     
    }
    int main555()
    {	
    	//����һ��ͼ�δ���
    	initgraph(800,800,SHOWCONSOLE);
    	GameInit();
    	printf("��ӭ������ʯ��ʦ���ã��й�����");
    	BeginBatchDraw();
    	while (1)
    	{
    		GameDraw();
    		FlushBatchDraw();
    		MouseControl();
    		chessMove();
    	}
    	return 0;
    }
