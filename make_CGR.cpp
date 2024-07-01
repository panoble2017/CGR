#include <fstream>
#include <string>
#include <iostream>
#include <math.h>
#include <cstdlib>
#include <float.h>
#include <complex>
#include <iomanip>

// Copyright Peter A Noble January, 2018 Tucson Arizona

// g++ make_CGR_new.cpp -o make_CGR

// ./make_CGR test.fna
// ./make_CGR wierd_OP_mouse.fna

// ./make_CGR sign_genes3.fna
// ./make_CGR A_55_P2423586_Eya1_1.fna
// ./make_CGR test.fna
// ./make_CGR A_52_P212756_Tor1aip2_1.fna
// ./make_CGR mouse_brain_for_CGR.txt

using namespace std;

int main (int argc, char * const argv[]) {
	ifstream in(argv[1]); 		
	ofstream outfile; 	

	long double x=0;
	long double y=0;

	char ProbeID2[100];	
	int standard=50000;
	int x1;
	int size_t=100;
	
	char ProbeID[100];
	char Seq[standard];
			
	int size=0;
	int count=1;
	int number;

	string R;
	char* S = new char [R.length() +1];
	int first_time=0;	
	int length;
	int size2=1;
	int firsttime=0;
	
while(!in.eof())
	{
	in >> ProbeID;
	in >> Seq;
	length=strlen(ProbeID);
	string S(ProbeID,length);
	S += "_CGR.txt";
	outfile.open(S.c_str(), ios::app);
	size=strlen(Seq);

	x=0.0;
	y=0.0;
		
	for (int z=0; z<(size);z++)
		{
		if (Seq[z]=='A') {x=double(double(x-1)/2); y=double(double(y+1)/2);}
		if (Seq[z]=='T') {x=double(double(x+1)/2); y=double(double(y+1)/2);}
		if (Seq[z]=='G') {x=double(double(x-1)/2); y=double(double(y-1)/2);}
		if (Seq[z]=='C') {x=double(double(x+1)/2); y=double(double(y-1)/2);}		
		cout << Seq[z] << "\t" <<  x << "\t" << y << "\n"; 
		outfile << setprecision(60)  << Seq[z] << "\t" <<  x << "\t" << y << "\n"; 
		count=count+1;		
		}
	outfile.close();
	}		
	
    return 0;
}
