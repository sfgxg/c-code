//#include<stdio.h>
#include"game.h"

void game()
{
	//�׵���Ϣ�Ĵ洢
	//1.���úõ��׵���Ϣ
	char mine[ROWS][COLS] = {0};  //11 * 11
	//2.�Ų�õ��׵���Ϣ
	char show[ROWS][COLS] = { 0 };
	//��ʼ��
	Initboard(mine,ROWS,COLS,'0');
	Initboard(show, ROWS, COLS,'*');
	//��ӡ����
	Displayboard(show, ROW, COL);
	//������
	Setmine(mine,ROW,COL);
	//ɨ��
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
		menu(); //�˵�
		printf("��ѡ��");
		scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 0:
			printf("�˳���Ϸ��\n");
			break;
		default:
			printf("ѡ�����������ѡ��\n");
			break;
		}
		
	} while (input);
}
int main()
{
	text();
	return 0;
}