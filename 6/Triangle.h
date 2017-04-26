#ifndef _TRIANGLE_H_
#define _TRIANGLEE_H

namespace trngl{
	class Triangle: public Shape {
	  public:
 	  Triangle(double a, double b, double c);
 	  void ShowInfo ();
	  double FindPerimetr();
	  double FindArea ();
	  double a_,b_,c_;     
  };
}
#endif// _TRIANGLE_H_ 