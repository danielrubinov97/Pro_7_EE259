//
// SKELETON FOR PROJECT 7
//

#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "/ee259/tools/pro_7/sample_p6_mod.h"

using namespace std;

class EZ_CURVE_FIT: public LINEAR_SOLVER
{
   public:
	EZ_CURVE_FIT(int); // constructor; 
		// example: s.EZ_CURVE_FIT(5);
		// there are 5 pairs of data points;

	void LS_FIT_BY_ME(char *); 
		// example: s.LS_FIT_BY_ME("data_file");
		// perform least squares fit using inheritance 
		// data is in "data_file";
		
	void LS_FIT_BY_MATLAB (char *); 
		// example: s.LS_FIT_BY_MATLAB("data_file);
		// perform least squares fit using MATLAB; 
		
   private:
	int np; // number of data pairs
};
 
// constructor code 
EZ_CURVE_FIT::EZ_CURVE_FIT(int x)
	:LINEAR_SOLVER("in.6", 2) // initialize base class LINEAR_SOLVER;
				  // we need to solve a linear equation 
				  // system of AX=B, for a 2x2 A matrix 
{
        np = x;
}

void EZ_CURVE_FIT::LS_FIT_BY_ME(char * data_file)
{
	float S1, S2, S3, S4, S5, S6, error;
	error=S1=S2=S3=S4=S5=S6=0.0;
	float X[15], Y[15];
	int i, j;
	
	float m, b;		
	ifstream input_file(data_file, ios::in);   
	
	 for(i=0; i<np; i++)
        {
        	input_file >> X[i]>> Y[i];
        }
	
	// calculate the S1-S6 values:


	// put them into a in.6 in the format that sample_p6_mod.h
	// will read them:

	ofstream out_s_file("in_temp.6", ios::out);
	
	
	// declare an LINEAR_SOLVER object:

	
	// access results from SOLVE_LINEAR_EQUATION in out.6 file:


	// get the results from out.6 file and enter into out_7.txt file:
	ofstream output("out_7.txt", ios::out);



}

void EZ_CURVE_FIT::LS_FIT_BY_MATLAB(char * file_name)
{
   float X[50],Y[50];
   int i,j;
   
   ifstream input_file(file_name,ios::in);
   
   for (i=0;i<np;i++)
   {
   	input_file >> X[i] >>Y[i];
   }
    
   ofstream output_file("mat_1.m",ios::out); 

   // populate mat_1.m file:


   // run matlab with mat1_1.m file that you created:
   system("/bin/csh /ee259/tools/pro_7/run_mat_1");
}

