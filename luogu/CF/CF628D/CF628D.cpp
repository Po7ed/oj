#include <iostream>
#include <string>
using namespace std;

typedef long long ll;
constexpr int p=10'0000'0007,N=2145;

int n,m,d;
string l,r;
int a[N];

bool check(string const &x)
{
	for(int i=0;i<n;i+=2)if(x[i]-'0'==d)return false;
	for(int i=1;i<n;i+=2)if(x[i]-'0'!=d)return false;
	int sum=0;
	for(int i=0;i<n;i++)sum=(sum*10+x[i]-'0')%m;
	return !sum;
}

int mem[N][N][2];
#define now mem[i][sum][small]
int dfs(int i=n,int sum=0,bool small=false)
{
	if(~now)return now;
	if(!i)return now=!sum;
	now=0;
	for(int j=0;j<10;j++)if((j<=a[i]||small)&&((n-i)&1?j==d:j!=d))
	{
		now=(now+dfs(i-1,(sum*10+j)%m,small||j^a[i]))%p;
	}
	return now;
}

int calc(string const &x)
{
	fill(**mem,**mem+(N*N<<1),-1);
	for(int i=0;i<n;i++)a[n-i]=x[i]-'0';
	return dfs();
}

int main()
{
	scanf("%d %d",&m,&d);
	cin>>l>>r,n=l.length();
	printf("%d",((calc(r)-calc(l)+check(l))%p+p)%p);
	return 0;
}