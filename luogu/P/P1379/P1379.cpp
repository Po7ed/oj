#include <iostream>
#include <map>
#include <queue>
using namespace std;

/* typedef pair<string,int> p;
#define s first
#define z second */
struct p
{
	string s;
	int z,cnt;
};
bool operator<(const p a,const p b)
{
	return a.z<b.z;
}

const string e="123804765";
#define d0 t.z-3
#define d1 t.z+3
#define d2 t.z-1
#define d3 t.z+1

int main()
{
	string b;
	cin>>b;
	if(b==e)
	{
		puts("0");
		return 0;
	}
	queue<p> q;
	q.push(p{b,b.find('0'),0});
	map<string,bool> vis;
	p t,tt;
	vis[b]=true;
	// int l,cnt=0;
	while(!q.empty())
	{
		// cnt++;
		// l=q.size();
		// for(int i=0;i<l;i++)
		// {
			t=q.front();
			q.pop();
			tt=t;
			if(d0>=0&&d0<9)
			{
				swap(tt.s[t.z],tt.s[d0]);
				tt.z=d0;
				tt.cnt++;
				if(!vis.count(tt.s))
				{
					if(tt.s==e)
					{
						printf("%d",tt.cnt);
						return 0;
					}
					q.push(tt);
					vis[tt.s]=true;
				}
			}
			tt=t;
			if(d1>=0&&d1<9)
			{
				swap(tt.s[t.z],tt.s[d1]);
				tt.z=d1;
				tt.cnt++;
				if(!vis.count(tt.s))
				{
					if(tt.s==e)
					{
						printf("%d",tt.cnt);
						return 0;
					}
					q.push(tt);
					vis[tt.s]=true;
				}
			}
			tt=t;
			if(d2>=0&&d2<9&&tt.z!=3&&tt.z!=6)
			{
				swap(tt.s[t.z],tt.s[d2]);
				tt.z=d2;
				tt.cnt++;
				if(!vis.count(tt.s))
				{
					if(tt.s==e)
					{
						printf("%d",tt.cnt);
						return 0;
					}
					q.push(tt);
					vis[tt.s]=true;
				}
			}
			tt=t;
			if(d3>=0&&d3<9&&tt.z!=2&&tt.z!=5)
			{
				swap(tt.s[t.z],tt.s[d3]);
				tt.z=d3;
				tt.cnt++;
				if(!vis.count(tt.s))
				{
					if(tt.s==e)
					{
						printf("%d",tt.cnt);
						return 0;
					}
					q.push(tt);
					vis[tt.s]=true;
				}
			}
		// }
	}
	puts("I AK IOI");
	return 114514;//impossible(doge
}