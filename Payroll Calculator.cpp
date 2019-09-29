/*
	Programmed by Kaden Golda
	kadengoldasteam@gmail.com
	Lab 5 - Payroll
*/

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctype.h>

using namespace std;

// Defining terms for the program.
int id, result;
double hourlyWage, hours, wage, salary, fica, allowances, previousytd, sum,
  check, tax;
ofstream outputFile;
ifstream inputFile;
string file, strings, maritalStat;
char name[100];

// Prototype functions
void getEmployeeInfor ();
double calcWage ();
double calcYTD ();
double calcTax (double &tax, double &fica);
double amtCheck (double &tax, double &fica);
void output ();

int main () {
  // Get employee information
  getEmployeeInfor ();
  // Calculate the total wage
  wage = calcWage ();
  // Calculate Salary
  salary = calcYTD ();
  sum = calcTax (tax, fica);
  check = amtCheck (tax, fica);
  // Prints the Table to the outputFile
  output ();

  return 0;
}

// Function for asking user for Employee Id, pay rate, and the hours worked
void getEmployeeInfor () {
  cout << "Please enter your name: ";
  cin.get (name, 100);

  cout << "What's you hourly wage?: ";
  cin >> hourlyWage;

  cout << "How many hours have you worked this period?: ";
  cin >> hours;

  cout << "Are you withholding allowances, if so, how much?: ";
  cin >> allowances;

  cout << "What's your previous year-to-date earnings?";
  cin >> previousytd;

  cout << "What's your Marital Status?";
  cin >> maritalStat;
}

// Function for calculating the Wage
double calcWage () {
  double wages;
  return wages = hourlyWage * hours;
}

// Function for calculating Salary
double calcYTD () {
  double salary;
  salary = wage + previousytd;
  return salary;
}

// Calculate FICA and Federal Tax
double calcTax (double &tax, double &fica) {

  //tax increments have been calculated

  const double tax1 = 18.70;	// first tax increment 
  const double tax2 = 87.34;	// second increment 
  const double tax3 = 276.54;	// thrid increment 
  const double tax4 = 629.82;	// fourth increment 
  const double tax5 = 896.70;	// fourth increment 
  const double tax6 = 2957.85;	// fourth increment 


//      double tax;                     //how much taxes are

  if (maritalStat == "s" || maritalStat == "S")
    {
      if (wage <= 73)
	{
	  tax = 0;
	}
      else if (wage >= 260.00 && wage <= 832.00)
	{
	  tax = (wage * .10) + tax1;	//calculates tax amount
	}
      else if (wage >= 832.00 && wage <= 1692.00)
	{
	  tax = (wage * .12) + tax2;	//calculates tax 
	}
      else if (wage >= 1692.00 && wage <= 3164.00)
	{
	  tax = (wage * .22) + tax3;	//calculates tax 
	}
      else if (wage >= 3164.00 && wage <= 3998.00)
	{
	  tax = (wage * .24) + tax4;	//finds tax amount
	}
      else if (wage >= 3998.00 && wage <= 9887.00)
	{
	  tax = (wage * .32) + tax5;	//finds tax amount
	}
      else if (wage > 9887.00)
	{
	  tax = (wage * .35) + tax6;	//finds tax amount
	}
      else
	cout << "Please enter a positive number. " << endl;
      return tax;
    }
  else if (maritalStat == "m" || maritalStat == "M")
    {
      //tax increments have been calculated

      const double tax1 = 0.00;	// first tax increment 
      const double tax2 = 37.30;	// second increment 
      const double tax3 = 174.70;	// thrid increment 
      const double tax4 = 553.10;	// fourth increment 
      const double tax5 = 1259.66;	// fourth increment 
      const double tax6 = 1793.42;	// fourth increment 
      const double tax7 = 3167.52;	// fourth increment 

      if (wage <= 227)
	{
	  tax = 0;
	}
      else if (wage >= 227.00 && wage <= 600.00)
	{
	  tax = (wage * .10) + tax1;	//calculates tax amount
	}
      else if (wage >= 600.00 && wage <= 1745.00)
	{
	  tax = (wage * .12) + tax2;	//calculates tax
	}
      else if (wage >= 1745.00 && wage <= 3465.00)
	{
	  tax = (wage * .22) + tax3;	//calculates tax
	}
      else if (wage >= 3465.00 && wage <= 6409.00)
	{
	  tax = (wage * .24) + tax4;	//finds tax amount
	}
      else if (wage >= 6409.00 && wage <= 8077.00)
	{
	  tax = (wage * .32) + tax5;	//finds tax amount
	}
      else if (wage >= 8077.00 && wage <= 12003.00)
	{
	  tax = (wage * .32) + tax6;	//finds tax amount
	}
      else if (wage > 12003.00)
	{
	  tax = (wage * .35) + tax7;	//finds tax amount
	}
      else
	cout << "Please enter a positive number. " << endl;
      return tax;
    }
  if (salary < 132900.00)
    {
      fica = salary * 0.062;
      return fica;
    }
  else if (salary > 132900.00)
    {
      fica = 0;
      return fica;
    }
}

double amtCheck (double &tax, double &fica) {
  double calccheck;
  calccheck = (wage - fica) - tax;
  return calccheck;
}

// Function for printing information to the outputFile
void output () {
  cout << tax << endl;
}
