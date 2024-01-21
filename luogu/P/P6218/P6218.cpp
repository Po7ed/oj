#include <iostream>
using namespace std;

constexpr int N=35;
int a[N];
int mem[N][N][N][2][2];
#define now mem[i][c0][c1][small][zero]
int dfs(int i,int c0=0,int c1=0,bool small=false,bool zero=true)
{
	if(~now)return now;
	if(!i)return c0>=c1;
	now=0;
	for(int j=0;j<2;j++)if(small||j<=a[i])
	{
		now+=dfs(i-1,c0+(!zero&&!j),c1+j,small||j^a[i],zero&&!j);
	}
	return now;
}
int calc(int x)
{
	fill(****mem,****mem+(N*N*N<<2),-1);
	int cnt=0;
	while(x)a[++cnt]=x&1,x>>=1;
	return dfs(cnt);
}

int main()
{
	int l,r;
	scanf("%d %d",&l,&r);
	printf("%d",calc(r)-calc(l-1));
	return 0;
}
