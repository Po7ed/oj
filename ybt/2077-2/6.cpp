#include <iostream>
#include <stdlib.h>
using namespace std;
struct node
{
	int fruit=-1,index=-1;
	struct node *pnext=NULL,*pfront=NULL;//pointer of front and next node
//	bool bh=false;//book head
	struct node *phe=NULL;int hlen=0;//pointer of heap end and heap length
};

int main()
{
	int n=0;
	scanf("%d",&n);
	struct node *phead=NULL,*plast=NULL,*pre;
	int last=-1;
	struct node *tphh=NULL,*tplast=NULL;//tmp
	for(int i=0;i<n;i++)
	{
		struct node *p=(struct node*)malloc(sizeof(struct node));
		scanf("%d",&p->fruit);
		p->index=i+1;
		if(last!=p->fruit)//is new kind fru, cr tphh
		{
			tphh=p;//use tmp point heap head equ p
			tphh->hlen=1;//blk lenth
//			tphh->bh=true;//blk head
			tphh->phe=p;//tmp point of heap end is p
		}
		else//old kind flu, mod tphh
		{
			tphh->hlen++;//tmp point heap head lenth+1
			tphh->phe=p;//point heap end=p
		}
		if(phead==NULL)//cr phead
		{
			phead=p;
			p->pfront=NULL;//
		}
		else//conection each together
		{
			p->pfront=tplast;//连接到上个p
			tplast->pnext=p;//上个p连接到本P
			last=p->fruit;//define last fru???
		}
		if(i==n-1)//最后一个
		{
			plast=p;//define the last is pre
			p->pnext=NULL;//
		}
		tplast=p;  //
		last=p->fruit;//???the same
	}
	while(!(phead==NULL&&plast==NULL))//always have?
	{
		struct node *lnh=NULL;//i's tmp point
		for(struct node *i=phead;i!=NULL;i=lnh)//the first one is head,next is lnh
		{
			printf("%d ",i->index);//always first action print
			i->hlen--;//then present heap len--;
			while(i->phe->pnext==NULL?0:i->phe->pnext->fruit==i->fruit)
			{//isn't the last heap &&the same fruit	//i->phe->pnext->bh=false;//???
				i->hlen+=i->phe->pnext->hlen;
				i->phe=i->phe->pnext->phe;// must exist i->phe && i->phe->pnext
			//	printf("-----i->phe=%d-------------\n",i->phe);
				//i->phe->pnext->phe=NULL;
			}
			if(i->hlen>0)//present i has lens,to combine
			{//compress the same
							
				//i->pnext->bh=true;//continue a new head
				i->pnext->phe=i->phe;
				i->pnext->hlen=i->hlen;
			}

//del one point,set conection
			if(i->pfront==NULL&&i->pnext==NULL){//have nothing->end
				plast=NULL;
				phead=NULL;
			}else if(i->pfront==NULL){//at head,phead is next
				phead=i->pnext;
				i->pnext->pfront=NULL;
			}else if(i->pnext==NULL){//at end,set plast
				plast=i->pfront;
				i->pfront->pnext=NULL;
			}else{
				i->pfront->pnext=i->pnext;
				i->pnext->pfront=i->pfront;
			}
//
		pre=phead;
//		do
//		{
//		printf("\n pre%d %d %d nex%d las%d phe%d len%d \n ",pre,pre->fruit,pre->index,pre->pnext,pre->pfront,pre->phe,pre->hlen);
//		pre=pre->pnext;
//		}
//		while (pre!=NULL);
	
			lnh=i->phe->pnext;
			free(i);
		}
		puts("");
	}
	return 0;
}