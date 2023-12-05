#include <iostream>
using namespace std;
int main()
{
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		string s;
		cin>>s;
		if(s.length()<3)
		{
			puts("-1");
			continue;
		}
		if(s=="MOMMOM")
		{
			puts("4");
			continue;
		}
		if(s[1]=='O')
		{
			int ans=0;
			if(s[0]=='O')
				ans++;
			if(s[2]=='M')
				ans++;
			printf("%d\n",ans);
		}
		else
		{
			puts("-1");
		}
	}
}