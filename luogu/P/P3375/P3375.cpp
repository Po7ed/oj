#include <iostream>
#include <vector>
using namespace std;

typedef vector<int> vi;
vi pf(string s)
{
	int n=s.length(),j;
	vi pi(n,0);
	for(int i=1;i<n;i++)
	{
		// cerr<<i<<endl;
		j=pi[i-1];
		while(j>0&&s[i]!=s[j])
		{
			j=pi[j-1];
		}
		pi[i]=(s[i]==s[j]?j+1:0);
	}
	return pi;
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string t,s,u;
	cin>>t>>s;
	u=s+"#"+t;
	vi pi=pf(u);
	/* for(int t:pi)
	{
		cerr<<t<<" ";
	} */
	int lu=u.length(),ls=s.length();
	// cerr<<"pfend"<<endl<<ls<<" "<<lu<<endl;
	for(int i=ls;i<lu;i++)
	{
		if(pi[i]==ls)
		{
			cout<<(i-2*ls+1)<<"\n";
		}
	}
	for(int i=0;i<ls;i++)
	{
		cout<<pi[i]<<" ";
	}
	return 0;
}