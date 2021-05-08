// C++ Program to print the elements of a 
// Two-Dimensional array 
#include<iostream> 
using namespace std; 
  
int main() 
{ 
    //------- solve Ax = b using 'naive' Gauss elimination -------//

    // size of square matrix (the augmented matrix has an extra column)
    int n = 3;

    // initialize solution matrix
    double x[3];

    // augmented matrix [A|b]
    double Atild[3][4] = {{10,2,-1,-27},{-3,-5,2,-61.5},{1,1,6,-21.5}};

    //------- forward substitution algorithm -------//

    // loop through rows
    for (int k = 0; k < n-1; k++)
    {
	// place the partial pivoting loop here
	int p = k;
	for(int g = k+1; g < n; g++)
	{
		if(abs(Atild[g][k]) > abs(Atild[p][k]))
		{
			p = g;
		}
	}
	if(p != k)
	{
		for(int q = 0; q < n + 1; q++)
		{
			double temp = Atild[k][q];
			Atild[k][q] = Atild[p][q];
			Atild[p][q] = temp;
		}
	}

        for (int i = k+1; i < n; i++)
        {
            // compute the factor eliminates x_{k}
            double gamma = Atild[i][k] / Atild[k][k];

            // multiply kth row and subtract from ith
            for (int j = k; j < n+1; j++)
            {
                Atild[i][j] = Atild[i][j]
                                - gamma*Atild[k][j];
            }
        }
    }

    // print the elements of augmented matrix
    for (int i = 0; i < n; i++) 
    { 
        for (int j = 0; j < n+1; j++) 
        { 
            cout << "Element at A[" << i 
                 << "][" << j << "]: "; 
            cout << Atild[i][j] << endl;
        } 
    } 

    //------- back substitution algorithm -------//
	// calculate unknown in last equation (indexing uses minus 1)
	x[n-1] = Atild[n-1][n]/Atild[n-1][n-1];
	for(int i = n-2; i >= 0; i--)
	{
		double s = 0.0;
		for(int j = i+1; j < n; j++)
		{
			s+= Atild[i][j] * x[j];
			x[i] = (Atild[i][n]-s)/Atild[i][i];


		}
	}

	for(int i = 0; i < n; i++)
	{
		cout<<x[i]<<endl;
	}

    return 0; 
} 
