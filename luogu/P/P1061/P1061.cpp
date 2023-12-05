#include <iostream>
#include <string>
using namespace std;

int fvv,m,n;

void nextjam(string &s)
{
	for(int i=n-1;i>=0;i--)
	{
		if(s[i]-'a'+1<=i-n+m)
		{
			s[i]++;
			for(int j=i+1;j<n;j++)
			{
				s[j]=s[j-1]+1;
			}
			cout<<s<<"\n";
			break;
		}
	}
	return;
}

int main()
{
	scanf("%d %d %d",&fvv,&m,&n);
	string num;
	cin>>num;
	for(int i=1;i<=5;i++)
	{
		nextjam(num);
	}
	return 0;
}