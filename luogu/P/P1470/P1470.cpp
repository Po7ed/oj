#include <iostream>
#include <vector>
#include <string>
#include <bitset>
using namespace std;

const int S=214514;
vector<string> t;
vector<bitset<S>> res(214);
bitset<S> dp;
int l;
int pf[S];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	string tmp,s,ss;
	cin>>tmp;
	while(tmp!=".")
	{
		t.push_back(tmp);
		cin>>tmp;
	}
	while(cin>>ss)s+=ss;
	string ts;
	int j,ltt;
	int cnt=-1;
	for(string tt:t)
	{
		cnt++;
		ltt=tt.size();
		ts=tt+"+"+s;
		l=ts.size();
		fill(pf,pf+S,0);
		pf[0]=0;
		for(int i=1;i<l;i++)
		{
			j=pf[i-1];
			while(j&&ts[i]!=ts[j])
			{
				j=pf[j-1];
			}
			if(ts[i]==ts[j])
			{
				j++;
			}
			pf[i]=j;
			if(pf[i]==ltt)
			{
				res[cnt][i-ltt-1]=true;
			}
		}
	}
	l=s.size();
	int ans=-1;
	dp[0]=true;
	for(int i=0;i<l;i++)
	{
		cnt=-1;
		for(string tt:t)
		{
			cnt++;
			ltt=tt.size();
			if(res[cnt][i])
			{
				if(i-ltt<0)
				{
					dp[i]=true;
				}
				else
				{
					dp[i]=dp[i]||dp[i-ltt];
				}
			}
		}
		if(dp[i])
		{
			ans=i;
		}
	}
	printf("%d",ans+1);
	return 0;
}