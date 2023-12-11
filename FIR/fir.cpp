#include <graphics.h>
#include<iostream>
using namespace std;
const int Num = 12;
int Size;//可以自由选择地图的size
char current = 'O';//O先手X后手
void mapsize()
{
	cout << "choose ur map size" << endl
		<< "1:small" << endl
		<< "2:medium" << endl
		<< "3:large" << endl;
	int k1;
	cin >> k1;
	switch (k1)
	{
	case 1:Size = 300;
		break;
	case 2:Size = 600;
		break;
	case 3:Size = 900;
		break;
	}
}
char a[Num+10][Num+10];


bool CheckWin(char c,int x,int y)//检测X或O是否获胜,共有2+2+4+4+4+4种情况
{
	if (a[y-2][x-2] == c && a[y-1][x-1] == c && a[y][x] == c && a[y+1][x+1] == c && a[y+2][x+2] == c) return true;
	if (a[y - 1][x +1] == c && a[y - 2][x +2] == c && a[y][x] == c && a[y + 1][x - 1] == c && a[y + 2][x - 2] == c) return true;


	if (a[y][x] == c && a[y - 1][x] == c && a[y - 2][x] == c && a[y +2][x] == c && a[y + 1][x] == c) return true;
	if (a[y][x] == c && a[y ][x-1] == c && a[y][x-2] == c && a[y ][x+1] == c && a[y ][x+2] == c) return true;


	if (a[y][x] == c && a[y-1][x] == c && a[y-2][x] == c && a[y-3][x] == c && a[y-4][x] == c) return true;
	if (a[y][x] == c && a[y + 1][x] == c && a[y + 2][x] == c && a[y + 3][x] == c && a[y + 4][x] == c) return true;
	if (a[y][x] == c && a[y][x-1] == c && a[y][x-2] == c && a[y][x-3] == c && a[y][x-4] == c) return true;
	if (a[y][x] == c && a[y][x + 1] == c && a[y][x + 2] == c && a[y][x + 3] == c && a[y][x + 4] == c) return true;

	if (a[y][x] == c && a[y - 1][x] == c && a[y - 2][x] == c && a[y - 3][x] == c && a[y +1][x] == c) return true;
	if (a[y][x] == c && a[y + 1][x] == c && a[y + 2][x] == c && a[y + 3][x] == c && a[y -1][x] == c) return true;
	if (a[y][x] == c && a[y][x - 1] == c && a[y][x - 2] == c && a[y][x - 3] == c && a[y][x +1] == c) return true;
	if (a[y][x] == c && a[y][x + 1] == c && a[y][x + 2] == c && a[y][x + 3] == c && a[y][x -1] == c) return true;

	if (a[y][x] == c && a[y - 1][x-1] == c && a[y - 2][x-2] == c && a[y - 3][x-3] == c && a[y - 4][x-4] == c) return true;
	if (a[y][x] == c && a[y + 1][x+1] == c && a[y + 2][x+2] == c && a[y + 3][x+3] == c && a[y + 4][x+4] == c) return true;
	if (a[y][x] == c && a[y+1][x - 1] == c && a[y+2][x - 2] == c && a[y+3][x - 3] == c && a[y+4][x - 4] == c) return true;
	if (a[y][x] == c && a[y-1][x + 1] == c && a[y-2][x + 2] == c && a[y-3][x + 3] == c && a[y-4][x + 4] == c) return true;

	if (a[y][x] == c && a[y - 1][x-1] == c && a[y - 2][x-2] == c && a[y - 3][x-3] == c && a[y + 1][x+1] == c) return true;
	if (a[y][x] == c && a[y + 1][x+1] == c && a[y + 2][x+2] == c && a[y + 3][x+3] == c && a[y - 1][x-1] == c) return true;
	if (a[y][x] == c && a[y+1][x - 1] == c && a[y-2][x - 2] == c && a[y+3][x - 3] == c && a[y-1][x + 1] == c) return true;
	if (a[y][x] == c && a[y-1][x + 1] == c && a[y-2][x + 2] == c && a[y-3][x + 3] == c && a[y+1][x - 1] == c) return true;


	return false;//以上条件都不满足 false

}
bool CheckDraw()//检测平局
{
	for (int i = 0; i <= Num-1; i++)
		for (int j = 0; j <= Num-1; j++)
			if (a[i][j] == '-') return false;
	return true;//如果棋盘填满了，返回true
}
void DrawBoard()//画棋盘
{
	/*line(0, 0, 0, Size);//画直线x1,y1,x2,y2
	line(Size / 3, 0, Size / 3, Size);
	line(Size * 2 / 3, 0, Size * 2 / 3, Size);
	line(Size, 0, Size, Size);
	line(0, 0, Size, 0);
	line(0, Size / 3, Size, Size / 3);
	line(0, Size * 2 / 3, Size, Size * 2 / 3);
	line(0, Size, Size, Size);*/
	for (int i = 0; i <= Num; i++)
	{
		line(0, Size * i / Num, Size, Size * i / Num);
		line(Size * i / Num, 0, Size * i / Num, Size);
	}
}
void DrawPiece()//画棋子
{
	for (int i = 0; i <= Num-1; i++)
		for (int j = 0; j <= Num-1; j++)
		{
			int x2 = j * Size / Num + Size / (Num*2);//当前棋盘格子中心的坐标
			int y2 = i * Size / Num + Size / (Num*2);
			if (a[i][j] == 'O')
			{
				circle(x2, y2, Size / (2*Num));//画O
			}
			else if (a[i][j] == 'X')
			{
				line(x2 - Size / (Num*2), y2 - Size / (Num * 2), x2 + Size / (Num * 2), y2 + Size / (Num * 2));//画X
				line(x2 + Size / (Num * 2), y2 - Size / (Num * 2), x2 - Size / (Num * 2), y2 + Size / (Num * 2));

			}
		}
}
void DrawTipText()
{
	static TCHAR str[64];//TCHAR是API自带的数据类型
	_stprintf_s(str, _T("当前棋子类型： % c"), current);//一种特殊的printf
	settextcolor(RGB(225, 175, 45));//RGB颜色格式
	outtextxy(0, 0, str);//在特定坐标输出文本框
}

