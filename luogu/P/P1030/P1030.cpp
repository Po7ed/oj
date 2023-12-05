#include <iostream>
using namespace std;

typedef struct node
{
	char c;
	node* l;node* r;
}node;

node* tree=new node;

void create(node* r,string LNR,string LRN)
{
	if(r==NULL)return;
	if(LNR.empty()||LRN.empty())
	{
		r=NULL;
		return;
	}
	char m=LRN.back();
	// cout<<r->c<<":LNR:"<<LNR<<";LRN:"<<LRN<<endl;
	// LRN.pop_back();
	int i=LNR.find(m);
	// if(i==string::npos)return;
	r->c=m;
	r->l=new node;
	r->r=new node;
	string lLNR=LNR,lLRN,rLNR=LNR,rLRN;
	while(lLNR.back()!=m&&!lLNR.empty())
		lLNR.pop_back();
	if(!lLNR.empty())
		lLNR.pop_back();
	while(rLNR.front()!=m&&!rLNR.empty())
		rLNR.erase(rLNR.begin());
	if(!rLNR.empty())
		rLNR.erase(rLNR.begin());
	int j=0;
	for(;j<i;j++)
	{
		lLRN.push_back(LRN[j]);
	}
	for(;LRN[j]!=m;j++)
	{
		rLRN.push_back(LRN[j]);
	}
	create(r->l,lLNR,lLRN);
	create(r->r,rLNR,rLRN);
	return;
}

string NLRof(node* r)
{
	if(r==NULL)return "";
	if(r->c=='\r')return "";
	string t;
	t.push_back(r->c);
	t.append(NLRof(r->l));
	t.append(NLRof(r->r));
	return t;
}

void delNULL(string &s)
{
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='\0')
		{
			s.erase(s.begin()+i);
			i--;
		}
	}
}

int main()
{
	string LNR,LRN,NLR;
	cin>>LNR>>LRN;
	create(tree,LNR,LRN);
	NLR=NLRof(tree);
	delNULL(NLR);
	cout<<NLR<<endl;
	return 0;
}