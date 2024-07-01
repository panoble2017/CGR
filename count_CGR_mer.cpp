#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <float.h>
#include <complex>
#include <iomanip>

// Copyright Peter A Noble January 2018, Tucson, Arizona

// g++ count_CGR_mer.cpp -o count_CGR_mer 

//  ./count_CGR_mer AAACCA Eya1_1_CGR.txt AAACCA.txt

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
	//cout << length << "\t"; 
	for (int z=0;z<(length);z++) 
		{		
		if (seq_interest[z]=='A') {x=double(double(x-1)/2); y=double(double(y+1)/2);}
		if (seq_interest[z]=='T') {x=double(double(x+1)/2); y=double(double(y+1)/2);}
		if (seq_interest[z]=='G') {x=double(double(x-1)/2); y=double(double(y-1)/2);}
		if (seq_interest[z]=='C') {x=double(double(x+1)/2); y=double(double(y-1)/2);}		
		}

//		x=-0.74445209646088439381372836578520946204662322998046875;	y=0.74370699134964890486543254155549220740795135498046875;

setprecision(60);	
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
setprecision(60);	
return y;
}

/// ******************************************************************///
/// ******************************************************************///

// end subroutines


int main (int argc, char * const argv[]) {

int standard=100;
int interator=0;
char* seq_interest = new char[standard];

	seq_interest=argv[1]; 	
	ifstream in(argv[2]); 	
	ofstream out(argv[3]); 	

	long double xnumber=0;
	long double ynumber=0;
	long double demon=0;
	long double i_demon=0;
	long double n;	   //0.25 --> 8  //0.25 -->16   
	
	int count;
	long double a[20];	

	char* Seq = new char[standard];
	int c=0;
	long double scale=0.5;	
	char str[100];
	char str2[100];
	long double start;

	interator=strlen(seq_interest);
	demon=pow(2.0,interator);
	out << interator << "\t"<< seq_interest << "\t" ;//exit(1);
	cout << seq_interest << "\t" ;//exit(1);
	
	start=calx(seq_interest);  

	n=((double(1.0)/(demon))); 
	
count=0;
int numbers=0;

while(!in.eof())
   {
	xnumber=99;
	ynumber=99;
	int x=0; 
	int y=0;
	strcpy(Seq,"  ");
	int number=0;
	in >> Seq;	
	in >> xnumber;
	in >> ynumber;	

	if ((xnumber>(calx(seq_interest)-n)) && (xnumber<(calx(seq_interest)+n)) && (ynumber>(caly(seq_interest)-n)) && (ynumber<(caly(seq_interest)+n))) 
		{
		count=count+1;	//cout << Seq << "\n"; 
		}
	numbers=numbers+1; 
	}
	cout << count << "\t" << numbers << "\n";
	out << count << "\t" << numbers << "\n";

  return 0;
}
