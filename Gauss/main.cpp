#include <math.h>
#include <iostream>
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Trapezoid.h"
using namespace std;

double integrand(double x)
{
	return pow(x,4.0);
}

int main()
{
	// subintervals
	int n = 40;

	// limits of integration
	double xlo = 0;
	double xhi = 1;

	// determine dx
	double dx = (xhi-xlo)/n;

	// sum
	double mSum = 0.0;
	double tSum = 0.0;
	
	// create object of type rectangle
	Rectangle rec;

	// mid point Riemann sum
	for(int i = 0; i < n; i++)
	{
		double x = xlo + i*dx;
		double xm = x + (dx/2.0);
		rec.setLengths(integrand(xm),0);
		rec.setLengths(dx,1);
		mSum += rec.getArea();
	}

	// create object of type trapezoid
	Trapezoid trap;

	//Trapezoidal rule
	for(int i = 0; i < n; i++)
	{
		double x = xlo + i*dx;
		trap.setLengths(integrand(x),0);
		trap.setLengths(integrand(x+dx),1);
		trap.setLengths(dx,2);
		tSum += trap.getArea();
	}
	
	// print the output
	cout << "The area using the midpoint sum is: " << mSum << endl;
	cout << "The area using the trapezoidal sum is: " << tSum << endl;
	return 0;
}
