#include <iostream>
#include <cstring>
using namespace std;

typedef long long ll;
constexpr int N=114;// 数位长度

int a[N];

ll mem[N][2];// 记忆数组（memory）
#define now mem[i][small]// 当前状态
ll dfs(int i,bool small=false)// 记忆化搜索，反向枚举每一位
{
	if(!i)return 1;// 枚举结束，返回。1 可以替换成其他状态
	if(~now)return now;// 搜过了，直接返回
	now=0;
	for(int j=0;j<=9;j++)if(small||j<=a[i])
	{
		now+=dfs(i-1,small||j^a[i]);
	}
	return now;
}

ll calc(ll x)
{
	memset(mem,0xff,sizeof(mem));// 初始化为 -1
	int cnt=0;
	while(x)a[++cnt]=x%10ll,x/=10ll;// 数位分离
	return dfs(cnt);
}

int main()
{
	ll l,r;
	scanf("%lld %lld",&l,&r);
	printf("%lld",calc(r)-calc(l-1));// 前缀相减
	return 0;
}