// future_value_of_investment format: inital balance/ contributions/ interest rate in decimal form/
// compound_per_time is how much times it is compounded per unit of time, for example if doing annualy the compound_per_time should
// be set to 1/ time_invested is the unit of time the money will sit, for example if investing for 10 years, then time is 10.
class investCalculator
{
public:
	void future_value_of_investment(double initial_balance, double contributions,
		double interest_rate, double compounded_per_time, double time_invested);
	double savings_goal(double goal, double initial_balance, double interest_rate, double compounded, double years_to_save);
};

