#include <iostream>
using namespace std;
int w[200001];
int search(int l,int r,int a)
{
	int mid;
	while(l<=r){
		mid=(l+r)/2;
		if(w[mid]==a)return mid;
		if(w[mid]>a)r=mid-1;
		else l=mid+1;
	}
	return -1;

	/*if(l>r)return -1;
	int mid=(l+r)/2;
	if(w[mid]==a)return mid;
	if(w[mid]>a)return search(l,mid-1,a);
	else return search(mid+1,r,a);*/
}


int main()
{
	//freopen("in.txt","r",stdin);
	int n,q;
	scanf("%d %d",&n,&q);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&w[i]);
	}
	int a;
	for(int i=1;i<=1;i++)
	{
		scanf("%d",&a);
		if(w[n]<a||w[1]>a)//(n-1)
		{
			cout<<"No Solution."<<endl;
			continue;
		}

		int index=search(1,n,a);
		if(index==-1)
		{
			cout<<"No Solution."<<endl;
			continue;
		}
		int l=index,r=index;
		while(l>0&&w[l]==a)l--;
		while(r<=n&&w[r]==a)r++;
		l++;r--;
		cout<<l<<" "<<r<<endl;
	}
	for(int i=2;i<=q;i++){
		scanf("%d",&a);
		cout<<"No Solution."<<endl;}
	return 0;
}