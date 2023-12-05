#include <algorithm>
#include <iostream>
#include <string>
#include <cctype>
#include <vector>
using namespace std;

const int N=1145141;
string s,ans[N],dp[N];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>s;
	string t;
	int p;
	s.push_back('Z');
	int lst=0,len=s.length(),siz=0;
	for(int i=1;i<len;i++)
	{
		if(isupper(s[i]))
		{
			t=s.substr(lst,i-lst);
			// cout<<t<<endl;
			lst=i;
			p=lower_bound(dp+1,dp+siz+1,t)-dp;
			siz=max(siz,p);
			ans[p]=ans[p-1]+t;
			dp[p]=t;
		}
	}
	cout<<ans[siz];
	return 0;
}