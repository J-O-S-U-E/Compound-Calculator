#include "investCalculator.h"
#include <iostream>
#include <iomanip>
#include <math.h>

void investCalculator::future_value_of_investment(double initial_balance, double contributions, 
	double interest_rate, double compounded_per_time, double time_invested)
{
	double final_amount;

	final_amount = (initial_balance * (pow( (1 + (interest_rate / compounded_per_time)), (compounded_per_time * time_invested))))
		+ (contributions * (pow(1 + (interest_rate / compounded_per_time), (compounded_per_time * time_invested))
			-1)/(interest_rate / compounded_per_time));

	std::cout << std::fixed << std::setprecision(2) << "Future balance: $" << final_amount << std::endl;
	std::cout << "Starting amount: $" << initial_balance << std::endl;
	std::cout << "Total contributions: $" << contributions * time_invested << std::endl;
	std::cout << "Total money earned from interest: $" << final_amount - (initial_balance + (contributions * time_invested))
		<< std::endl;
}

double investCalculator::savings_goal(double goal, double initial_balance,
	double interest_rate, double compounded, double years_to_save)
{
	double monthly_contributions_needed;
	monthly_contributions_needed = 
		((interest_rate / compounded) * (goal - initial_balance * pow((1 + (interest_rate / compounded)), (compounded * years_to_save))))
		/
		((pow(1 + (interest_rate / compounded), (compounded * years_to_save))) - 1);

	return monthly_contributions_needed;
}