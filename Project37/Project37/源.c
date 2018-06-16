#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<conio.h>

#ifndef _List_H

struct Node;
typedef struct Node *PtrToNode;
typedef PtrToNode List;
typedef PtrToNode Position;

void PrintList(List L, int numebr);//��ӡ����
void RandomMove(List L, int number);//����ƶ�
void MoveBack(List L, int number);//��0�ƶ������½�
void StartGame(List L, int number);//��Ϸ��ʼ����������;����С�� 

int RightMove(List L, int number);//�����ƶ� 
int LeftMove(List L, int number);//�����ƶ�
int UpMove(List L, int number);//�����ƶ� 
int DownMove(List L, int number);//�����ƶ�

List CreatList();//������ͷ 
List CreatArray(int number);//��������

Position FindZero(List L);//Ѱ��0��λ�� 
Position FindPosite(List L, int number);//Ѱ��ĳ��λ�� 


#endif   /* _List_H */

struct Node
{
	int Element;
	Position Right;
	Position Left;
	int posite;
};

//��������ͷ������ 
List  CreatList()
{
	PtrToNode F_List;
	F_List = /*(Node*)*/malloc(sizeof(struct Node));

	if (F_List == NULL)
	{
		printf("\nOut of place!!");
		Sleep(1000);
		exit(0);
	}
	else
	{
		F_List->Element = 1;
		F_List->Left = NULL;
		F_List->Right = NULL;
		F_List->posite = 1;
		return F_List;
	}
}

//��������
List  CreatArray(int number)
{
	int Tnumber = number * number;
	PtrToNode Tmp;
	List L = CreatList(), Header;

	Header = L;

	//������0�Ĳ��� 
	while (Tnumber - 2)
	{
		Tmp = /*(Node*)*/malloc(sizeof(struct Node));

		if (Tmp == NULL)
		{
			printf("\nOut of place!!");
			Sleep(1000);
			exit(0);
		}

		else
		{
			Tmp->Element = (number * number - Tnumber + 2);
			Tmp->posite = Tmp->Element;
			Tmp->Right = NULL;
			L->Right = Tmp;
			Tmp->Left = L;
			L = Tmp;
		}
		Tnumber--;
	}

	//����0�Ĳ���
	Tmp = /*(Node*)*/malloc(sizeof(struct Node));

	if (Tmp == NULL)
	{
		printf("\nOut of place!!");
		Sleep(1000);
		exit(0);
	}

	Tmp->Element = 0;
	Tmp->posite = number * number;
	Tmp->Right = NULL;
	L->Right = Tmp;
	Tmp->Left = L;

	//���ر�ͷ 
	return Header;
}

//��ӡ����
void  PrintList(List L, int number)
{
	int TmpNumber = number;
	Position Posite;
	Posite = L;

	if (L->Right == NULL)
	{
		printf("\nList is Empty!!");
		Sleep(1000);
		exit(0);
	}

	while (Posite != NULL)
	{
		if (TmpNumber == 0)
		{
			printf("\n\n\n");
			TmpNumber = number;
		}

		printf("%4d     ", Posite->Element);
		Posite = Posite->Right;
		TmpNumber--;
	}
	printf("\n    ��Ϸע�����\n1���ڽ�����Ϸ֮ǰ�����Ȱ���д������Capslk\n2������Ϸ���������У���Ч�Ĳ�����Ϊ'W''A''S''D'�����ֱ��ʾ�����·����ҷ����Ϸ��������ֽ������ƣ����ƣ����ƣ����Ʋ���\n3�������ִ����ң����ϵ��·ֱ�Ϊ1��15��0ʱ����Ϸ�ɹ�\n4������'Q'���˳�\n");
}

//Ѱ��0��λ�ã�����λ��. 
Position  FindZero(List L)
{
	Position Tmp, Posite;
	Tmp = L;
	Posite = L;

	while (Tmp != NULL)
	{
		if (Tmp->Element == 0)
		{
			return Tmp;
			break;
		}
		else
		{
			Posite = Tmp->Right;
			Tmp = Posite;
		}
	}
}

//Ѱ�Ҹ�����λ�ã�����λ��. 
Position FindPosite(List L, int number)
{
	Position Tmp, Posite;
	Tmp = L;
	Posite = L;

	while (Tmp != NULL)
	{
		if (Tmp->posite == number)
		{
			return Tmp;
			break;
		}
		else
		{
			Posite = Tmp->Right;
			Tmp = Posite;
		}
	}
}

