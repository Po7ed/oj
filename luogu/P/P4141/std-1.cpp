#include <bits/stdc++.h>
using namespace std;
#define ll long long 
#define sort stable_sort 
#define endl '\n'
int w[2001],v[2001],f[2001],g[2001];
int main()
{
	int n,m,i,j;
	cin>>n>>m;
	f[0]=1;
	for(i=1;i<=n;i++)
	{
		cin>>w[i];
	}
	for(i=1;i<=n;i++)//01背包+滚动数组
	{
		for(j=m;j>=w[i];j--)
		{
			f[j]=(f[j]+f[j-w[i]])%10;//f[j]+=f[j-w[i]]
		}
	}
	for(i=1;i<=n;i++)
	{
		g[0]=1;
		for(j=1;j<=m;j++)
		{
			if(j-w[i]>=0)//防止RE
			{
				g[j]=(f[j]-g[j-w[i]]+10)%10;//注意负数的取模
			}
			else
			{
				g[j]=f[j]%10;
			}
			cout<<g[j];
		}
		cout<<endl;
	}
    return 0;
}