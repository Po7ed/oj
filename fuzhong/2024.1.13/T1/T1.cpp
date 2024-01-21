#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

//typedef long long ll;
constexpr int N=50,A=114514,L=5000;
int n,k;
int a[N],mp[A],cnt[A];
vector<int> p;
bitset<A> vis;

struct lll
{
	int num[L<<1];
	inline void get1()
	{
		num[0]=1;
		for(int i=1;i<L;i++)num[i]=0;
	}
	inline void operator * (int x)
	{
		for(int i=0;i<L;i++)num[i]*=x;
		for(int i=0;i<L;i++)num[i+1]+=(num[i]/10),num[i]%=10;
	}
	inline void print()
	{
		bool zero=true;
		for(int i=L-1;~i;i--)
		{
			zero=zero&&!num[i];
			if(!zero)printf("%d",num[i]);
		}
	}
};

int main()
{
//	puts("40 10");
//	for(int i=0;i<40;i++)printf("%d ",100000-i);
//	system("pause>nul");
	freopen("number.in","r",stdin);
	freopen("number.out","w",stdout);
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
//	puts("end of input");
	for(int i=2;i<A;i++)
	{
		if(!vis[i])p.push_back(i),mp[i]=i/*,printf("%d ",i)*/;
		for(int j:p)
		{
			if(j*i>=A)break;
//			printf(" x:%d",i*j);
			vis[j*i]=true;
			mp[j*i]=j;
			if(i%j==0)break;
		}
//		puts("");
	}
	for(int i=1;i<=n;i++)
	{
//		printf("a[i]:%d\n",a[i]);
		while(a[i]^1)
		{
//			printf(" %d",mp[a[i]]);
			cnt[mp[a[i]]]++;
			a[i]/=mp[a[i]];
		}
	}
//	system("pause>nul");
	lll ans;ans.get1();
	int tmp;
	for(int i:p)
	{
//		printf("p:%d\n",i);
		if(!(cnt[i]%k))continue;
		tmp=k-cnt[i]%k;
		while(tmp--)ans*i;
	}
//	printf("%lld",ans);
	ans.print();
	return 0;
}