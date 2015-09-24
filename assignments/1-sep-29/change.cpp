#include <iostream>
#include <string>
#include <cctype>
 
bool is_number(const std::string& s)
{
    std::string::const_iterator it = s.begin();
    while(it != s.end() && std::isdigit(*it)) ++it;
 
    return !s.empty() && it == s.end();
}
 
int getInputInt()
{
    int res = 0;
    std::string in;
 
    std::getline(std::cin, in);
 
    if(is_number(in))
    {
        res = atoi(in.c_str());
    }
    else
    {
        std::cout << std::endl << "Non-Integer detected." << std::endl
                  << "Exiting..." << std::endl;
        exit(0);
    }
 
    return res;
}
 
int main()
{
    int price, tender, change = 0;
    int coins[] = {1000, 500, 100, 25, 10, 5, 1};
 
 
    std::cout << "Please enter the total price cost: ";
    price = getInputInt();
 
    std::cout << "Please enter the money tendered:   ";
    tender = getInputInt();
 
 
    if(price > tender)
    {
        std::cout << "Money tendered cannot be less than the total price!" << std::endl
                  << "exiting...";
        return 0;
    }
 
    change = tender - price;
 
 
    std::cout << "The change value is $" << change/100.F << std::endl
              << "You must return the following bills and coins:" << std::endl;
 
 
    int i = 0;
    int temp = 0;
    while(i < 7)
    {
        if(change >= coins[i])
        {
            temp++;
            change -= coins[i];
        }
        else
        {
            if(i == 0) std::cout << temp << " $10 bills" << std::endl;
            else if(i == 1) std::cout << temp << " $5 bills" << std::endl;
            else if(i == 2) std::cout << temp << " loonies" << std::endl;
            else if(i == 3) std::cout << temp << " quarters" << std::endl;
            else if(i == 4) std::cout << temp << " dimes" << std::endl;
            else if(i == 5) std::cout << temp << " nickels" << std::endl;
            else if(i == 6) std::cout << temp << " pennies" << std::endl;
            else std::cout << temp << " " << coins[i] << " cent coins" << std::endl; // this should never show up
 
            i++;
            temp = 0;
        }
    }
 
 
    return 0;
}