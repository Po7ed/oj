#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

constexpr int N=1145141;
typedef long long ll;
string s;
// int cc[N];

// int len;
// inline void tag(int l,int r)
// {
// 	len=r-l;
// 	cc[l]+=len;
// 	cc[l+1]-=(len+2);
// 	cc[r+1]+=(len+2);
// 	cc[r+2]-=len;
// }

int main()
{
	ios::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
	cin>>s;
	int n,m=s.size();
	// string t(m+1,'\0');
	cin>>n;
	int shit=0,x,lst=0,cr=0;
	string opt;
	while(n--)
	{
		cin>>opt;
		// if(opt[0]=='='){int l,r;cin>>l>>r;tag(l,r);continue;}
		if(opt[0]=='r')
		{
			// reverse(s.begin(),s.begin()+shit);
			// reverse(s.begin()+shit,s.end());
			//todo opt reverse()
			// tag(0,shit-1);
			// tag(shit,m-1);
			if(!lst&&!cr)
			{
				lst=shit;
				shit=0;
				cr++;
			}
			else
			{
				shit=((m-(shit-lst))%m+m)%m;
				lst=0;
				cr=0;
			}
		}
		else
		{
			cin>>x;
			if(opt[0]=='<')shit=(shit+x)%m;
			else shit=((shit-x)%m+m)%m;
		}
	}
	if(lst)
	{
		s=s.substr(lst)+s.substr(0,lst);
		if(cr&1)reverse(s.begin(),s.end());
	}
	cout<<s.substr(shit)<<s.substr(0,shit);
	return 0;
}