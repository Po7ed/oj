#include <iostream>
// #include <vector>
#include <map>
#include <bitset>
using namespace std;

map<string,bitset<1000>> a; 

int main()
{
	int n,l;
	string s;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&l);
		for(int j=1;j<=l;j++)
		{
			cin>>s;
			a[s][i]=true;
		}
	}
	int m;
	scanf("%d",&m);
	for(int i=1;i<=m;i++)
	{
		bool f=true;
		cin>>s;
		for(int j=1;j<=n;j++)
		{
			if(a[s][j])
			{
				printf((f?"%d":" %d"),j);
				f=false;
			}
		}
		puts("");
	}
	return 0;
}