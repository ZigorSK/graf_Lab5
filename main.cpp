#include"Bmat.h"
#include"figure.h"
#include"funch.h"
#include<conio.h>



using namespace std;

int main()
{

	system("chcp 1251");
	char choice = '0';
	figure A;

	system("cls");
	do
	{


		Draw(A, 1);
		choice = _getch();
		system("cls");

		switch (choice)
		{
		case '6'://сдвиг вправо по х - 6
			A = move(A, 6);
			break;

		case '4'://Сдвиг влево по х - 4
			A = move(A, 4);
			break;

		case '2'://Сдвиг сдвиг вверх по у - 2
			A = move(A, 2);
			break;

		case '8'://Сдвиг вних по у - 8
			A = move(A, 8);
			break;

		case '7'://сдвиг от экрана по z - 7
			A = move(A, 7);
			break;

		case '9'://сдвиг к экрану по z - 9
			A = move(A, 9);
			break;

		case '1'://Уменьшить - 1
			A = Scale(A, 1);
			break;

		case '3'://увеличить -3
			A = Scale(A, 3);
			break;

			//
		case 'w'://Вращать вокруг х против часовой
			A = roat(A, 1, 0);
			break;
		case 's'://Вращать вокруг х по часовой
			A = roat(A, 1, 1);
			break;
		case 'a'://Вращать вокруг y по часовой
			A = roat(A, 2, 0);
			break;
		case 'd'://Вращать вокруг y против часовой
			A = roat(A, 2, 1);
			break;
		case 'q'://Вращать вокруг z против часовой
			A = roat(A, 3, 0);
			break;
		case 'e'://Вращать вокруг z по часовой
			A = roat(A, 3, 1);
			break;
		default: break;
		}

	} while (choice != '0');


	return 0;
}
