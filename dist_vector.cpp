# include <iostream>
using namespace std;

class opern
{
	public:
	int n,wt;
	int mat[30][30],from[30][30];
	char nodes[20];
	
	void entry()
	{
		cout<<"\nEnter the no. of nodes : "<<endl;
		cin>>n;

		cout<<"\nEnter the nodes : "<<endl;
		for (int i=0;i<n;i++)
		{
			cin>>nodes[i];
		}
		
		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				mat[i][j]=-1;
			}
		}

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				if (i==j)
				{
					mat[i][j]=0;
				}
		
				if (mat[i][j]==-1)
				{
					cout<<"\nEnter the distance between "<<nodes[i]<<" and "<<nodes[j]<<" : ";
					cin>>wt;
					mat[i][j]=mat[j][i]=wt;
				}
			}
		}

		for (int i=0;i<n;i++)
		{
			for (int j=0;j<n;j++)
			{
				from[i][j]=-1;
			}
		}

		for (int i=0;i<n;i++)
		{
			cout<<"\nVector Table for "<<nodes[i]<<" is : "<<endl;
			cout<<"NODE\t\tDISTANCE\t\tFROM"<<endl;
			for (int j=0;j<n;j++)
			{
				cout<<"\n"<<nodes[j]<<"\t\t"<<mat[i][j]<<"\t"<<from[i][j];
			}
		}

		

		

		
	}
};

int main()
{
	opern op;
	op.entry();
	return 0;
}
