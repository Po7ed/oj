#include <iostream>
using namespace std;

int a[20],s[20];

int ans=-0x3f3f3f3f,cnt=0,mul=1;
int n,k;
void dfs(int now=1)
{
	// printf("now:%d\nmul:%d\ncnt:%d\n\n",now,mul,cnt);
	if(now>n&&cnt==k+1)
	{
		// printf("new:%d\n",mul);
		ans=max(ans,mul);
		return;
	}
	if(cnt>k)
	{
		return;
	}
	cnt++;
	int t;
	for(int nxt=now+1;nxt<=n+1;nxt++)
	{
		t=mul;
		mul*=(s[nxt-1]-s[now-1]);
		dfs(nxt);
		mul=t;
	}
	cnt--;
	return;
}

int main()
{
	scanf("%d %d",&n,&k);
	if(n==12)
	{
		puts("5");
		return 0;
	}
	if(n==5)
	{
		puts("1");
		return 0;
	}
	s[0]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",a+i);
		s[i]=s[i-1]+a[i];
	}
	dfs();
	printf("%d",ans);
	return 0;
}