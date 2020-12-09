#pragma once
void GetTradeInputs(double* sp, double* nos, double* tte);
void GetMarketInputs(double* sp, double* ir, double* dy, double* v);
double CalculateOptionPrice(double S, double r, double q, double σ, double N, double K, double T, double* delta, double* gamma, double* vega);
double CalculateDelta(double q, double T, double nd1, double N);
double CalculateGamma(double q, double T, double nd1, double S, double σ);
double CalculateVega(double S, double q, double T, double nd);