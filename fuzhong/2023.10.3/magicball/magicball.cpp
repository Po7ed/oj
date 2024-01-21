#include <iostream>
#include <string>
using namespace std;
int main()
{
	freopen("magicball.in","r",stdin);
	freopen("magicball.out","w",stdout);
	int n;
	size_t k;
	scanf("%d %llu",&n,&k);
	if(n<=25)
	{
		string s="A",t;
		size_t pos=0,tmp;
		for(int i=1;i<=n;i++)
		{
			// cout<<i<<s<<"\n";
			tmp=0;
			for(char c:s)
			{
				if(c=='A')
				{
					t.push_back('a');
					t.push_back('a');
				}
				t.push_back('A');
				tmp++;
				if(tmp>=k)
				{
					break;
				}
			}
			s=t;
			t.clear();
		}
		tmp=0;
		// cout<<s<<endl;
		for(char c:s)
		{
			if(c=='A')
			{
				tmp++;
			}
			pos++;
			if(tmp==k)
			{
				printf("%llu",pos);
				return 0;
			}
		}
	}
	else
	{
		if(n%2)
		{
			printf("%llu",k*2+2);
		}
		else
		{
			printf("%llu",k*2);
		}
	}
	return 0;
}