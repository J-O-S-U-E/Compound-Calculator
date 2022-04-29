#include "debtCalculator.h"
#include <math.h>

double debtCalculator::payment_amount(double principal, double monthly_interest, double loan_months)
{
	double monthly_payment_amount;
	monthly_payment_amount =
		(principal * monthly_interest) /
		(1 - (pow((1 + monthly_interest), (-loan_months))));
	return monthly_payment_amount;
}

double debtCalculator::amount_of_payments(double owed, double interest, double payments)
{
	double amount_payments;
	amount_payments =
		(-log(1 - interest * owed / payments))/
		(log(1 + interest));
	return amount_payments;
}