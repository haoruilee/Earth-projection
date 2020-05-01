#include  <iostream>
#include <math.h>
#include <cmath>

/*
# 高斯正反算
- 所有字母均符合latex公式规则，以_com表示' 以_double_com表示''
- 默认使用角度
- 默认双精度型

注意：
- 未规定上下界判别
- 未设计进位
*/

///////////////////////1975///////////////////////////////////

//正算公式
double forward_x_1975(double B_double_com, double rho_double_com, double a_0, double a_4, double a_6, double l, double  N, double B)
{
	//x的正算公式(代入1975国际椭球参数后)
	return ((6367452.1328 * B_double_com / rho_double_com) - (a_0 - (0.5 + (a_4 + a_6 * pow(l,2)) *pow(l,2))* pow(l,2) * N) * cos(B) * sin(B));
}

double forward_y_1975(double l, double a_3, double a_5, double B)
{
	//y的正算公式(代入1975国际椭球参数后)
	return ( (1+(a_3+a_5*pow(l,2))*pow(l,2))*l*N*cos(B) )
}

//正算x,y所用函数
double N_1975(double B)
{
	return (6399596.652 - (21565.045 - (108.996 - 0.603 * pow(cos(B),2)) * pow(B,2)) * pow(B,2));
}

double a_0_1975(double B)
{
	return (32144.5189 - ((135.3646 - (0.7034 - 0.0041 * pow(cos(B),2)) * pow(cos(B),2)) * pow(cos(B),2)));
}

double a_4_1975(double B)
{
	return ((0.25 + 0.002 53 * pow(cos(B),2)) * pow(cos(B),2) - 0.041 67);
}

double a_6_1975(double B)
{
	return ((0.167 * pow(cos(B),2) - 0.083) * pow(cos(B),2));
}

double a_3_1975(double B)
{
	return ((0.3333333 + 0.001123 * pow(cos(B),2)) * pow(cos(B),2) - 0.1666667);
}

double a_5_1975(double B)
{
	return (0.00878 - (0.1702 - 0.20382 * pow(cos(B),2)) * pow(cos(B),2));
}

//反算公式
double backward_B_1975(double B_f, double b_4, double Z, double b_2, double rho_double_com)
{
	//B的反算公式(代入1975)
	return (B_f -(1 - (b_4 -0.147*pow(Z,2) )*pow(Z,2) )*pow(Z,2)*b_2*rho_double_com);
}

double backward_l_1975(double b_3, double b_5, double Z, double rho_double_com)
{
	//l的反算公式(代入1975)
	return ((1 - (b_1 - b_5 * pow(Z,2)) * pow(Z,2)) * Z * rho_double_com);
}

//反算B,l用到的公式
double Z_1975(double y, double N_f, double B_f)
{
	return ((y) / (N_f * cos(B_f)));
}

double b_2_1975(double B_f)
{
	return((0.5 + 0.00336975 * pow(cos(B_f),2)) * sin(B_f) * cos(B_f));
}

double b_3_1975(double B_f)
{
	return (0.333333 - (0.1666667 - 0.001123 * pow(cos(B_f),2)) * pow(cos(B_f),2));
}

double b_4_1975(double B_f)
{
	return (0.25 + (0.161612 + 0.005617 * pow(cos(B_f),2)) * pow(cos * (B_f),2));
}

double b_5_1975(double B_f)
{
	return (0.2 - (0.16667 - 0.00878 * pow(cos(B_f),2)) * pow(cos(B_f),2));
}

double B_f_1975(double beta, double B)
{
	return (beta - 2.518829807 * 0.001 * sin(2 * B) + 2.643546 * 0.000001 * sin(4 * B) - 3.452 * 0.000000001 * sin(6 * B) + 5 * pow(0.1, 12) * sin(8 * B));

}

double N_f_1975(double B_f, double a)//////a目前不知道传入什么值
{
	return (a * pow((1 - pow(2.71828, 2) * pow(sin(B_f), 2)), -0.5));
}

////////////////////克氏椭球///////////////
//K

double backward_B_K(double B_f, double Z, double b_4, double b_2, double rho_double_com)
{
	return (B_f - (1 - (b_4 - 0.12 * pow(Z, 2)) * pow(Z, 2)) * pow(Z, 2) * b_2 * rho_double_com);
}

double l_K(double b_3, double b_5, double Z, double rho_double_com)
{
	return ((1 - (b_3 - b_5 * pow(Z, 2)) * pow(Z, 2)) * Z * rho_double_com);
}

double L_k(double L_0, double l)
{
	return (L_0 + l);
}

