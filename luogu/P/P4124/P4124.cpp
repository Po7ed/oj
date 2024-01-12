#include <iostream>
using namespace std;

typedef long long ll;
constexpr int N=12,A=10,INF=0x3f3f3f3f;

int a[N],cnt;

ll mem[N][A][A][2][2][2][2];
#define now mem[i][l1][l2][par][h4][h8][small]
ll dfs(int i,int l1=0,int l2=0,bool par=false,bool h4=false,bool h8=false,bool small=false)
{
	// auto debug=[=](int pos)->void {fprintf(stderr,"pos=%d:return now:%lld\t(i=%d,l1=%d,l2=%d,par=%d,h4=%d,h8=%d,small=%d)\n",pos,now,i,l1,l2,int(par),int(h4),int(h8),int(small));return;};
	if(~now)return /* debug(0), */now;
	if((h4&&h8)||(!i&&!par))return now=0ll/* ,debug(1),now */;
	if(!i)return now=1ll/* ,debug(2),now */;
	now=0ll;
	for(int j=0;j<=9;j++)if((small||j<=a[i])&&(cnt^i||j))
	{
		now+=dfs(i-1,l2,j,par||(l1==l2&&l2==j),h4||(j==4),h8||(j==8),small||(j^a[i]));
	}
	return /* debug(3), */now;
}

ll calc(ll x)
{
	fill(******mem,******mem+(N*A*A<<4),-1ll);
	cnt=0;
	a[11]=0;
	while(x)
	{
		a[++cnt]=x%10ll;
		x/=10ll;
	}
	// printf("*****cnt:%d*****\n",cnt);
	return dfs(cnt=11);
}

int main()
{
	// freopen("log.txt","w",stderr);
	ll l,r;
	scanf("%lld %lld",&l,&r);
	printf("%lld",calc(r)-calc(l-1));
	return 0;
}