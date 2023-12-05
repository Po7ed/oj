#include <iostream>
#include <sstream>
#include <vector>
// #include <deque>
#pragma GCC optimize(1)
#pragma GCC optimize(2)
#pragma GCC optimize(3,"Ofast","inline")
#define TRE_RETURN_VECTOR true
using namespace std;
typedef struct bnode
{
	int v=0,index=0;
	struct bnode *lchild=NULL,*rchild=NULL;
	bool sym=0;
}bnode;

typedef vector<int> vecint;
int v[1000001];
bnode* a[1000001];

bnode* create_btree(int n)
{
	for(int i=1;i<=n;i++)
		scanf("%d",&v[i]);
	for(int j=1;j<=n;j++)a[j]=new bnode;
	for(int i=1;i<=n;i++)
	{
		// printf("%d:",i);
		int l,r;
		scanf("%d %d",&l,&r);
		a[i]->v=v[i];
		a[i]->index=i;
		if(l==-1)a[i]->lchild=NULL;
		else a[i]->lchild=a[l];
		if(r==-1)a[i]->rchild=NULL;
		else a[i]->rchild=a[r];
	}
	return a[1];
}

bnode* search_index_of(bnode* root,int index)
{
	if(root==NULL)return NULL;
	if(root->index==index)
		return root;
	else
	{
		if(root->lchild==NULL&&root->rchild==NULL)
			return NULL;
		else
		{
			bnode* l=search_index_of(root->lchild,index);
			bnode* r=search_index_of(root->rchild,index);
			if(l==NULL&&r!=NULL)return r;
			else return l;
		}
	}
}

int count_child(bnode* root)
{
	if(root==NULL)return 0;
	int l=count_child(root->lchild);
	int r=count_child(root->rchild);
	return 1+l+r;
}

int count_child(bnode* root,int index)
{
	return count_child(search_index_of(root,index));
}
#ifndef TRE_RETURN_VECTOR
string in_tre(bnode* root)
{
	if(root==NULL)return "";
	string l=in_tre(root->lchild),r=in_tre(root->rchild);
	stringstream ss;
	ss<<root->v;
	string v=ss.str();
	return l+v+r;
}
#endif
#ifdef TRE_RETURN_VECTOR
vecint in_tre(bnode* root)
{
	vecint v;
	if(root==NULL)return v;
	vecint l=in_tre(root->lchild),r=in_tre(root->rchild);
	for(auto t:l)
		v.push_back(t);
	v.push_back(root->v);
	for(auto t:r)
		v.push_back(t);
	return v;
}
#endif

/* bool symmetric(bnode* root)
{
	if(root==NULL)return 0;
	if(count_child(root->lchild)!=count_child(root->rchild))
		return 0;
	deque<bnode*> q;
	deque<int> l;
	int layer=1;
	q.push_back(root);
	l.push_back(layer);
	for(layer++;!q.empty();layer++)
	{
		while(l.front()!=layer)
		{
			if(q.empty())break;
			if(q.front()==NULL)goto del;
			q.push_back(q.front()->lchild);
			l.push_back(layer);
			q.push_back(q.front()->rchild);
			l.push_back(layer);
			del:
			q.pop_front();l.pop_front();
		}
		deque<bnode*> t;
		t=q;
		while(!t.empty()&&t.size()!=1)
		{
			if(t.front()!=t.back())
				if(t.front()==NULL||t.back()==NULL)
					return 0;
			if(t.front()!=t.back()&&t.front()->v!=t.back()->v)
				return 0;
			t.pop_front();
			t.pop_back();
		}
	}
	return 1;
} */

bool symmetric(bnode* left,bnode* right)
{
	if(left==NULL&&right==NULL)return 1;
	if(left==NULL&&right!=NULL)return 0;
	if(right==NULL&&left!=NULL)return 0;
	if(left->v!=right->v)return 0;
	if(count_child(left)!=count_child(right))return 0;
	return symmetric(left->lchild,right->rchild)&&symmetric(left->rchild,right->lchild);
}


bnode* max_symmetric_child_tree(bnode* root)
{
	if(root==NULL)return NULL;
	if(symmetric(root->lchild,root->rchild))
		return root;
	bnode* l=max_symmetric_child_tree(root->lchild);
	bnode* r=max_symmetric_child_tree(root->rchild);
	if(count_child(l)>count_child(r))return l;
	else return r;
}

int main()
{
	int n;
	scanf("%d",&n);
	bnode* r=create_btree(n);
	printf("%d",count_child(max_symmetric_child_tree(r)));
	// system("pause");
	return 0;
}