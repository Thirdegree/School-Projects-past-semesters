#include <iostream>
#include <fstream>
#include <string>

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

int main() {
    int t = (5||1) * 5;
    if (t==5) {
        cout << "works";
    } else {
        cout << t;
    }
    return 0;
}