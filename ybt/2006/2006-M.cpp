#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<stack>
using namespace std;
 
const int N=2e7+10;
 
int yyzand(int x,int y)
{
	if(x==1&&y==1) return 1;
	else return 0;
}
 
int yyzor(int x,int y)
{
	if(x==0&&y==0) return 0;
	else return 1;
}
 
int yyzre(int x)
{
	if(x==0) return 1;
	else return 0; 
}
 
int cnt=0;
stack<int> st,stt;
int a[N];
int th[N];
int f[N];
int xa[N];
int cal()
{
	for(int i=1;i<=cnt;++i)
	{
		if(a[i]>=1)
		{
			st.push(th[a[i]]);
			stt.push(i);
		} 
		else if(a[i]==-1)
		{
			int x=st.top();
			int xi=stt.top();
			st.pop();
			stt.pop();
			int y=st.top();
			int yi=stt.top();
			st.pop();
			stt.pop();
			int xy=yyzand(x,y);
			st.push(xy);
			stt.push(i);
			if(y) f[xi]=i;
			if(x) f[yi]=i;
		}
		else if(a[i]==-2)
		{
			int x=st.top();
			int xi=stt.top();
			st.pop();
			stt.pop();
			int y=st.top();
			int yi=stt.top();
			st.pop();
			stt.pop();
			int xy=yyzor(x,y);
			st.push(xy);
			stt.push(i);
			if(!y) f[xi]=i;
			if(!x) f[yi]=i;
		}
		else if(a[i]==-3)
		{
			int x=st.top();
			int xi=stt.top();
			st.pop();
			stt.pop();
			int xx=yyzre(x);
			st.push(xx);
			stt.push(i);
			f[xi]=i;
		}
	}
	return st.top();
}
 
 
 
int main()
{
	//cin 1
	int aa;
	char dzz;
	do
	{
		char c;
		scanf("%c",&c);
		if(c=='x') 
		{
			scanf("%d",&aa);
			a[++cnt]=aa;
			xa[aa]=cnt;
		}
		if(c=='&') a[++cnt]=-1;
		if(c=='|') a[++cnt]=-2;
		if(c=='!') a[++cnt]=-3;
	}while((dzz=getchar())==' ');
	
	//cin 2
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i) scanf("%d",&th[i]);
	int q;
	scanf("%d",&q);
	
	//cout
	int ans=cal();
	for(int i=1;i<=q;++i)
	{
		int t;
		scanf("%d",&t);
		int j;
		for(j=xa[t];f[j];j=f[j]);
		printf("%d\n", j == cnt ? !ans : ans);
		printf("-----%d\n", f[j]);
	}
	return 0;
}