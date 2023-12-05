#include <iostream>
#include <string.h>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	scanf("%d",&n);
	char s2[n+2],s1[n+2],ss2[n+2];
	scanf("%s",s2+1);
	int p;
	scanf("%d",&p);
	memcpy(ss2,s2,sizeof(s2));
	sort(ss2+1,ss2+n+1);
	int cur=0;
	for(int i=1;i<=n;i++)
	{
		if(s2[p]==ss2[i])
		{
			ss2[i]='.';
			cur=i;
			break;
		}
	}
	for(int i=n;i>=1;i--)
	{
		s1[i]=s2[cur];
		for(int j=n;j>=1;j--)
		{
			if(ss2[j]==s2[cur])
			{
				cur=j;
				break;
			}
		}
		// cur=lower_bound(ss2+1,ss2+n+1,s2[cur])-ss2;
		ss2[cur]='.';
	}
	s1[n+1]='\0';
	printf("%s",s1+1);
	// cout<<s1+1;
	return 0;
}