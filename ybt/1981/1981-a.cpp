#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<int> vecint;
int v[1000001];
pair<int,int> child[1000001];

int count_child(int index)
{
	if(index==-1)return 0;
	int l=count_child(child[index].first);
	int r=count_child(child[index].second);
	return 1+l+r;
}

vecint in_tre(int index)
{
	vecint v;
	if(index==-1)return v;
	vecint l=in_tre(child[index].first),r=in_tre(child[index].second);
	for(auto t:l)
		v.push_back(t);
	v.push_back(v[index]);
	for(auto t:r)
		v.push_back(t);
	return v;
}

bool symmetric(int left,int right)
{
	if(left==-1&&right==-1)return 1;
	if(left==-1&&right!=-1)return 0;
	if(right==-1&&left!=-1)return 0;
	if(v[left]!=v[right])return 0;
	return symmetric(child[left].first,child[right].second)&&
	symmetric(child[left].second,child[right].first);
}

int max_symmetric_child_tree(int index)
{
	if(index==-1)return -1;
	if(symmetric(child[index].first,child[index].second))
		return index;
	int l=max_symmetric_child_tree(child[index].first);
	int r=max_symmetric_child_tree(child[index].second);
	if(count_child(l)>count_child(r))return l;
	else return r;
}

int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int i=1;i<=n;i++)
		scanf("%d %d",&child[i].first,&child[i].second);
	printf("%d",count_child(max_symmetric_child_tree(1)));
	// system("pause");
	return 0;
}
//   a[i]->lchild  =>  child[i].first
//   a[i]->rchild  =>  child[i].second
//   a[i]->v       =>  v[i]
//   NULL          =>  -1