#include <graphics.h>
#include<iostream>
using namespace std;
const int Num = 12;
int Size;//��������ѡ���ͼ��size
char current = 'O';//O����X����
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


bool CheckWin(char c,int x,int y)//���X��O�Ƿ��ʤ,����2+2+4+4+4+4�����
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


	return false;//���������������� false

}
bool CheckDraw()//���ƽ��
{
	for (int i = 0; i <= Num-1; i++)
		for (int j = 0; j <= Num-1; j++)
			if (a[i][j] == '-') return false;
	return true;//������������ˣ�����true
}
void DrawBoard()//������
{
	/*line(0, 0, 0, Size);//��ֱ��x1,y1,x2,y2
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
void DrawPiece()//������
{
	for (int i = 0; i <= Num-1; i++)
		for (int j = 0; j <= Num-1; j++)
		{
			int x2 = j * Size / Num + Size / (Num*2);//��ǰ���̸������ĵ�����
			int y2 = i * Size / Num + Size / (Num*2);
			if (a[i][j] == 'O')
			{
				circle(x2, y2, Size / (2*Num));//��O
			}
			else if (a[i][j] == 'X')
			{
				line(x2 - Size / (Num*2), y2 - Size / (Num * 2), x2 + Size / (Num * 2), y2 + Size / (Num * 2));//��X
				line(x2 + Size / (Num * 2), y2 - Size / (Num * 2), x2 - Size / (Num * 2), y2 + Size / (Num * 2));

			}
		}
}
void DrawTipText()
{
	static TCHAR str[64];//TCHAR��API�Դ�����������
	_stprintf_s(str, _T("��ǰ�������ͣ� % c"), current);//һ�������printf
	settextcolor(RGB(225, 175, 45));//RGB��ɫ��ʽ
	outtextxy(0, 0, str);//���ض���������ı���
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

	BeginBatchDraw();//��Ⱦ����������

	while (!End)//û�н����źžͼ���ѭ��
	{
		DWORD start_time = GetTickCount();

		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)//��¼����������
			{
				int x = msg.x;
				int y = msg.y;
				int x1 = x / (Size / Num);//��������ȡ�����������ȷ�
				int y1 = y / (Size / Num);
				if (a[y1][x1] == '-')//ע����a��y��x���������׸������
				{
					a[y1][x1] = current;//������ӣ���O��X
					if (current == 'O') current = 'X';
					else if (current == 'X') current = 'O';
				}

				if (CheckWin('X', x1, y1))
				{
					End = true;
					//cout << "X��һ�ʤ" << endl;//������һ�ʤ��Ϣ
					MessageBox(GetHWnd(), _T("X��һ�ʤ"), _T("��Ϸ����"), MB_OK);
				}//����Ҳ����ʹ��easyx����Messagebox�����������Ի���
				if (CheckWin('O', x1, y1))
				{
					End = true;
					//cout << "O��һ�ʤ" << endl;
					MessageBox(GetHWnd(), _T("O��һ�ʤ"), _T("��Ϸ����"), MB_OK);

				}
				if (CheckDraw())
				{
					End = true;
					//cout << "ƽ��" << endl;
					MessageBox(GetHWnd(), _T("ƽ��"), _T("��Ϸ����"), MB_OK);

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