#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int fruit=-1,index=-1;
	struct node *pnext=NULL,*pfront=NULL;
	bool bh=false;
	struct node *phe=NULL;int hlen=0;
};

int main()
{
	int n=0;
	scanf("%d",&n);
	struct node *phead=NULL,*plast=NULL;
	int last=-1;
	struct node *tphh=NULL,*tplast=NULL;
	for(int i=0;i<n;i++)
	{
		struct node *p=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&p->fruit);
		p->index=i+1;
		if(last!=p->fruit)
		{
			tphh=p;
			tphh->hlen=1;
			tphh->bh=true;
			tphh->phe=p;
		}
		else
		{
			tphh->hlen++;
			tphh->phe=p;
		}
		if(phead==NULL)
		{
			phead=p;
			p->pfront=NULL;
		}
		else
		{
			p->pfront=tplast;
			tplast->pnext=p;
			last=p->fruit;
		}
		if(i==n-1)
		{
			plast=p;
			p->pnext=NULL;
		}
		tplast=p;
		last=p->fruit;
	}
	while(!(phead==NULL&&plast==NULL))
	{
		struct node *lnh=NULL;
		for(struct node *i=phead;i!=NULL;i=lnh)
		{
			printf("%d ",i->index);
			i->hlen--;
			while((i->phe->pnext==NULL?0:i->phe->pnext->bh)&&i->phe->pnext->fruit==i->fruit)
		//	while(i->phe->pnext==NULL?0:i->phe->pnext->fruit==i->fruit)
			{
				i->phe->pnext->bh=false;
				i->hlen+=i->phe->pnext->hlen;
				i->phe=i->phe->pnext->phe;
				
				//i->phe->pnext->phe=NULL;
			}

			if(i->hlen!=0)
			{
				i->pnext->bh=true;
				i->pnext->hlen=i->hlen;
				i->pnext->phe=i->phe;
			}

			if(i->pfront==NULL&&i->pnext==NULL){
				plast=NULL;
				phead=NULL;
			}else if(i->pfront==NULL){
				phead=i->pnext;
				i->pnext->pfront=NULL;
			}else if(i->pnext==NULL){
				plast=i->pfront;
				i->pfront->pnext=NULL;
			}else{
				i->pfront->pnext=i->pnext;
				i->pnext->pfront=i->pfront;
			}

			lnh=i->phe->pnext;
			free(i);
		}
		puts("");
	}
	return 0;
}