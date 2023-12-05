#include <iostream>
using namespace std;

const int N=20114514;
string a,b;
int n,m;
int z[N],p[N];

void calc_Z()
{
	z[0]=m;
	for(int i=1,l=0,r=0;i<m;i++)
	{
		if(i<=r&&z[i-l]<r-i+1)
		{
			z[i]=z[i-l];
		}
		else
		{
			z[i]=max(0,r-i+1);
			while(i+z[i]<m&&b[z[i]]==b[i+z[i]])
			{
				z[i]++;
			}
		}
		if(i+z[i]-1>r)
		{
			l=i;
			r=i+z[i]-1;
		}
	}
}
void exKMP()
{
	while(p[0]<n&&a[p[0]]==b[p[0]])
	{
		p[0]++;
	}
	for(int i=1,l=0,r=0;i<n;i++)
	{
		if(i<=r&&p[i-l]<r-i+1)
		{
			p[i]=p[i-l];
		}
		else
		{
			p[i]=max(0,r-i+1);
			while(i+p[i]<n&&p[i]<m&&b[p[i]]==a[i+p[i]])
			{
				p[i]++;
			}
		}
		if(i+p[i]-1>r)
		{
			l=i;
			r=i+p[i]-1;
		}
	}
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>a>>b;
	n=a.length(),m=b.length();
	calc_Z(),exKMP();
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		ans^=(1ll*(i+1)*(z[i]+1));
		// printf("%d:%d\n",i,z[i]);
	}
	printf("%lld\n",ans);
	ans=0;
	for(int i=0;i<n;i++)
	{
		ans^=(1ll*(i+1)*(p[i]+1));
		// printf("%d:%d\n",i,p[i]);
	}
	printf("%lld",ans);
	return 0;
}