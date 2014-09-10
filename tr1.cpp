//Course: 4002-208
//Author: Sean Leeka
//Day: 03
//Project 1
//Name: tr1.cpp
//Purpose:  This program calls for an input number of Megabytes to be transmitted,
//          as well as the transmission speed in bits per second,
//          then outputs the time required to transmit the message.

//include library for input and output
#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int main()
{
    
int Megabytes = 0;
int speed = 0;
double seconds = 0;
int conversion = 8388608;

cout << "Enter number of Megabytes to be transmitted: ";
cin >> Megabytes;
cout << "Enter transmission speed in bits per second: ";
cin >> speed;

cout << endl;

//calculates the number of seconds required to send the transmission,
//after converting Megabytes to bits
seconds = static_cast <double> (Megabytes * conversion) / (speed);

cout << "Time to transmit the message: " << seconds << " seconds." << endl << endl;

system("pause");

return 0;    
    
}
