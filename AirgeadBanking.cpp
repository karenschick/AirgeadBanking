// AirgeadBanking.cpp - Class definition

#include <iostream>
#include <iomanip>
#include "AirgeadBanking.h"

using namespace std;

// Default construction
AirgeadBanking::AirgeadBanking() : m_initialInvestment(0), m_monthlyDeposit(0), m_annualInterest(0), m_numYears(0) {}

// Sets the Initial Investment
void AirgeadBanking::SetInitialInvestment(double t_initialInvestment)
{
    m_initialInvestment = t_initialInvestment;
}

// Returns the Initial Investment
double AirgeadBanking::GetInitialInvestment() const
{
    return m_initialInvestment;
}

// Sets the Monthly Deposit Amount
void AirgeadBanking::SetMonthlyDeposit(double t_monthlyDeposit)
{
    m_monthlyDeposit = t_monthlyDeposit;
}

// Returns the Monthly Deposit Amount
double AirgeadBanking::GetMonthlyDeposit() const
{
    return m_monthlyDeposit;
}

// Sets the Annual Interest Rate
void AirgeadBanking::SetAnnualInterest(double t_annualInterest)
{
    m_annualInterest = t_annualInterest;
}

// Returns the Annual Interest Rate
double AirgeadBanking::GetAnnualInterest() const
{
    return m_annualInterest;
}

// Sets the Number of Years
void AirgeadBanking::SetNumYears(int t_numYears)
{
    m_numYears = t_numYears;
}

// Returns the Number of Years
int AirgeadBanking::GetNumYears() const
{
    return m_numYears;
}

// Calculates investment balance with no Monthly Deposit
double AirgeadBanking::DisplayWithoutMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numYears)
{
    double yearEndBalance = m_initialInvestment;
    double yearEndInterest = 0.0;

    cout << "---------------------------------------------------------" << endl;
    cout << "Balance and Interest Without Additional Monthly Payments" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << left << setw(10) << "Year" << setw(25) << "Year-end Balance" << setw(25) << "Year-end Interest"
         << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int i = 1; i <= m_numYears; i++)
    {
        yearEndInterest = yearEndBalance * (m_annualInterest / 100); // Calculate yearly interest
        yearEndBalance += yearEndInterest;                           // Update yearEndBalance

        cout << left << setw(10) << i << "$" << left << setw(25) << fixed << setprecision(2) << yearEndBalance << "$" << setw(25) << yearEndInterest << endl;
    }

    return yearEndBalance;
}

// Calculates investment balance with Monthly Deposit
double AirgeadBanking::DisplayWithMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numYears, double t_monthlyDeposit)
{
    double yearEndBalance = m_initialInvestment;
    double yearEndInterest = 0.0;

    cout << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "Balance and Interest With Additional Monthly Payments" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << left << setw(10) << "Year" << setw(25) << "Year-end Balance" << setw(25) << "Year-end Interest"
         << endl;
    cout << "---------------------------------------------------------" << endl;

    for (int i = 1; i <= m_numYears; i++) // Yearly calculation
    {
        double yearEndInterest = 0.0; // Reset yearly interest at beginning of each year

        for (int j = 1; j <= 12; j++) // Monthly calculation
        {
            yearEndBalance += m_monthlyDeposit;                                        // Add monthly deposit
            double monthlyInterest = yearEndBalance * ((m_annualInterest / 100) / 12); // Calculate monthly interest
            yearEndBalance += monthlyInterest;                                         // Update yearEndBalance
            yearEndInterest += monthlyInterest;                                        // Accumulate total interest earned through year
        }

        // Display results
        cout << left << setw(10) << i << "$" << left << setw(25) << fixed << setprecision(2) << yearEndBalance << "$" << setw(25) << yearEndInterest << endl;
    }
    return yearEndBalance;
}
