// AirgeadBanking.h - Class declaration
#ifndef AIRGEAD_BANKING_H
#define AIRGEAD_BANKING_H

// AirgeadBanking class declaration
class AirgeadBanking
{
public:
    AirgeadBanking(); // Default constructor

    void SetInitialInvestment(double t_initialInvestment); // Sets the inital investment amount
    double GetInitialInvestment() const;                   // Gets the inital investment amount

    void SetMonthlyDeposit(double t_monthlyDeposit); // Sets the monthly deposit amount
    double GetMonthlyDeposit() const;                // Gets the monthly deposit amount

    void SetAnnualInterest(double t_annualInterest); // Sets the annual interest
    double GetAnnualInterest() const;                // Gets the annual interest

    void SetNumYears(int t_numYears); // Sets the number of years
    int GetNumYears() const;          // Gets the number of years

    double DisplayWithoutMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numYears);                       // Calculates and displays investment without monthly depoists
    double DisplayWithMonthlyDeposit(double t_initialInvestment, double t_annualInterest, int t_numYears, double t_monthlyDeposit); // Calculates and displays investment with monthly depoists

private:
    double m_initialInvestment;
    double m_monthlyDeposit;
    double m_annualInterest;
    int m_numYears;
};

#endif