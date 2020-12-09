#include <iostream>
#include "NormalCDF.h"
using namespace std;


double CalculateDelta(double q, double T, double nd, double N)
{
	double delta = exp(-q * T) * nd * N;
	return delta;
}


double CalculateGamma(double q, double T, double nd, double S, double σ)
{
	double partone = exp(-q * T);
	double parttwo = nd / (S * σ * sqrt(T));
	double gamma = partone * parttwo;
	return gamma;
}

double CalculateVega(double S, double q, double T, double nd)
{
	double vega = S * exp(-q * T) * nd * sqrt(T);
	return vega;
}


void GetTradeInputs(double* sp, double* nos, double* tte)
{

	cout << "	" << "Number of shares: ";
	cin >> *nos;
	cout << "	" << "Strike Price: ";
	cin >> *sp;
	cout << "	" << "Time to Expiry (in years): ";
	cin >> *tte;
}


void GetMarketInputs(double* sp, double* ir, double* dy, double* v)
{
	cout << "	" << "Share Price: ";
	cin >> *sp;
	cout << "	" << "Interest Rate (%): ";
	cin >> *ir;
	*ir /= 100;
	cout << "	" << "Dividend Yield (%): ";
	cin >> *dy;
	*dy /= 100;
	cout << "	" << "Volatility (%): ";
	cin >> *v;
	*v /= 100;
}

double CalculateOptionPrice(double S, double r, double q, double σ, double N, double K, double T, double* delta, double* gamma, double* vega)
{
	double DiscountFactor = exp(-r * T);
	double Forward = S * exp((r - q) * T);
	double VolTimesSqrt = σ * sqrt(T);
	double d1 = (log(Forward / K) / VolTimesSqrt) + .5 * VolTimesSqrt;
	double d2 = (log(Forward / K) / VolTimesSqrt) - .5 * VolTimesSqrt;
	double nd1 = exp(-(pow(d1, 2))) / sqrt(2 * 3.14159265);
	double nd2 = exp(-(pow(d2, 2))) / sqrt(2 * 3.14159265);
	double cdf1 = CumulativeNormalDistribution(d1);
	double cdf2 = CumulativeNormalDistribution(d2);
	double OptionPrice = DiscountFactor * ((Forward * cdf1) - (K * cdf2)) * N;
	*delta = CalculateDelta(q, T, nd1, N);
	*gamma = CalculateGamma(q, T, nd1, S, σ);
	*vega = CalculateVega(S, q, T, nd1);
	return OptionPrice;
}

