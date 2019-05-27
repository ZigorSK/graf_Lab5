#include "Bmat.h"

Bmat::Bmat(double b00, double b01, double b02, double b03, double b10, double b11, double b12, double b13, double b20, double b21, double b22, double b23, double b30, double b31, double b32, double b33)
{
	B[0][0] = b00;
	B[0][1] = b01;
	B[0][2] = b02;
	B[0][3] = b03;

	B[1][0] = b10;
	B[1][1] = b11;
	B[1][2] = b12;
	B[1][3] = b13;

	B[2][0] = b20;
	B[2][1] = b21;
	B[2][2] = b22;
	B[2][3] = b23;

	B[3][0] = b30;
	B[3][1] = b31;
	B[3][2] = b32;
	B[3][3] = b33;
}
