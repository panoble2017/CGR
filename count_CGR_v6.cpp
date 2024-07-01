#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <float.h>
#include <complex>
#include <iomanip>

// Copyright Peter A Noble November 2017, Tucson, Arizona

// g++ count_CGR_v6.cpp -o count_CGR 

// ./count_CGR 64 AAACAA Eya1_1_coord.txt AAACAA.txt

using namespace std;

double calx(char seq_interest[100]);
double caly(char seq_interest[100]);

/// ******************************************************************///
/// ******************************************************************///

double calx(char seq_interest[100])
{
	int length;
	length=strlen(seq_interest); 
	long double x=0;
	long double y=0;
	int z=0;

	for (int z=0;z<(length);z++) 
		{		
		if (seq_interest[z]=='A') {x=double(double(x-1)/2); y=double(double(y+1)/2);}
		if (seq_interest[z]=='T') {x=double(double(x+1)/2); y=double(double(y+1)/2);}
		if (seq_interest[z]=='G') {x=double(double(x-1)/2); y=double(double(y-1)/2);}
		if (seq_interest[z]=='C') {x=double(double(x+1)/2); y=double(double(y-1)/2);}		
		}

setprecision(30);	
return x; 
}

/// ******************************************************************///
/// ******************************************************************///

double caly(char seq_interest[100])
{
	int length;
	length=strlen(seq_interest); 
	long double x=0;
	long double y=0;
	int z=0;
	//cout << length << "\t"; 
	for (int z=0;z<(length);z++) 
		{		
		if (seq_interest[z]=='A') {x=double(double(x-1)/2); y=double(double(y+1)/2);}
		if (seq_interest[z]=='T') {x=double(double(x+1)/2); y=double(double(y+1)/2);}
		if (seq_interest[z]=='G') {x=double(double(x-1)/2); y=double(double(y-1)/2);}
		if (seq_interest[z]=='C') {x=double(double(x+1)/2); y=double(double(y-1)/2);}		
		}

return y;
}

/// ******************************************************************///
/// ******************************************************************///
// end subroutines


int main (int argc, char * const argv[]) {

int standard=100;
int interator=0;
char* seq_interest = new char[standard];

	interator=atoi(argv[1]); 	//cout << interator << "\t";
	seq_interest=argv[2]; 		//cout << seq_interest << "\t"; 
	ifstream in(argv[3]); 	
	ofstream out(argv[4]); 	

	cout << setprecision(30) << argv[3] << "\t" << seq_interest << "\tx=" << calx(seq_interest) << "\ty=" << caly(seq_interest) << "\n"; //exit(0);
	 out << setprecision(30) << argv[3] << "\t" << seq_interest << "\t" << calx(seq_interest) << "\t" << caly(seq_interest) << "\t"; //exit(0);

	long double xnumber=0;
	long double ynumber=0;
	long double demon=0;
	long double i_demon=0;
	long double n;	   //0.25 --> 8  //0.25 -->16   
	int x=0; 
	int y=0;
	int number=0;
	
	int count;
	long double a[20];	

	char* Seq = new char[standard];
	int c=0;
	long double scale=0.5;	
	char str[100];
	char str2[100];
	long double start=calx(seq_interest);  //-0.5

	n=((double(1)/interator));  // 4 ---> 0.5   16 --> 0.125  8 ---> 0.25

	count=0;
	int numbers=0;

while(!in.eof())
    {
	xnumber=99;
	ynumber=99;
	x=0; 
	y=0;
	number=0;
	
	in >> xnumber;
	in >> ynumber;	
	in 	>> Seq;	

	if ((xnumber>calx(seq_interest)-n) && (xnumber<(calx(seq_interest)+n)) && (ynumber>(caly(seq_interest)-n)) && (ynumber<(caly(seq_interest)+n))) 
		{
		count=count+1;	cout << Seq << "\n";
		}
	numbers=numbers+1; 
	}

	cout << count << "\t" << numbers << "\n";
	out << count << "\t" << numbers << "\n";

   return 0;
}
