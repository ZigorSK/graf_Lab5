#pragma once
#ifndef _func_H_

#include"Bmat.h"
#include"figure.h"
#include<windows.h>
#include<cstdlib>
#include<ctime>
#include<cmath>

#define _func_H_

void Draw(figure &A, int flag);//������ ��������� �������
void DrowLine(double ax, double ay, double bx, double by, double cx, double cy, double ex, double ey, int flag, int flag2);//������ �����
figure & move(figure &A, int flag);//����� �� ����
figure & Scale(figure &A, int flag);
figure & roat(figure &A, int flag, int flag2);

#endif
