#include <iostream>
// #include <algorithm>
using namespace std;

void reverse(unsigned long long n)
{
	if(n<10){printf("%d",n);return;}
	printf("%d",n%10);
	reverse(n/10);
}

int main()
{
	unsigned long long n;
	cin>>n;
	// reverse(s.begin(),s.end());
	reverse(n);
	// cout<<s<<endl;
	return 0;
}