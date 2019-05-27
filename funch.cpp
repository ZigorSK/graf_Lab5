#include "funch.h"

const int delta_o = 20;
const double SCALE = 1.05;
const double scale = 0.95;
const double fi = 0.1;

void DrowLine(double ax, double ay, double bx, double by,  double cx, double cy, double ex, double ey, int flag, int flag2)
{
	int R1, R2, R3;


	if (flag2 == 1)
	{
		R1 = 0;
		R2 = 255;
		R3 = 255;
	}
	if (flag2 == 2)
	{
		R1 = 0;
		R2 = 0;
		R3 = 255;
	}
	if (flag2 == 3)
	{
		R1 = 0;
		R2 = 255;
		R3 = 0;
	}
	if (flag2 == 4)
	{
		R1 = 255;
		R2 = 255;
		R3 = 0;
	}
	if (flag2 == 5)
	{
		R1 = 230;
		R2 = 230;
		R3 = 250;
	}
	if (flag2 == 6)
	{
		R1 = 220;
		R2 = 20;
		R3 = 60;
	}



	int A[5][3] = { {round(ax),round(ay),1} ,{round(bx),round(by),1} ,{round(cx),round(cy),1} ,{round(ex),round(ey),1}, {round(ax),round(ay),1} };
	int array_x[4000], array_y[4000], *arr_x = array_x, *arr_y = array_y, count = 0, flag_repeat;


		HWND sHwnd = GetForegroundWindow();
		HDC hdc = GetDC(sHwnd);

		for (int i = 0; i < 4; i++)
		{

			int B[2][3] = { {round(A[i][0]),round(A[i][1]),A[i][2]} ,{round(A[i + 1][0]),round(A[i + 1][1]),A[i + 1][2]} };

			int dx = abs(B[0][0] - B[1][0]);
			int dy = abs(B[0][1] - B[1][1]);
			int sx = B[0][0] < B[1][0] ? 1 : -1;
			int sy = B[0][1] < B[1][1] ? 1 : -1;
			int err = (dx > dy ? dx : -dy) / 2;
			int e2 = err;

			while (1)
			{
				if (flag)
				{
					SetPixel(hdc, B[0][0], B[0][1], RGB(R1, R2, R3));
				}
				else
				{
					SetPixel(hdc, B[0][0], B[0][1], RGB(0,0,0));
				}
				
				//Заполняем массив граничных точек фигуры
				if (count < 4000)// Если в массиве есть место
				{
					flag_repeat = B[0][1];
					if (flag_repeat != *(arr_y + count - 1))
					{
						*(arr_x + count) = B[0][0];//Запоминаем x
						*(arr_y + count) = B[0][1];//ЗАпоминаем y

						count++;
					}

				}
				else// Если Массив переполнен
				{
					flag_repeat = B[0][1];
					if (flag_repeat != *(arr_y + count - 1))
					{
						arr_x = (int *)realloc(arr_x, sizeof(int)*(count + 1));
						arr_y = (int *)realloc(arr_y, sizeof(int)*(count + 1));

						*(arr_x + count) = B[0][0];//Запоминаем x
						*(arr_y + count) = B[0][1];//ЗАпоминаем y

						count++;
					}
				}
				
				if (B[0][0] == B[1][0] && B[0][1] == B[1][1]) break;
				e2 = err;

				if (e2 > -dx)
				{
					err -= dy; B[0][0] += sx;
				}

				if (e2 < dy)
				{
					err += dx; B[0][1] += sy;
				}
			}
		}
		
		//Посрочная заливка, используя граничные точкив массивах arr_x And arr_y

		//Сортируем массивы по Y(Если Y равны, то по х)
		count--;

		int tmp;
		int noSwap;

		for (int i = count - 1; i >= 0; i--)
		{
			noSwap = 1;
			for (int j = 0; j < i; j++)
			{

				if (arr_y[j] > arr_y[j + 1])
				{
					tmp = arr_y[j];
					arr_y[j] = arr_y[j + 1];
					arr_y[j + 1] = tmp;

					tmp = arr_x[j];
					arr_x[j] = arr_x[j + 1];
					arr_x[j + 1] = tmp;
					noSwap = 0;
				}

			}
			if (noSwap == 1)
				break;
		}

		//ЗАносим в массив точки по определённому Y Сортируем их и если по этому y не вершина фгуры, заливаем линию
		int count_x = 0, count_y = 0, now_y = arr_y[0];
		int mas_x[3];

		do {

			count_x = 0;

			while (1)
			{
				*(mas_x + count_x) = *(arr_x + count_y);
				count_x++;
				count_y++;

				if (now_y != arr_y[count_y])	break;
			}

			//сортируем массив и заливаем линию
			if (count_x == 2)
			{
				if (*mas_x > *(mas_x + 1))
				{
					int tmp = *mas_x;
					*mas_x = *(mas_x + 1);
					*(mas_x + 1) = tmp;
				}

				while (*mas_x != *(mas_x + 1))
				{
					if (flag)
					{
						SetPixel(hdc, *mas_x, now_y, RGB(R1, R2, R3));
					}
					else
					{
						SetPixel(hdc, *mas_x, now_y, RGB(0,0,0));
					}
						*mas_x = *mas_x + 1;
					
				}
			}
			now_y = *(arr_y + count_y);
		} while (count_y < count);


		if (count > 4000)
		{
			free(arr_x);
			free(arr_y);
		}
		ReleaseDC(sHwnd, hdc);
	}


	figure& move(figure & A, int flag)
	{
		double dx = 0, dy = 0, dz = 0;
		if (flag == 6)
		{
			dx = delta_o;
		}
		if (flag == 4)
		{
			dx = -delta_o;
		}
		if (flag == 8)
		{
			dy = -delta_o;
		}
		if (flag == 2)
		{
			dy = delta_o;
		}
		if (flag == 7)
		{
			dz = -delta_o;
		}	if (flag == 9)
		{
			dz = delta_o;
		}

		Bmat B((1), (0), (0), (dx), (0), (1), (0), (dy), (0), (0), (1), (dz), (0), (0), (0), (1));
		A = A * B;//Перемножение матриц
		return A;
	}

	figure & Scale(figure &A, int flag)
	{
		double k;
		if (flag == 3)
		{
			k = SCALE;
		}
		if (flag == 1)
		{
			k = scale;
		}
		double dx = 0, dy = 0, dz = 0;
		for (int i = 0; i < 8; i++)
		{
			dx += A.A[i][0];
			dy += A.A[i][1];
			dz += A.A[i][2];
		}
		dx /= 8;
		dy /= 8;
		dz /= 8;
		Bmat B((k), (0), (0), (0), (0), (k), (0), (0), (0), (0), (k), (0), (0), (0), (0), (1));
		Bmat Bd((1), (0), (0), (-dx), (0), (1), (0), (-dy), (0), (0), (1), (-dz), (0), (0), (0), (1));
		Bmat Bmd((1), (0), (0), (dx), (0), (1), (0), (dy), (0), (0), (1), (dz), (0), (0), (0), (1));

		A = A * Bd;
		A = A * B;
		A = A * Bmd;

		return A;
	}

	figure & roat(figure & A, int flag, int flag2)
	{
		double dx = 0, dy = 0, dz = 0;
		//находим центр
		for (int i = 0; i < 8; i++)
		{
			dx += A.A[i][0];
			dy += A.A[i][1];
			dz += A.A[i][2];
		}
		dx /= 8;
		dy /= 8;
		dz /= 8;

		Bmat Bd((1), (0), (0), (-dx), (0), (1), (0), (-dy), (0), (0), (1), (-dz), (0), (0), (0), (1));
		Bmat Bmd((1), (0), (0), (dx), (0), (1), (0), (dy), (0), (0), (1), (dz), (0), (0), (0), (1));


		double U = flag2 ? fi : -fi;
		if (flag == 1)//вокруг х
		{
			Bmat B((1), (0), (0), (0), (0), (cos(U)), (-sin(U)), (0), (0), (sin(U)), (cos(U)), (0), (0), (0), (0), (1));

			A = A * Bd;
			A = A * B;
			A = A * Bmd;
		}
		if (flag == 2)// вокруг у
		{
			Bmat B((cos(U)), (0), (-sin(U)), (0), (0), (1), (0), (0), (sin(U)), (0), ((cos(U))), (0), (0), (0), (0), (1));

			A = A * Bd;
			A = A * B;
			A = A * Bmd;
		}
		if (flag == 3)// вокруг z
		{
			Bmat B((cos(U)), (-sin(U)), (0), (0), (sin(U)), (cos(U)), (0), (0), (0), (0), (1), (0), (0), (0), (0), (1));

			A = A * Bd;
			A = A * B;
			A = A * Bmd;
		}

		return A;
	}




