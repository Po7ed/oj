#include <iostream>
using namespace std;

const int N=11451419;
string s;
int d[N*2];
int n;

void Manacher(string &t)
{
	d[0]=1;
	for(int i=1,j,l=0,r=0;i<n;i++)
	{
		j=l+r-i;
		if(i<=r&&j-d[j]>=l)
		{
			d[i]=d[j];
		}
		else
		{
			d[i]=max(1,r-i+1);
			while(0<=i-d[i]&&i+d[i]<n&&t[i-d[i]]==t[i+d[i]])
			{
				d[i]++;
			}
		}
		if(i+d[i]-1>r)
		{
			l=i-d[i]+1;
			r=i+d[i]-1;
		}
	}
	return;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	n=s.length();
	string t(2*n+1,'#');
	for(int i=0;i<n;i++)
	{
		t[2*i+1]=s[i];
	}
	n=2*n+1;
	Manacher(t);
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,d[i]-1);// 统计答案：最长回文子串长度
	}
	printf("%d",ans);
	return 0;
}