int main()
{
	mapsize();
	initgraph(Size, Size);
	for (int i = 0; i <= Num-1; i++)
	for (int j = 0; j <= Num-1; j++)
	{
		a[i][j] = '-';
	}
	bool End = false;
	ExMessage msg;

	BeginBatchDraw();//渲染缓冲区三连

	while (!End)//没有结束信号就继续循环
	{
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)//记录鼠标左键按下
			{
				int x = msg.x;
				int y = msg.y;
				int x1 = x / (Size / Num);//除法向下取整，棋盘三等分
				int y1 = y / (Size / Num);
				if (a[y1][x1] == '-')//注意是a（y，x），很容易搞错！！！
				{
					a[y1][x1] = current;//鼠标下子，先O后X
					if (current == 'O') current = 'X';
					else if (current == 'X') current = 'O';
				}

				if (CheckWin('X', x1, y1))
				{
					End = true;
					//cout << "X玩家获胜" << endl;//弹出玩家获胜信息
					MessageBox(GetHWnd(), _T("X玩家获胜"), _T("游戏结束"), MB_OK);
				}//我们也可以使用easyx带的Messagebox函数，弹出对话框
				if (CheckWin('O', x1, y1))
				{
					End = true;
					//cout << "O玩家获胜" << endl;
					MessageBox(GetHWnd(), _T("O玩家获胜"), _T("游戏结束"), MB_OK);

				}
				if (CheckDraw())
				{
					End = true;
					//cout << "平局" << endl;
					MessageBox(GetHWnd(), _T("平局"), _T("游戏结束"), MB_OK);

				}

			}
		}
		cleardevice();
		DrawBoard();
		DrawPiece();
		DrawTipText();
		FlushBatchDraw();

		DWORD end_time = GetTickCount();
		DWORD time = end_time-start_time;
		if (time<=1000/60)
		{
			Sleep(1000 / 60 - time);
		}

	}

	EndBatchDraw();
	return 0;
}