//0�����ƶ�(������������)
int  LeftMove(List L, int number)
{
	Position P;
	int MID, have = 0;
	P = FindZero(L);

	if (P->posite % number != 0 && P->Right != NULL)
	{
		MID = P->Element;
		P->Element = P->Right->Element;
		P->Right->Element = MID;
		have = 1;
	}

	return have;
}

//0�����ƶ�(������������)
int  RightMove(List L, int number)
{
	Position P;
	int MID, have = 0;
	P = FindZero(L);

	if (P->posite % number != 1 && P->Left != NULL)
	{
		MID = P->Element;
		P->Element = P->Left->Element;
		P->Left->Element = MID;
		have = 1;
	}

	return have;
}

//0�����ƶ�(������������)
int  UpMove(List L, int number)
{
	Position P1, P2;
	int MID, have = 0;
	P1 = FindZero(L);

	if (P1->posite <= number * (number - 1))
	{
		P2 = FindPosite(L, (P1->posite + number));
		MID = P1->Element;
		P1->Element = P2->Element;
		P2->Element = MID;
		have = 1;
	}

	return have;
}

//0�����ƶ�(������������)
int  DownMove(List L, int number)
{
	Position P1, P2;
	int MID, have = 0;
	P1 = FindZero(L);

	if (P1->posite >= number + 1)
	{
		P2 = FindPosite(L, (P1->posite - number));
		MID = P1->Element;
		P1->Element = P2->Element;
		P2->Element = MID;
		have = 1;
	}

	return have;
}

//��0�ƶ������½�
void  MoveBack(List L, int number)
{
	int have = 0;
	Position Posite;
	Posite = FindZero(L);

	if (Posite->posite == number * number)
		have = 1;

	else(!have);
	{
		while (Posite->posite % number != 0)
		{
			LeftMove(L, number);
			Posite = Posite->Right;
		}
		while (Posite->posite != number * number)
		{
			UpMove(L, number);
			Posite = FindPosite(L, Posite->posite + number);
		}
	}
}

//����ƶ� 
void  RandomMove(List L, int number, int Line)
{
	srand((int)time(NULL));
	int point = 1, RDnumber;

	for (; point <= number; )
	{
		RDnumber = rand() % 4;
		switch (RDnumber)
		{
		case 0:
			point += UpMove(L, Line);
			break;
		case 1:
			point += DownMove(L, Line);
			break;
		case 2:
			point += LeftMove(L, Line);
			break;
		case 3:
			point += RightMove(L, Line);
			break;
		}
	}

}


//��Ϸ��ʼ
void  StartGame(List L, int number)
{
	char PutIn = 'W';
	int win = 0;
	List Game, Tmp;
	Game = CreatArray(number);
	RandomMove(Game, number * number * number * 3, number);
	MoveBack(Game, number);
	PrintList(Game, number);
	Tmp = Game;
	//��ʼ������


	while (!win)
	{
		win = 1;

		if (_kbhit())
		{
			PutIn = _getch();
		}

		switch (PutIn)
		{
		case 'W':
			UpMove(Game, number);
			system("cls");
			PrintList(Game, number);
			break;
		case 'S':
			DownMove(Game, number);
			system("cls");
			PrintList(Game, number);
			break;
		case 'A':
			LeftMove(Game, number);
			system("cls");
			PrintList(Game, number);
			break;
		case 'D':
			RightMove(Game, number);
			system("cls");
			PrintList(Game, number);
			break;
		case'Q':
			exit(0);
		}

		PutIn = '\0';

		while (Tmp->Right != NULL)
		{
			if (Tmp->Element != Tmp->posite)
				win = 0;

			Tmp = Tmp->Right;
		}

		Tmp = Game;

	}

	printf("\nYou win this game!");

}

void main()
{
	int k;
	double duration;
	clock_t start, finish;
	List list, position;
	printf("������3��10֮���һ�����֣������ִ����ݵ���������\n���ĸ����㣬����㲻�����Ļ������ܵ��ͷ�Ŷ����\n");
	scanf_s("%d", &k);
	int point = 0;
	while (k < 3 || k>10)
	{
		if (point < 3)
			printf("Are you OK?");
		else
		{
			printf("\nListen to me buddy!!!");
			Sleep(1000);
			exit(0);
		}
		point++;
		scanf_s("%d", &k);
	}

	list = CreatArray(k);
	//PrintList( list , 4 ) ;
	start = clock();
	StartGame(list, k);
	finish = clock();
	duration = (double)(finish - start) / CLOCKS_PER_SEC;
	printf("\n����ʱ�� %f seconds\n", duration);
	printf("\n\n\n");


	//PrintList(list, 4);
	system("pause");
	return 0;
}