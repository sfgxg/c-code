
#include"game.h"


void Initboard(char board[ROWS][COLS], int rows, int cols,char set)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			board[i][j] = set;
		}
	}
}
void Displayboard(char board[ROWS][COLS], int row, int col)
{

	int i = 0;
	int j = 0;
	//打印列号
	for (i = 0; i <= col; i++)
	{
		printf("%d ", i);
	}
	printf("\n");
	for (i = 1; i <=row; i++)
	{
		//打印行号
		printf("%d ", i);
		for (j = 1; j <= col; j++)
		{
			printf("%c ", board[i][j]);
		}
		printf("\n");
	}
}
void  Setmine(char board[ROWS][COLS], int row, int col)
{

	int count = Easy_count;
	while (count)
	{
		int x = rand()%row+1;//1-9
		int y = rand()%col+1;//1-9
		if (board[x][y] == '0')
		{
			board[x][y]='1';
			count--;
		}
		
	}
}
//'0'-'0'=0
int get_mine_count(char mine[ROWS][COLS], int x, int y)
{
	   return  mine[x - 1][y] +
		mine[x - 1][y - 1] +
		mine[x][y - 1] +
		mine[x + 1][y - 1] +
		mine[x + 1][y] +
		mine[x + 1][y + 1] +
		mine[x][y + 1] +
		mine[x - 1][y + 1]-8*'0';




}
void  Findmine(char mine[ROWS][COLS], char show[ROWS][COLS], int row, int col)
{
	
	int x = 0;
	int y = 0;
	int win = 0;
	while (win<row*col- Easy_count)
	{
		printf("请输入坐标：");
		scanf_s("%d%d", &x, &y);
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			//坐标合法
			//1.是雷
			if (mine[x][y] == '1')
			{
				printf("很遗憾，你被炸死了！\n");
				Displayboard(mine, row, col);
				break;
			}
			//2.不是雷
			else
			{
				//计算x,y坐标周围雷的个数
				int count =get_mine_count(mine,x,y);
				show[x][y]=count + '0';
				Displayboard(show, row, col);
				win++;

			}

		}
		else
		{
			printf("坐标非法,请重新输入！\n");

		}

	}
	if (win == row * col - Easy_count)
	{
		printf("恭喜你排雷成功\n");
		Displayboard(mine,row,col);
	}
}
