#include <graphics.h>
#include<iostream>
using namespace std;
const int Num = 12;
int Size;//��������ѡ���ͼ��size
char current = 'O';//O����X����
int x1 = 0, y1 = 0;
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
	case 3:Size = 700;
		break;
	}
}
char a[Num][Num];


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
	for (int i = 0; i <= Num; i++)
		for (int j = 0; j <= Num; j++)
			if (a[i][j] == '-') return false;
	if (CheckWin(current) == false) return true;
}
void DrawBoard()//������
{
	line(0, 0, 0, Size);//��ֱ��x1,y1,x2,y2
	line(Size / 3, 0, Size / 3, Size);
	line(Size * 2 / 3, 0, Size * 2 / 3, Size);
	line(Size, 0, Size, Size);
	line(0, 0, Size, 0);
	line(0, Size / 3, Size, Size / 3);
	line(0, Size * 2 / 3, Size, Size * 2 / 3);
	line(0, Size, Size, Size);
}
void DrawPiece()//������
{
	for (int i = 0; i <= 2; i++)
		for (int j = 0; j <= 2; j++)
		{
			int x2 = j * Size / 3 + Size / 6;//��ǰ���̸������ĵ�����
			int y2 = i * Size / 3 + Size / 6;
			if (a[i][j] == 'O')
			{
				circle(x2, y2, Size / 6);//��O
			}
			else if (a[i][j] == 'X')
			{
				line(x2 - Size / 6, y2 - Size / 6, x2 + Size / 6, y2 + Size / 6);//��X
				line(x2 + Size / 6, y2 - Size / 6, x2 - Size / 6, y2 + Size / 6);

			}
		}
}

int main()
{
	mapsize();
	initgraph(Size, Size);
	for (int i = 1; i <= Num; i++)
	for (int j = 1; j <= Num; j++)
	{
		a[i][j] = '-';
	}
	bool End = false;
	ExMessage msg;

	BeginBatchDraw();//��Ⱦ����������

	while (!End)//û�н����źžͼ���ѭ��
	{

		while (peekmessage(&msg))
		{
			if (msg.message == WM_LBUTTONDOWN)//��¼����������
			{
				int x = msg.x;
				int y = msg.y;
				x1 = x / (Size / 3);//��������ȡ�����������ȷ�
				y1 = y / (Size / 3);
				if (a[y1][x1] == '-')//ע����a��y��x���������׸������
				{
					a[y1][x1] = current;//������ӣ���O��X
					if (current == 'O') current = 'X';
					else if (current == 'X') current = 'O';
				}
			}
		}

		if (CheckWin('X',x1,y1))
		{
			End = true;
			//cout << "X��һ�ʤ" << endl;//������һ�ʤ��Ϣ
			MessageBox(GetHWnd(), _T("X��һ�ʤ"), _T("��Ϸ����"), MB_OK);
		}//����Ҳ����ʹ��easyx����Messagebox�����������Ի���
		if (CheckWin('O',x1,y1))
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
		cleardevice();
		DrawBoard();
		DrawPiece();
		FlushBatchDraw();
	}

	EndBatchDraw();
	return 0;
}