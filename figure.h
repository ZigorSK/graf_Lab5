#pragma once
#ifndef _figure_H_

#include<cmath>

using namespace std;

#define _figure_H_
#include"Bmat.h"
class figure
{
public:
	double A[8][4];

	figure();
	figure(const figure &F);


	friend figure &operator *(figure &Aa, Bmat &Bb);
	figure &operator =(figure &f);


};
#endif