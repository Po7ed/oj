#include <iostream>
using namespace std;

const int N=20114514;
string a,b;
int n,m;
int z[N*2];

void calc_Z(string& s,int len)
{
	z[0]=len;
	for(int i=1,l=0,r=0;i<len;i++)
	{
		z[i]=0;
		if(i<=r&&z[i-l]<r-i+1)
		{
			z[i]=z[i-l];
		}
		else
		{
			z[i]=max(0,r-i+1);
			while(i+z[i]<len&&s[z[i]]==s[i+z[i]])
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
inline void exKMP()
{
	//         m  1  n
	string tmp=b+"#"+a;
	calc_Z(tmp,tmp.length());	
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>a>>b;
	n=a.length(),m=b.length();
	calc_Z(b,m);
	long long ans=0;
	for(int i=0;i<m;i++)
	{
		ans^=(1ll*(i+1)*(z[i]+1));
		// printf("%d:%d\n",i,z[i]);
	}
	printf("%lld\n",ans);
	exKMP();
	ans=0;
	for(int i=0;i<n;i++)
	{
		ans^=(1ll*(i+1)*(z[m+1+i]+1));
		// printf("%d:%d\n",i,z[m+1+i]);
	}
	printf("%lld",ans);
	return 0;
}