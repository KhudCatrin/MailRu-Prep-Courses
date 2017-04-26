#include "Shape.h"
#include "Triangle.h"
#include <iostream>
#include <math.h>

trngl::Triangle::Triangle( double a, double b, double c ) {
	if( ( a > 0) && ( b > 0 ) && ( c > 0 ) ) 
	{
		a_ = a;
	    b_ = b;
	    c_ = c;
	}
	else 
	{
		a_ = 0;
		b_ = 0;
		c_ = 0;
	}
}

void trngl::Triangle::ShowInfo () {
	std::cout<<"\n\nSides: "<<"\n a = "<<a_<<"\n b = "<< b_ << 
	"\n c = "<<c_ << "\nPerimetr is "<<
	trngl::Triangle::FindPerimetr()<<"\nArea is "<<trngl::Triangle::FindArea()<<"\n";
}

double trngl::Triangle::FindPerimetr  () {
	return ( a_ + b_ +c_);
}

double trngl::Triangle::FindArea () {
	double p = (a_ + b_ + c_)/2;
	double S = sqrt(p * ( p - a_) * ( p - b_) * ( p - c_));
	if ( S > 0) {
		return S;
	}
		
	else {
		return -1;
	}
}