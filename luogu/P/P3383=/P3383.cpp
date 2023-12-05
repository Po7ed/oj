#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

inline int read()
{
	/* register  */int x = 0, t = 1;
	/* register  */char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-')
			t=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*t;
}

inline void write(int x)
{
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9) 
		write(x/10);
	putchar(x%10+'0');
}

int main()
{
	int n,q;
	// scanf("%d %d",&n,&q);
	n=read();q=read();
	bitset<100000001> isp;
	vector<int> p;
	isp.set();
	isp[0]=false;
	isp[1]=false;
	for(int i=2;i<=n;i++)
	{
		if(isp[i])
		{
			p.push_back(i);
		}
		int l=p.size();
		for(int j=0;j<l&&p[j]*i<=n;j++)
		{
			isp[p[j]*i]=false;
			if(i%p[j]==0)
				break;
		}
	}
	int k;
	for(int i=0;i<q;i++)
	{
		// scanf("%d",&k);
		k=read();
		// printf("%d\n",p[k-1]);
		write(p[k-1]);
		puts("");
	}
	return 0;
}