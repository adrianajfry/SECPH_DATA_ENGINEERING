const double PI = 3.14159;

/** @class Sphere Sphere.h "Sphere.h"
 * Definition of a class of Spheres. */
class Sphere
{
public:
	Sphere();
	Sphere(double initialRadius);
	void setRadius(double newRadius);
	double getRadius() const;
	double getDiameter() const;
	double getCircumference() const;
	double getArea() const;
	double getVolume() const;
	void displayStatistics() const;

private:
	/** The Sphere's radius */
	double theRadius;
};  // end Sphere