//K反算所用常数
double B_f_K(double beta, double rho_double_com)
{
	return (beta + (50221746 + (293622 + (2350 + 22 * pow(cos(beta), 2)) * pow(cos(beta), 2)) * pow(cos(beta), 2)) * pow(0.1, 10) * sin(beta) * cos(beta) * rho_double_com);
}

double beta_K(double x, double rho)
{
	return (x * rho / 6367558.4969);
}

double Z_K(double y, double N_f, double B_f)
{
	return (y / (N_f * cos(B_f)));
}

double N_f_K(double B_f)
{
	return (6399698.902 - (21562.267 - (108.973 - 0.612 * pow(cos(B_f), 2)) * pow(cos(B_f),2)) * pow(cos(B_f), 2));
}

double b_2_K(double B_f)
{
	return ((0.5 + 0.003369 * pow(cos(B_f), 2)) * sin(B_f) * cos(B_f));
}

double b_3_K(double B_f)
{
	return (0.333333 - (0.166667 - 0.001123 * pow(cos(B_f), 2)) * pow(cos(B_f), 2));
}

double b_4_K(double B_f)
{
	return (0.25 + (0.16161 + 0.00562 * pow(cos(B_f), 2)) * pow(cos(B_f), 2));
}

double b_5_K(double B_f)
{
	return(0.2 - (0.1667 - 0.0088 * pow(cos(B_f), 2)) * pow(cos(B_f), 2));
}

=======
#include  <iostream>
#include <math.h>
#include <cmath>

/*
# 高斯正反算
- 所有字母均符合latex公式规则，以_com表示' 以_double_com表示''
- 默认使用角度
- 默认双精度型

注意：
- 未规定上下界判别
- 未设计进位
*/

///////////////////////1975///////////////////////////////////

//正算公式
double forward_x_1975(double B_double_com, double rho_double_com, double a_0, double a_4, double a_6, double l, double  N, double B)
{
	//x的正算公式(代入1975国际椭球参数后)
	return ((6367452.1328 * B_double_com / rho_double_com) - (a_0 - (0.5 + (a_4 + a_6 * pow(l,2)) *pow(l,2))* pow(l,2) * N) * cos(B) * sin(B));
}

double forward_y_1975(double l, double a_3, double a_5, double B)
{
	//y的正算公式(代入1975国际椭球参数后)
	return ( (1+(a_3+a_5*pow(l,2))*pow(l,2))*l*N*cos(B) )
}

//正算x,y所用函数
double N_1975(double B)
{
	return (6399596.652 - (21565.045 - (108.996 - 0.603 * pow(cos(B),2)) * pow(B,2)) * pow(B,2));
}

double a_0_1975(double B)
{
	return (32144.5189 - ((135.3646 - (0.7034 - 0.0041 * pow(cos(B),2)) * pow(cos(B),2)) * pow(cos(B),2)));
}

double a_4_1975(double B)
{
	return ((0.25 + 0.002 53 * pow(cos(B),2)) * pow(cos(B),2) - 0.041 67);
}

double a_6_1975(double B)
{
	return ((0.167 * pow(cos(B),2) - 0.083) * pow(cos(B),2));
}

double a_3_1975(double B)
{
	return ((0.3333333 + 0.001123 * pow(cos(B),2)) * pow(cos(B),2) - 0.1666667);
}

double a_5_1975(double B)
{
	return (0.00878 - (0.1702 - 0.20382 * pow(cos(B),2)) * pow(cos(B),2));
}

//反算公式
double backward_B_1975(double B_f, double b_4, double Z, double b_2, double rho_double_com)
{
	//B的反算公式(代入1975)
	return (B_f -(1 - (b_4 -0.147*pow(Z,2) )*pow(Z,2) )*pow(Z,2)*b_2*rho_double_com);
}

double backward_l_1975(double b_3, double b_5, double Z, double rho_double_com)
{
	//l的反算公式(代入1975)
	return ((1 - (b_1 - b_5 * pow(Z,2)) * pow(Z,2)) * Z * rho_double_com);
}

//反算B,l用到的公式
double Z_1975(double y, double N_f, double B_f)
{
	return ((y) / (N_f * cos(B_f)));
}

double b_2_1975(double B_f)
{
	return((0.5 + 0.00336975 * pow(cos(B_f),2)) * sin(B_f) * cos(B_f));
}

double b_3_1975(double B_f)
{
	return (0.333333 - (0.1666667 - 0.001123 * pow(cos(B_f),2)) * pow(cos(B_f),2));
}

