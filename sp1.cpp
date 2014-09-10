//Course: 4002-208
//Author: Sean Leeka
//Day: 04
//Lab 2
//Name: sp1.cpp
//Purpose:  This program is used to compute the cost of buying a block of stock.
//          It will Prompt the user to enter the name of the company (multiple words),
//          the stock symbol (one word), the cost per share, and the number of shares.  
            

//include library for input and output
#include <iostream>
using namespace std;

int main()
{

string CompanyName, CompanySymbol;
const double ComissionConst = 0.0125;
double PurchasePrice;
int SharesPurchased;

double InitialPayment;
double CalculatedComission;


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

cout << CompanyName << " (" << CompanySymbol << ")" << endl;
cout << InitialPayment << endl;
cout << CalculatedComission << endl;
cout << InitialPayment + CalculatedComission << endl << endl;


system("pause");

return 0;

}
