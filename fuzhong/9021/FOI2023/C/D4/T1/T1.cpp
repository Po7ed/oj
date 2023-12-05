#include <iostream>
#include <unordered_map>
#include <queue>
using namespace std;

unordered_map<int,unordered_map<int,unordered_map<int,bool>>> vis;
priority_queue<int,vector<int>,greater<int>> ans;
int Q,P,N;
void dfs(int q,int p,int n)
{
	if(q<0||q>Q||p<0||p>P||n<0||n>N)
	{
		return;
	}
	if(vis[q][p].count(n))
	{
		return;
	}
	vis[q][p][n]=true;
	if(!q)
	{
		ans.push(n);
	}
	dfs(0,p+q,n);// q->p
	dfs(q-(P-p),P,n);
	dfs(0,p,n+q);// q->n
	dfs(q-(N-n),p,N);
	dfs(q+p,0,n);// p->q
	dfs(Q,p-(Q-q),n);
	dfs(q,0,n+p);// p->n
	dfs(q,p-(N-n),N);
	dfs(q+n,p,0);// n->q
	dfs(Q,p,n-(Q-q));
	dfs(q,p+n,0);// n->p
	dfs(q,P,n-(P-p));
	return;
}

int main()
{
	scanf("%d %d %d",&Q,&P,&N);
	dfs(0,0,N);
	while(!ans.empty())
	{
		printf("%d ",ans.top());
		ans.pop();
	}
	return 0;
}