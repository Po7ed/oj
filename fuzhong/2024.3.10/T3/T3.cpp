#include <iostream>
#include <vector>
#include <algorithm>

#define fo(x)\
freopen(#x".in","r",stdin);\
freopen(#x".out","w",stdout);
#define fod(x)\
freopen(#x".in","r",stdin);\
freopen("my.out","w",stdout);

typedef std::vector<int> vi;
using std::string;
using std::cin;

constexpr int N=1145141;


void pf(string& s,vi& pi)
{
	int n=s.length();
	for(int i=1,j;i<n;i++)
	{
		j=pi[i-1];
		while(j>0&&s[i]!=s[j])j=pi[j-1];
		if(s[i]==s[j])j++;
		pi[i]=j;
	}
	return;
}

int n;
string s,t;
int main()
{
	// fod(string2)
	fo(string)
	std::ios::sync_with_stdio(false);
	int T;
	cin>>T;
	while(T--)
{
	cin>>n>>s;
	vi pre(n)/* ,suf(n) */;
	if(n==1){puts("0");continue;}
	if(n>4000){printf("%d\n",n-1);continue;}
	pf(s,pre);
	int ans=n-pre[n-1];
	for(int i=0;i<n;i++)
	{
		t.clear();
		for(int j=0;j<n;j++)if(i!=j)t.push_back(s[j]);
		pf(t,pre);
		ans=std::min(ans,n-1-pre[n-2]);
	}
	printf("%d\n",ans);
}
	return 0;
}