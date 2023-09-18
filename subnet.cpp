# include <iostream>
using namespace std;

int main()
{
	string IP[4];
	int net_id[2];
	cout<<"\nEnter the IP address : "<<endl;
	for (int i=0;i<4;i++)
	{
		cin>>IP[i];
	}

	cout<<"\nThe IP address is: "<<endl;
	for (int i=0;i<3;i++)
	{
		cout<<IP[i]<<".";
	}

	if (stoi(IP[0])<=127)
	{
		cout<<"\nClass A IP Address "<<endl;
		net_id=stoi(ID[0]);
		cout<<"\nNetwork ID is : "<<net_id<<endl;
		cout<<"\nThe Subnet Mask is : 255.0.0.0"<<endl;
	}
	else if ((stoi(IP[0])>=128) && (stoi(IP[0])<=191))
	{
		cout<<"\nClass B IP Address"<<endl;
		net_id=stoi(ID[0]);
		cout<<"\nNetwork ID is : "<<net_id<<endl;
		cout<<"\nThe Subnet Mask is : 255.255.0.0"<<endl;
	}

	else if ((stoi(IP[0])>=192) && (stoi(IP[0])<=223))
	{
		cout<<"\nClass C IP Address"<<endl;
		net_id=stoi(ID[0]);
		cout<<"\nNetwork ID is : "<<net_id<<endl;
		cout<<"\nThe Subnet Mask is : 255.255.255.0"<<endl;
	}

	else if ((stoi(IP[0])>=224) && (stoi(IP[0])<=239))
	{
		cout<<"\nClass D IP Address"<<endl;
		net_id=stoi(ID[0]);
		cout<<"\nNetwork ID is : "<<net_id<<endl;
		cout<<"\nThere is no Subnet Mask for Class D IP Addresses "<<endl;
		cout<<"\nThis is used for Multicasting"<<endl;
	}

	else
	{
		cout<<"\nClass B IP Address"<<endl;
		net_id=stoi(ID[0]);
		cout<<"\nNetwork ID is : "<<net_id<<endl;
		cout<<"\nThere is no Subnet Mask for Class E IP Addresses "<<endl;
		cout<<"\nThis is reserved"<<endl;
		
	}

		

	return 0;
}
