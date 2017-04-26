#include "Shape.h"
#include "Circle.h"
#include <iostream>
#include <math.h>

static const double pi = 3.141592;

 crcl::Circle::Circle( double r) {
 	if ( r > 0) {
 		r_ = r;
 	}
 	else {
 		r_ =  0;
 	}
 	
 }


double crcl::Circle::FindPerimetr () {
	return r_ * 2 * pi;
}

double crcl::Circle::FindArea () {
	return pi* r_ * r_ ;
}

void crcl::Circle::ShowInfo  () {
	std::cout<<"\n\nRadius is "<<r_<<"\nPerimetr is "<<
	crcl::Circle::FindPerimetr()<<"\nArea is "<<crcl::Circle::FindArea()<<"\n";
}