void Draw(figure &A, int flag)
{
	double zk = 2000, zm = 100;//Задание данных кординат подобрано вручную zk - расстояние до глаза в пикселях ^_^ zm расстояние от 3-х ерного объекта до монитора

	//проекция перспективная
	figure L = A;
	for (int i = 0; i < 8; i++)
	{
		L.A[i][0] = A.A[i][0] * (zk - zm) / (zk - A.A[i][2]);
		L.A[i][1] = A.A[i][1] * (zk - zm) / (zk - A.A[i][2]);
	}
	//закраска линй 1-2 2-3 3-1  4-1 4-2 4-3
	double Rasp[6][2] = { {(A.A[0][2] + A.A[1][2] + A.A[2][2]+ A.A[3][2])/4, 0}, {(A.A[4][2] + A.A[5][2] + A.A[6][2] + A.A[7][2]) / 4, 1},
	{(A.A[4][2] + A.A[5][2] + A.A[1][2] + A.A[0][2])/4, 2}, {(A.A[5][2] + A.A[1][2] + A.A[2][2] + A.A[6][2]) / 4, 3}, {(A.A[6][2] + A.A[2][2] + A.A[3][2] + A.A[7][2]) / 4, 4},
	{(A.A[7][2] + A.A[3][2] + A.A[0][2] + A.A[4][2]) / 4, 5}, };
	//Смотрим какие y расположены ближе к камере Смотрим по оси z
	//Последними рисуются ближние к камере
	//сортируем по убыванию
	double tmp;
	bool noSwap;

	for (int i = 6 - 1; i >= 0; i--)
	{
		noSwap = 1;
		for (int j = 0; j < i; j++)
		{
			if (Rasp[j][0] > Rasp[j + 1][0])
			{
				//меняем значения суммы z
				tmp = Rasp[j][0];
				Rasp[j][0] = Rasp[j + 1][0];
				Rasp[j + 1][0] = tmp;
				// меняем номер линии
				tmp = Rasp[j][1];
				Rasp[j][1] = Rasp[j + 1][1];
				Rasp[j + 1][1] = tmp;
				//
				noSwap = 0;
			}
		}
		if (noSwap == 1)
			break;
	}

	//
	for (int i = 0; i < 6; i++)
	{
		switch (((int)(Rasp[i][1])))// В зависимости от того, какая линия дальше от экрана рисуем линии
		{
		case 0:
			DrowLine(L.A[0][0], L.A[0][1], L.A[1][0], L.A[1][1], L.A[2][0], L.A[2][1], L.A[3][0], L.A[3][1], flag, 1);//Закраска 0-1-2-3
			break;
		case 1:
			DrowLine(L.A[4][0], L.A[4][1], L.A[5][0], L.A[5][1], L.A[6][0], L.A[6][1], L.A[7][0], L.A[7][1], flag, 2);//Закраска 4-5-6-7
			break;
		case 2:
			DrowLine(L.A[4][0], L.A[4][1], L.A[5][0], L.A[5][1], L.A[1][0], L.A[1][1], L.A[0][0], L.A[0][1], flag, 3);//Закраска 4-5-1-0
			break;

		case 3:
			DrowLine(L.A[5][0], L.A[5][1], L.A[1][0], L.A[1][1], L.A[2][0], L.A[2][1], L.A[6][0], L.A[6][1], flag, 4);//5-1-2-6
			break;
		case 4:
			DrowLine(L.A[6][0], L.A[6][1], L.A[2][0], L.A[2][1], L.A[3][0], L.A[3][1], L.A[7][0], L.A[7][1], flag, 5);//Закраска 6-2-7-3
			break;

		case 5:
			DrowLine(L.A[7][0], L.A[7][1], L.A[3][0], L.A[3][1], L.A[0][0], L.A[0][1], L.A[4][0], L.A[4][1], flag, 6);//7-3-0-4
			break;
		default: break;
		}
	}
}