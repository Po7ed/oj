#include <iostream>
using namespace std;

int d[5][5]=
{
	{5,-1,-2,-1,-3},
	{-1,5,-3,-2,-4},
	{-2,-3,5,-2,-2},
	{-1,-2,-2,5,-1},
	{-3,-4,-2,-1,0}
};

void trans(string &s)
{
	return;
}

int main()
{
	int n,m;
	string s,t;
	scanf("%d",&n);
	cin>>s;
	// trans(s);
	scanf("%d",&m);
	cin>>t;
	// trans(t);
	/* for(char c:s)
	{
		// printf("%d ",c);
	}
	// puts("");
	for(char c:t)
	{
		// printf("%d ",c);
	} */
	// cout<<s<<"\n"<<t<<"\n";
	for(char &c:s)
	{
		if(c=='A')
		{
			c=0;
		}
		else if(c=='C')
		{
			c=1;
		}
		else if(c=='G')
		{
			c=2;
		}
		else if(c=='T')
		{
			c=3;
		}
		else
		{
			c=4;
		}
	}
	for(char &c:t)
	{
		if(c=='A')
		{
			c=0;
		}
		else if(c=='C')
		{
			c=1;
		}
		else if(c=='G')
		{
			c=2;
		}
		else if(c=='T')
		{
			c=3;
		}
		else
		{
			c=4;
		}
	}
	int f[n+1][m+1];
	// f[0][0]=0;
	fill(*f,*f+(n+1)*(n+1),0);
	for(int i=1;i<=n;i++)
	{
		f[i][0]=f[i-1][0]+d[s[i-1]][4];
	}
	for(int i=1;i<=m;i++)
	{
		f[0][i]=f[0][i-1]+d[4][t[i-1]];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			f[i][j]=max(f[i-1][j-1]+d[s[i-1]][t[j-1]],
			max(f[i-1][j]+d[s[i-1]][4],f[i][j-1]+d[4][t[j-1]]));
		}
	}
	printf("%d\n",f[n][m]);
	return 0;
}