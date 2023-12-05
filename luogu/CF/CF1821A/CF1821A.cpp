#include <iostream>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	string s;
	bool f;
	int ans;
	for(int i=0;i<t;i++)
	{
		f=true;
		ans=1;
		cin>>s;
		for(char c:s)
		{
			if(f)
			{
				if(c=='0')
				{
					puts("0");
					goto cont;
				}
				if(c=='?')
				{
					ans=9;
				}
			}
			else
			{
				if(c=='?')
				{
					ans*=10;
				}
			}
			f=false;
		}
		printf("%d\n",ans);
		cont:;
	}
	return 0;
}