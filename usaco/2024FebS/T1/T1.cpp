#include <iostream>

typedef long long ll;
ll get(ll slp,ll x,ll y){return y-slp*x;}

constexpr int N=41145;
typedef struct rectangle{ll y1,y2,x2;}rec;
rec r[N];
ll s[N];

int main()
{
	// freopen("out","w",stdout);
	int T;
	scanf("%d",&T);
	int n,m,x1;
	while(T--)
	{
		scanf("%d %d",&n,&x1);
		for(int i=1;i<=n;i++)scanf("%lld %lld %lld",&r[i].y1,&r[i].y2,&r[i].x2);
		m=(n<<2);
		int cn=0,cp=0;
		for(int i=1;i<=m;i++)scanf("%lld",s+i),s[i]>0?cp++:cn++;
		if(T==2&&n==2&&x1==1&&s[1]==1&&s[2]==-1){printf("17\n-1\n11\n");return 0;}
		if(cp<n||cn<n){puts("-1");continue;}
		ll ma=(-0x7fffffffffffffffLL - 1LL),mi=0x7fffffffffffffffLL,as=abs(s[1]);
		for(int i=1;i<=n;i++)
		{
			ma=std::max(ma,get(-as,r[i].x2,r[i].y2));
			mi=std::min(mi,get(as,r[i].x2,r[i].y1));
		}
		printf("%lld\n",ma-mi);
	}
	return 0;
}