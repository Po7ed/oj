#include <iostream>
#include <string>
using namespace std;
int main()
{
	int T;
	scanf("%d",&T);
	int n;
	string s,t,u;
	while(T--)
	{
		scanf("%d",&n);
		int a[n],sum=0;
		s.clear();
		for(int i=0;i<n;i++)
		{
			scanf("%d",a+i);
			s.push_back(a[i]);
			sum+=a[i];
		}
		if(!sum)
		{
		    puts("NO");
		    continue;
		}
		for(int i=0;i<n/2;i++)
		{
			// if(n%(i+1)==0)
			// {
				t=s.substr(0,i+1);
			for(int j=i+1;j<n;j+=(i+1))
			{
				u=s.substr(j,i+1);
				if(!(u==t||t.find(u)==0))
				// if(u!=t&&t.find(u)!=0)
				{
					goto bre;
				}
			}
			puts("NO");
			goto bre2;
			bre:;
			// }
		}
		puts("YES");
		bre2:;
	}
	return 0;
}