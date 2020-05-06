#include<bits/stdc++.h>
#include<cmath>
#include <math.h>
#include <iostream>
using namespace std;
#define Pi 3.14159

///经度 
double longitude_h[1000];
double longitude_m[1000];
double longitude_s[1000];
///纬度 
double latitude_h[1000]; 
double latitude_m[1000]; 
double latitude_s[1000];
///读入xy 
double read_x[100];
double read_y[100];
///正算得xy 
double x[100];
double y[100]; 
///反算的BL 
double f_B[100];
double f_L[100]; 

void outarray_BL();
double rho_double_com=206265;
double L_0=111;

//正算公式

double forward_x_1975(double B_double_com, double rho_double_com, double a_0, double a_4, double a_6, double l, double  N, double B)
{   //x的正算公式(代入1975国际椭球参数后)
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

	return ((B_f - (1 - (b_4 - 0.147 * pow(Z, 2)) * pow(Z, 2)) * pow(Z, 2) * b_2 )*rho_double_com);
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

double B_f_1975(double beta, double rho_double_com)

{double a=50221746 + (293622 + (2350 + 22 * cos(beta) * cos(beta)) * pow(cos(beta), 2)) * pow(cos(beta), 2);


	return(beta + (50221746 + (293622 + (2350 + 22 * cos(beta) * cos(beta)) * pow(cos(beta), 2)) * pow(cos(beta), 2)) * pow(0.1, 10) * sin(beta) * cos(beta) );

}
double beta_1975(double x)

{

	return (x  / 6367558.4969);

}


double N_f_1975(double B_f)

{

	return (6399698.902 - (21562.267 - (108.973 - 0.612 * pow(cos(B_f), 2)) * pow(cos(B_f), 2)) * pow(cos(B_f), 2));

}

////////////////////克氏椭球///////////////

//K
double backward_B_K(double B_f, double Z, double b_4, double b_2, double rho_double_com)
{
//	cout<<"值      "<<B_f - (1 - (b_4 - 0.12 * pow(Z, 2)) * pow(Z, 2)) * pow(Z, 2) * b_2 <<endl;
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
double B_f_K(double beta)
{
	return (beta + ((50221746 + (293622 + (2350 + 22 * pow(cos(beta), 2)) * pow(cos(beta), 2)) * pow(cos(beta), 2)) * pow(0.1, 10) * sin(beta) * cos(beta) ));
}

double beta_K(double x)
{
	return (x  / 6367558.4969);
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
    inf.open("data.txt", ifstream::in);	
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

cout << "Chosse K or 1975: 1:1975, 0: K" << endl;
int flag = 0;
cin >> flag;
while (flag != 0 && flag != 1)
{
	cout<<"Wrong input! Please only input 0 or 1!"<<endl;
	cin >> flag;
}

//int flag=0;

//////flag==1 1975    flag==0  k式 
if(flag)
{ 
//1975正算 
double L,l;
for (int i=0;i<5;i++)
	{double B_double_com=3600*latitude_h[i]+60*latitude_m[i];
	
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
	x[i]=forward_x_1975(B_double_com, rho_double_com,a_0,a_4,a_6, l, N,B);
	y[i]=forward_y_1975(l,a_3,a_5,B,N);

	}
	cout<<"---------------1975正算结果----------------"<<endl; 
	for (int i=0;i<5;i++)
	{cout<<"第"<<i+1<<"个点  x ="<<x[i]<<"     y=   "<<y[i]<<endl;
	}
//1975反算 

	for (int i=0;i<5;i++)
	{
	double beta=beta_1975(read_x[i]);
	double B_f=B_f_1975(beta,rho_double_com);
	double N_f=N_f_1975(B_f);
	double Z=Z_1975(read_y[i],N_f,B_f) ;
	double b_2=b_2_1975(B_f);
	double b_3=b_3_1975(B_f);
	double b_4=b_4_1975(B_f);
	double b_5=b_5_1975(B_f);
	f_B[i]=backward_B_1975(B_f,b_4,Z,b_2,rho_double_com);
 	f_L[i]=backward_l_1975(b_3,b_5,Z,rho_double_com); 
	}
	cout<<"---------------1975反算结果-------------------"<<endl; 
	for (int i=0;i<5;i++)
	{cout<<"第"<<i+1<<"个点     B="<<f_B[i]<<"     L=   "<<f_L[i]<<endl;
	}   cin.get();
	} 
	
	////	K式 
	else
	{double L,l;
	///  k式正算 
for (int i=0;i<5;i++)
	{double B_double_com=3600*latitude_h[i]+60*latitude_m[i];
	
	double B=latitude_h[i];
	L=longitude_h[i];
	l=((L-L_0)*3600+60*longitude_m[i])/rho_double_com;
	B=B*Pi/180;
	double a_0=a_0_K(B);
	double a_3=a_3_K(B);
	double a_4=a_4_K(B);
	double a_5=a_5_K(B);
	double a_6=a_6_K(B);
	double N=N_K(B);
	x[i]=forward_x_1975(B_double_com, rho_double_com,a_0,a_4,a_6, l, N,B);
	y[i]=forward_y_1975(l,a_3,a_5,B,N);

	}
	cout<<"---------------K式正算结果----------------"<<endl; 
	for (int i=0;i<5;i++)
	{cout<<"第"<<i+1<<"个点 x ="<<x[i]<<"     y=   "<<y[i]<<endl;
	}
	
//  K式 反算 

	for (int i=0;i<5;i++)
	{
	/////////参数 
	double beta=beta_K(read_x[i]);
	double B_f=B_f_K(beta);
	double N_f=N_f_K(B_f);
	double Z=Z_K(read_y[i],N_f,B_f) ;
	double b_2=b_2_K(B_f);
	double b_3=b_3_K(B_f);
	double b_4=b_4_K(B_f);
	double b_5=b_5_K(B_f);


	f_B[i]=backward_B_1975(B_f,b_4,Z,b_2,rho_double_com);
 	f_L[i]=backward_l_1975(b_3,b_5,Z,rho_double_com); 
	}
	cout<<"---------------K式反算结果-------------------"<<endl; 
	for (int i=0;i<5;i++)
	{cout<<"第"<<i+1<<"个点     B="<<f_B[i]<<"     L=   "<<f_L[i]<<endl;
	}   cin.get();
	} 
	 
 } 


