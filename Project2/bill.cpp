#include <iostream>
#include <string>
using namespace std;

int main()
{
	double bill;
	int yearsAsCustomer, numberOfGigawattsUsed;
	string engergyEfficientHome, y = "y", n = "n";
	string residentialCity;

	cout << "Years as customer: ";
	cin >> yearsAsCustomer;
	if (yearsAsCustomer < 0)
	{
			cout << "The years as customer must not be negative" << endl;
			return 1; //// non-zero value means failure
	}
	
	cout << "Energy efficient home? (y/n): ";
	cin >> engergyEfficientHome;
	if (engergyEfficientHome != y && engergyEfficientHome != n) //The energyEfficientHome must not be anything other than 'y' and 'n'
	{
		cout << "You must enter y or n" << endl;
		return 1;
	}

	cin.ignore(10000, '\n'); //prevent getline(cin, residentialCity) from reading the previous cin, which is energyEfficientHome
	cout << "Residential city: ";
	getline(cin, residentialCity);
	if (residentialCity == "")
	{	
		cout << "You must enter a residence" << endl;
		return 1;
	}

	cout << "Number of gigawatts used: ";
	cin >> numberOfGigawattsUsed;

	if (numberOfGigawattsUsed < 0)
	{
		cout << "The number of gigawatts used must not be negative" << endl;
		return 1;
	}

	cout << "---" << endl;

	if (yearsAsCustomer <= 3) //If the year as customer is less than or equal to 3
	{					
		if (numberOfGigawattsUsed <= 2)					  
		{
			bill = 1.05;								   //AND the number of gigawatts used is less, the bill is $1.05
		}
		else if (engergyEfficientHome == y && numberOfGigawattsUsed > 2)
		{
			bill = 1.05 + 0.88 *numberOfGigawattsUsed;
		}
		else
		{
			bill =	1.21 + 0.88 * numberOfGigawattsUsed;
		}
	}					

	else if (yearsAsCustomer >= 10)//If the year as customer is larger or equal to 10, then the bill is counted in a discounted rate
	{                                                               
		if (engergyEfficientHome == y && numberOfGigawattsUsed <= 2)//If the customer ALSO lives in the energy efficient home and uses
		{                                                           //less than 2 gigawatts, the bill is still $1.05.
			bill = 1.05;
		}
		else{
			bill = 0.8 + 0.3 * numberOfGigawattsUsed;
		}
	}
	else if (yearsAsCustomer > 3 && engergyEfficientHome == y)
	{
		if (numberOfGigawattsUsed <= 2)					 							                                  
		{
			bill = 1.05;								   
		}
		else
		{
			bill = 1.21 + 0.88 * numberOfGigawattsUsed;
		}
	}
	
	else
	{
		bill = 1.21 + 0.88 * numberOfGigawattsUsed;
	}

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(2);

	cout << "The bill for this customer in " << residentialCity << " is $" << bill << endl;

	return 0;

}