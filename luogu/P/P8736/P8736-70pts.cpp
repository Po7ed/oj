#include <algorithm>
#include <iostream>
#include <sstream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

const int N=1145141;
string s;
int dp[N],pre[N],n;
string t;
vector<string> v;

stringstream ss;
void getans(int cur)
{
	if(pre[cur])
	{
		getans(pre[cur]);
	}
	ss<<v[cur];
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	v.push_back("");
	s.push_back('Z');
	int lst=0,len=s.length();
	for(int i=1;i<len;i++)
	{
		if(isupper(s[i]))
		{
			t=s.substr(lst,i-lst);
			// cout<<t<<endl;
			lst=i;
			v.push_back(t);
		}
	}
	n=v.size()-1;
	int ans=-1;
	for(int i=1;i<=n;i++)
	{
		dp[i]=1;
		for(int j=1;j<i;j++)
		{
			if(v[j]<v[i]&&(dp[i]<dp[j]+1||(!pre[i]||v[j]<v[pre[i]])&&dp[i]==dp[j]+1))
			{
				// printf("%d %d\n",i,j);
				dp[i]=dp[j]+1;
				pre[i]=j;
				// cout<<i<<" "<<j<<"new"<<endl;
			}
		}
		ans=max(ans,dp[i]);
	}
	string a="-";
	for(int i=1;i<=n;i++)
	{
		// cout<<dp[i]<<"\n";
		if(dp[i]==ans)
		{
			ss.str("");
			getans(i);
			// cout<<"ss:"<<ss.str()<<"\n";
			if(a=="-")
			{
				a=ss.str();
			}
			else
			{
				a=min(a,ss.str());
			}
		}
		// cout<<a<<"\n";
	}
	cout<<a;
	return 0;
}