#include "Trapezoid.h"

double Trapezoid :: getArea()
{
	return .5 * (lengths[0] + lengths[1]) * (lengths[2]);
}
