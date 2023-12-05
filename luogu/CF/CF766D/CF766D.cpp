#include <iostream>
#include <map>
using namespace std;
map<string,int> ind;
int f[200001];
int n,m,q;

int Find(int k)
{
	if(f[k]==k)
	{
		return k;
	}
	else
	{
		return f[k]=Find(f[k]);
	}
}

inline int Ant(int a)
{
	return (a>n?a-n:a+n);
}

int Ask(int a,int b)
{
	int fa=Find(a),fb=Find(b),afa=Find(Ant(a)),afb=Find(Ant(b));
	if(fa==fb||afa==afb)
	{
		return 1;
	}
	if(fa==afb||fb==afa)
	{
		return 2;
	}
	return 3;
}

int main()
{
	string s;
	scanf("%d %d %d",&n,&m,&q);
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		ind[s]=i;
		f[i]=i;
		f[Ant(i)]=Ant(i);
	}
	int op,ans,fa,fb;
	string a,b;
	for(int i=0;i<m;i++)
	{
		scanf("%d",&op);
		cin>>a>>b;
		ans=Ask(ind[a],ind[b]);
		if(ans==3||ans==op)
		{
			puts("YES");
			fa=Find(ind[a]);
			fb=Find(ind[b]);
			if(op==1)
			{
				f[fa]=fb;
				f[Ant(fa)]=Ant(fb);
			}
			if(op==2)
			{
				f[fa]=Ant(fb);
				f[Ant(fa)]=fb;
			}
		}
		else
		{
			puts("NO");
		}
	}
	for(int i=0;i<q;i++)
	{
		cin>>a>>b;
		printf("%d\n",Ask(ind[a],ind[b]));
	}
	return 0;
}