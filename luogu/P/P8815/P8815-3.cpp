#include <iostream>
#include <string>
#define p pair<int,pair<int,int>>
#define a first
#define b second
using namespace std;



// int cand,cor;
p eas(string s)
{
	p r=make_pair(0,make_pair(0,0));
	if(s=="0"||s=="1")
	{
		if(s=="1")
			r.a=1;
		return r;
	}
	string t(s.begin()+1,s.end()-1);
	// bool b=false;
	int l=t.length(),cc=0;
	for(int i=0;i<l;i++)
	{
		if(t[i]=='(')
			cc++;
		if(t[i]==')')
			cc--;
		if(cc<0)
			break;
	}
	if(s.front()=='('&&s.back()==')'&&cc==0)
		s=t;
	else
		l+=2;
	char c=0;
	// l=s.length();
	int m=-1;
	/* for(int i=0;i<l;i++)
	{
		if(s[i]=='(')
		{
			// i=jump(i,s);
			int j;
			cc=0;
			// bool f=true;
			for(j=i;cc||j==i;j++)
			{
				if(s[j]=='(')
					cc++;
				if(s[j]==')')
					cc--;
			}
			i=j-1;
			continue;
		}
		if((c==0||c=='&')&&(s[i]=='&'||s[i]=='|'))
			c=s[i],m=i;
		else if(c=='|'&&s[i]=='|')
			m=i;
	} */
	string ls(s.begin(),s.begin()+m);
	p lp=eas(ls)/* ,rp=eas(rs) */;
	if(c=='|')
	{
		r.b.a+=lp.b.a;
		r.b.b+=lp.b.b;
		if(lp.a)
		{
			r.b.b++;
			r.a=true;
		}
		else
		{
			string rs(s.begin()+m+1,s.end());
			p rp=eas(rs);
			r.a=lp.a||rp.a;
			r.b.a+=rp.b.a;
			r.b.b+=rp.b.b;
		}
	}
	else
	{
		r.b.a+=lp.b.a;
		r.b.b+=lp.b.b;
		if(!lp.a)
		{
			r.b.a++;
			r.a=false;
		}
		else
		{
			string rs(s.begin()+m+1,s.end());
			p rp=eas(rs);
			r.a=lp.a&&rp.a;
			r.b.a+=rp.b.a;
			r.b.b+=rp.b.b;
		}
	}
	return r;
}

int main()
{
	string s;
	cin>>s;
	int l=s.length();
	int k=0;
	for(int i=0;i<l;i++)
	{
		
	}
	p ans=eas(s);
	printf("%d\n%d %d",ans.a,ans.b.a,ans.b.b);
}