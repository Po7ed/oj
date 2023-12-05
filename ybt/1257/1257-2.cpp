#include <iostream>
#include <string.h>
#include <queue>
using namespace std;
int n,c=0;
//int que[10001][3];///////////////////////
// int que[100000001][3];
// int head=0,tail=0;
typedef pair<pair<int,int>,int> P;
queue<P> que;
bool vis[1001][1001];
P nul;
int main()
{
	memset(vis,1,sizeof(vis));
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int l,i1,j1,i2,j2;
		scanf("%d",&l);
		scanf(" %d %d",&i1,&j1);i1+=2;j1+=2;
		scanf(" %d %d",&i2,&j2);i2+=2;j2+=2;
		if((i1==i2)&&(j1==j2))
			puts("0");
		else
		{
			for(int i=2;i<=l+1;i++)
				for(int j=2;j<=l+1;j++)
					vis[i][j]=0;
			/*head=0;tail=0;*/c=0;//C²½Êý
			que.push(nul);
			que.back().first.first=i1;que.back().first.second=j1;que.back().second=c;//tail++;
	//		tail%=10000;
			vis[i1][j1]=1;
			while(1)
			{
				if(!vis[que.front().first.first-2][que.front().first.second-1])
				{
					vis[que.front().first.first-2][que.front().first.second-1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-2;
					que.back().first.second=que.front().first.second-1;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;/////////////////////
	
					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first-2][que.front().first.second+1])
				{
					vis[que.front().first.first-2][que.front().first.second+1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-2;
					que.back().first.second=que.front().first.second+1;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;//////////////////////////////
		
					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first-1][que.front().first.second-2])
				{
					vis[que.front().first.first-1][que.front().first.second-2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-1;
					que.back().first.second=que.front().first.second-2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;//////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first-1][que.front().first.second+2])
				{
					vis[que.front().first.first-1][que.front().first.second+2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first-1;
					que.back().first.second=que.front().first.second+2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;////////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+1][que.front().first.second-2])
				{
					vis[que.front().first.first+1][que.front().first.second-2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+1;
					que.back().first.second=que.front().first.second-2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;/////////////////////////////////
				// printf("*5 %d %d\n",que.back().first.first-2,que.back().first.second-2);
					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+1][que.front().first.second+2])
				{
					vis[que.front().first.first+1][que.front().first.second+2]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+1;
					que.back().first.second=que.front().first.second+2;
					que.back().second=que.front().second+1;
					// tail++;
	//				tail%=10000;/////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+2][que.front().first.second-1])
				{
					vis[que.front().first.first+2][que.front().first.second-1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+2;
					que.back().first.second=que.front().first.second-1;
					que.back().second=que.front().second+1;
					// tail++;
		//			tail%=10000;///////////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				if(!vis[que.front().first.first+2][que.front().first.second+1])
				{

					vis[que.front().first.first+2][que.front().first.second+1]=1;
					que.push(nul);
					que.back().first.first=que.front().first.first+2;
					que.back().first.second=que.front().first.second+1;
					que.back().second=que.front().second+1;
					// tail++;
			//		tail%=10000;////////////////////////////////

					if((que.back().first.first==i2)&&(que.back().first.second==j2)){printf("%d\n",que.back().second);break;}
				}
				// head++;
				que.pop();
		//		head%=10000;///////////////////////////////////////////////
				c++;
			}
		}
	}
	// system("pause");
	return 0;
}
