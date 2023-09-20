// Exercise 12.13 Solution: exl3_13.cpp
// Driver to test Shape hierarchy
#include <iostream> 
#include <array> 
#include "Shape.h" 
#include "TwoDimensionalShape.h" 
#include "ThreeDimensionalShape.h" 
#include "Circle.h" 
#include "Square.h" 
#include "Sphere.h" 
#include "Cube.h" 

using namespace std;

int main()
{
    array <Shape*, 4 > shapes;
    shapes[0] = new Circle(3.5, 6, 9);
    shapes[1] = new Square(12, 2, 2);
    shapes[2] = new Sphere(5, 1.5, 4.5);
    shapes[3] = new Cube(2.2);

    for (int i = 0; i < 4; ++i)
    {
        cout << *shapes[i] << endl;

        TwoDimensionalShape* twoDimensionalShapePtr = dynamic_cast <TwoDimensionalShape*>(shapes[i]);

        if (twoDimensionalShapePtr != 0)
            cout << "Area:" << twoDimensionalShapePtr->getArea() << endl;

        ThreeDimensionalShape* threeDimensionalPtr = dynamic_cast<ThreeDimensionalShape*>(shapes[i]);

        if (threeDimensionalPtr != 0)
        {
            cout << "Area:" << threeDimensionalPtr->getArea()
                << "\nVolume : " << threeDimensionalPtr->getVolume()
                << endl;
            cout << endl;
        }

        system("pause");





    }
}