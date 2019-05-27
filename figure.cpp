#include "figure.h"

figure::figure()
{
	A[0][0] = 0+100;
	A[0][1] = 0 + 100;
	A[0][2] = 0;
	A[0][3] = 1;

	A[1][0] = 100 + 100;
	A[1][1] = 0 + 100;
	A[1][2] = 0;
	A[1][3] = 1;

	A[2][0] = 100 + 100;
	A[2][1] = 100 + 100;
	A[2][2] = 0;
	A[2][3] = 1;

	A[3][0] = 0 + 100;
	A[3][1] = 100 + 100;
	A[3][2] = 0;
	A[3][3] = 1;

	A[4][0] = 0 + 150;
	A[4][1] = 0 + 150;
	A[4][2] = 150;
	A[4][3] = 1;

	A[5][0] = 100 + 150;
	A[5][1] = 0 + 150;
	A[5][2] = 150;
	A[5][3] = 1;

	A[6][0] = 100 + 150;
	A[6][1] = 100 + 150;
	A[6][2] = 150;
	A[6][3] = 1;

	A[7][0] = 0 + 150;
	A[7][1] = 100 + 150;
	A[7][2] = 150;
	A[7][3] = 1;

}

figure::figure(const figure & F)
{
	for (int i = 0; i < 8; i++)
	{
		A[i][0] = F.A[i][0];
		A[i][1] = F.A[i][1];
		A[i][2] = F.A[i][2];
		A[i][3] = F.A[i][3];
	}
}

figure & figure::operator=(figure & f)
{
	for (int i = 0; i < 8; i++)
	{
		A[i][0] = f.A[i][0];
		A[i][1] = f.A[i][1];
		A[i][2] = f.A[i][2];
		A[i][3] = f.A[i][3];
	}

	return *this;
}

figure & operator*(figure & Aa, Bmat & Bb)
{
	double tmp[8][4];

	for (int i = 0; i < 8; i++)
	{

		tmp[i][0] = (Aa.A[i][0] * Bb.B[0][0] + Aa.A[i][1] * Bb.B[0][1] + Aa.A[i][2] * Bb.B[0][2] + Aa.A[i][3] * Bb.B[0][3]);
		tmp[i][1] = (Aa.A[i][0] * Bb.B[1][0] + Aa.A[i][1] * Bb.B[1][1] + Aa.A[i][2] * Bb.B[1][2] + Aa.A[i][3] * Bb.B[1][3]);
		tmp[i][2] = (Aa.A[i][0] * Bb.B[2][0] + Aa.A[i][1] * Bb.B[2][1] + Aa.A[i][2] * Bb.B[2][2] + Aa.A[i][3] * Bb.B[2][3]);
		tmp[i][3] = (Aa.A[i][0] * Bb.B[3][0] + Aa.A[i][1] * Bb.B[3][1] + Aa.A[i][2] * Bb.B[3][2] + Aa.A[i][3] * Bb.B[3][3]);


	}

	for (int i = 0; i < 8; i++)
	{
		Aa.A[i][0] = tmp[i][0];
		Aa.A[i][1] = tmp[i][1];
		Aa.A[i][2] = tmp[i][2];
		Aa.A[i][3] = tmp[i][3];
	}
	return Aa;
}


