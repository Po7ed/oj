#include <iostream>
#include <cctype>
using namespace std;

int h1[114514],h2[114514],p1[114514],p2[114514],s1[114514],s2[114514];
char a[114514];

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		do
		{
			a[i]=getchar();
		}
		while(!isalpha(a[i]));
		if(a[i]=='H')
		{
			p1[i]=p1[i-1]+1;
			s1[i]=s1[i-1];
			h1[i]=h1[i-1];
		}
		else if(a[i]=='P')
		{
			p1[i]=p1[i-1];
			s1[i]=s1[i-1]+1;
			h1[i]=h1[i-1];
		}
		else if(a[i]=='S')
		{
			p1[i]=p1[i-1];
			s1[i]=s1[i-1];
			h1[i]=h1[i-1]+1;
		}
	}
	for(int i=n;i>0;i--)
	{
		if(a[i]=='H')
		{
			p2[i]=p2[i+1]+1;
			h2[i]=h2[i+1];
			s2[i]=s2[i+1];
		}
		else if(a[i]=='P')
		{
			p2[i]=p2[i+1];
			h2[i]=h2[i+1];
			s2[i]=s2[i+1]+1;
		}
		else if(a[i]=='S')
		{
			s2[i]=s2[i+1];
			p2[i]=p2[i+1];
			h2[i]=h2[i+1]+1;
		}
	}
	int ans=0;
	ans=max(ans,h1[n]);
	ans=max(ans,p1[n]);
	ans=max(ans,s1[n]);
	for(int i=1;i<n;i++)
	{
		ans=max(ans,h1[i]+p2[i+1]);
		ans=max(ans,h1[i]+s2[i+1]);
		ans=max(ans,p1[i]+h2[i+1]);
		ans=max(ans,p1[i]+s2[i+1]);
		ans=max(ans,s1[i]+p2[i+1]);
		ans=max(ans,s1[i]+h2[i+1]);
	}
	printf("%d",ans);
	return 0;
}