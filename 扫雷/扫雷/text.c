//#include<stdio.h>
#include"game.h"

void game()
{
	//雷的信息的存储
	//1.布置好的雷的信息
	char mine[ROWS][COLS] = {0};  //11 * 11
	//2.排查好的雷的信息
	char show[ROWS][COLS] = { 0 };
	//初始化
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show, ROWS, COLS,'*');
	//打印棋盘
	Displayboard(show, ROW, COL);
	//布置雷
	Setmine(mine,ROW,COL);
	//扫雷
	Displayboard(mine, ROW, COL);
	Findmine(mine,show ,ROW,COL);


}


void menu()
{
	printf("***********************\n");
	printf("***1.play   0.exit ****\n");
	printf("***********************\n");
}
void text()
{
	int input = 0;
	srand((unsigned int)time(NULL));
	do
	{
		menu(); //菜单
		printf("请选择：");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("退出游戏！\n");
			break;
		default:
			printf("选择错误，请重新选择！\n");
			break;
		}
		
	} while (input);
}
int main()
{
	text();
	return 0;
}