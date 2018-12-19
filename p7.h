
#include <iostream>
#include <fstream>
#include <cstring>
#include <cstdlib>
#include "/ee259/tools/pro_7/sample_p6_mod.h"

using namespace std;


      ofstream outstream("out_71", ios::out);

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
  
    for(i = 0; i<np; i++)
    {
        S1 += (X[i]*X[i]);
        S2 += X[i];
        S3 +=(X[i]*Y[i]);
        S4 +=X[i];
        S5 += 1;
        S6 += Y[i];
    }
    // calculate the S1-S6 values

    ofstream out_s_file("in.6", ios::out);
  
    out_s_file<<S1<<" "<<S2<<endl;
    out_s_file<<S4<<" "<<S5<<endl;
    out_s_file<<S3<<endl;
    out_s_file<<S6<<endl;
  
    out_s_file.close();

    LINEAR_SOLVER L(2);
    L.SOLVE_LINEAR_EQUATION("NONE");


    ifstream input_solver("out.6",ios::in);
 	 

	int k;
 	int number_of_lines ;
 	number_of_lines =0;
 	string line_1;
 	ifstream myfile("out.6", ios::in);

	while(getline(myfile, line_1))
  	  ++number_of_lines;
  
	  myfile.close();

	for(k=0; k<(number_of_lines -3);k++)
	{
		getline(input_solver, line_1);
	}

	input_solver >> line_1;
	input_solver >> m;
	input_solver >> line_1;
	input_solver >> b;

	input_solver.close();
cout<< "OPENING OUT_7 FILE" << endl;


    outstream<<"LEAST_SQUARE_FIT RESULT:"<<endl;
    outstream<<"USING INHERITANCE:"<<endl;
    outstream<<"MATCHING FUNCTION IS Y  = "<< setprecision(2)<<setiosflags(ios::fixed | ios::showpoint) << m << "*"<<" X + "<<b<<endl;

    for(i=0;i<np;i++)
    {
    	error += pow((Y[i]-(m*X[i])-b),2);
    }
  
    outstream<<"THE ERROR FROM LS_FIT_BY_ME METHOD IS "<<setprecision(3)<<setiosflags(ios::fixed | ios::showpoint) << error <<endl;
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



    output_file<<"x=[";

    for(i=0;i<np;i++)

    {

        output_file<<X[i];

        if(i != np-1)

        {

            output_file<<",";

        }

        else{}

    }

    output_file<<"];"<<endl;

  

    output_file<<"y=[";

    for(i=0;i<np;i++)

    {

        output_file<<Y[i];

        if(i != np-1)

        {

            output_file<<",";

        }



        else{}

    }





    output_file<<"];"<<endl;

  

    output_file<<"coef=polyfit(x,y,1);"<<endl;

    output_file<<"m=coef(1);"<<endl;

    output_file<<"b=coef(2);"<<endl;

    output_file<<"Y=m*x+b;"<<endl;

    output_file<<"matlab_error=sum((y - Y).^2);"<<endl;

    output_file<<"fid=fopen('out_71','a');"<<endl;

    output_file<<"fprintf(fid,'*** RESULT FROM MATLAB\\n');"<<endl;

    output_file<<"fprintf(fid,'*** THE MATCHING FUNCTION IS Y=(%.3f) * X +(%.3f) \\n',m,b);"<<endl;

    output_file<<"fprintf(fid,'*** THE ERROR FROM MATLAB IS %.3f \\n', matlab_error);"<<endl;

 	output_file.close();



    system("/bin/csh /ee259/tools/pro_7/run_mat_1");



    outstream.close();

    outstream.open("out_71", ios::app);

}

