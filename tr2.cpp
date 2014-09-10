//Course: 4002-208
//Author: Sean Leeka
//Day: 03
//Project 1
//Name: tr2.cpp
//Purpose:  This program calls for an input number of Megabytes to be transmitted,
//          as well as the transmission speed in bits per second.
//          The program then calculates the number of packets that will be required,
//          then outputs the time required to transmit the message given the packet overhead.
//          It also outputs the number of full packets and the number of data bytes
//          in the last packet.

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
int bits = 0;
int bytes = 0;

cout << "Enter number of Megabytes to be transmitted: ";
cin >> Megabytes;
cout << "Enter transmission speed in bits per second: ";
cin >> speed;

cout << endl;

bytes = Megabytes * 1048576;
bits = (Megabytes * conversion);

int const FullPacketsBytes = bytes / 1472;
int const LastPacketBytes = bytes % 1472;

//int const FullPacketsBits = bits / 1472;
//int const LastPacketBits = bits % 1472;

//calculates the number of bits with the added packet overhead
bits = ((FullPacketsBytes * 8) * 1500) + (LastPacketBytes * 8) + 28;

cout << "Packet length is 1500 bytes with 28 bytes of overhead." << endl;
cout << "Number of full packets: " << FullPacketsBytes << " bytes." << endl;
cout << "Number of data bytes in the last packet: " << LastPacketBytes << " bytes." << endl;

//calculates the number of seconds required to transmit
seconds = static_cast <double> (bits) / (speed);

//This number produced a number 0.01 less than the number in Sample Execution 1 (but not for 2).
//I'm not sure why.  It should be correct.
cout << "Time to transmit the message: " << seconds << " seconds." << endl << endl;

system("pause");

return 0;    
    
}
