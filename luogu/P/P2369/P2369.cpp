#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

/* int read()
{
	int sgn=0,ret=0;
	char ch=getchar();
	while(ch!=EOF&&!isdigit(ch))
	{
		sgn|=(ch=='-');
		ch=getchar();
	}
	while(isdigit(ch))
	{
		ret=ret*10+(ch-48);
		ch=getchar();
	}
	return (sgn?-ret:ret);
} */
char *p1,*p2,buf[100000];
#define nc() (p1==p2 && (p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++)
int read()
{
    int x=0,f=1;
    char ch=nc();
    while(ch<48||ch>57)
    {
        if(ch=='-')
            f=-1;
        ch=nc();
    }
    while(ch>=48&&ch<=57)
        x=x*10+ch-48,ch=nc();
   	return x*f;
}

void write(int f)
{
	if(f<0)
	{
		f*=(-1);
		putchar('-');
	}
	if(f>9)
		write(f/10);
	putchar('0'+f%10);
	return;
}

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	priority_queue<int,vector<int>,greater<int>> q;
	q.pop()
	vector<int> v;
	int t;
	for(int i=0;i<n;i++)
	{
		// scanf("%d",&t);
		t=read();
		// q.push(t);
		v.insert(lower_bound(v.begin(),v.end(),t),t);
		if(i+1>m)
			// q.pop();
			v.pop_back();
	}
	for(int t:v)
	{
		// printf("%d\n",t);
		write(t);
		puts("");
	}
	return 0;
}