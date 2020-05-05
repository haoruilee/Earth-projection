#include<bits/stdc++.h>
#include<cmath>
#include <math.h>
using namespace std;
#define Pi 3.14159


double longitude_h[1000];
double longitude_m[1000];
double longitude_s[1000];

double latitude_h[1000]; 
double latitude_m[1000]; 
double latitude_s[1000];
double read_x[100];
double read_y[100];
double x[100];
double y[100]; 
double f_B[100];
double f_L[100]; 
//void outarray_XY();
void outarray_BL();
double rho_double_com=206265;
double L_0=111;
double forward_x_1975(double B_double_com, double rho_double_com, double a_0, double a_4, double a_6, double l, double  N, double B)
{
//	cout<<6367452.1328 * B_double_com / rho_double_com<<"   "<<(a_0 - (0.5 + (a_4 + a_6 * pow(l,2)) *pow(l,2))* pow(l,2) * N) * cos(B) * sin(B)<<endl;
	return ((6367452.1328 * B_double_com / rho_double_com) - (a_0 - (0.5 + (a_4 + a_6 * pow(l,2)) *pow(l,2))* pow(l,2) * N) * cos(B) * sin(B));
}

double forward_y_1975(double l, double a_3, double a_5, double B,double N)
{
	//y的正算公式(代入1975国际椭球参数后)
	return ( (1+(a_3+a_5*pow(l,2))*pow(l,2))*l*N*cos(B) ); 
}

//正算x,y所用函数
double l_1975(double L)
{
}
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
	return ((0.25 + 0.00253 * pow(cos(B),2)) * pow(cos(B),2) - 0.04167);
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
	return ((1 - (b_3 - b_5 * pow(Z,2)) * pow(Z,2)) * Z * rho_double_com);
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
	return (0.25 + (0.161612 + 0.005617 * pow(cos(B_f),2)) * pow(cos(B_f),2));
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

double forward_y_K(double l, double a_3, double a_5, double B,double N)
{
	//y的正算公式(代入K参数后)
	return ((1 + (a_3 + a_5 * pow(l, 2)) * pow(l, 2)) * l * N * cos(B));
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
	return ((0.25 + 0.00252 * pow(cos(B), 2)) * pow(cos(B), 2) - 0.04166);
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

void outarray_BL()
{
	ifstream inf;
    inf.open("123.txt", ifstream::in);	
    int cnt = 3;          
    string line;   
    //int i = 0;
    int j = 0;
    int line_number=0;
    while (!inf.eof())
    {

	j=0;
	getline(inf,line);
	int n = line.size();
	for (int i = 0; i < n; ++i)
	{
		if (line[i] == ','){
			line[i] = ' ';
		}
	}
	istringstream out(line);
	string str;
	stringstream ss;
	if(line_number<=9)
	{
	
	while (out >> str){
	
   double a = atoi(str.c_str());
	if(line_number%2==0)
	{if(j==0)
	longitude_h[line_number/2]=a;
	else if(j==1)
	longitude_m[line_number/2]=a;
	else if (j==2)
	longitude_s[line_number/2]=a;
	}
	else if(line_number%2==1)
	{if(j==0)
	latitude_h[line_number/2]=a;
	else if(j==1)
	latitude_m[line_number/2]=a;
	else if (j==2)
	latitude_s[line_number/2]=a;
	}
    j++;
	}
	line_number++;
	}
	else
	{	while (out >> str){
	
   double a = atoi(str.c_str());
	if(j==0)
	{read_x[line_number-10]=a;
	j++;
	}
	else
	{j=0;
	read_y[line_number-10]=a;
	}
	
   }
 	line_number++;
	}
	}
	}
int main()
{outarray_BL();

//1975���� 
double L,l;
for (int i=0;i<5;i++)
	{double B_double_com=3600*latitude_h[i]+60*latitude_m[i];
	//cout<<"B_double_com"<<B_double_com;
	
	double B=latitude_h[i];
	L=longitude_h[i];
	l=((L-L_0)*3600+60*longitude_m[i])/rho_double_com;
	B=B*Pi/180;
	double a_0=a_0_1975(B);
	double a_3=a_3_1975(B);
	double a_4=a_4_1975(B);
	double a_5=a_5_1975(B);
	double a_6=a_6_1975(B);
	double N=N_1975(B);
	cout<<"l= "<<l<<"   a_3 ="<<a_3<<"  a_5 "<<a_5<<"  B = "<<B<<"  N== "<<N<<endl; 
	x[i]=forward_x_1975(B_double_com, rho_double_com,a_0,a_4,a_6, l, N,B);
	y[i]=forward_y_1975(l,a_3,a_5,B,N);

	}
//1975���� 
	for (int i=0;i<5;i++)
	{
	 
	double B_f_1975= ;
	double N_f_1975=N_f_1975(B_f_1975,a);
	double Z_1975=Z_1975(read_y[i],N_f_1975,B_f_1975) ;
	double b_2=b_2_1975(B_f_1975);
	double b_3=b_3_1975(B_f_1975);
	double b_4=b_4_1975(B_f_1975);
	double b_5=b_5_1975(B_f_1975);
	}
	
 } 


