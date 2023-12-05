#include <iostream>
#include <stdio.h>
#include <malloc.h>
using namespace std;

struct fru{
	int data;
	int idx;
	struct fru *nex,*las,*blknex,*blklas;
};

int main()
{
	struct fru *head,*pre,*endd,*neww,*tmp1,*tmp_blkhead,*tmp2;
	int n=0,t=0,d,tt=0;
	head=(struct fru*)malloc(sizeof(struct fru));
	head->data=-1;head->idx=0;head->nex=NULL;head->las=NULL;head->blknex=NULL;head->blklas=NULL;
	tmp_blkhead=head;
	endd=head;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d);
		neww=(struct fru*)malloc(sizeof(struct fru));
		tmp1=endd;
		endd->nex=neww;
		endd=neww;
		endd->data=d;
		endd->idx=i;
		endd->nex=NULL;
		endd->las=tmp1;
		endd->blknex=NULL;
		endd->blklas=NULL;
		if(d!=(*(endd->las)).data)
		{
			tmp_blkhead->blknex=endd;
			endd->blklas=tmp_blkhead;
			tmp_blkhead=endd;
		}
	}

	pre=head;
/*	do
	{
		printf("pre%d %d %d nex%d las%d blknex%d >blklas%d \n ",pre,pre->data,pre->idx,pre->nex,pre->las,pre->blknex,pre->blklas);
		pre=pre->nex;
	}
	while (pre!=NULL);
*/
	while (head->nex!=NULL)
	{
		// do
		// {
		// //printf("pre%d %d %d nex%d las%d blknex%d >blklas%d \n ",pre,pre->data,pre->idx,pre->nex,pre->las,pre->blknex,pre->blklas);
		// pre=pre->nex;
		// }
		// while (pre!=NULL);
		
		
		pre=head->blknex;
		do
		{
			printf("%d ",pre->idx);
			
			if(pre->blknex!=NULL&&pre->nex!=NULL)//t the last & not the last blk
			{
				(*(pre->las)).nex=pre->nex;//del pre
				(*(pre->nex)).las=pre->las;
//printf("\npre%d %d %d nex%d las%d blknex%d >blklas%d------------ \n ",pre,pre->data,pre->idx,pre->nex,pre->las,pre->blknex,pre->blklas);
				if((*(pre->nex)).data!=(*(pre->las)).data&&pre->data==(*(pre->nex)).data)//new blk
				{
					pre->nex->blklas=pre->blklas;
					pre->nex->blknex=pre->blknex;
					pre->blklas->blknex=pre->nex;
					pre->blknex->blklas=pre->nex;
			//	pre=pre->blknex;
			//	free(pre);	
//printf("newblk%d  ",pre->nex);
				}
				else
				{
					(*(pre->blklas)).blknex=pre->blknex;
					(*(pre->blknex)).blklas=pre->blklas;
				}
			}
			else
			{
				if(pre->nex==NULL)//the last fru
				{

					pre->blklas->blknex=NULL;
					pre->las->nex=NULL;
				}
				else//the last blk
				{
					(*(pre->las)).nex=pre->nex;//del pre
					(*(pre->nex)).las=pre->las;
					if((*(pre->nex)).data!=(*(pre->las)).data)//new blk
					{	
						pre->blklas->blknex=pre->nex;
						pre->nex->blklas=pre->blklas;
						pre->nex->blknex=NULL;
					}
					else
					{
						pre->blklas->blknex=NULL;
					}
				}
			}

			tmp2=pre->blknex;
		//	free(pre);
			pre=tmp2;
//printf("oldblk%d  ",pre);
				
		}
		while (pre!=NULL);

		printf("\n");
		printf("-----------------------%d-------",head->nex);
	}
	
	return 0;
}
