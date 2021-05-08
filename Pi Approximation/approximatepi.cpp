#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iomanip>

using namespace std;

// number of darts to throw
#define Ntot 1e6

// function to approximate pi
void approxpi(double &pi, double tot)
{
	int Nhit = 0;

	// initialize random seed
	srand(time(NULL));

	// throw darts
	for (int i = 0; i < Ntot; i++)
	{

		// generate random numbers for x and y
		double x = ((double) rand()/(RAND_MAX));
		double y = ((double) rand()/(RAND_MAX));

		// check if the random numbers lie in the circle, if so, increase counter
		if ( (sqrt((pow(x-.5,2)) + (pow(y-.5,2))) < .5))
		{
			Nhit++;
		}
	}

	// compute pi
	pi = 4 * (double)Nhit/tot;
}

int main()
{
	// declare mypi value
	double mypi = 0.0;

	// call function
	approxpi(mypi, Ntot);

	// output results
	cout<<"The value of pi after " << Ntot << " iterations is: " << mypi<< endl;
}
