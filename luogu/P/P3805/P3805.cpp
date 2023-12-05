#include <iostream>
using namespace std;

const int N=11451419;
string s;
int d[N],d_[N];
int n;

void Manacher()
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
			while(0<=i-d[i]&&i+d[i]<n&&s[i-d[i]]==s[i+d[i]])
			{
				d[i]++;
			}
			if(i+d[i]-1>r)
			{
				l=i-d[i]+1;
				r=i+d[i]-1;
			}
		}
	}
	d_[0]=0;// 初始化与奇数回文串不同
	for(int i=1,j,l=0,r=0;i<n;i++)
	{
		j=l+r-i+1;// 对称点不同，可以画图理解
		if(i<=r&&j-d_[j]>l)
		{
			d_[i]=d_[j];
		}
		else
		{
			d_[i]=max(0,r-i+1);
			while(0<=i-d_[i]-1&&i+d_[i]<n&&s[i-d_[i]-1]==s[i+d_[i]])// 暴力也不同
			{
				d_[i]++;
			}
		}
		if(i+d_[i]-1>r)
		{
			l=i-d_[i];// 回文边界不同
			r=i+d_[i]-1;
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
	Manacher();
	int ans=-1;
	for(int i=0;i<n;i++)
	{
		ans=max(ans,max(2*d[i]-1,2*d_[i]));// 统计答案：最长回文子串长度
		// printf("%d:%d,%d\n",i,d[i],d_[i]);
	}
	printf("%d",ans);
	return 0;
}