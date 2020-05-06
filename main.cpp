#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;
int longitude_h[1000];
int longitude_m[1000];
int longitude_s[1000];

int latitude_h[1000]; 
int latitude_m[1000]; 
int latitude_s[1000]; 
int main()
{
    ifstream inf;
    inf.open("data.txt", ifstream::in);
  
    const int cnt = 3;          
    string line;   
    //int i = 0;
        int j = 0;
    size_t comma = 0;
    size_t comma2 = 0;
    int line_number=0;
    
    
    while (!inf.eof())
    {	
        getline(inf,line);
  
        comma = line.find(',',0);
        if (line_number%2==0)
        	longitude_h[line_number/2]=strtol(line.substr(0,comma).c_str());
		else
       		latitude_h[line_number/2]=line.substr(0,comma).c_str();
	   // cout<<line.substr(0,comma).c_str()<<' ';
        while (comma < line.size() && j != cnt-1)
        {
            comma2 = line.find(',',comma + 1);
            ++j;
            if(j==1)
            	{	
             if (line_number%2==0)
        		longitude_m[line_number/2]=line.substr(comma + 1,comma2-comma-1).c_str();
			else
       			latitude_m[line_number/2]=line.substr(comma + 1,comma2-comma-1).c_str();
       			}
       	if(j==2)
       		{
       		if (line_number%2==0)
        		longitude_s[line_number/2]=line.substr(comma + 1,comma2-comma-1).c_str();
			else
       			latitude_s[line_number/2]=line.substr(comma + 1,comma2-comma-1).c_str();
		   }
         //   cout<<line.substr(comma + 1,comma2-comma-1).c_str()<<' ';
            
          //  cout<<"j="<<j<<endl;
            comma = comma2;
        }
        cout<<endl;
        j = 0;
        line_number++;
    }
  
    inf.close();
  
    return 0;
} 
