#include  <iostream>
#include <math.h>
#include <cmath>

/*
# ��˹������
- ������ĸ������latex��ʽ������_com��ʾ' ��_double_com��ʾ''
- Ĭ��ʹ�û�����
- Ĭ��˫������

ע�⣺
- δ�涨���½��б��绡�Ȳ��ܳ���2pi��
*/

///////////////////////1975///////////////////////////////////

//���㹫ʽ
double forward_x_1975(double B_double_com, double rho_double_com, double a_0, double a_4, double a_6, double l, double  N, double B)
{
	//x�����㹫ʽ(����1975�������������)
	return ((6367452.1328 * B_double_com / rho_double_com) - (a_0 - (0.5 + (a_4 + a_6 * pow(l)) *pow(l))* pow(l) * N) * cos(B) * sin(B));
}

double forward_y_1975(double l, double a_3, double a_5, double B)
{
	//y�����㹫ʽ(����1975�������������)
	return ( (1+(a_3+a_5*pow(l))*pow(l))*l*N*cos(B) )
}

//����x,y���ú���
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

//���㹫ʽ
double backward_B_1975(double B_f, double b_4, double Z, double b_2, double rho_double_com)
{
	//B�ķ��㹫ʽ(����1975)
	return (B_f -(1 - (b_4 -0.147*pow(Z) )*pow(Z) )*pow(Z)*b_2*rho_double_com);
}

double backward_l_1975(double b_3, double b_5, double Z, double rho_double_com)
{
	//l�ķ��㹫ʽ(����1975)
	return ((1 - (b_1 - b_5 * pow(Z)) * pow(Z)) * Z * rho_double_com);
}

//����B,l�õ��Ĺ�ʽ
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

///B_f,N_fûд

/////////////////////////