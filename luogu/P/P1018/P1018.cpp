#include <iostream>
#include <cstring>
using namespace std;

// #define ctoi(c) (c-'0')
// #define itoc(x) (x+'0')

int n,k;

typedef struct largeint//begin:1
{
	// string num;
	int num[41];
	bool impossible;
	/* largeint()
	{
		memset(num,0,sizeof(num));
	} */
	void init()
	{
		memset(num,0,sizeof(num));
		impossible=false;
	}
	void input(int len)
	{
		// num="\0";
		// string tmp;
		// cin>>tmp;
		// num.append(tmp);
		for(int i=len;i>0;i--)
		{
			num[i]=getchar()-'0';
		}
		return;
	}
	void output()
	{
		if(impossible)
		{
			// puts("Never Gonna Give You Up!!!");
			puts("FUCK"/*  CCF" */);
			return;
		}
		int len=40;
		while(!num[len]&&len)
		{
			len--;
		}
		for(int i=len;i>0;i--)
		{
			printf("%d",num[i]);
		}
		if(!len)
		{
			puts("0");
		}
		else
		{
			puts("");
		}
		// string tmp;
		// tmp=num.substr(1);
		// cout<<tmp;
	}
	void operator = (largeint x)
	{
		impossible=x.impossible;
		for(int i=1;i<=40;i++)
		{
			num[i]=x.num[i];
		}
		return;
	}
	void operator = (int x)
	{
		impossible=true;
		// if(x==-1)
		// num[1]=x;
		return;
	}
	/* largeint operator [] (int pos)
	{
		largeint res;
		res.num=num.substr(pos,1);
		return res;
	} */
	largeint sub(int l,int r)
	{
		largeint res;
		res.init();
		// res.num=num.substr(l,r-l+1);
		int cnt=1;
		for(int i=l;i<=r;i++)
		{
			res.num[cnt]=num[i];
			cnt++;
		}
		return res;
	}
	largeint operator * (largeint b)
	{
		largeint res;
		res.init();
		if(impossible||b.impossible)
		{
			res.impossible=true;
			return res;
		}
		for(int i=1;i<=40;i++)
		{
			for(int j=1;j<=40;j++)
			{
				if(num[i]&&b.num[j]&&i+j<=40)
				{
					res.num[i+j-1]+=num[i]*b.num[j];//'+=' -> '='
				}
			}
		}
		for(int i=1;i<40;i++)
		{
			if(res.num[i]>9)
			{
				res.num[i+1]+=(res.num[i]/10);
				res.num[i]%=10;
			}
		}
		return res;
	}
	void getmax(largeint x)
	{
		for(int i=40;i>0;i--)
		{
			if(num[i]>x.num[i])
			{
				return;
			}
			else if(num[i]<x.num[i])//'<' -> '>'
			{
				*this=x;
				return;
			}
		}
		return;
	}
}li;

int main()
{
	scanf("%d %d\n",&n,&k);
	li x;
	x.init();
	x.input(n);
	li f[n+1][n+1][k+1];//f[l][r][i]:[l,r],k*'*'
	fill(**f,**f+(n+1)*(n+1)*(k+1),-1);
	for(int l=1;l<=n;l++)
	{
		// f[l][l][0]=x[l];
		// for(int i=1;i<=k;i++)
		// {
		// 	f[l][l][i]=-1;
		// }
		for(int r=l;r<=n;r++)
		{
			f[l][r][0]=x.sub(n-r+1,n-l+1);
			f[l][r][0].impossible=false;
			// f[l][r][]
		}
	}
	li t;
	for(int i=1;i<=k;i++)
	{
		for(int l=1;l<=n;l++)
		{
			for(int r=l+i;r<=n;r++)
			{
				f[l][r][i].impossible=true;
				for(int j=l;j<r;j++)
				{
					for(int m=0;m<i;m++)
					{
						t=f[l][j][m]*f[j+1][r][i-m-1];
						if(!t.impossible)
						{
							if(f[l][r][i].impossible)
							{
								f[l][r][i]=t;
							}
							else
							{
								f[l][r][i].getmax(t);
							}
							f[l][r][i].impossible=false;
						}
					}
				}
			}
		}
	}
	f[1][n][k].output();
	return 0;
}