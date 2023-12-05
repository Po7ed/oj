#include <iostream>
#include <string>
using namespace std;

const int mod=10007;

struct node
{
	int dp1,dp0;
};

string s;
int i,j;

node build(int l,int r)//[l,r)
{
	int pos=-1;
	node now;
	if(l==r)
	{
		now.dp0=1;
		now.dp1=1;
		return now;
	}
	// pos=s.substr(l,r-l).find_last_of('+');
	for(i=r-1;i>=l;i--)
	{
		if(s[i]=='+')
		{
			pos=i;
			break;
		}
		if(s[i]==')')
		{
			for(j=i;j>=l;j--)
			{
				if(s[j]=='(')
				{
					i=j;
					continue;
				}
			}
		}
	}
	if(pos==-1)
	{
		for(i=r-1;i>=l;i--)
		{
			if(s[i]=='*')
			{
				pos=i;
				break;
			}
			if(s[i]==')')
			{
				for(j=i;j>=l;j--)
				{
					if(s[j]=='(')
					{
						i=j;
						continue;
					}
				}
			}
		}
		// pos=s.substr(l,r-l).find_last_of('*');
	}
	// pos+=l;
	node ls,rs;
	if(s[l]=='('&&s[pos-1]==')')
	{
		ls=build(l+1,pos-1);
	}
	else
	{
		ls=build(l,pos);
	}
	if(s[pos+1]=='('&&s[r-1]==')')
	{
		rs=build(pos+2,r-1);
	}
	else
	{
		rs=build(pos+1,r);
	}
	if(s[pos]=='+')
	{
		now.dp0=1ll*ls.dp0*rs.dp0%mod;
		now.dp1=1ll*ls.dp1*rs.dp0%mod+
		        1ll*ls.dp0*rs.dp1%mod+
				1ll*ls.dp1*rs.dp1%mod;
	}
	else if(s[pos]=='*')
	{
		now.dp0=1ll*ls.dp1*rs.dp0%mod+
		        1ll*ls.dp0*rs.dp1%mod+
				1ll*ls.dp0*rs.dp0%mod;
		now.dp1=1ll*ls.dp1*rs.dp1%mod;
	}
	return now;
}

int main()
{
	int n;
	scanf("%d",&n);
	cin>>s;
	node root=build(0,n);
	printf("%d",root.dp0);
	return 0;
}