#include "NormalCDF.h"
#include "ExtraFunctions.h"
#include <iostream>
using namespace std;

int main()
{
	double SharePrice=0, InterestRate=0, DividendYield=0, Volatility=0, NumberOfShares=0, Strike=0, YearsToExpiry = 0;
	double Delta = 0, Gamma = 0, Vega = 0;
	cout << "This is a program to determine the price of a share via the Black Scholes formula." << endl;
	cout << "Please input market data." << endl;
	GetMarketInputs(&SharePrice, &InterestRate, &DividendYield, &Volatility);
	cout << "Please input trade data." << endl;
	GetTradeInputs(&Strike, &NumberOfShares, &YearsToExpiry);
	/*
	double InputArray[] = { SharePrice, InterestRate, DividendYield, Volatility, NumberOfShares, Strike, YearsToExpiry };
	double size_array = sizeof(InputArray) / sizeof(InputArray[0]);
	for (int i = 0; i < size_array; i++)
	{
		cout << InputArray[i] << " ";
	}
	*/
	double FinalPrice = CalculateOptionPrice(SharePrice, InterestRate, DividendYield, Volatility, NumberOfShares, Strike, YearsToExpiry, &Delta, &Gamma, &Vega);
	cout << "The price of the option is: " << FinalPrice << endl;
	cout << "Delta is " << Delta << ", Gamma is " << Gamma << ", and Vega is " << Vega << "." << endl;
	return 0;
}