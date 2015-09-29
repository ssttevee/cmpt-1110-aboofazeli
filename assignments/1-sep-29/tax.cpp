#include <iostream>
#include <iomanip>

const int taxBrackets[] = { 500000, 250000, 100000, 75000, 50000, 0};

int main ()
{
	float income = 0;
	
	while (true)
	{
		std::cout << "Enter yearly income amount (0.0 to quit): $ ";
		std::cin >> income;

		if (!income) break;

		float taxAmount = 0;
		for (int i = 0; i < 7; i++)
		{
			if(income > taxBrackets[i])
			{
				taxAmount += (6.F - i) / 100.F * (income - taxBrackets[i]);
				income = taxBrackets[i];
			}
		}

		std::cout << "The U.S. 1913 income tax = $ " << std::fixed << std::setprecision(2) << floor(taxAmount * 100 + 0.5) / 100 << std::endl << std::endl;
	}

	std::cout << "Processing Completed..." << std::endl;
}