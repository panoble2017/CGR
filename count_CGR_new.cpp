#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <float.h>
#include <complex>
#include <iomanip>

// Copyright Peter A Noble November 2017, Tucson, Arizona

// g++ count_CGR_new.cpp -o count_CGR 

// Note: increments can only be functions of 4... 1, 4, 8, 16 ....

// ./count_CGR  4 1 A_55_P2423586_Eya1_1_CGR.txt Eya1_1.out
// ./count_CGR  4 1 test_CGR.txt test_1.out

using namespace std;

string convert_num_str(long double x, long double y);

/// ******************************************************************///
/// ******************************************************************///

string convert_num_str(long double x, long double y)
	{
	long double xnumber=0;
	long double ynumber=0;
	long double demon=0.0;	
	char str[100];
	char str2[100];
	int flag=0;
	setprecision(60);	
	int count=1;

	while (flag!=1)
		{
		demon=0.0;	
		demon=pow(2, double(count));  
	
			 if ((x<xnumber) && (y>ynumber)) {str[count]='C';	xnumber=xnumber-(double(double(1)/demon));  ynumber=ynumber+(double(double(1)/demon)); }
		else if ((x<xnumber) && (y<ynumber)) {str[count]='G';	xnumber=xnumber-(double(double(1)/demon));  ynumber=ynumber-(double(double(1)/demon)); }
 		else if ((x>xnumber) && (y<ynumber)) {str[count]='A';	xnumber=xnumber+(double(double(1)/demon));  ynumber=ynumber-(double(double(1)/demon)); }
 		else if ((x>xnumber) && (y>ynumber)) {str[count]='T';	xnumber=xnumber+(double(double(1)/demon));  ynumber=ynumber+(double(double(1)/demon)); }

		count=count+1;
 		if ((abs(x)==abs(xnumber)) && (abs(y)==abs(ynumber))) {flag=1;}
 		 } 

	for (int i=0;i<count;i++) // reverses order of CGR output
		{
		str2[i]=str[count-1-i]; 
		}
		str2[count-1]='\0';
		 		
return string(str2); 
}

/// ******************************************************************///
/// ******************************************************************///


// end subroutines

int main (int argc, char * const argv[]) {

int interator=8;
int header=0;

	interator=atoi(argv[1]); 	
	header=atoi(argv[2]); 	
	ifstream in(argv[3]); 	
	ofstream out(argv[4]); 	

	int standard=300000;
	long double xnumber=0;
	long double ynumber=0;
	long double demon=0;
	long double i_demon=0;
	long double n;	      
	setprecision(60);
	int count[standard];
	int count2=0;
	long double a[standard];	

	string Seq;
	int c=0;	
	
	n=((double(1)/interator)*2);  // 4 ---> 0.5   16 --> 0.125  8 ---> 0.25

	long double start=-1;  //-1
	long double increment=0;
	increment=start;
	int interator2=interator*2;
	long double m=double(double(n)/2);
	
for (int y=0;y<interator2+1;y++) 
	{
	a[y]=increment; 
//	cout << "a[" << y << "]=" << a[y] << "\n";
	increment=increment+m;
	}	
if (header==1)
	{
	for (int y=0;y<interator2;y++) 
		{
		y=y+1;
		for (int x=0;x<interator2;x++) 
			{
			x=x+1;
			count2=count2+1;
			cout << convert_num_str(a[y],a[x])  << "\t";;			
			out << convert_num_str(a[y],a[x])  << "\t";;			
			}
		}
	cout << "\n";
	out << "\n";
	}
	
for (int y=0;y<interator+1;y++) 
	{
	a[y]=start+(y*n); 
//	cout << "a[" << y << "]=" << a[y] << "\n";
	}	

while(!in.eof())
    {
	xnumber=99;
	ynumber=99;
	int x=0; 
	int y=0;
	int number=0;
	
	in >> Seq;
	in >> xnumber;
	in >> ynumber;	
	
	for (int y=0;y<(interator);y++) 
		{
		for (int x=0;x<interator;x++) 
			{
			if ((xnumber>a[x]) && (xnumber<a[x+1]) && (ynumber>a[y]) && (ynumber<a[y+1])) {count[number]=count[number]+1;}
			number=number+1;
//			cout << setprecision(60) << xnumber << "\t" << a[x] << "\t" << a[x+1] << "\t";
//			cout << setprecision(60) << ynumber << "\t" << a[y] << "\t" << a[y+1] << "\n";			
			}	
		}
	}
	
	for (int i=0;i<(interator*interator);i++) 
		{
		c=count[i]+c;
		}
	
	cout << argv[3] << "\t" << interator<< "\t" ;
	out << argv[3] << "\t" << interator<< "\t" ;
	
	for (int i=0;i<(interator*interator);i++) // reverses order of CGR output
		{
//		out << count[i] << "\t";
		out << double(double(count[i])/c) << "\t";
		cout << count[i] << "\t";
		}
	cout << c << "\n";
	out << c << "\n";
	
	
   return 0;
}
