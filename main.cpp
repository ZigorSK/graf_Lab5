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
		case '6'://����� ������ �� � - 6
			A = move(A, 6);
			break;

		case '4'://����� ����� �� � - 4
			A = move(A, 4);
			break;

		case '2'://����� ����� ����� �� � - 2
			A = move(A, 2);
			break;

		case '8'://����� ���� �� � - 8
			A = move(A, 8);
			break;

		case '7'://����� �� ������ �� z - 7
			A = move(A, 7);
			break;

		case '9'://����� � ������ �� z - 9
			A = move(A, 9);
			break;

		case '1'://��������� - 1
			A = Scale(A, 1);
			break;

		case '3'://��������� -3
			A = Scale(A, 3);
			break;

			//
		case 'w'://������� ������ � ������ �������
			A = roat(A, 1, 0);
			break;
		case 's'://������� ������ � �� �������
			A = roat(A, 1, 1);
			break;
		case 'a'://������� ������ y �� �������
			A = roat(A, 2, 0);
			break;
		case 'd'://������� ������ y ������ �������
			A = roat(A, 2, 1);
			break;
		case 'q'://������� ������ z ������ �������
			A = roat(A, 3, 0);
			break;
		case 'e'://������� ������ z �� �������
			A = roat(A, 3, 1);
			break;
		default: break;
		}

	} while (choice != '0');


	return 0;
}
