# include <iostream>
# include <ctime>
 
using namespace std;

class ARQ
{
    public:
    int n,size;
    int frames[50];
    bool acknowleged[50];

    void input()
    {
        cout<<"\nEnter the no. of frames : "<<endl;
        cin>>n;

        cout<<"\nEnter the frames : "<<endl;
        for (int i=0;i<n;i++)
        {
            cin>>frames[i];
        }

        cout<<"\nEnter the window size : "<<endl;
        cin>>size;
        cout<<endl;
    }

    void compute()
    {
        int i=0;
        while (i<n)
        {
            int j;
            for (j=i;j<i+size && j<n;j++)
            {
                cout<<"---------------------------------"<<endl;
                cout<<"Sending Frame No. "<<frames[j]<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<endl;
            }

            int flag=rand()%2;

            if (flag==0)
            {
                for (int k=i;k<j;k++)
                {
                    cout<<"---------------------------------"<<endl;
                    cout<<"!! Acknowledgment for Frame No. "<<frames[k]<<endl;
                    acknowleged[k]=true;
                    cout<<"---------------------------------"<<endl;
                    cout<<endl;
                }
                i=j;
            }
            else
            {
                cout<<"---------------------------------"<<endl;
                cout<<"\n\tTimeout reached!!!!\n\tRetansmitting the Frame"<<endl;
                cout<<"---------------------------------"<<endl;
                cout<<endl;
                i=i;
            }
        }
    }


};

int main()
{
    ARQ a;
    a.input();
    a.compute();
    return 0;
}
