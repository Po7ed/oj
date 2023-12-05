#include <iostream>
using namespace std;

int main()
{
	freopen("in.txt","w",stdout);
	cout<<"500000"<<endl;
	for(int i=1;i<=500000;i++)
		// cout<<(i-1)%1000+1<<" ";
		cout<<"1 ";
	cout<<endl;
	for(int i=1;i<=500000;i++)
		cout<<(2*i>500000?-1:2*i)<<" "<<(2*i+1>500000?-1:2*i+1)<<" ";
	return 0;
}
