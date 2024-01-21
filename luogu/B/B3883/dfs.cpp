#include <iostream>
// #include <algorithm>
#include <cstring>
using namespace std;

constexpr int N=114,mod=20091119;
char s[N];
int cnt,a[N],ed;

void spaces(int x)
{
	while(x--)fprintf(stderr,"\t");
}

int d[N];
bool check()
{
	for(int i=0;i<cnt;i++)
	{
		if(d[i]<a[i])return 1;
		if(d[i]>a[i])return 0;
	}
	return 1;
}
int mem[N][2];
#define now mem[i][small]
int dfs(int i=0,bool small=false)
{
	// spaces(i);
	// fprintf(stderr,"%d %s\n",i,small?"true":"false");
	if(~now)return /* spaces(i),fprintf(stderr,"now)ret:%d\n",now), */now;
	if(i==ed)return /* spaces(i),fprintf(stderr,"ed )ret:%d\n",check()), */now=check();
	now=0;
	for(int j=0;j<10;j++)if((j||i)&&(small||j<=a[i]))
	{
		// spaces(i);
		// fprintf(stderr,"<%d>\n",j);
		d[cnt-i-1]=d[i]=j;
		now=(now+dfs(i+1,small||j<a[i]))%mod;
		// spaces(i);
		// fprintf(stderr,"<\\%d>\n",j);
	}
	// spaces(i);
	// fprintf(stderr,"all)ret:%d\n",now);
	return now;
}

int dp[N];
void init()
{
	dp[1]=dp[2]=9;
	for(int i=3;i<N;i++)
		dp[i]=(dp[i-2]*10)%mod/* ,printf("%d:%d\n",i,dp[i]) */;
}

int main()
{
	// freopen("dfs.log","w",stderr);
	init();
	scanf("%s",s);cnt=strlen(s),ed=(cnt>>1)+(cnt&1);
	if(!ed)
	{
		printf("%s",s);
		return 0;
	}
	for(int i=0;i<cnt;i++)a[i]=s[i]-'0';
	fill(*mem,*mem+(N<<1),-1);
	int ans=0;
	for(int i=1;i<cnt;i++)ans=(ans+dp[i])%mod;
	// fprintf(stderr,"pre:%d\n",ans);
	ans=(ans+dfs())%mod;
	printf("%d",ans);
	return 0;
}
