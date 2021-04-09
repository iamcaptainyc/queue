    #include<stdio.h>
    #include<graphics.h>
    #define INTERVAL 50  //前面的间隔
    #define CHESS_GRID_SIZE 70  //格子宽度
    #define ROW  10
    #define COL  9
    enum PIECES//枚举棋子
    {
    	車,馬,象,士,将,砲,卒,
    	俥,马,相,仕,帥,炮,兵,
    	SPACE,BEGIN,END
    };
    //红黑方棋子、
    int redChess[] = { 車, 馬, 象, 士, 将, 砲, 卒};
    int blackChess[] = { 俥, 马, 相, 仕, 帥, 炮, 兵 };
    const char*chessName[] = { "車", "馬", "象", "士", "将", "砲", "卒", "俥", "马", "相", "仕", "帥", "炮", "兵" };
    struct Chess//棋子属性
    {
    	int x;
    	int y;
    	int id;//哪个棋子
    	int type;//是哪一方的棋子 红，黑？
    	bool river;//判断小兵是否过了河
    };
    struct Chess  map[ROW][COL];//结构体数组，用来保存每一个点的信息
    POINT begin = { -1, -1 }, end = { -1, -1 };//保存前后两次点击的数组下标
    int state = BEGIN;
    //初始化游戏数据
    void GameInit()
    {
    	for (int i = 0; i < ROW; i++)
    	{
    		for (int k = 0; k < COL; k++)
    		{
    			int chessname = SPACE;
    			int mcolor = BLACK;
    			//黑棋
    			if (i <= 4)
    			{
    				mcolor = BLACK;
    				//初始化第一行的棋子，
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
    				//设置炮
    				if (i == 2 && (k == 1 || k == 7))
    				{
    					chessname = blackChess[砲];
    				}
    				//设置小兵
    				if (i == 3 && k % 2 == 0)
    				{
    					chessname = blackChess[卒];
    				}
     
    			}
    			//紅棋
    			else 
    			{
    				mcolor = RED;
    				//初始化第一行的棋子，
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
    				//设置炮
    				if (i == 7 && (k == 1 || k == 7))
    				{
    					chessname = redChess[炮];
    				}
    				//设置小兵
    				if (i == 6 && k % 2 == 0)
    				{
    					chessname = redChess[兵];
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
    //游戏的绘制函数
    void GameDraw()
    {
    	//设置背景颜色 red black 
    	setbkcolor(RGB(252, 215, 162));
    	cleardevice();
     
    	//绘制棋盘
    	setlinecolor(BLACK);
    	setlinestyle(PS_SOLID, 2);
    	for (int i = 0; i < 10; i++)
    	{
    		//画横线
    		line(INTERVAL, i*CHESS_GRID_SIZE + INTERVAL, 8 * CHESS_GRID_SIZE + INTERVAL, i*CHESS_GRID_SIZE + INTERVAL);
    		//画竖线
    		if (i < 9)
    		{
    			line(i*CHESS_GRID_SIZE + INTERVAL, INTERVAL, i*CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL);
    		}
    	}
    	rectangle(INTERVAL - 5, INTERVAL - 5, 8 * CHESS_GRID_SIZE + INTERVAL+5, 5+9 * CHESS_GRID_SIZE + INTERVAL);
    	//楚河汉界显示
    	setfillcolor(RGB(252, 215, 162));
    	fillrectangle(INTERVAL, 4 * CHESS_GRID_SIZE + INTERVAL, 8 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL);
    	//显示文字
    	char river[20] = "楚河        汉界";
    	settextstyle(50, 0, "楷体");
    	settextcolor(BLACK);
    	setbkmode(TRANSPARENT);
    	outtextxy(INTERVAL+100, 4 * CHESS_GRID_SIZE + INTERVAL+10, river);
    	//画九宫格
    		//画上面
    	line(3 * CHESS_GRID_SIZE + INTERVAL, INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL);
    	line(3 * CHESS_GRID_SIZE + INTERVAL, 2 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, INTERVAL);
    	   //画下面
    	line(3 * CHESS_GRID_SIZE + INTERVAL, 7 * CHESS_GRID_SIZE + INTERVAL, 5 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE + INTERVAL);
    	line(3 * CHESS_GRID_SIZE + INTERVAL, 9 * CHESS_GRID_SIZE+INTERVAL,5*CHESS_GRID_SIZE+INTERVAL,7*CHESS_GRID_SIZE+INTERVAL);
    	//画棋子
    	settextstyle(30, 0, "楷体");
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
    			//获取鼠标点击的数组的下标
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
    	//创建一个图形窗口
    	initgraph(800,800,SHOWCONSOLE);
    	GameInit();
    	printf("欢迎来到顽石老师课堂，中国象棋");
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
