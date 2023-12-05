//ÓÃ¹é²¢µÄ
#include<iostream>
#include<algorithm>
using namespace std;

const int maxn = 200005;
struct data{
	int grade;
	int num;
	//int w;
};
data a[maxn];//totle 
data A[100001];//winnner
data B[100001];//loser
int w[maxn];//weight
bool cmp(data a,data b){
	if(a.grade != b.grade){
		return a.grade > b.grade;
	}else{
		return a.num < b.num;
	}
	
}

int n,r,q;
void mergesort(){
	int i=1,j=1,k=1;
	while(i<=n && j<=n){
		if(A[i].grade > B[j].grade || 
		(A[i].grade == B[j].grade && A[i].num < B[j].num)){
			a[k].grade = A[i].grade;//A[i]copy to a[k]
			a[k].num = A[i].num;
			i++;
		}else{
			a[k].grade = B[j].grade;//B[j]copy to a[k]
			a[k].num = B[j].num;
			j++;
		}
		k++;
	}
	while(i<=n){
			a[k].grade = A[i].grade;
			a[k].num = A[i].num;
			i++;
			k++;
	}
	while(j<=n){
			a[k].grade = B[j].grade;
			a[k].num = B[j].num;
			j++;
			k++;
	}
}
int main(){
	cin>>n>>r>>q;
	for(int i=1;i<=2*n;i++){
		cin>>a[i].grade;
		a[i].num = i;
	}
	for(int i=1;i<=2*n;i++){
		cin>>w[i];
	}
	sort(a+1,a+1+2*n,cmp);

	while(r--){

	
		int tt =1;
		for(int i=1;i<2*n;i+=2){

			if(w[a[i].num] > w[a[i+1].num]){
				A[tt].grade = a[i].grade+1;//a[i] copy to A[tt]
				A[tt].num = a[i].num;
				B[tt].grade = a[i+1].grade;//a[i+1] copy to B[tt]
				B[tt].num = a[i+1].num;
			}else{
                A[tt].grade = a[i+1].grade+1;//a[i+1] copy to A[tt]
                A[tt].num = a[i+1].num;
                B[tt].grade  =  a[i].grade;//a[i] copy to B[tt]
                B[tt].num = a[i].num;
			}
			
			tt++;
		}
		mergesort();
	}
	
	cout<<a[q].num<<endl;
	return 0;
}