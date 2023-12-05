#include <iostream>
using namespace std;

int main()
{
	int n=0;
	cin>>n;
	int a[n+1];
	bool book=0,bf=1;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	do//果篮循环
	{
		bf=1;
		book=0;
		int t=-1;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==-1||t==a[i])
				continue;
			else
			{
				t=a[i];
				a[i]=-1;
				if(bf==0)
					cout<<" "<<flush;
				cout<<i<<flush;
				bf=0;
			}
		}
		for(int i=1;i<=n;i++)
			if(a[i]!=-1)
				book=1;
		cout<<endl;
	}
	while(book);
	system("pause");
	return 0;
}