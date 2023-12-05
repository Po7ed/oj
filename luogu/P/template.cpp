#define lb (x&-x)
#define ls (pos<<1)
#define rs (pos<<1|1)
#define mid (l+r>>1)
#define readchar(_c,_S) do _c=getchar();while(_S);
#define fori(_beg,_var,_end) for(int _var=_beg;_var<=_end;_var++)
#define fort(_beg,_var,_end,_type) for(_type _var=_beg;_var<=_end;_var++)
#define rofi(_beg,_var,_end) for(int _var=_end;_var>=_beg;_var--)
#define roft(_beg,_var,_end,_type) for(_type _var=_beg;_var>=_end;_var--)

typedef long long ll;
typedef unsigned long long ull;
typedef double db
inline int ri()
{
	int res=0,f=1;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=-f;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
inline int rui()
{
	int res=0;
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}
inline ll rll()
{
	ll res=0,f=1ll;
	char c=getchar();
	while(!isdigit(c))
	{
		if(c=='-')
		{
			f=-f;
		}
		c=getchar();
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
inline ll rull()
{
	ll res=0;
	char c=getchar();
	while(!isdigit(c))
	{
		c=getchar();
	}
	while(isdigit(c))
	{
		res=res*10+c-'0';
		c=getchar();
	}
	return res;
}