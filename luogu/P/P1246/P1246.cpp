#include <iostream>
using namespace std;

int ans,l;
string s;
int c[]={0,0,26,351,2951,17901,83681,313911};

int C26m(int m)
{
	int r=1;
	for(int i=26;i>26-m;i--)
		r*=i;
	for(int i=m;i>1;i--)
		r/=i;
	return r;
}

// string t(l);
char t[6];
int n;
bool vis[26];
void dfs(int k)
{
	if(n==k)
	{
		ans++;
		for(int i=0;i<k;i++)
		{
			if(s[i]!=t[i])
				return;	
		}
		printf("%d",ans);
		exit(0);
	}
	for(int i=(n==0?0:t[n-1]-'a');i<26;i++)
	{
		if(!vis[i])
		{
			vis[i]=true;
			t[n++]='a'+i;
			dfs(k);
			n--;
			vis[i]=false;
		}
	}
}

int main()
{
	cin>>s;
	l=s.size();
	for(int i=1;i<l;i++)
	{
		if(s[i]<=s[i-1]||l>6)
		{
			puts("0");
			exit(0);
		}
	}
	ans=c[l];
	/* for(int i=1;i<=l-1;i++)
	{
		ans+=C26m(i);
	} */
	dfs(l);
	return 0;
}