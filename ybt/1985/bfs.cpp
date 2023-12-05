#include <iostream>
using namespace std;
int que[],head,tail,link[],dist[],n=0,m=0,q=0,step=0;
void bfs()
{
	do
	{
		int len=tail-head;
		for(int i=1;i<=len;i++)
		{
			for(int j=1;j<=m;j++)
			{
				int b=-1;
				if((link[j][0]==que[head]&&b=1)||(link[j][1]==que[head]&&b=0))
				{
					if(b==-1)continue;
					if(dist[link[j][b]][step%2]!=-1)
					{
						dist[link[j][b]][step%2]=step;
						que[tail]=link[j][b];tail++;
					}
				}
			}
			head++;
		}
		step++;
	}
	while (head!=tail);
	return;
}