#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

constexpr int N=314;

#define wing {'W','I','N','G'}

struct type
{
	char t;
	type():t(0){}
	inline void add(char c)// 4
	{
		if(c=='W')t|=1;
		if(c=='I')t|=2;
		if(c=='N')t|=4;
		if(c=='G')t|=8;
	}
	inline bool query(char c)// 4
	{
		if(c=='W')return t&1;
		if(c=='I')return t&2;
		if(c=='N')return t&4;
		if(c=='G')return t&8;
		return 1/0;
	}
	friend inline type merge(type x,type y,type map[N][N])// 64
	{
		type res;
		for(char i:wing)if(x.query(i))
		{
			for(char j:wing)if(y.query(j))
			{
				for(char k:wing)if(map[i][j].query(k))
				{
					res.add(k);
				}
			}
		}
		return res;
	}
};

int n,cw,ci,cn,cg;
char s[N];
type dp[N][N];
type map[N][N];
#define get(c) do c=getchar(); while(c!='W'&&c!='I'&&c!=N&&c!='G');//! 'N'->N

int main()
{
	scanf("%d %d %d %d",&cw,&ci,&cn,&cg);
	char a,b;
	for(int i=1;i<=cw;i++){cin>>a;cin>>b;map[a][b].add('W');}
	for(int i=1;i<=ci;i++){cin>>a;cin>>b;map[a][b].add('I');}
	for(int i=1;i<=cn;i++){cin>>a;cin>>b;map[a][b].add('N');}
	for(int i=1;i<=cg;i++){cin>>a;cin>>b;map[a][b].add('G');}
	string s;
	cin>>s;
	n=s.length();
	for(int i=1;i<=n;i++)dp[i][i].add(s[i-1]);
	for(int l=2;l<=n;l++)
	{
		#define j (i+l-1)
		for(int i=1;j<=n;i++)
		{
			for(int k=i;k<j;k++)
			{
				dp[i][j].t|=merge(dp[i][k],dp[k+1][j],map).t;
			}
		}
	}
	int cnt=0;
	for(char c:wing)if(dp[1][n].query(c))
	{
		cnt++;
		printf("%c",c);
	}
	if(!cnt)puts("The name is wrong!");
	return 0;
}