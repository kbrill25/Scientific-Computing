#ifndef QUADRILATERAL_H
#define QUADRILATERAL_H

class Quadrilateral
{
	protected:
	double lengths [4];

	public:
	void setLengths(double, int);
	virtual double getArea() {}
};
#endif
