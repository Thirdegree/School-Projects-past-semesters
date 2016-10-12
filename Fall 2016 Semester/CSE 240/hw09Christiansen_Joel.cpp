// Joel Christiansen

#include <iostream>
#include <fstream>
#include <string>
#include <math.h>//used to define pi

# define PI 3.1415

using namespace std;

// Please read the Word document in the homework folder for the structure of the classes and the linked list
class Shape{
    public:
    //initialize virtual area function
    virtual float area()
    {
        return 0;
    }

    //initialize virtual displayInfo function
    virtual void displayInfo(){ }
};

// Q1 : Circle Class (derived from Shape) : (5 points)
// - Create a constructor for Circle that will accept 1 float parameter
//   Use this float parameter to initialize the 'radius' value of the Circle
//
// - Create a setRaduis() function that will accept 1 float parameter
//   Use this float parameter to set the 'radius' value of the Circle
//   NOTE: This function will have no return value
//
// - Create an area() function that returns a float value
//   The area of a Circle is calculated by (PI * radius * radius)
//   IMPORTANT: You MUST use the macro PI that has already been defined above
class Circle : public Shape{
    private:
        float radius;

    public:
    // Create Circle constructor here
    Circle(float radius) {
        this->radius = radius;
    }
    // Create setRadius() function here ( NOTE : function MUST be named setRadius )
    //void setRadius(int )
    void setRadius(int radius) {
        this->radius = radius;
    }
    // Create area() function here ( NOTE : function MUST be named area() )
    float area() {
        return PI * radius * radius;
    }

    virtual void displayInfo()
    {
        cout << "Circle Radius: " << radius << endl;
        cout << "Circle Area: " << area() << endl;
    }
};

// Q2 : Rectangle Class (derived from Shape) : (5 points)
// - Create a constructor for Rectangle that will accept 2 float parameters
//   Use these float parameters to initialize the 'base' and 'height' values of the Rectangle
//
// - Create getters and setters for the 'base' and 'height' values
//   The setters will accept 1 float parameter and return nothing
//   The getters will accept no parameters and return a float value
//
// - Create a area() function that returns a float value
//   The area of a Rectangle is calculated by (base * height)
class Rectangle : public Shape{
private:
    float base;
    float height;

public:
    // Create Rectangle constructor here
    Rectangle(float base, float height) {
        this->base = base;
        this->height = height;
    }
    // Create setBase ( NOTE : function MUST be named setBase )
    void setBase(float base) {
        this->base = base;
    }
    // Create setHeight ( NOTE : function MUST be named setHeight )
    void setHeight(float height) {
        this->height = height;
    }
    // Create getBase() ( NOTE : function MUST be named getBase() )
    float getBase() {
        return base;
    }
    // Create getHeight() ( NOTE : function MUST be named getHeight() )
    float getHeight() {
        return height;
    }
    // Create area() function here ( NOTE : function MUST be named area() )
    float area() {
        return base*height;
    }

    void displayInfo()
    {
        cout << "Rectangle Base: " << base << endl;
        cout << "Rectangle Height: " << height << endl;
        cout << "Rectangle Area: " << area() << endl;
    }
};

// Q3 : Square Class (derived from Rectangle) : (10 points)
// - Create a constructor for Square that will accept 1 float parameter for any given side of a Square
//   Hint: Use the superclass Rectangle constructor and send the side value for both parameters
//
// - Create a setSides() function that will accept 1 float parameter
//   Use the superclass Rectangle functions setBase and setHeight to set the side values given the parameter
//   NOTE: This function will have no return value
//
// - Create an area() function that returns a float value
//   The area of a Square is calculated by (side * side)
//   Use the superclass Rectangle functions getBase() and getHeight() functions for your side values
//   NOTE: In order for this to work properly, you must have completed the previous 2 steps as desribed
class Square : public Rectangle{
public:
    // Create Square constructor here
    Square(float side):Rectangle(side, side) {}
    // Create setSides ( NOTE : function MUST be named setSides )
    void setSides(float side) {
        setHeight(side);
        setBase(side);
    }
    // Create area() function here ( NOTE : function MUST be named area() )
    float area() {
        return getBase()*getHeight();
    }
    void displayInfo()
    {
        cout << "Square Base: " << getBase() << endl;
        cout << "Square Height: " << getHeight() << endl;
        cout << "Square Area: " << area() << endl;
    }
};

