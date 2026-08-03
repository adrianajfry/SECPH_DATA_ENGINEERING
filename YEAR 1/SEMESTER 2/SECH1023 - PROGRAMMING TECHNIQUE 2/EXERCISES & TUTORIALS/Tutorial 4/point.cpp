
#include <iostream>
#include <cmath>

using namespace std;

// 1. Declare a class that represents a 2D point with the following methods.
//
//    (a). A default constructor that sets the coordinates x and y to 0
//    (b). A constructor that accepts only one parameter. This constructor uses
//         the parameter to set both x and y coordinates
//    (c). A constructor that accepts two parameters to initialize the coordinates x and y respectively
//    (d). A destructor that does nothing
//
//    (e). A method that perfoms an addition operation of two points. Point additions is done by
//         adding the coordinates, respectively. This method returns the result as another point
//         e.g. let p1 =(1, 2) and p2 (4, 0).   Adding p1 and p2 results in p3=(5, 2)
//
//    (f-i). A method that perfoms a scaling operation to the point by multiplying the coordinates x and y
//         with a number. This method returns the result as another point.
//         e.g.  Multiplying p1 with 2.5 results in a point of (2.5 , 5.0)
//    (f-ii). A method that perfoms a conversion from the object to an int. The conversion will be done as the square root 
//         of the sum of squared of the coordinates x and y. i.e., value = sqrt( x^2 + y^2)
//         e.g.  int d = p1 => d will result in 2.236

// UP TO (F)
//
//    (g) The same method from (e), but this time using an overloaded operator +
//
//    (h) The same method from (g), but this time using an overloaded operator *
//
//    (i) A method that prints the coordinates x and y
//
// 2. Define a regular function that calculates the distance between two points. Specify this function as a friend to the class
//    Do google on pythagoras theorem, to know the formula about finding the distance
//
// 3. Test the class (from 1) and the function (from 2) in the main function by
//    (a). Creating two points
//    (b). Finding the distance between these points (utilize the function from (2) for this task)
//    (c). Finding the middle point between these points (utilize the operators from (1) for this task)

#include <iostream>
#include <cmath>

using namespace std;

class Point
{
private:
    double x, y;

public:
    // Default constructor
    Point() : x(0), y(0) {}

    // Constructor with one parameter
    Point(double val) : x(val), y(val) {}

    // Constructor with two parameters
    Point(double x_val, double y_val) : x(x_val), y(y_val) {}

    // Destructor
    ~Point() {}

    // Method to perform addition of two points
    Point add(const Point &p) const
    {
        return Point(x + p.x, y + p.y);
    }

    // Method to perform scaling of the point
    Point scale(double factor) const
    {
        return Point(x * factor, y * factor);
    }

    // Method to perform conversion to int
    int toInt() const
    {
        return sqrt(x * x + y * y);
    }

    // Method to print coordinates
    void print() const
    {
        cout << "(" << x << ", " << y << ")";
    }

    // Overloaded + operator
    Point operator+(const Point &p) const
    {
        return add(p);
    }

    // Overloaded * operator
    Point operator*(double factor) const
    {
        return scale(factor);
    }

    // Friend function to calculate distance between two points
    friend double distance(const Point &p1, const Point &p2);
};

// Function to calculate distance between two points
double distance(const Point &p1, const Point &p2)
{
    double dx = p1.x - p2.x;
    double dy = p1.y - p2.y;
    return sqrt(dx * dx + dy * dy);
}

int main()
{
    // Creating two points
    Point p1(1, 2);
    Point p2(4, 0);

    // Finding the distance between the points
    cout << "Distance between ";
    p1.print();
    cout << " and ";
    p2.print();
    cout << " is: " << distance(p1, p2) << endl;

    // Finding the middle point
    Point middle = (p1 + p2) * 0.5;
    cout << "Middle point between ";
    p1.print();
    cout << " and ";
    p2.print();
    cout << " is: ";
    middle.print();
    cout << endl;

    system("pause");
    return 0;
}


