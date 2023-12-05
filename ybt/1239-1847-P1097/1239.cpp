#include <iostream>
using namespace std;
int a[200000];
void qsort(int b,int e)
{
	if(b==e)return;
	int i=b+1,j=e;
	while(i<=j)
	{
		if(a[j]<a[b])
			if(a[i]>a[b])
			{
				swap(a[i],a[j]);
				i++,j--;
			}
			else i++;
		else j--;
	}
	swap(a[b],a[j]);
	if(i==e+1)
	{
		qsort(b,e-1);
		return;
	}
	qsort(b,j);
	qsort(i,e);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	qsort(0,n-1);
	int last=-1,count=0;
	for(int i=0;i<n;i++)
	{
		if(last!=a[i]){if(i)printf("%d\n",count);printf("%d ",a[i]);count=1;last=a[i];}
		else count++,last=a[i];
	}
	printf("%d",count);
	return 0;
}