class ShapeList{
public:
    //ShapeNode is a struct "linked list" containing Shapes
    struct ShapeNode{
        Shape* shape;
        ShapeNode* next;
    } *list = NULL;

    ~ShapeList(){ cleanUp(); } //   destructor
    void helper(); //               declare helper function
    void insert(Shape*); //         declare insert function
    void display(); //              declare display function
    void cleanUp(); //              declare cleanUp function
    struct ShapeNode* getList() { return list; }
};

// The helper function is used to determine which type of shape is to be inserted
// It creates a new temp shape pointer and calls insertion() sending it as a parameter
// There is no implementation needed here, but you should trace it and know how it works
void ShapeList::helper()
{
    //prompt input
    int type = 0;
    cout << "Enter shape type" << endl;
    cout << "1. Circle" << endl;
    cout << "2. Rectangle" << endl;
    cout << "3. Square" << endl;
    cin >> type;

    while (type < 1 || type > 3)
    {
        cout << "Invalid shape type" << endl;
        cin >> type;
    }

    // create new temp shape
    Shape* s = NULL;

    float rad, base, height;

    // determine shape type
    if (type == 1)//circle
    {
        cout << "Enter radius: ";
        cin >> rad;
        s = new Circle(rad);
    }
    else if (type == 2)//rectangle
    {
        cout << "Enter base: ";
        cin >> base;
        cout << "Enter height: ";
        cin >> height;
        s = new Rectangle(base, height);

    }
    else//square
    {
        cout << "Enter side: ";
        cin >> base;
        s = new Square(base);
    }

    insert(s);
}

// Q4 : insert function : (10 points)
// Use the temp pointer p provided to add to your 'list' at the end of the list
// IMPORTANT: You MUST insert the new node at the end of the list
void ShapeList::insert(Shape* s)
{
    ShapeNode* p = new ShapeNode();
    p->shape = s;
    p->next = NULL;
    ShapeNode* tempList = list;
    if (tempList == NULL) {
        list = p;
    } else {
        while (tempList->next != NULL) {
            tempList = tempList->next;
        }
        tempList->next = p;
    }

}

// Q5 : display function : (10 points)
// Use the temp pointer p provided to traverse your 'list' and display the info for each shape
// Use the displayInfo() function that is already defined in each shape's class
// Example display format:
//  Rectangle Base: 5
//  Rectangle Height: 10
//  Rectangle Area: 50
//
//  Circle Radius: 5
//  Circle Area: 78.5375
void ShapeList::display()
{
    ShapeNode* p = list;
    while (p!=NULL) {
        p->shape->displayInfo();
        p = p->next;
    }
}

// Q6 : cleanUp function : (10 points)
// Traverse your 'list' and delete all memory to ensure no memory leaks
// This function will be called in your destructor automatically upon exiting the program
void ShapeList::cleanUp()
{
    while (list!=NULL) {
        delete list->shape;
        ShapeNode* tempList = list->next;
        delete list;
        list = tempList;
        delete tempList;
    }
}

int main()
{
    //_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF); // Use to check for memory leaks in VS

    ShapeList newList; // new list of shapes

    int input = 0; // prompts user for input

    while (input != 3)
    {
        cout << "Enter one of the following" << endl;
        cout << "1. Insert shape" << endl;
        cout << "2. Display shapes" << endl;
        cout << "3. Quit" << endl;

        cin >> input;

        if (input == 1) newList.helper();
        else if (input == 2) newList.display();
        else if (input == 3) cout << "Goodbye";
        else cout << "Invalid choice" << endl;
    }
    return 0;
}