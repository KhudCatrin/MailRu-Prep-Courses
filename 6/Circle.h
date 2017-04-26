#ifndef _CIRCLE_H_
#define _CIRCLE_H

namespace crcl {
  class Circle: public Shape {
  public:
 	  Circle(double r);
 	  void ShowInfo ();
	  double FindPerimetr();
	  double FindArea ();
	  double r_;     
  };
 }

#endif //_CIRCLE_H_

