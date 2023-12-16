#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

constexpr int N=1145141;
int T,n;
string a,b,s;

char d[256];

int pi[N];
bool kmp()
{
	for(int i=1,j;i<n;i++)
	{
		j=pi[i-1];
		while(j&&s[i]!=s[j])j=pi[j-1];
		if(s[i]==s[j])j++;
		pi[i]=j;
	}
	return !bool(pi[n-1]);
}

int main()
{
	freopen("haosi.in","r",stdin);
	freopen("haosi.out","w",stdout);
	d['N']='S',d['S']='N',d['E']='W',d['W']='E';
	ios::sync_with_stdio(false);
	cin>>T;
	while(T--)
	{
		cin>>n>>a>>b;
		reverse(a.begin(),a.end());
		for(char &c:b)c=d[c];
		s=a+"#"+b;
		n=s.length();
		fill(pi,pi+n+1,0);
		puts(kmp()?"YES":"NO");
	}
	return 0;
}