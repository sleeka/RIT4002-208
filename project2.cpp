//Course: 4002-208-01
//Author: Sean Leeka
//Project 2 in 20081
//Name:  Project2.cpp
//Purpose: Program to calculate the number of seconds to transmit a message
//         that is transmitted in IP packets 0f 2385 bytes with 45 bytes
//         of overhead.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    
    int KB = 1024;
    int MB = KB * KB;
    
    int MessageSize = 0;
    char SizeUnits;
    
    const int Speed1 = 19200;
    const int Speed2 = 56000;    
    const int Speed3 = 1544000;
    int TransmissionSpeed = 0;
    int SpeedChoice = 0;
    
    const int PacketSize = 2385;
    const int Overhead = 45;
    
    int FullPackets = 0;
    int LastPacket = 0;
    
    double TimeFullPacket;
    double TimeLastPacket;
    double TimeTotal;
      

    cout << "Enter size of message to be transmitted: ";
    cin >> MessageSize;
    cout << endl;
    
    if (MessageSize < 1)
    {
       //invalid size
       cout << "Invalid size - must be greater than or equal to 1";
       system("pause");
       return 0;                
    }
    
    
    cout << "Enter units for size of message (K or M): ";
    cin >> SizeUnits;
    cout << endl;
    
    if (SizeUnits == 'K')
    {
       MessageSize *= KB;
    }
    
    else
    { 
        if(SizeUnits == 'M')
        {
                     MessageSize *= MB;             
        } 
         else
        {
           //invalid unit entered
            cout << "Invalid unit for measurement entered - must be K or M";
            system("pause");
            return 0;                  
        }
    }
    
    
    cout << "Available transmission speeds" << endl;
    cout << "1." << right << setw(8) << Speed1 << " bps" << endl;
    cout << "2." << right << setw(8) << Speed2 << " bps" << endl;
    cout << "3." << right << setw(8) << Speed3 << " bps" << endl;
    cout << "Enter choice: ";
    cin >> SpeedChoice;
    cout << endl;
    
    switch (SpeedChoice)
    {
           case 1:
                TransmissionSpeed = Speed1;
                break;
           case 2:
                TransmissionSpeed = Speed2;
                break;
           case 3:
                TransmissionSpeed = Speed3;
                break;
           default:
                   //invalid unit entered
                   cout << "Invalid choice - must be 1, 2, or 3";
                   system("pause");
                   return 0;
                   break;       
    }

    FullPackets = MessageSize / (PacketSize - Overhead);
    LastPacket = MessageSize % (PacketSize - Overhead);

    cout << "Packet length is " << PacketSize << " bytes with " << Overhead << " bytes of overhead." << endl;
    cout << "Number of full packets: " << FullPackets << endl;
    cout << "Number of data bytes in last packet: " << LastPacket << endl << endl;
    
    TimeFullPacket = static_cast<double> (PacketSize) / (static_cast<double>(TransmissionSpeed) / 8);
    TimeLastPacket = static_cast<double> (LastPacket + Overhead) / (static_cast<double>(TransmissionSpeed) / 8);
    TimeTotal = static_cast<double>(TimeFullPacket * FullPackets) + static_cast<double>(TimeLastPacket);
    
    cout << "Time to transmit a full packet is " << fixed << setprecision(4) << TimeFullPacket << " seconds." << endl;
    
    if (TimeLastPacket > 0)
    {
       cout << "Time to transmit the last packet is " << TimeLastPacket << " seconds." << endl;
    }
       
    if (TimeTotal >= 60)
    {
       int Minutes = static_cast<int> (TimeTotal) / 60;
       double Seconds = TimeTotal - (Minutes * 60);
       cout << "Time to transmit the message is " << Minutes << " minutes and " << Seconds << " seconds." << endl << endl;
    }
    
    else
    {
       cout << "Time to transmit the message is " << TimeTotal << " seconds." << endl << endl;
    }
    
    
    system("Pause");
    return 0;
    
}
