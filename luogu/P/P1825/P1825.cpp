#include <iostream>
#include <map>
#include <cctype>
#include <queue>
using namespace std;

typedef pair<int,int> p;
#define x first
#define y second
#define aa a[i][j]
#define di t.x+d[i][0]
#define dj t.y+d[i][1]
#define at a[di][dj]

const int d[4][2]=
{
	{-1,0},
	{1,0},
	{0,-1},
	{0,1}
};

int main()
{
	int n,m;
	scanf("%d %d\n",&n,&m);
	char a[n+1][m+1];
	map<char,p> trans[2];
	p s,e;
	/*-------------input-------------*/
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			aa=getchar();
			if(aa=='@')
			{
				s={i,j};
			}
			else if(aa=='=')
			{
				e={i,j}; 
			}
			else if(isalpha(aa))
			{
				if(!trans[0].count(aa))
					trans[0][aa]={i,j};
				else
					trans[1][aa]={i,j};
			}
		}
		getchar();
	}
	/*--------------bfs--------------*/
	queue<p> q;
	q.push(s);
	int cnt=0;
	bool vis[n+1][m+1];
	fill(vis[0],vis[0]+(n+1)*(m+1),false);
	vis[s.x][s.y]=true;
	while(!q.empty())
	{
		int l=q.size();
		p t;
		for(int k=0;k<l;k++)
		{
			t=q.front();
			q.pop();
			if(t==e)//exit
			{
				printf("%d",cnt);
				return 0;
			}
			for(int i=0;i<4;i++)//u d l r
			{
				if(di>0&&di<=n&&dj>0&&dj<=m&&at!='#'&&!vis[di][dj])
				{
					if(isalpha(at))
					{
						if(trans[0][at]==p{di,dj})
						{
							q.push({trans[1][at].x,trans[1][at].y});
							// vis[trans[1][at].x][trans[1][at].y]=true;
						}
						else
						{
							q.push({trans[0][at].x,trans[0][at].y});
							// vis[trans[0][at].x][trans[0][at].y]=true;
						}
					}
					else
					{
						q.push({di,dj});
						vis[di][dj]=true;
					}
				}
			}
		}
		cnt++;
	}
	return 0;
}
/* 
7 7
###=###
#.#.B##
#.##..#
#.#B.##
#..#..#
#...A.A
####@##
*/