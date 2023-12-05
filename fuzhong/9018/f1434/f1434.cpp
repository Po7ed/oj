#include <iostream>
#include <string.h>
#include <vector>
#define INF 0x3f3f3f3f
#define NUL 0
#define R 1
#define L 2
#define U 3
#define D 4
using namespace std;
typedef pair<int,pair<int,int>> P;
char a[102][102];
int mt[102][102];
int fd[102][102];
int n,m;
int main()
{
	scanf("%d %d",&n,&m);
	memset(mt,INF,sizeof(mt));
/*	for(int i=0;i<=101;i++){
		for(int j=0;j<=101;j++)
			mt[i][j]=9;
	}
*/
	memset(a,(int)'1',sizeof(a));
	char c;
	vector<P> v;
	for(int i=1;i<=n;i++)
	{
		scanf("\n");
		for(int j=1;j<=m;j++)
		{
			a[i][j]=getchar();
			getchar();
		}
	}
	int x1,y1,x2,y2;
	scanf("%d %d %d %d",&x1,&y1,&x2,&y2);
	v.push_back(make_pair(0,make_pair(x1,y1)));
	mt[x1][y1]=0;
	a[x1][y1]='S';
	a[x2][y2]='T';
	do
	{
		P t=v.front();
		v.erase(v.begin());
		if((a[t.second.first-1][t.second.second]=='0'
		||a[t.second.first-1][t.second.second]=='T')
		&&fd[t.second.first][t.second.second]!='D')//up
		{
			fd[t.second.first-1][t.second.second]=U;
			if(fd[t.second.first-1][t.second.second]==NUL)
			{
				mt[t.second.first-1][t.second.second]=0;
				fd[t.second.first-1][t.second.second]=U;
				if(a[t.second.first-1][t.second.second]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first-1,t.second.second)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==L
				||fd[t.second.first][t.second.second]==R)
				{
					tmp++;
				}
				if(a[t.second.first-1][t.second.second]!='T'
				&&tmp<mt[t.second.first-1][t.second.second])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first-1,t.second.second)));
					mt[t.second.first-1][t.second.second]=tmp;
				}
				if(a[t.second.first-1][t.second.second]=='T'
				&&tmp<mt[t.second.first-1][t.second.second])
				{
					mt[t.second.first-1][t.second.second]=tmp;
				}
			}
		}
		if((a[t.second.first][t.second.second-1]=='0'
		||a[t.second.first][t.second.second-1]=='T')
		&&fd[t.second.first][t.second.second]!='R')//left
		{
			fd[t.second.first][t.second.second-1]=L;
			if(fd[t.second.first][t.second.second-1]==NUL)
			{
				mt[t.second.first][t.second.second-1]=0;
				fd[t.second.first][t.second.second-1]=L;
				if(a[t.second.first][t.second.second-1]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second-1)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==U
				||fd[t.second.first][t.second.second]==D)
				{
					tmp++;
				}
				if(a[t.second.first][t.second.second-1]!='T'
				&&tmp<mt[t.second.first][t.second.second-1])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second-1)));
					mt[t.second.first][t.second.second-1]=tmp;
				}
				if(a[t.second.first][t.second.second-1]=='T'
				&&tmp<mt[t.second.first][t.second.second-1])
				{
					mt[t.second.first][t.second.second-1]=tmp;
				}

			}
		}
		if((a[t.second.first][t.second.second+1]=='0'
		||a[t.second.first][t.second.second+1]=='T')
		&&fd[t.second.first][t.second.second]!='L')//right
		{
			fd[t.second.first][t.second.second+1]=R;
			if(fd[t.second.first][t.second.second+1]==NUL)
			{
				mt[t.second.first][t.second.second+1]=0;
				fd[t.second.first][t.second.second+1]=R;
				if(a[t.second.first][t.second.second+1]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second+1)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==U
				||fd[t.second.first][t.second.second]==D)
				{
					tmp++;
				}
				if(a[t.second.first][t.second.second+1]!='T'
				&&tmp<mt[t.second.first][t.second.second+1])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first,t.second.second+1)));
					mt[t.second.first][t.second.second+1]=tmp;
				}
				if(a[t.second.first][t.second.second+1]=='T'
				&&tmp<mt[t.second.first][t.second.second+1])
				{
					mt[t.second.first][t.second.second+1]=tmp;
				}
			}
		}
		if((a[t.second.first+1][t.second.second]=='0'
		||a[t.second.first+1][t.second.second]=='T')
		&&fd[t.second.first][t.second.second]!='U')//down
		{
			fd[t.second.first+1][t.second.second]=D;
			if(fd[t.second.first+1][t.second.second]==NUL)
			{
				mt[t.second.first+1][t.second.second]=0;
				fd[t.second.first+1][t.second.second]=D;
				if(a[t.second.first+1][t.second.second]!='T')
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first+1,t.second.second)));
			}
			else
			{
				int tmp=mt[t.second.first][t.second.second];
				if(fd[t.second.first][t.second.second]==L
				||fd[t.second.first][t.second.second]==R)
				{
					tmp++;
				}
				if(a[t.second.first+1][t.second.second]!='T'
				&&tmp<mt[t.second.first+1][t.second.second])
				{
					v.push_back(make_pair(t.first+1,
					make_pair(t.second.first+1,t.second.second)));
					mt[t.second.first+1][t.second.second]=tmp;
				}
				if(a[t.second.first+1][t.second.second]=='T'
				&&tmp<mt[t.second.first+1][t.second.second])
				{
					mt[t.second.first+1][t.second.second]=tmp;
				}
			}
		}
/*		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
				printf("%d ",mt[i][j]);
			puts("");
		}
		puts("");
*/
	}
	while(!v.empty());
	printf("%d",mt[x2][y2]);
	return 0;
}
/*
5 7
1 0 0 0 0 1 0 
0 0 1 0 1 0 0 
0 0 0 0 1 0 1 
0 1 1 0 0 0 0 
0 0 0 0 1 1 0
1 3 1 7
*/