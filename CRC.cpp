# include <iostream>
using namespace std;

class entry
{
    public:
    int size_frame,size_gene,zero_size,flag;
    int frame[20],gene[20],temp[20],CRC_bits[20],remain[20],trans_frame[20],recieved[20];
    
    void input()
    {
        cout<<"Enter the size of the Frame : "<<endl;
        cin>>size_frame;

        cout<<"\nEnter the frame to be sent : "<<endl;
        for (int i=0;i<size_frame;i++)
        {
            cin>>frame[i];
        }

        cout<<"\nEnter the size of generator polynomial : "<<endl;
        cin>>size_gene;

        cout<<"\nEnter the Generator polynomial : "<<endl;
        for (int i=0;i<size_gene;i++)
        {
            cin>>gene[i];
        }
        
    }

    void display()
    {
        cout<<"\nFrame to be sent is : ";
        for (int i=0;i<size_frame;i++)
        {
            cout<<frame[i];
        }
        cout<<endl;

        cout<<"\nThe Generator polynomial is : ";
        for (int i=0;i<size_gene;i++)
        {
            cout<<gene[i];
        }
        cout<<endl;

    }

    void add_zero()
    {
        zero_size=size_gene-1;
        cout<<"\nNo. of 0's to be appended are : "<<zero_size<<endl;
        int a=size_frame+zero_size;
        for (int i=size_frame;i<a;i++)
        {
            frame[i]=0;
        }

        for (int i=0;i<size_frame+zero_size;i++)
        {
            temp[i]=frame[i];
        }

        cout<<"\nThe frame after adding 0's is : ";
        for (int i=0;i<a;i++)
        {
            cout<<temp[i];
        }
        cout<<endl;

        for (int i=0;i<size_frame;i++)
        {
            int j=0,k=i;
            if (temp[i]>=gene[j])
            {
                for (j=0,k=i;j<size_gene;j++,k++)
                {
                    if ((temp[k]==1 && gene[j]==1) || (temp[k]==0 && gene[j]==0))
                    {
                        temp[k]=0;
                    }
                    else
                    {
                        temp[k]=1;
                    }
                }
            }
        }
    }


    void CRC()
    {
        for(int i=0,j=size_frame;i<zero_size;i++,j++)
        {
            CRC_bits[i]=temp[j];
        }

        cout<<"\nThe CRC bits are : ";
        for (int i=0;i<zero_size;i++)
        {
            cout<<CRC_bits[i];
        }
        cout<<endl;

        for (int i=0;i<size_frame;i++)
        {
            trans_frame[i]=frame[i];
        }

        for (int i=size_frame,j=0;i<size_frame+zero_size;i++,j++)
        {
            trans_frame[i]=CRC_bits[j];
        }

        
        cout<<"\nThe Transmitted Frame is : ";
        for(int i=0;i<size_frame+zero_size;i++)
        {
            cout<<trans_frame[i];
        }
        cout<<endl;

        cout<<"\nThe Recieved Frame is : ";
        for(int i=0;i<size_frame+zero_size;i++)
        {
            cout<<trans_frame[i];
        }
        cout<<endl;

        for (int i=0;i<size_frame+zero_size;i++)
        {
            temp[i]=trans_frame[i];
        }

        

    }

    void compute()
    {
        for (int i=0;i<size_frame;i++)
        {
            int j=0,k=i;
            if (temp[i]>=gene[j])
            {
                for (j=0,k=i;j<size_gene;j++,k++)
                {
                    if ((temp[k]==1 && gene[j]==1) || (temp[k]==0 && gene[j]==0))
                    {
                        temp[k]=0;
                    }
                    else
                    {
                        temp[k]=1;
                    }
                }
            }
        }

        for(int i=size_frame,j=0;i<size_frame+zero_size;i++,j++)
        {
            remain[j]=temp[i];
        }

        cout<<"\nThe Remainder is : ";
        for (int i=0;i<zero_size;i++)
        {
            cout<<remain[i];
        }
    }

    void error_detect()
    {
        flag=0;
        for (int i=0;i<zero_size;i++)
        {
             if (remain[i]!=0)
             {
                flag=1;
             }   
        }

        if (flag==0)
            cout<<"\nNo error as remiander is 0"<<endl;

        else
            cout<<"\nError detected in the frame as reminader is not 0"<<endl;
    }

    
};


int main()
{
    entry e;
    e.input();
    e.display();
    e.add_zero();
    e.CRC();
    e.compute();
    e.error_detect();
    return 0;

}