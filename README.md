# Airgead Banking Investment Calculator

This is a C++ console application developed by **Karen Schick** for **CS-210: Programming Languages** at **Southern New Hampshire University (SNHU)**. The program calculates and displays how an investment grows over time with and without additional monthly deposits, using compound interest.

## 📅 Project Details

- **Author:** Karen Schick  
- **Date:** February 9, 2025  
- **Course:** CS-210 Programming Languages  
- **Instructor:** Professor Sabahudin Tricic

## 📘 Description

This program allows users to:

- Enter an initial investment amount
- Optionally include monthly deposits
- Specify an annual interest rate
- Define an investment period in years

It then outputs the investment growth with two separate breakdowns:

1. **Without Additional Monthly Deposits**
2. **With Additional Monthly Deposits**

These breakdowns display year-end balances and interest earned for each year.

## 🛠️ Technologies Used

- **C++**
- Standard Library: `<iostream>`, `<iomanip>`, `<limits>`, `<stdexcept>`, `<sstream>`
- Custom class: `AirgeadBanking` (in `AirgeadBanking.h` and `AirgeadBanking.cpp`)

## 💡 Features

- Input validation using templates and exception handling
- Clear console-based output formatted in tables
- Separation of logic using OOP principles

## 📚 Resources
GeeksforGeeks: How to use cin.fail() method in C++

GeeksforGeeks: Templates in C++

W3Schools: C++ Exceptions

## 📄 License
This project is for educational purposes as part of SNHU's CS-210 course and is not intended for commercial use.

## 🚀 Getting Started

### Prerequisites

- A C++ compiler (e.g., `g++`, Visual Studio, Code::Blocks, etc.)
- A terminal or IDE to compile and run the program

### Compilation

If you're using `g++`:

```bash
g++ main.cpp AirgeadBanking.cpp -o AirgeadBanking
./AirgeadBanking


