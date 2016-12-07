// Joel Christiansen

#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

// READ BEFORE YOU START:
// A polyhedron is is a three-dimensional solid figure in which each side is a flat surface 
// (source: http://www.regentsprep.org/regents/math/geometry/gg2/polyhedra.htm)
//
// This program takes inputs for the height and 4 side values of a polyhedron. It uses these values to determine if the values are for a triangular, square, or 
// rectangular polyhedron. Do not worry if you are not familiar with these formulas, as the formulas have been provided to you in comments. If the input is
// for a Triangular polyhedron, any one of the given sides will be 0. You can also assume that the input sides for the base of a Triangular polyhedron will be for 
// a right triangle. You can also assume that no input will be less than 0. You can also assume that the input types will be valid. If the input is for a Square 
// polyhedron all of the sides will be even. If the input is for a Rectangular polyhedron any given side will have exactly 1 more equal side.
//
// Example Triangular Polyhedron input: 3, 5, 0, 4
// Example Square Polyhedron input: 5.75, 5.75, 5.75, 5.75
// Example Rectangular Polyhedron input: 3.8, 4.9, 3.8, 4.9

using namespace std;

// enumeration type used to determine the shape of the polyhedron
enum Shape { Triangular, Square, Rectangular };

class Polyhedron
{
    private:
        // private local variables
        float side1;
        float side2;
        float side3;
        float side4;
        float height;
        float sides[4];

    public:
        // setters
        void setSide1(float s) { side1 = s; }
        void setSide2(float s) { side2 = s; }
        void setSide3(float s) { side3 = s; }
        void setSide4(float s) { side4 = s; }
        void setSides() {
            sides[0]=side1;
            sides[1]=side2;
            sides[2]=side3;
            sides[3]=side4;
        }
        void setHeight(float h) { height = h; }

        // getters
        float getSide1() { return side1; }
        float getSide2() { return side2; }
        float getSide3() { return side3; }
        float getSide4() { return side4; }
        float getHeight() { return height; }

        // Q1 : 10 points
        // TypeChecker returns an enum shape type based on the side values
        // Hints:
        // If any one of the side values is 0, then it is Triangular
        // If all of the sides are equal, then it is Square
        Shape TypeChecker()
        {
            if (side1==side2 && side1==side3 && side1==side1) {
                return Square;
            }
            if (side1==0 || side2==0 || side3==0 || side4==0) {
                return Triangular;
            }
            return Rectangular;
        }

        // Q2 : 20 points
        // BaseArea returns the float value of the area of the base of the polyhedron
        // Use the temp enum type returned from TypeChecker() and the switch statement given
        // You are only determining the area of the base here (a 2D figure)
        //
        // Area of a Triangle:
        // You can assume that the input sides of a triangle are for a right triangle
        // You can find the area of a triangle by multiplying the 2 shorter sides, and dividing that product by 2.
        // For example : if your side values are 5, 3, 0, 4  then you would compute the area as ((3*4)/2)
        // Keep in mind that any of the side values can be 0
        //
        // Area of a Square:
        // You can find the area of a square by multipling any 2 sides together
        //
        // Area of a Rectangle:
        // You can find the area of a rectangle by multiplying any 2 non-equal sides
        // Keep in mind that for a shape to be a rectangle, for any side, there is exactly 1 more equal side.
        // For example : 2, 2, 6, 6  or  13.675, 12.5, 13.675, 12.5
        float BaseArea()
        {
            Shape temp = TypeChecker();
            switch (temp)
            {
                case Triangular:
                    setSides();
                    sort(sides, sides+5, greater<float>());
                    return sides[1]*sides[2]/2;

                case Rectangular:
                    if (side1!=side2) {
                        return side1*side2;
                    }
                    if (side1!=side3) {
                        return side1*side3;
                    }
                case Square:
                    return side1*side1;

            }
        }



        // Q3 : 5 points
        // The area of a pyramid is calculated as ((baseArea * height) / 3) for all polyhedrons
        float PyramidVolume(float baseArea)
        {;
            return baseArea*height/3;
        }

        // Q4 : 5 points
        // The area of a prism is calculated as (baseArea * height) for all polyhedrons
        float PrismVolume(float baseArea)
        {
            return baseArea*height;
        }

};

int main()
{
    Polyhedron polyhedron; // new polyhedron object
    float side = 0;
    float height = 0;

    // Q5 : 10 points
    // Convert all C input/output (printf/scanf) to C++ input/output (cin/cout) in this main method.
    // (this includes the 3 C output (printf) used near the end of the main method.)
    // Your C++ input/output must be equivalent to the given C input/output.

    printf("Enter the sides of the base of the polhedron:");
    printf("\nIf the polhedron is triangular, please enter 0 for any given side.");

    cout<<"\nSide 1: ";
    cin>>side;
    polyhedron.setSide1(side);

    cout<<"\nSide 2: ";
    cin>>side;
    polyhedron.setSide2(side);

    cout<<"\nSide 3: ";
    cin>>side;
    polyhedron.setSide3(side);

    cout<<"\nSide 4: ";
    cin>>side;
    polyhedron.setSide4(side);

    cout<<"\nHeight: ";
    cin>>height;
    polyhedron.setHeight(height);
    //polyhedron.setSides();

    Shape temp = polyhedron.TypeChecker();
    string shape;

    switch (temp)
    {
    case Triangular:
        shape = "Triangular Polyhedron";
        break;
    case Square:
        shape = "Square Polyhedron";
        break;
    default:
        shape = "Rectangular Polyhedron";
        break;
    }

    float baseArea = polyhedron.BaseArea();
    float pyramidVolume = polyhedron.PyramidVolume(baseArea);
    float prismVolume = polyhedron.PrismVolume(baseArea);

    cout<<"\nThis is a " << shape.c_str(); // c_str() is used to convert a string to char *
    cout<<"\nThe volume of this pyramid is: " << pyramidVolume;
    cout<<"\nThe volume of this prism is: " << prismVolume << "\n";

    return 0;
}