/*
Author: Karen Schick
Date: February 9, 2025
Course: CS-210 Programming Languages
Professor: Sabahudin Tricic

Description:
Program that allows users to see how their investments grow over time.

Resources:
GeeksforGeeks. (n.d.). How to use cin.fail() method in C++? https://www.geeksforgeeks.org/how-to-use-cin-fail-method-in-cpp/

GeeksforGeeks. (n.d.). Templates in C++. https://www.geeksforgeeks.org/templates-cpp/

W3Schools. (n.d.). C++ exceptions. https://www.w3schools.com/cpp/cpp_exceptions.asp
*/

// main.cpp - main() function
#include <iostream>
#include <string>
#include <limits>
#include <stdexcept>
#include <iomanip>
#include "AirgeadBanking.h"
#include <sstream>

using namespace std;

// Function to validate user input for numerical values
template <typename T>
T validateInput(const string &prompt, T minValue)
{
    T value;
    while (true)
    {
        cout << prompt;
        cin >> value;

        // Check if input is numberical and positive
        if (!cin.fail() && value >= minValue)
        {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return value;
        }

        // Clear the error flags on input stream
        cin.clear();
        // Leave the rest of the line
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        // Create string stream to format error message
        stringstream errorMessage;
        errorMessage << fixed << setprecision(0) << static_cast<double>(minValue);
        // Ask user to enter valid number
        cout << "Please enter a number greater than or equal to " + errorMessage.str() << endl;
    }
}

int main()
{
    AirgeadBanking banking; // Create banking object of AirgeadBanking class

    try
    {

        double initialInvestment = validateInput("Enter your Initial Investment Amount: ", 0.0); // Prompt user to enter their inital investment and call validateInput function to ensure input is valid
        banking.SetInitialInvestment(initialInvestment);                                         // Set the inital invest amount in the AirgeadBanking object

        double monthlyDeposit = validateInput("Enter your Montly Deposit Amount: ", 0.0); // Prompt user to enter their Montly Deposit Amount and call validateInput function to ensure input is valid
        banking.SetMonthlyDeposit(monthlyDeposit);                                        // Set the Montly Deposit Amount in the AirgeadBanking object

        double annualInterest = validateInput("Enter your Annual Interest Rate Percentage: ", 0.0); // Prompt user to enter their Annual Interest Rate  and call validateInput function to ensure input is valid
        banking.SetAnnualInterest(annualInterest);                                                  // Set the Annual Interest Rate in the AirgeadBanking object

        int numYears = validateInput("Enter Number of Years: ", 1); // Prompt user to enter Number of Years and call validateInput function to ensure input is valid
        banking.SetNumYears(numYears);                              // Set the Number of Years in the AirgeadBanking object

        // Blank line for aesthetics
        cout << endl
             << endl;

        // Call functions to calculate and display results
        banking.DisplayWithoutMonthlyDeposit(banking.GetAnnualInterest(), banking.GetInitialInvestment(), banking.GetNumYears());
        banking.DisplayWithMonthlyDeposit(banking.GetAnnualInterest(), banking.GetInitialInvestment(), banking.GetNumYears(), banking.GetMonthlyDeposit());
    }
    catch (const exception &e)
    {
        cout << e.what() << endl;
    }

    return 0;
}