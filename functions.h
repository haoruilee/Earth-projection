#include  <iostream>
#include <math.h>
#include <cmath>

/*
# 高斯正反算
- 所有字母均符合latex公式规则，以_com表示' 以_double_com表示''
- 默认使用弧度制
- 默认双精度型

注意：
- 未规定上下界判别（如弧度不能超过2pi）
*/

///////////////////////1975///////////////////////////////////

//正算公式
double forward_x_1975(double B_double_com, double rho_double_com, double a_0, double a_4, double a_6, double l, double  N, double B)
{
	//x的正算公式(代入1975国际椭球参数后)
	return ((6367452.1328 * B_double_com / rho_double_com) - (a_0 - (0.5 + (a_4 + a_6 * pow(l)) *pow(l))* pow(l) * N) * cos(B) * sin(B));
}

double forward_y_1975(double l, double a_3, double a_5, double B)
{
	//y的正算公式(代入1975国际椭球参数后)
	return ( (1+(a_3+a_5*pow(l))*pow(l))*l*N*cos(B) )
}

//正算x,y所用函数
double N(double B)
{
	return (6399596.652 - (21565.045 - (108.996 - 0.603 * pow(cos(B))) * pow(B)) * pow(B));
}

double a_0(double B)
{
	return (32144.5189 - ((135.3646 - (0.7034 - 0.0041 * pow(cos(B))) * pow(cos(B))) * pow(cos(B))));
}

double a_4(double B)
{
	return ((0.25 + 0.002 53 * pow(cos(B))) * pow(cos(B)) - 0.041 67);
}

double a_6(double B)
{
	return ((0.167 * pow(cos(B)) - 0.083) * pow(cos(B)));
}

double a_3(double B)
{
	return ((0.3333333 + 0.001123 * pow(cos(B))) * pow(cos(B)) - 0.1666667);
}

double a_5(double B)
{
	return (0.00878 - (0.1702 - 0.20382 * pow(cos(B))) * pow(cos(B)));
}

//反算公式
double backward_B_1975(double B_f, double b_4, double Z, double b_2, double rho_double_com)
{
	//B的反算公式(代入1975)
	return (B_f -(1 - (b_4 -0.147*pow(Z) )*pow(Z) )*pow(Z)*b_2*rho_double_com);
}

double backward_l_1975(double b_3, double b_5, double Z, double rho_double_com)
{
	//l的反算公式(代入1975)
	return ((1 - (b_1 - b_5 * pow(Z)) * pow(Z)) * Z * rho_double_com);
}

//反算B,l用到的公式
double Z(double y, double N_f, double B_f)
{
	return ((y) / (N_f * cos(B_f)));
}

double b_2(double B_f)
{
	return((0.5 + 0.00336975 * pow(cos(B_f))) * sin(B_f) * cos(B_f));
}

double b_3(double B_f)
{
	return (0.333333 - (0.1666667 - 0.001123 * pow(cos(B_f))) * pow(cos(B_f)));
}

double b_4(double B_f)
{
	return (0.25 + (0.161612 + 0.005617 * pow(cos(B_f))) * pow(cos * (B_f)));
}

double b_5(double B_f)
{
	return (0.2 - (0.16667 - 0.00878 * pow(cos(B_f))) * pow(cos(B_f)));
}

///B_f,N_f没写

/////////////////////////