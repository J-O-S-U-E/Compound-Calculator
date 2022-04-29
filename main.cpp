#include <iostream>
#include "investCalculator.h"
#include "debtCalculator.h"
#include <iomanip>

void print_menu();
char get_user_command();
void future_balance();
void time_for_savings_goal();
void payment();
void payments();

int main()
{
	char choice;
	do
	{
		print_menu();
		choice = toupper(get_user_command());
		switch (choice)
		{
		case '1': future_balance();
			break;
		case '2': time_for_savings_goal();
			break;
		case '3': payment();
			break;
		case '4': payments();
			break;
		case 'E': std::cout << "Exiting menu...\n";
			break;
		default: std::cout << choice << " is invalid.\n";
		}
	} while (choice != 'E');
	std::cout << "\n";
	
	return 0;
}

void print_menu()
{
	std::cout << "\n\n";
	std::cout << "LOAN/DEBT & INVESTMENT CALCULATOR\n";
	std::cout << "The following choices are available: \n";
	std::cout << " 1.  Calculate the future balance.\n";
	std::cout << " 2.  Calculate the monthly contributions to reach a savings goal amount.\n";
	std::cout << " 3.  Calculate the monthly payment amount to pay off your debt with a desired time frame (in months).\n";
	std::cout << " 4.  Calculate the expected time frame (in months) with a desired monthly payment amount.\n";
	std::cout << " E.  Exit menu.\n";
}

char get_user_command()
// Library facilities used: iostream
{
	char command;

	std::cout << "Enter choice: ";
	std::cin >> command; //Input of characters skips blanks and newline character
	return command;
}

void future_balance()
{
	investCalculator temp;
	double initial, contribution, interest, compound = 0, time;
	char compound_choice;
	std::cout << "What is the amount of money that you have available to invest intially?" << std::endl;
	while(!(std::cin >> initial)||initial<0)
	{
		std::cout << "ERROR: Please enter a positive number: ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	do
	{
		std::cout << "Is your compound frequency monthly or annualy?\nEnter M for monthly:\nEnter A for annualy:\n";
		std::cin >> compound_choice;
		compound_choice = toupper(compound_choice);
		switch (compound_choice)
		{
		case 'M': compound = 12;
			break;
		case 'A': compound = 1;
			break;
		default: std::cout << "Invalid choice\n";
		}
	} while (compound_choice != 'M' && compound_choice != 'A');
	

	std::cout << "What is the amount that you plan to contribute monthly?\n";
	while (!(std::cin >> contribution)||contribution<0)
	{
		std::cout << "ERROR: Please enter a positive number: ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}
	if (compound_choice == 'A')
		contribution = contribution * 12;

	std::cout << "What is your estimated annual interest rate (in decimal form)?\n";

	while (!(std::cin >> interest) || (interest < 0 || interest >= 1))
	{
		std::cout << "ERROR: Please enter a decimal number between 0 and 1: ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}
	std::cout << "How many years do you plan to save for?\n";


	while (!(std::cin >> time) || time < 0)
	{
		std::cout << "ERROR: Please enter a postive number: ";
		std::cin.clear();
		std::cin.ignore(123, '\n');
	}

	//std::cout << "Your future estimated balance is: ";
	temp.future_value_of_investment(initial, contribution, interest, compound, time);
}

void time_for_savings_goal()
{
	investCalculator temp;
	double goal, initial, interest, compound = 0, time;
	char compound_choice;
	std::cout << "What is the amount of money that you have available to invest intially?" << std::endl;
	std::cin >> initial;
	std::cout << "What is your desired final savings amount?\n";
	std::cin >> goal;

	do
	{
		std::cout << "Is your compound frequency monthly or annualy?\nEnter M for monthly:\nEnter A for annualy:\n";
		std::cin >> compound_choice;
		compound_choice = toupper(compound_choice);
		switch (compound_choice)
		{
		case 'M': compound = 12;
			break;
		case 'A': compound = 1;
			break;
		default: std::cout << "Invalid choice\n";
		}
	} while (compound_choice != 'M' && compound_choice != 'A');

	std::cout << "What is your estimated annual interest rate (in decimal form)?\n";
	std::cin >> interest;

	std::cout << "How many years do you plan to save for?\n";
	std::cin >> time;
	
	if (compound_choice == 'M')
	{
		std::cout << "To reach your goal your monthly contributionsS should be: $";
		std::cout << std::fixed << std::setprecision(2) <<
			temp.savings_goal(goal, initial, interest, compound, time) << std::endl;// monthly
	}
	else
	{
		std::cout << "To reach your goal your monthly contributions should be: $";
		std::cout << std::fixed << std::setprecision(2) <<
			temp.savings_goal(goal, initial, interest, compound, time) / 12 << std::endl; //annualy
	}
}

void payment()
{
	debtCalculator temp;
	double owed, interest, months;
	std::cout << "How much money do you owe?\n";
	std::cin >> owed;
	std::cout << "What is your annual interest rate (in decimal form)?\n";
	std::cin >> interest;
	std::cout << "What is your loan term or desired payoff timeframe in months?\n";
	std::cin >> months;

	std::cout << "Your expected monthly payment amount is: $";
	std::cout << std::fixed << std::setprecision(2) <<
		temp.payment_amount(owed, interest / 12, months) << std::endl;
}

void payments()
{
	debtCalculator temp;
	double owed, interest, payment;
	std::cout << "How much money do you owe?\n";
	std::cin >> owed;
	std::cout << "What is your annual interest rate (in decimal form)?\n";
	std::cin >> interest;
	std::cout << "What is your expected monthly payment amount?\n";
	std::cin >> payment;
	std::cout << "Your expected payoff time in months is: ";
	std::cout << std::fixed << std::setprecision(0) << temp.amount_of_payments(owed, interest/12, payment) << std::endl;
}