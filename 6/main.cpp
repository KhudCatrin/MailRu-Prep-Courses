#include "Shape.h"
#include "Circle.h"
#include "Triangle.h"
#include <iostream>
#include <iomanip>
#include <vector>
#include <memory>
#include <cctype>



template<typename T, typename... Args>
std::unique_ptr<T> make_unique(Args&&... args)
{
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

int main() {
    std::vector<std::unique_ptr<Shape>> shapes;
    char ch;
    std:: cout<< "t for triangle, c for circle\nexample input: t(1,2,3),c(2) (WITHOUT SPACES);"<<
     "\nend of input - different char sequence\n";
    
    while (std::cin.get(ch)) {
        switch (ch) {
            char l_bracket, r_bracket;
            char comma;
            case 't':
                double a,b,c; 
                std::cin >> l_bracket >> a >> comma >> b >> comma >> c >> r_bracket >> comma;
                shapes.push_back(make_unique<trngl::Triangle>(a,b,c));
                break;
            case 'c':
                double r; 
                std::cin >> l_bracket >> r >> r_bracket >> comma;
                 shapes.push_back(make_unique<crcl::Circle>(r));               
                break;
            default:
                std::cout << "Unknown Shape" << std::endl;
                std::cin.setstate(std::ios_base::failbit);
                break;
        }
        
    }
    
   for (auto it = 0; it < shapes.size(); ++it) {
			shapes[it]-> ShowInfo();					
	}

    return 0;
}