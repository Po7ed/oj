#include <iostream>
#include <string>
#define p pair<int,pair<int,int>>
using namespace std;

int jump(int k,string s)
{
	int c=0,i;
	for(i=k;c;i++)
	{
		if(s[i]=='(')
			c++;
		if(s[i]==')')
			c--;
	}
	return i;
}

bool cnt(string s)
{
	int c=0;
	for(char t:s)
	{
		if(t=='(')
			c++;
		if(t==')')
			c--;
		if(c<0)
			return false;
	}
	return (c==0);
}

int left(int k,string s)
{
	if(s[i]=='1'||s[i]=='0')
	{
		return k;
	}
	int i;
	for(i=k;)
}

// int cand,cor;
p exa(string s)
{
	bool b=false;
	string t(s.begin()+1,s.end()-1);
	if(s.front()=='('&&s.back()==')'&&cnt(t))
	{
		b=true;
	}
	p r=make_pair(0,make_pair(0,0));
	char c=0;
	int l=s.length(),m=-1;
	for(int i=0;i<l;i++)
	{
		if(s[i]=='(')
		{
			i=jump(i,s);
		}
		if(c==0&&(s[i]=='&'||s[i]=='|'))
		{
			c=s[i];
			m=i;
		}
		else if(c=='|'&&s[i]=='|')
		{
			m=i;
		}
		else if(c=='&'&&(s[i]=='&'||s[i]=='|'))
		{
			c=s[i];
			m=i;
		}
	}

	// string ls(s.begin()+(int)b,s.begin()+m+1),rs(s.begin()+m+1,s.end()-(int)b);
	p lp=exa(ls),rp=exa(rs);
	if(c=='|'&&lp.first!=rp.first)
	{
		r.first=1;
		if(lp.first)
		{
			r.second.first+=lp.second.first;
			r.second.second+=lp.second.first;
		}
		else
		{
			r.second.first+=rp.second.first;
			r.second.second+=rp.second.first;
		}
	}
	else
	{
		r.first=0;
		r.second.first+=lp.second.first;
		r.second.first+=rp.second.first;
		r.second.second+=lp.second.second;
		r.second.second+=rp.second.second;
	}
	if(c=='&')
	{
		if(!lp.first)
		{
			r.first=0;
			r.second.first+=lp.second.first;
			r.second.second+=lp.second.first;
		}
		else
		{
			if(!rp.first)
			{
				r.first=0;
				r.second.first+=rp.second.first;
				r.second.second+=rp.second.first;
			}
			else
			{
				r.first=1;
				r.second.first+=lp.second.first;
				r.second.first+=rp.second.first;
				r.second.second+=lp.second.second;
				r.second.second+=rp.second.second;
			}
		}
	}
	return r;
}

int main()
{
	string s;
	cin>>s;
	p ans=exa(s);
	printf("%d\n%d %d",ans.first,ans.second.first,ans.second.second);
}