double b_4_1975(double B_f)
{
	return (0.25 + (0.161612 + 0.005617 * pow(cos(B_f),2)) * pow(cos * (B_f),2));
}

double b_5_1975(double B_f)
{
	return (0.2 - (0.16667 - 0.00878 * pow(cos(B_f),2)) * pow(cos(B_f),2));
}

double B_f_1975(double beta, double B)
{
	return (beta - 2.518829807 * 0.001 * sin(2 * B) + 2.643546 * 0.000001 * sin(4 * B) - 3.452 * 0.000000001 * sin(6 * B) + 5 * pow(0.1, 12) * sin(8 * B));

}

double N_f_1975(double B_f, double a)//////a目前不知道传入什么值
{
	return (a * pow((1 - pow(2.71828, 2) * pow(sin(B_f), 2)), -0.5));
}

////////////////////克氏椭球///////////////
//K

double backward_B_K(double B_f, double Z, double b_4, double b_2, double rho_double_com)
{
	return (B_f - (1 - (b_4 - 0.12 * pow(Z, 2)) * pow(Z, 2)) * pow(Z, 2) * b_2 * rho_double_com);
}

double l_K(double b_3, double b_5, double Z, double rho_double_com)
{
	return ((1 - (b_3 - b_5 * pow(Z, 2)) * pow(Z, 2)) * Z * rho_double_com);
}

double L_k(double L_0, double l)
{
	return (L_0 + l);
}

//K反算所用常数
double B_f_K(double beta, double rho_double_com)
{
	return (beta + (50221746 + (293622 + (2350 + 22 * pow(cos(beta), 2)) * pow(cos(beta), 2)) * pow(cos(beta), 2)) * pow(0.1, 10) * sin(beta) * cos(beta) * rho_double_com);
}

double beta_K(double x, double rho)
{
	return (x * rho / 6367558.4969);
}

double Z_K(double y, double N_f, double B_f)
{
	return (y / (N_f * cos(B_f)));
}

double N_f_K(double B_f)
{
	return (6399698.902 - (21562.267 - (108.973 - 0.612 * pow(cos(B_f), 2)) * pow(cos(B_f),2)) * pow(cos(B_f), 2));
}

double b_2_K(double B_f)
{
	return ((0.5 + 0.003369 * pow(cos(B_f), 2)) * sin(B_f) * cos(B_f));
}

double b_3_K(double B_f)
{
	return (0.333333 - (0.166667 - 0.001123 * pow(cos(B_f), 2)) * pow(cos(B_f), 2));
}

double b_4_K(double B_f)
{
	return (0.25 + (0.16161 + 0.00562 * pow(cos(B_f), 2)) * pow(cos(B_f), 2));
}

double b_5_K(double B_f)
{
	return(0.2 - (0.1667 - 0.0088 * pow(cos(B_f), 2)) * pow(cos(B_f), 2));
}

//////////////////////////正算开始
//和1975几乎一样

double forward_x_K(double B_double_com, double rho_double_com, double a_0, double a_4, double a_6, double l, double  N, double B)
{
	//x的正算公式(代入K参数后)
	return ((6367558.4969 * B_double_com / rho_double_com) - (a_0 - (0.5 + (a_4 + a_6 * pow(l, 2)) * pow(l, 2)) * pow(l, 2) * N) * cos(B) * sin(B));
}

double forward_y_K(double l, double a_3, double a_5, double B)
{
	//y的正算公式(代入K参数后)
	return ((1 + (a_3 + a_5 * pow(l, 2)) * pow(l, 2)) * l * N * cos(B))
}

//正算x,y所用函数
double N_K(double B)
{
	return (6399698.902 - (21562.267 - (108.996 - 0.603 * pow(cos(B), 2)) * pow(B, 2)) * pow(B, 2));
}

double a_0_K(double B)
{
	return (32140.404 - ((135.3302 - (0.7092 - 0.004 * pow(cos(B), 2)) * pow(cos(B), 2)) * pow(cos(B), 2)));
}

double a_4_K(double B)
{
	return ((0.25 + 0.002 52 * pow(cos(B), 2)) * pow(cos(B), 2) - 0.041 66);
}

double a_6_K(double B)
{
	return ((0.166 * pow(cos(B), 2) - 0.084) * pow(cos(B), 2));
}

double a_3_K(double B)
{
	return ((0.3333333 + 0.001123 * pow(cos(B), 2)) * pow(cos(B), 2) - 0.1666667);
}

double a_5_K(double B)
{
	return (0.0083- (0.1667 - (0.1968 + 0.004*pow(cos(B), 2))* pow(cos(B), 2)) * pow(cos(B), 2));
}