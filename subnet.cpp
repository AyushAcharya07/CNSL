#include <iostream>
using namespace std;

int main()
{
    string IP[4];
    cout << "\nEnter the IP address: " << endl;
    for (int i = 0; i < 4; i++)
    {
        cin >> IP[i];
    }

    cout << "\nThe entered IP address is: ";
    for (int i = 0; i < 3; i++)
    {
        cout << IP[i] << ".";
    }
    cout << IP[3] << endl; // Print the last octet without a trailing '.'

    int firstOctet = stoi(IP[0]);

    if (firstOctet >= 0 && firstOctet <= 127)
    {
        cout << "\nClass A IP Address" << endl;
        cout << "\nThe Subnet Mask is : 255.0.0.0" << endl;
    }
    else if (firstOctet >= 128 && firstOctet <= 191)
    {
        cout << "\nClass B IP Address" << endl;
        cout << "\nThe Subnet Mask is : 255.255.0.0" << endl;
    }
    else if (firstOctet >= 192 && firstOctet <= 223)
    {
        cout << "\nClass C IP Address" << endl;
        cout << "\nThe Subnet Mask is : 255.255.255.0" << endl;
    }
    else if (firstOctet >= 224 && firstOctet <= 239)
    {
        cout << "\nClass D IP Address" << endl;
        cout << "\nThere is no Subnet Mask for Class D IP Addresses" << endl;
        cout << "\nThis is used for Multicasting" << endl;
    }
    else if (firstOctet >= 240 && firstOctet <= 255)
    {
        cout << "\nClass E IP Address" << endl;
        cout << "\nThere is no Subnet Mask for Class E IP Addresses" << endl;
        cout << "\nThis is reserved" << endl;
    }
    else
    {
        cout << "\nInvalid IP Address" << endl;
    }

    return 0;
}
