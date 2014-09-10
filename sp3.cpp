//Course: 4002-208
//Author: Sean Leeka
//Day: 04
//Lab 2
//Name: sp3.cpp
//Purpose:  This program is used to compute the cost of buying a block of stock.
//          It will Prompt the user to enter the name of the company (multiple words),
//          the stock symbol (one word), the cost per share, and the number of shares.  
            

//include library for input and output
#include <iostream>
#include <iomanip>
using namespace std;


int main()
{

string CompanyName, CompanySymbol;
const double ComissionConst = 0.0125;
double PurchasePrice;
int SharesPurchased;

double InitialPayment;
double CalculatedComission;

double SellingPrice;
const double SellingComission = 0.011;
double net;
double BuyingTotal, Selling, CalculatedSellComission, SellingTotal;


cout << "Enter the name of company: ";
getline(cin, CompanyName);

cout << "Enter symbol: ";
cin >> CompanySymbol;

cout << "Purchase price per share: ";
cin >> PurchasePrice;

cout << "Enter number of shares purchased: ";
cin >> SharesPurchased;

cout << endl;

InitialPayment = PurchasePrice * SharesPurchased;
CalculatedComission = InitialPayment * ComissionConst;

BuyingTotal = InitialPayment + CalculatedComission;

cout << CompanyName << " (" << CompanySymbol << ")" << endl;
cout << setw(10) << fixed << setprecision(2) << InitialPayment << endl;
cout << setw(10) << CalculatedComission << endl;
cout << setw(10) << InitialPayment + CalculatedComission << endl << endl;

cout << "Selling price per share: ";
cin >> SellingPrice;

Selling = SellingPrice * SharesPurchased;
CalculatedSellComission = Selling * SellingComission;

SellingTotal = Selling - CalculatedSellComission;

cout << setw(10) << Selling << endl;
cout << setw(10) << CalculatedSellComission << endl;
cout << setw(10) << Selling - CalculatedSellComission << endl << endl;

net = SellingTotal - BuyingTotal;

cout << "The profit or loss is " << net << endl << endl;
system("pause");

return 0;

}

