/*
Sana Tauqir							PIC 10A: Intro to Programming
Spring 2014
*/

#include <iostream>
#include <string>
#include <ccc_animate.h>
#include <ccc_msw.h>
#include <ccc_shap.h>
#include <ccc_win.h>
using namespace std;

double PI = 3.14;

void RectangleinRectangle (); //helper function

class Rectangle {
	public:
	// constructors
	Rectangle(); 
	Rectangle(Point pos, double h, double w); // lower left corner, height and width are the arguments

	// Accessor methods
	double get_height() const; 
	double get_width() const;
	Point get_pos() const; // Gets position of lower left corner as an object of type Point.

	void draw() const; // Prints the rectangle using cwin
	void move(double x, double y);
	void set_height(double h);
	void set_width(double w);

	private:
	Point bottom_left;
	double height;
	double width;
};

// Default constructor.
Rectangle::Rectangle() {
	height = 0;
	width = 0;
	bottom_left = Point(0,0);
}

Rectangle::Rectangle(Point pos, double h, double w) {
	height = h;
	width = w;
	bottom_left = pos;
}

double Rectangle::get_height() const {
return height;
}

double Rectangle::get_width() const {
return width;
}

Point Rectangle::get_pos() const { return bottom_left; }

void Rectangle::move(double x, double y) { bottom_left.move(x,y); }

void Rectangle::set_height( double h) { height = h;}

void Rectangle::set_width( double w) {width = w;}

void Rectangle::draw() const {
	Point upper_left(bottom_left.get_x(),bottom_left.get_y()+height);
	Point bottom_right(bottom_left.get_x()+width,bottom_left.get_y());
	Point upper_right(bottom_left.get_x()+width,bottom_left.get_y()+height);
	cwin << Line(bottom_left,upper_left);
	cwin << Line(bottom_left,bottom_right);
	cwin << Line(upper_left,upper_right);
	cwin << Line(bottom_right,upper_right);
}

// UNIONJACK CLASS ----------------------------------------------------------------------

class Unionjack
{
	public:
		Unionjack (Point location);
		void draw() const;
		void move(const Point& newLocation);
		Point getLocation ();
	private:
		Point location;
		const int size;
};

Unionjack::Unionjack(Point location): size(3)
{
	location = location;
}

void Unionjack::draw () const
{
	Point left_middle(location.get_x()-size,location.get_y());
	Point left_top (location.get_x()-size, location.get_y()+size);
	Point left_bottom (location.get_x()-size, location.get_y()-size);
	
	Point middle_bottom (location.get_x(), location.get_y()-size);
	Point middle_top (location.get_x(), location.get_y()+size);

	Point right_middle (location.get_x()+size, location.get_y());
	Point right_top (location.get_x()+size, location.get_y()+size);
	Point right_bottom (location.get_x()+size, location.get_y()-size);

	cwin << Line(left_middle,right_middle);
	cwin << Line(left_top, right_bottom);
	cwin << Line(left_bottom, right_top);
	cwin << Line(middle_bottom, middle_top);
}

void Unionjack::move (const Point& newLocation)
{
	location = newLocation;
}

Point Unionjack::getLocation ()
{
	return location;
}

//--------------------------BEGIN MAIN----------------------------------------

int ccc_win_main()
{	
	// asks for the username
	string ask_name = "Enter name: ";	
	string name = cwin.get_string (ask_name);

	Point message_corner (-6,0);
	
	//prints different messages within the rectangles
			
	RectangleinRectangle();
	Message x(message_corner, "THE RIVALRY CONTINUES...THIS WEEKEND");
	cwin << x;
	pause (1200);
	cwin.clear();
	
	RectangleinRectangle();
	Message y(message_corner, "UCLA VS USC FOOTBALL @ THE ROSE BOWL");
	cwin << y;
	pause (1200);
	cwin.clear();
	
	RectangleinRectangle();
	Message z(message_corner, "UCLA BRUINS!!! FIGHT FIGHT FIGHT!!! :-)");
	cwin << z;
	pause (1200);
	cwin.clear();
	
	//clears the screen at the user's click at the end
	string ask_click = "Click somewhere";
	Point click = cwin.get_mouse(ask_click);
	cwin.clear();

	// prints out a pinwheel with points
	Point center = Point (0,0);
	Point toRotate = Point (0,5);
	
	for (double j=0; j<10; j++)	// rotates the circle 10 times
	{
		for (double i= j/10; i < 2*PI; i=i+(2*PI)/20)	//drawing the circle with 20 radii
		{
			// prints a circle in the middle of the pinwheel
			Circle c = Circle (center, 2);
			cwin << c;

			Point returned = rotate(center,toRotate,i); //point on circumference of circle
			cwin << returned;
			// prints the line connecting center to point
			cwin << Line (center, returned);
		}
		pause (700);
		cwin.clear();

	}

	// prints out the unionjack with lines
	Point w (-10,-10);
	Unionjack e = Unionjack (w);
	e.draw();
	
	//
	for (int i=0; i<6; i++)
	{
		Point newLocation (e.getLocation().get_x()+i, e.getLocation().get_y()+i);
		e.move(newLocation);
		cwin.clear();
		e.draw();
		pause(1000);
	}

	Message n(message_corner, "Brought to you by: ");
	cwin << n;
	pause (1000);
	cwin.clear();
	Message m(message_corner, name);
	cwin<<m;
	pause (600);

	return 0;
}

//helper function to draw the rectangle inside rectangle which will contain the messages

void RectangleinRectangle ()
{
	Point origin = Point (-8,-3);
	Point origin2 = Point (-7,-2);
	Rectangle r = Rectangle (origin,6,16);
	Rectangle r2 = Rectangle (origin2,4,14); 
	r.draw();
	r2.draw();
}