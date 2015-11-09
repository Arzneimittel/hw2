#include <iostream>
#include <fstream>
using namespace std;

int main(){
	double x0 = 0.5;
	double k;
	int Nskip = 100; //Number of iterations to skip
	int Nend  = 200; //Number of total iterations
	double x[(Nend-Nskip)];
	ofstream out("output.txt");

	for(double r=0; r <= 4; r += 0.001){
	   k=x0;
	   for(int i=1; i <= Nskip; i++)
		   k = r*k*(1-k);
	   for(int i=0; i <(Nend-Nskip); i++){
	   		   x[i] = r*k*(1-k);
			   k=x[i];
	   		   //cout << r << "\t" << x[i-(Nend-Nskip)-1] << endl;
   	       }
   	       
   	   for(int i=0; i<(Nend-Nskip); i++){
	      out << r << "\t" << x[i] << endl;
	       }  
	}
	out.close();
	return 0;
}