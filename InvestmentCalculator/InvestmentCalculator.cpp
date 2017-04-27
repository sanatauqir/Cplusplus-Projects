/*
Sana Tauqir							PIC 10A: Intro to Programming
ID: 604211208						Spring 2014
*/

#include <iostream>
#include <string>
#include <cmath>
using namespace std;

// declaring functions
int getValidInt();
double getValidDouble();
double effective_rate (double annual_rate, int num_times_compounded);
double balance (double annual_rate, double principle, double years_elapsed, int num_times_compounded);
double m_fold_time (double m, double annual_rate, int num_times_compounded);
double present_value (double target_value, double annual_rate, double years_elapsed, int num_times_compounded);
void printTriangle (int height);

int main()
{
	// variables for storing function return values
	double a = 0;
	double b = 0;
	int c = 0;
	double d = 0;
	int height =0;

	// set precision to two decimals
	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "Investment Calculator" << endl << endl;
	cout << "Enter an annual interest rate: "; 
	a = getValidDouble();

	
	cout << endl << "How much principal do you want to invest? ";
	b = getValidDouble();

	// How long will you invest for?
	cout << endl << "How much time will elapse in years? ";
	c = getValidInt();

	// reading in how often, quarterly,monthly, etc interest will be compounded
	cout << endl << "How many times per year will interest be compounded?" << endl;
	cout << "<Enter \'0\' for continously compounded>: ";
	d = getValidInt();

	//balance given the above variables as parameters
	cout << endl << "Balance: $" << balance (a, b, c, d) << endl;

	// how long it will take for your money to double
	cout << "Doubling time: " << m_fold_time (2, a, d) << " years" << endl;

	cout << "To become a millionaire in 10 years using this strategy," << endl;
	cout << "you need to invest: $" << present_value (1000000, a, c, d) << endl << endl;
	
	cout << "****************** Drawing a Triangle *******************" << endl;
	cout << "Enter the height of a triangle: ";
	cin>> height;
	printTriangle(height);
}

//defining functions

int getValidInt ()
{
	int i=0;	
	cin>> i;
	string invalid_input;

	while (cin.fail()) 
	{
		cin.clear();
		getline(cin,invalid_input);
		cout << endl << "You entered a value of the wrong type!" << endl;
		cin >> i;
	}

	return i;
}


double getValidDouble()
{
	double j=0;	
	cin>> j;
	string invalid_input;

	while (cin.fail()) 
	{
		cin.clear();
		getline(cin,invalid_input);
		cout << endl << "You entered a value of the wrong type!" << endl;
		cout << "Enter a double value this time: " << endl;
		cin >> j;
	}

	return j;
}

double effective_rate (double annual_rate, int num_times_compounded = 0)
{
	double i=0, effective_rate=0;
	if (num_times_compounded == 0)
	{
		effective_rate = (exp (annual_rate) - 1);
		return effective_rate;
	}

	i = (1 + annual_rate/num_times_compounded);
	effective_rate = (pow (i, num_times_compounded)) - 1;
	return effective_rate;
}

double balance (double annual_rate, double principle, double years_elapsed, int num_times_compounded = 0)
{
	double x = 0, y =0, balance = 0;
	if (num_times_compounded == 0)
	{
		y = exp(annual_rate);
		balance = principle* (pow (y, years_elapsed));
		return balance;
	}

	x = effective_rate (annual_rate, num_times_compounded);
	balance = principle*(1 +(pow (x, years_elapsed)));
	return balance;
}

double m_fold_time (double m, double annual_rate, int num_times_compounded = 0)
{
	double x= 0, m_fold_time =0;

	x = effective_rate (annual_rate, num_times_compounded);
	m_fold_time = log(m) / (log (1+x));
	return m_fold_time;
}

double present_value (double target_value, double annual_rate, double years_elapsed, int num_times_compounded = 0)
{
	double x=0 , present_value = 0;
	x = effective_rate (annual_rate, num_times_compounded) + 1 ;
	present_value = target_value / (pow (x, 10));
	return present_value;
}

void printTriangle (int height)
{
	// outer loop for keeping track of the current row number
   	for(int row = 0; row < height; row++)
	{
		// inner loop keeps track of the position of the graphic being drawn
	    for(int col = 0; col < height; col++)
		{
			if (row == col || col == height -1 || row == 0)
				cout << "*";
			else
				cout << " ";
		}
		cout << endl;
	}
        cout << endl;
}