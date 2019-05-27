#pragma once
#ifndef _Bmat_H_

#define _Bmat_H_

class Bmat
{
public:
	double B[4][4];
	Bmat(double b00, double b01, double b02, double b03, double b10, double b11, double b12, double b13, double b20, double b21, double b22, double b23, double b30, double b31, double b32, double b33);

};

#endif