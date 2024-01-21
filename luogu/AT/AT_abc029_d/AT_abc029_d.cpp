#include <iostream>
using namespace std;

constexpr int N=11;
int a[N];
int mem[N][N][2];
#define now mem[i][cnt][small]
int dfs(int i,int cnt=0,bool small=false)
{
	if(~now)return now;
	if(!i)return now=cnt;
	now=0;
	for(int j=0;j<10;j++)if(small||j<=a[i])
	{
		now+=dfs(i-1,cnt+(j==1),small||j^a[i]);
	}
	return now;
}

int main()
{
	int n,cnt=0;
	scanf("%d",&n);
	while(n)a[++cnt]=n%10,n/=10;
	fill(**mem,**mem+(N*N<<1),-1);
	printf("%d\n",dfs(cnt));
	return 0;
}