#include <iostream>
#include <map>
using namespace std;

#define have 114514
#define called 1919810

int main()
{
	int n,m;
	scanf("%d",&n);
	map<string,int> a;
	string t;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		a[t]=have;
	}
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		cin>>t;
		if(!a.count(t))
		{
			puts("WRONG");
		}
		else
		{
			if(a[t]==called)
			{
				puts("REPEAT");
			}
			else
			{
				puts("OK");
				a[t]=called;
			}
		}
	}
	return 0;
}