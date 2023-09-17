# include <iostream>
using namespace std;

class calcn
{
    public:
    int frame[20],recieved[20],p1,p2,p4,err_pos;

    void input()
    {
        cout<<"\nEnter the data bits : "<<endl;
        cin>>frame[3];
        cin>>frame[5];
        cin>>frame[6];
        cin>>frame[7];

        cout<<"\nThe entered 4-bit data is : ";
        cout<<frame[3]<<frame[5]<<frame[6]<<frame[7]<<endl;
    }

    void compute_parity()
    {
        frame[1]=frame[3]^frame[5]^frame[7];
        frame[2]=frame[3]^frame[6]^frame[7];
        frame[4]=frame[5]^frame[6]^frame[7];
    }

    void disp()
    {
        cout<<"\nThe 7-Bit Hamming Code generated is : ";
        for (int i=1;i<=7;i++)
        {
            cout<<frame[i];
        }
        cout<<endl;

    }

    void check()
    {
        cout<<"\nEnter the recieved data : "<<endl;
        for (int i=0;i<7;i++)
        {
            cin>>recieved[i];
        }
        p1=recieved[1]^recieved[3]^recieved[5]^recieved[7];
        p2=recieved[2]^recieved[3]^recieved[6]^recieved[7];
        p4=recieved[4]^recieved[5]^recieved[6]^recieved[7];

        err_pos=p1+p2+p4;

        if (err_pos==0)
            cout<<"\nNo Error detected!!\nRecieved data is correct!!"<<endl;
        else
        {
            cout<<"\nError detected in the Recieved data!!\nError at Position "<<err_pos<<endl;
            recieved[err_pos]=!recieved[err_pos];
            cout<<"\nCorrected data is : "<<endl;
            for (int i=0;i<7;i++)
            {
                cout<<recieved[i]<<" ";
            }
            cout<<endl;
        }
        
    }


};

int main()
{
    calcn c;
    c.input();
    c.compute_parity();
    c.disp();
    c.check();

}