//Scott Rowe
//Professor Alvis Forrest
//CS-210
//April 3, 2022

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
	//variables for input
	double initialInvestmentAmount, monthlyDeposit, annualInterest, months, numberOfYears;
	//variables for year end total amount, interest, and yearly interest
	double totalAmount, interestAmount, yearlyTotalInterest;

	//menu
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: " << endl;
	cout << "Monthly Deposit: " << endl;
	cout << "Annual Interest: " << endl;
	cout << "Number of years: " << endl;

	//press any key to continue
	system("PAUSE");

	//user input
	cout << "**********************************" << endl;
	cout << "*********** Data Input ***********" << endl;
	cout << "Initial Investment Amount: $" << endl;
	cin >> initialInvestmentAmount;
	cout << "Monthly Deposit: $" << endl;
	cin >> monthlyDeposit;
	cout << "Annual Interest: %" << endl;
	cin >> annualInterest;
	cout << "Number of years: " << endl;
	cin >> numberOfYears;
	months = numberOfYears * 12;

	system("PAUSE");

	//total amount towards the initial investment
	totalAmount = initialInvestmentAmount;

	//dislpaying the year end data if there is no monthly deposits
	cout << endl << "Balance and Interest Without Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//calculating the yearly interset with the year end total
	for (int i = 0; i < numberOfYears; i++) {
		//calculating the yearly interest amount
		interestAmount = ((totalAmount) * (annualInterest / 100));

		//calculating the year end total
		totalAmount = totalAmount + interestAmount;

		//using set precision to 2 decimal places
		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << interestAmount << endl;
	}
	//calculating the montly interest and end total
	totalAmount = initialInvestmentAmount;

	//displaing the yearly end data w/monthly deposits
	cout << endl << "Balance and Interest With Additional Monthly Deposits" << endl;
	cout << "================================================================" << endl;
	cout << "Year          Year End Balance          Year End Earned Interest" << endl;
	cout << "----------------------------------------------------------------" << endl;

	//calculating the yearly interest w/year end total
	for (int i = 0; i < numberOfYears; i++) {
		//Initialize yearly interest to 0
		yearlyTotalInterest = 0;

		for (int j = 0; j < 12; j++) {
			//calculating the monthly interest amount
			interestAmount = (((totalAmount + monthlyDeposit) * (annualInterest / 100)) / 12);

			//calculating the monthly end interest
			yearlyTotalInterest = yearlyTotalInterest + interestAmount;

			//calculating the monthly end total
			totalAmount = totalAmount + monthlyDeposit + interestAmount;
		}

		cout << (i + 1) << "\t\t$" << fixed << setprecision(2) << totalAmount << "\t\t\t$" << yearlyTotalInterest << endl;
	}
	return 0;
}
